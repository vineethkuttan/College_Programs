'''from sqlalchemy.sql.schema import Column, 
Sequence
from sqlalchemy.sql.sqltypes import Integer, 
String'''
from sqlalchemy import Column,Sequence,Integer,String
from example import base
class Person(base.Base):
    __tablename__="tbl_it"
    id=Column(Integer,Sequence('seq_id',start=111),
              primary_key=True)
    name=Column(String(20))
    age=Column(Integer)
    address=Column(String(20))
    email=Column(String(20))
    def __init__(self, name, age, address, email):
        self.name = name
        self.age = age
        self.address = address
        self.email = email
    def __repr__(self):
        return '{id:'+str(self.id)+', name:'+self.name+ '}'