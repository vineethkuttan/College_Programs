'''
Created on 15-Feb-2019

@author: student
'''
from math import factorial
def decorator_function(org):
    def wrapper_function(k):
        try:
            if k<=0 and org == fibo:
                raise ValueError
            elif k<0 and org==fact:
                raise ValueError
            else:
                return org(k)
        except ValueError:
            print("Negative exception")
    return wrapper_function
        
@decorator_function        
def fibo(k):
    def c_fibo(n):
        if n <= 1:
            yield n
        else:
            sum =0
            for k in c_fibo(n-1):
                sum+=k
            for k in c_fibo(n-2):
                sum+=k 
            yield sum
    li=[]
    for i in range(k):
        for j in c_fibo(i):
            li.append(j)
    return li
@decorator_function
def fact(n):
    return factorial(n)
for i in range(int(input("Enter the no of test Cases: "))):
    k=int(input("Enter the input :"))
    print("Factorial of {} is {}".format(k,fact(k)))
    print("Fibonacci of {} is {}".format(k,fibo(k)))
