import Queue
import threading
import time
def fun(name):
    print("{} thread started".format(name))
    time.sleep(5)
    print("{} thread ended".format(name))
q=Queue.PriorityQueue()
q.put((1,threading.Thread(target=fun,args=("Maximum",))))
q.put((2,threading.Thread(target=fun,args=("Normal",))))
q.put((3,threading.Thread(target=fun,args=("Minimum",))))
while not q.empty():
    x=q.get()[1]
    x.start()        