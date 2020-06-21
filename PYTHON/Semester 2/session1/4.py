import pickle
class Employee:
    def __init__(self,name=None,dob=None,dept=None,desn=None,sal=None):
        self.__name=name
        self.__dob=dob
        self.__dept=dept
        self.__desn=desn
        self.__sal=sal
    def get_name(self):
        return self.__name
    def get_dob(self):
        return self.__dob
    def get_dept(self):
        return self.__dept
    def get_desn(self):
        return self.__desn
    def get_sal(self):
        return self.__sal
    def set_name(self, value):
        self.__name = value
    def set_dob(self, value):
        self.__dob = value
    def set_dept(self, value):
        self.__dept = value
    def set_desn(self, value):
        self.__desn = value
    def set_sal(self, value):
        self.__sal = value
try:
    with open("input",'wb') as fp:
        obj=Employee(input("Enter the name "),input("Enter the DOB "),input("Enter the Department "),input("Enter the Designation "),input("Enter the Salary "))
        pickle.dump(obj,fp)
    with open("input","rb") as fp1:
        obje=pickle.load(fp1)
        print('Name : {}'.format(obje.get_name()))
        print("DOB : {}".format(obje.get_dob()))
        print("Designation : {}".format(obje.get_desn()))
        print("Department : {}".format(obje.get_dept()))
        print('Salary : {}'.format(obje.get_sal()))
except Exception as e:
    print(e)