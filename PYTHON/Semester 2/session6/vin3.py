from collections import namedtuple
li=[]
tup=namedtuple("person",'name age height')
n=int(input("Enter the no of persons "))+1
for i in range(1,n):
    exec('Person_{}=tup(input("Enter the name "),int(input("Enter the age ")),float(input("Enter the Height ")))'.format(i))
    exec("li.append(Person_{})".format(i))
for i in range(1,n):
    exec('''print(Person_{}.name)'''.format(i))
for i in sorted(li):
    print(i)
