class tree:
    def __init__(self,data=None):
        self.data=data
        if self.data:
            self.left=tree()
            self.right=tree()
        else:
            self.left=None
            self.right=None
        return
    def insert(self,d):
        if self.isempty():
            self.data=d
            self.left=tree()
            self.right=tree()
        if self.data==d:
            return
        if d<self.data:
            self.left.insert(d)
            return
        if d>self.data:
            self.right.insert(d)
            return
    def isleaf(self):
        if self.left==None and self.right==None:
            return True
        else:
            return False
        
    def isempty(self):
        if self.data==None:
            return True
        else:
            return False
        
    def foo(self):
        if self.isempty():
            return(0)
        elif self.isleaf():
            return(self.data)
        else:
            return(self.data+max(self.right.foo(),self.left.foo()))

                
    def inorderTraversal(self, root):
        res = []
        if root:
            res = self.inorderTraversal(root.left)
            res.append(root.data)
            res = res +self.inorderTraversal(root.right)
        return res
root = tree(35)
root.insert(23)
root.insert(46)
root.insert(26)
root.insert(40)
root.insert(39)
root.insert(41)
print(root.foo())
#print(root.inorderTraversal(root))
            
                
                
