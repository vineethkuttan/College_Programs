'''
Created on Jan 26, 2019

@author: Lenovo
'''
import cx_Oracle
con=cx_Oracle.connect("project1/1234@127.0.0.1/XE")
cur=con.cursor()
try:
    cur.execute("""drop table Exercise_logs""")
except cx_Oracle.Error as e:
    print("*"*30)
try:
    cur.execute("""create table Exercise_logs(exercise_id number PRIMARY KEY, type_of_exercise varchar(30), minutes_of_doing_it number,calories_burn number, heart_beat_rate number)""")
    cur.execute("""create or replace procedure insert_details(id IN number,type IN varchar2,minutes IN number,calories IN number,heart_rate IN number)
    is
    BEGIN
        insert into Exercise_logs values(id,type,minutes,calories,heart_rate);
    END;""")
    
    if __name__=="__main__":
        for i in range(int(input("Enter the number of rows : "))):
            print(f"\n  *****   Enter the {i+1} row Details    *****\n")
            cur.callproc("insert_details",[int(input("Enter the Exercise_Id : ")),input("Enter the Type_of_Exercise : "),int(input("Enter the Number_of_Minutes_doing_it : ")),int(input("Enter the No_of_Calories_Burnt : ")),int(input("Enter the Heart_Beat_Rate : "))])
        cur.execute("select * from Exercise_logs where calories_burn >= 50 and minutes_of_doing_it < 30")
        print("\n Details for Calories burnt is 50 and above \n and Minutes of doing it is less than 30 :")
        for i in cur.fetchall():
            print(  i  )   
        cur.execute("select * from Exercise_logs where calories_burn >= 50 or heart_beat_rate > 100")
        print("\n Details for Calories burnt is 50 and above \n and Heart beat rate is greater than 100 :")
        for i in cur.fetchall():
            print(  i  )  
        cur.execute("select * from Exercise_logs where calories_burn >= 50")
        print("\n Details for Calories burnt is 50 and above : ")
        for i in cur.fetchall():
            print(  i ) 
        typ=set() 
        cur.execute("select * from Exercise_logs")
        detail=cur.fetchall()
        for i in detail:
            typ.add(i[1])
        typ=list(typ)
        for i in typ:
            tot=0
            cur.execute("""select * from Exercise_logs where type_of_exercise = '{}'""".format(i))
            y=cur.fetchall()
            for j in y:
                tot+=j[3]
            avg=tot/len(y)
            print(f"\n   Average Calories burnt by {i} is {avg} !!")
                
except cx_Oracle.Error as e:
    print(e)