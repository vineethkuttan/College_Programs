'''
Created on Jan 30, 2019

@author: Lenovo
'''
def is_isogram(input):
    k=True
    input=input.casefold()
    for i in set(input):
        if i.isalpha():
            if(input.count(i)>1):
                k=False
                break
    return k
print(is_isogram("vineeth"))
