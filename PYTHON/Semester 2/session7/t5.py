import re
oldip=input("Enter ip address ")
newip = re.sub(r'\b0+(\d)', r'\1', oldip)
print(newip)
