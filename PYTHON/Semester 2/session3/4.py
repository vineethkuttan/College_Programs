'''
Created on Jan 26, 2019

@author: Lenovo
'''
import cx_Oracle
con=cx_Oracle.connect("project1/1234@127.0.0.1/XE")
cur=con.cursor()
try:
    cur.execute("""drop table employee""")
except cx_Oracle.Error as e:
    print("*"*45)
try:
    class Employee():
        def __init__(self,idd,name,designation,address,age,salary,exper):
            self.idd=idd
            self.name=name
            self.designation=designation
            self.address=address
            self.age=age
            self.salary=salary
            self.exper=exper
        def get_id(self):
            return self.idd
        def get_name(self):
            return self.name
        def get_des(self):
            return self.designation
        def get_add(self):
            return self.address
        def get_age(self):
            return self.age
        def get_sal(self):
            return self.salary
        def get_exp(self):
            return self.exper
        def creation(self):
            cur.execute("""create table employee(emp_id number(10) primary key,emp_name varchar2(30), emp_designation varchar2(30),emp_address varchar2(90),emp_age number(3),emp_salary number(9,2),emp_experience number(2))""")
        def insertion(self):
            cur.execute("""create or replace procedure insert_emp_details(eid IN number,ename IN varchar2,empdes IN varchar2,empadd IN varchar2,empage IN number,empsal IN number,empex IN number)
            is
            BEGIN
            insert into employee values(eid,ename,empdes,empadd,empage,empsal,empex);
            END;""")
            cur.callproc("insert_emp_details",[self.get_id(),self.get_name(),self.get_des(),self.get_add(),self.get_age(),self.get_sal(),self.get_exp()])
        def display(self):
            cur.execute("""create or replace function fn_list_all return SYS_REFCURSOR
            AS
            listall SYS_REFCURSOR;
            BEGIN
            open listall for 
                select * from employee;
            return listall;
            END fn_list_all;
            """)
            my_cursor=cur.callfunc("fn_list_all",returnType=cx_Oracle.CURSOR)
            print("\n   ****** All Employee Details  ***** \n")
            for row in my_cursor:
                print(row)
        def update(self):
            cur.execute("""create or replace procedure updaterow(id IN number,name IN varchar2)
            is
            BEGIN
            update employee set emp_name= name where emp_id = id;
            END;""")
            cur.callproc("updaterow",[int(input("\nId to update : ")),input("New Name : ")])
            print("\n Employee Detail Successfully Updated !!!! ")
        def deletion(self):
            cur.execute("""create or replace procedure deleterow(name IN varchar2)
            is
            BEGIN
            delete employee where emp_name = name;
            END;""")
            cur.callproc("deleterow",[input("\nEnter the name to delete its entire content ")])
            print("\nDeleted!!!! ")
    if __name__=="__main__":
        for i in range(int(input("Enter the no of rows : "))):
            print(f"\n  ***  Enter the Employee {i+1} Details  *** ")
            obj=Employee(int(input("Enter the Id : ")),input("Enter the Name : "),input("Enter the Designation : "),input("Enter the address : "),int(input("Enter the Age : ")),float(input("Enter the Salary : ")),int(input("Enter the Experience : ")))
            if i == 0:
                obj.creation()
            obj.insertion()
        obj.update()   
        obj.deletion()
        obj.display() 
        con.commit()
        con.close()
except cx_Oracle.Error as e:
    print("*"*20,e,"*"*20)