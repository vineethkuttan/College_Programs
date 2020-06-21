'''
Created on Jan 30, 2019

@author: Lenovo
'''
class SumOfMultiples():
    def get_sum_of_multiples(self,input1,input2):
        su1m=0
        for i in input2:
            for j in range(input1+1):
                if(j//i>=1):
                    su1m+=j
                    break      
        return su1m
class LeapYear():
    def checkleap(self,year):
        if(year%4==0 and year%100!=0 or year%400==0):
            return "Leap year"
        else:
            return "Not a leap year"
obj=SumOfMultiples()
print(obj.get_sum_of_multiples(4,[3,5]))  
obj1=LeapYear()
print(obj1.checkleap(2012))