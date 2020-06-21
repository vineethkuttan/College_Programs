def initialize(b,n):
    for i in ['qu','r','c','i','d']:
        b[i]={}
    for i in range(n):
        b['qu'][i]=-1
        b['r'][i]=0
        b['c'][i]=0
    for i in range(-(n-1),n):
        b['i'][i]=0
    for i in range(2*n-1):
        b['d'][i]=0
def placingboard(i,b):
    n=len(b['qu'].keys())
    for j in range(n):
        if b['r'][i]==0 and b['c'][j]==0 and b['i'][j-i]==0 and b['d'][j+i]==0:
            (b['qu'][i],b['r'][i],b['c'][j],b['i'][j-i],b['d'][j+i])=(j,1,1,1,1)
            if i==n-1:
                return 1
            else:
                ex=placingboard(i+1,b)
            if ex:
                return 1
            else:
                (b['qu'][i],b['r'][i],b['c'][j],b['i'][j-i],b['d'][j+i])=(-1,0,0,0,0)
    else:
        return 0
b={}
n=int(input("Enter the no of queens to add"))
initialize(b,n)
if placingboard(0,b):
    for i in sorted(b['qu'].keys()):
        print("Rows:{} and Col:{}".format(i,b['qu'][i]))
