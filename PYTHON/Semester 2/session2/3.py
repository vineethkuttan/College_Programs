import threading
import time
class Salesperson(threading.Thread):
    def __init__(self,sname,day):
        threading.Thread.__init__(self)
        self.sname=sname
        self.day=day
    def run(self):
        for i in self.sname:
            print(i)
class Days(threading.Thread):
    def __init__(self,days,sname):
        threading.Thread.__init__(self)
        self.days=days
        self.sname=sname
    def run(self):
        for i in self.days:
            print(i)
            if i in ["sunday","monday","tuesday"]:
                time.sleep(3)
            obj=Salesperson(self.sname,i)
            obj.start()
day=["sunday","monday","tuesday","wednesday","thursday","friday","saturday"]
sname=["oviya","yashika","vineeth"]
t1=Days(day,sname)
t1.start()        