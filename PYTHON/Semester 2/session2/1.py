import threading
def fun(a):
    print("Thread name before setting ",threading.currentThread().getName())
    threading.currentThread().setName(a)
    print("Thread name after setting ",threading.currentThread().getName())
t1=threading.Thread(target=fun,args=("scooby",))
t2=threading.Thread(target=fun,args=("shaggy",))
t1.start()
t1.join()
t2.start()
t2.join()
