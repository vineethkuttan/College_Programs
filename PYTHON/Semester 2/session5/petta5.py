'''
Created on 15-Feb-2019

@author: student
'''
class decorator_class:
    def __init__(self,org):
        self.org=org
    def __call__(self,*args):
        print("                    STATE BANK OF INDIA\n             Governed by Govt. of India.\n           Affiliated to Reserve Bank of India")
        return self.org(*args)
balance=0
@decorator_class
def deposit(damount):
    global balance
    balance+=damount
deposit(10000)
@decorator_class
def withdraw(wamount):
    global balance
    balance-=wamount
@decorator_class
def display():
    global balance
    print("Total balance is {}".format(balance))
withdraw(2000)
display()