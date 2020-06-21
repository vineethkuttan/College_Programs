'''
Created on 15-Feb-2019

@author: student
'''
def make_bold(fn):
    return lambda:"<b>" + fn() + "</b>"
def make_italic(fn):
    return lambda:"<u>" + fn() + "</i>"
def make_underline(fn):
    return lambda:"<i>" + fn() + "</i>"
@make_bold
@make_italic
@make_underline
def fun():
    return "Vineeth"
print(fun())