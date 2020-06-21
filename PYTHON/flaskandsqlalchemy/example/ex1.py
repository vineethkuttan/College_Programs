'''
Created on Oct 10, 2019

@author: Lenovo
'''
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy import exc
Base = declarative_base()
class customer(Base):
    __tablename__ = "customers"
    cust_id = Column(Integer, Sequence('seq_cust_id', start=5001), primary_key=True)
    name = Column(String(25))
    address = Column(String(35))
    customer_type= Column(String(20))
    def __init__(self,cust_id,name,address,customer_type):
        self.cust_id=cust_id
        self.name = name
        self.address = address
        self.customer_type = customer_type
    def get_id(self):
        return self.cust_id
    def get_name(self):
        return self.name
    def get_address(self):
        return self.address
    def get_type(self):
        return self.customer_type
    def set_id(self, value):
        self.cust_id = value
    def set_name(self, value):
        self.name = value
    def set_address(self, value):
        self.address = value
    def set_type(self, value):
        self.customer_type = value
    def __repr__(self):
        return f"\nCUSTOMER ID = {self.get_id()}\nNAME = {self.get_name()}\nADDRESS = {self.get_address()}\nCUSTOMER TYPE = {self.get_type()}"
Session = sessionmaker()
engine=create_engine("oracle://vineeth:vineeth@localhost:1521/XE")
Base.metadata.create_all(engine)    
session = Session.configure(bind=engine)
session = Session()
li=[]
for i in range(5):
    print(f"\n......Enter Customer {i+1} Details.......\n")
    temp=[]
    temp.append(int(input("Enter the Customer ID : ")))        
    temp.append(input("Enter the Name : "))
    temp.append(input("Enter the Adress : "))
    temp.append(input("Enter the Customer Type : "))
    li.append(temp)
obj1=customer(li[0][0],li[0][1],li[0][2],li[0][3])
obj2=customer(li[1][0],li[1][1],li[1][2],li[1][3])
obj3=customer(li[2][0],li[2][1],li[2][2],li[2][3])
obj4=customer(li[3][0],li[3][1],li[3][2],li[3][3])
obj5=customer(li[4][0],li[4][1],li[4][2],li[4][3])
session.add(obj1)  
session.add(obj2)
session.add(obj3)
session.add(obj4)
session.add(obj5)
session.commit()
print('\n\n........Display the First Record........\n')
print(session.query(customer).first())
session.commit()
print('\n........Update the Address of Any Customer........\n')
session.query(customer).filter_by(name=input("Enter the Name : ")).update({customer.address:input("Enter the New Address")})
session.commit()
print(session.query(customer).all())
print('\n.........Display CustomerId, Name and CustomerType of all the Customers........\n')
print(session.query(customer.cust_id,customer.name,customer.customer_type).all())
print("\n..........Delete any two person from the table.........\n")
session.query(customer).filter_by(name=input("Enter the Name : ")).delete()
session.query(customer).filter_by(name=input("Enter the Name : ")).delete()
session.commit()
print(session.query(customer).all())
session.close()
