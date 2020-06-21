class TBST:
	def __init__(self,data):
		self.data=data
		self.lc=None
		self.rc=None
		self.lf=1
		self.rf=1
	@staticmethod
	def insert(root,data):
		nn=TBST(data)
		if root is None:
			root=nn
		else:
			temp=root
			while temp!=None:
				if data<temp.data:
					if temp.lf is 0:
						temp=temp.lc
					else:
						nn.lc=temp.lc
						nn.rc=temp
						temp.lf=0
						temp.lc=nn
						break
				elif data>temp.data:
					if temp.rf is 0:
						temp=temp.rc
					else:
						nn.rc=temp.rc
						nn.lc=temp
						temp.rf=0
						temp.rc=nn
						break
				else:
					print("Element is already present\n")
					break
		return root
	@staticmethod
	def inordersuccessor(tree):
		temp=tree
		while(temp.lf==0):
			temp=temp.lc
		while(temp is not None):
			print("-> {}".format(temp.data))
			if(temp.rf==1):
				temp=temp.rc
			else:
				temp=temp.rc
				while(temp.lf==0):
					temp=temp.lc
root=None					
for i in range(int(input())):
	root=TBST.insert(root,int(input()))
TBST.inordersuccessor(root)					
