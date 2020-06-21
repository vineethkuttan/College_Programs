import time
import threading
class Mythread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
    def run(self):
        for i in range(1,11):
            if i>5:
                time.sleep(5)
                print(i)
            else:
                print(i)
t1=Mythread()
t1.start()