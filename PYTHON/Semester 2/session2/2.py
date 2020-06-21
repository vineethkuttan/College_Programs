import threading
import random
class Mythread(threading.Thread):
    def __init__(self,colour):
        threading.Thread.__init__(self)
        self.colour=colour
    def run(self):
        while True:
            x=random.randint(0,5)
            if self.colour[x]!='red':
                print(self.colour[x])
            else:
                break
li=["white","blue","black", "green","red","yellow"]
t1=Mythread(li)
t1.start()