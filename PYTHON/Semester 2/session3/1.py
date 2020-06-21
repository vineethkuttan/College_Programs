'''
Created on Jan 26, 2019

@author: Lenovo
'''
import cx_Oracle
con=cx_Oracle.connect("project1/1234@127.0.0.1/xe")
cur=con.cursor()
#cur.execute("""create table student(ID number,First_Name varchar(10),Last_Name varchar(10),Email varchar(25),Year_Of_Birth number)""")
per,temp=[],[]
for i in range(int(input("Enter No of persons "))):
    temp.append(int(input(f"Enter the ID of Person {i+1} ")))
    temp.append(input(f"Enter the First_Name of Person {i+1} "))
    temp.append(input(f"Enter the Last_Name of Person {i+1} "))
    temp.append(input(f"Enter the Email of Person {i+1} "))
    temp.append(int(input(f"Enter the Year_Of_Birth of Person {i+1} ")))
    per.append(tuple(temp))
    temp.clear()

cur.executemany("""insert into student values(:1,:2,:3,:4,:5)""",per)
cur.execute("""alter table student add(Address varchar(60))""")
cur.execute("""select First_Name,Last_Name from student where Year_Of_Birth=1993""")
li=cur.fetchall()
print(li)
con.commit()
cur.execute("delete from student where ID=121")
cur.arraysize=int(input("Enter the array size "))
cur.execute("select * from student")
for i in cur.fetchmany():
    print(i)
cur.execute("select * from student")
for i in cur.fetchall():
    print(i)
cur.execute("truncate table student")
con.commit()
con.close()