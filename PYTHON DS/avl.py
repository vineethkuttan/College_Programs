class AVL:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    @staticmethod
    def insert(root,ele):
        if root is None:
            root=AVL(ele)
        elif(ele < root.data):
            root.left=root.insert(root.left,ele)
            root=root.balance(root)
        elif(ele > root.data):
            root.right=root.insert(root.right,ele)
            root=root.balance(root)
        else:
            print("Element Already Exits")
        return root
    @staticmethod
    def balance(root):
        height_diff=root.height(root.left)-root.height(root.right)
        if height_diff==2:
            x=root.height(root.left.left)-root.height(root.left.right)
            if x==1 or x==0:
                root=root.leftleft(root)
            else:
                root=root.leftright(root)
        elif height_diff==-2:
            y=root.height(root.right.left)-root.height(root.right.right)
            if y==-1 or y==0:
                root=root.rightright(root)
            else:
                root=root.rightleft(root)
        return root
    @staticmethod
    def inorder(root):
        if root is not None :
            root.inorder(root.left)
            print(root.data,end=" ")
            root.inorder(root.right)
    @staticmethod
    def preorder(root):
        if root is not None :
            print(root.data,end=" ")
            root.preorder(root.left)
            root.preorder(root.right)
    @staticmethod
    def postorder(root):
        if root is not None :
            root.postorder(root.left)
            root.postorder(root.right)
            print(root.data,end=" ")
    @staticmethod
    def height(root):
        if root is None :
            return -1
        else:
            left_height=root.height(root.left)
            right_height=root.height(root.right)
            if left_height > right_height :
                return left_height + 1
            else:
                return right_height + 1
    @staticmethod
    def leftleft(root):
        k2=root
        k1=k2.left
        k2.left=k1.right
        k1.right=k2
        return k1
    @staticmethod
    def rightright(root):
        k1=root
        k2=k1.right
        k1.right=k2.left
        k2.left=k1
        return k2
    @staticmethod
    def leftright(root):
        k3=root
        k1=k3.left
        k2=k1.right
        k1.right=k2.left
        k3.left=k2.right
        k2.left=k1
        k2.right=k3
        return k2
    @staticmethod
    def rightleft(root):
        k1=root
        k3=k1.right
        k2=k3.left
        k1.right=k2.left
        k3.left=k2.right
        k2.left=k1
        k2.right=k3
        return k2
root=None
N=int(input("Enter the Number of Values:"))
values=str(input("Enter the Values:"))
for i in values.split():
    root=AVL.insert(root,i)
print("  \nDisplay Final AVL Tree Elements in Inorder  ")
AVL.inorder(root)
print("  \nDisplay Final AVL Tree Elements in Preorder  ")
AVL.preorder(root)
print("  \nDisplay Final AVL Tree Elements in Postorder  ")
AVL.postorder(root)

    


