from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy import exc
Base = declarative_base()
class Teacher(Base):
    __tablename__ = "teachers"
    id = Column(Integer, Sequence('author_id_seq'), primary_key=True)
    name = Column(String(50))
    qualification=Column(String(50))
    course_id=Column(Integer)
    course_name=Column(String(50))
    course_credit=Column(Integer,primary_key=True)
    course= relationship("Course", back_populates="teacher")
class Course(Base):    
    __tablename__ = "course"
    c_id = Column(Integer)
    c_name = Column(String(50))
    credits1= Column(Integer, ForeignKey('teachers.course_credit'))
    author = relationship("Author", back_populates="book")
    def __repr__(self):
        return("Course_id={}/nCourse_name={}/nCredits={}".format(self.c_id,self.c_name,self.credits1))
Session = sessionmaker()
engine=create_engine("oracle://vineethkuttan:hero@localhost:1521/XE")
Base.metadata.create_all(engine)
session = Session.configure(bind=engine)
session = Session()
obj=Teacher(1,'Ravi','be',12,'som',13)
obj1=Course(199,'Ram')
session.add(obj)
session.add(obj1)
session.commit()
#print(session.query(Author).all())
print(session.query(Teacher).all())
