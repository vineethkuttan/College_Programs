class BST:
	def __init__(self,data):
		self.data=data
		self.lchild=None
		self.rchild=None
	@staticmethod
	def insert(root,ele):
		if root is None:
			root=BST(ele)
			
		elif ele < root.data:
			root.lchild=BST.insert(root.lchild,ele)
		elif ele > root.data:
			root.rchild=BST.insert(root.rchild,ele)
		return root
def inorder(temp):
	if temp is not None:
		inorder(temp.lchild)
		print(temp.data)
		inorder(temp.rchild)
root=None
for i in range(int(input("enter n"))):
	root=BST.insert(root,int(input("enter elem")))
inorder(root)
