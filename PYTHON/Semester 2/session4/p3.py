'''
Created on Jan 30, 2019

@author: Lenovo
'''
class Employee:
    raise_amt = 1.05
    def __init__(self, first, last, pay,noofyear):
        self.first = first
        self.last = last
        self.pay = pay
        self.noofyears=noofyear
    def email(self):
        return '{}.{}@email.com'.format(self.first, self.last)
    def fullname(self):
        return '{} {}'.format(self.first, self.last)
    def apply_raise(self):
        self.pay = int(self.pay * self.raise_amt)
    def monthly_incentive(self, incentiveamount):
        self.pay=int(self.pay+self.incentiveamount)
        return self.pay
    def yearly_incentive(self, incentiveamount):
        self.pay=int(self.pay+self.incentiveamount)
        return self.pay
    def yearofexprences(self):
        return self.noofyear
    def details(self):
        return [self.fullname,self.email,self.yearofexprences()]