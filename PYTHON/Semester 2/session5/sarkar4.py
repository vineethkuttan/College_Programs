'''
Created on 15-Feb-2019

@author: student
'''
def decorator_function(org):
    def wrapper_function(*args):
        print("                    STATE BANK OF INDIA\n             Governed by Govt. of India.\n           Affiliated to Reserve Bank of India")
        return org(*args)
    return wrapper_function

balance=0
@decorator_function
def deposit(damount):
    global balance
    balance+=damount
deposit(10000)
@decorator_function
def withdraw(wamount):
    global balance
    balance-=wamount


@decorator_function
def display():
    global balance
    print("Total balance ",balance)
withdraw(2000)
display()