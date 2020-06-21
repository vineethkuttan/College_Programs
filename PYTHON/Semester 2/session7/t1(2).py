import re
print("Welcome to KCE!")
st=input("Enter register number of student : ")
res=re.search("\d{2}[a-zA-Z]\d{3}",st)
if res==None:
    print("Register number is invalid.")
else:
    if res.group()==st:
        print("Register number is valid.")
    else:
        print("Register number is invalid.")
