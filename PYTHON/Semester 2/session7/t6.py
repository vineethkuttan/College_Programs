import re
st=input("Enter float number : ")
res=re.search("\d+.\d+",st)
if res==None:
    print("Invalid format")
else:
    if res.group()==st:
        print("correct format")
    else:
        print("invalid format")
