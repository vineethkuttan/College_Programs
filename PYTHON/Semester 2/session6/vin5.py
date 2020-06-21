from collections import defaultdict
li=[]
di1=defaultdict(lambda:"Key Not Found")
for i in range(int(input("Enter the no of dictionaries : "))):
    di=defaultdict(lambda:"Key Not Found")
    di["id"]=eval(input("Enter the value for id "))
    di["success"]=eval(input("Enter the value for success "))
    di["name"]=eval(input("Enter the value for name "))
    li.append(di)
val1=eval(input("Enter the key value "))
c1,p=0,0
val2=eval(input("Enter the value "))
for i in li:
    if val1 in i.keys():
        p+=1
        if(i[val1]==val2):
            c1+=1
if c1!=0:
    print(c1)
elif p!=0:
    pass
else:
    print(di1[val1])


    
