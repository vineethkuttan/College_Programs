import re
st=input("Enter string : ")
res=re.findall("\d+",st)
if res==[]:
    print("No number in the string ")
else:
    print(max(map(int,res)))
