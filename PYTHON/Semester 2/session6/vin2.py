from collections import Counter
from math import factorial
l=input("Enter the string : " )
l=l.casefold()
c=Counter(l)
f=factorial(len(l))
for i in c.keys():
    if c[i]>1:
        f=f/factorial(c[i])
print(f)
        
