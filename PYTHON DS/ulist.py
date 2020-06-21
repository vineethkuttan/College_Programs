class ulist:
    def __init__(self,inv=None):
        self.val=inv
        self.nxt=None
    def isemp(self):
        if self.val==None:
            return(True)
        else:
            return False
    def append1(self,v):
        if self.isemp():
            self.val=v
        elif self.nxt==None:
            nn=ulist(v)
            self.nxt=nn
        else:
            (self.nxt).append1(v)
    def sum1(self):
        if self.val == None:
            return(0)
        elif self.nxt == None:
            return(self.val)
        else:
            return(self.val+self.nxt.sum1())
        
    def __str__(self):
        s=[]
        if self.val==None:
            return (str(s))
        t=self
        s.append(t.val)
        while(t.nxt!=None):
            t=t.nxt
            s.append(t.val)
        return (str(s))
    
l1=ulist()
l1.append1(5)
l1.append1(4)
l1.append1(3)
l1.append1(2)
print(l1.__str__())
print(l1.sum1())

