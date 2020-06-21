import threading
def fun1():
    for i in range(1,21):
        if(i%2==0):
            print(i)
def fun2():
    for i in range(1,21):
        if(i%2!=0):
            print(i)      
t1=threading.Thread(target=fun1)
t2=threading.Thread(target=fun2)      
t1.start()
t1.join()
t2.start()                        