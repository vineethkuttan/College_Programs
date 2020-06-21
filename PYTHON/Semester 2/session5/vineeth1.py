'''
Created on 15-Feb-2019

@author: student
'''
def decorator_function(orf):
    def wrapper_function():
        print("printing prime numbers between 100 to 1000...")
        return orf()
    return wrapper_function
@decorator_function
def CalcPrime():
    def isprime(a):
        k=0
        for i in range(2,a//2+1):
            if(a%i==0):
                k=k+1
        if(k<=0):
            return True
        else:
            return False
    for i in range(101,1000):
        if i%5!=3:
           if isprime(i):
               print(i) 
CalcPrime()