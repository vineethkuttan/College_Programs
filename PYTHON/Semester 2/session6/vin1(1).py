from collections import OrderedDict
d1,d2=OrderedDict(),OrderedDict()
for i in range(int(input("Enter the no of contacts : "))):
    d1[input("Enter the name ")]=int(input("Enter the phone number : "))
print(d1)
if input("Enter the key to check") in d1.keys():
    print("Key is present")
else:
    print("Oops!  sorry")
if int(input("Enter the value to check")) in d1.values():
    print("value is present")
else:
    print("Oops!  sorry")
for i,j in d1.items():
    d2[j]=i
print(d2)
    
