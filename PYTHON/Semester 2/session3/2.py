'''
Created on Jan 26, 2019

@author: Lenovo
'''
import cx_Oracle
con=cx_Oracle.connect("SYSTEM/SysOracle@127.0.01/XE")
cur=con.cursor()
li=[]
cur.execute("create table Train_reservation( trainno number, trainname varchar(30), fro_m varchar(30),t_o varchar(30),departur_e varchar(30), arriva_l varchar(30), clas_s varchar(30))")
for i in range(5):
    li.append(int(input("Enter the train no ")))
    li.append(input("Enter the train name "))
    li.append(input("Enter from "))
    li.append(input("Enter to"))
    li.append(input("Enter departure time"))
    li.append(input("Enter arrival time"))
    li.append(input("Enter class "))
    tup=tuple(li)
    li.clear()
    li.append(tup)
    cur.executemany("""insert into Train_reservation values(:1,:2,:3,:4,:5,:6,:7)""",li)
li.clear()
cur.execute("update Train_reservation set trainname='bombay express' where trainno=102")
cur.execute("delete from Train_reservation where trainno=103")
cur.execute("select * from Train_reservation")
for i in cur.fetchall():
    print(i)
con.commit()