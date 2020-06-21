from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy import exc
Base = declarative_base()
class Teacher(Base):
    __tablename__ = "teachers"
    t_id = Column(Integer, Sequence('teacher_id_seq'), primary_key=True)
    t_name = Column(String(50))
    t_qualification=Column(String(50))
    def __init__(self,t_id,t_name,t_qualification):
        self.t_id=t_id
        self.t_name = t_name
        self.t_qualification=t_qualification
    def __repr__(self):
        return(f"\nTeacher_ID = {self.t_id}\nTeacher_Name = {self.t_name}\nQualification = {self.t_qualification}\n")
    course= relationship("Course", back_populates="teacher")
class Course(Base):
    __tablename__ = "courses"
    c_id=Column(Integer,Sequence('course_id_seq'), primary_key=True)
    c_name=Column(String(50))
    c_credit=Column(Integer)
    teacher_id = Column(Integer,ForeignKey('teachers.t_id'))
    teacher=relationship("Teacher",back_populates="course")
    def __init__(self,c_id,c_name,c_credit,teacher):
        self.c_id=c_id
        self.c_name = c_name
        self.c_credit=c_credit
        self.teacher=teacher
    def __repr__(self):
        return(f"\n{self.teacher}\nCourse_ID = {self.c_id}\nCourse_Name ={self.c_name}\nCredits = {self.c_credit}\n")
    
Session = sessionmaker()
engine=create_engine("oracle://vineeth:vineeth@localhost:1521/XE")
Base.metadata.create_all(engine)
session = Session.configure(bind=engine)
session = Session()
t1=Teacher(120,'Mr.Vikram','M.Ed,B.Ed,MA')
c1=Course(10,'Python',5,teacher=t1)
c2=Course(12,'Web Developement',5,teacher=t1)
session.add(c1)
session.add(c2)
session.commit()
qry=session.query(Course).all()
for i in range(len(qry)):
    print(qry[i])
