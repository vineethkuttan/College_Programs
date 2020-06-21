#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lchild;
int lflag,data,rflag;
struct node *rchild;
};
typedef struct node tbst;
tbst* insert(tbst *tree,int element)
{
 tbst *newnode,*temp;
 newnode=(tbst*)malloc(sizeof(tbst));
 newnode->lflag=newnode->rflag=1;
 newnode->data=element;
 if(tree==NULL)
 {
	newnode->lchild=newnode->rchild=NULL;
	tree=newnode;
 }
 else
 {
	temp=tree;
	while(temp!=NULL)
	{
		if(element<temp->data)
		{
			if(temp->lflag==0)
			{
				temp=temp->lchild;
			}
			else
			{
				newnode->lchild=temp->lchild;
				newnode->rchild=temp;
				temp->lflag=0;
				temp->lchild=newnode;
				break;
			}
		}
		else if(element>temp->data)
		{
			if(temp->rflag==0)
			{
				temp=temp->rchild;
			}
			else
			{
				newnode->lchild=temp;
				newnode->rchild=temp->rchild;
				temp->rflag=0;
				temp->rchild=newnode;
				break;
			}
		}
		else
		{
			printf("element %d already exist",element);
			break;
		}
	}
 }
return tree;
}
void inorder_sucessor(tbst *tree)
{
tbst *temp=tree;
while(temp->lflag==0)
	temp=temp->lchild;
while(temp!=NULL)
{
	printf("%d\t",temp->data);
	if(temp->rflag==1)
		temp=temp->rchild;
	else
	{
		temp=temp->rchild;
		while(temp->lflag==0)
			temp=temp->lchild;
	}
}
}
void inorder_predecessor(tbst *tree)
{
tbst *temp=tree;
while(temp->rflag==0)
	temp=temp->rchild;
while(temp!=NULL)
{
	printf("%d\t",temp->data);
	if(temp->lflag==1)
		temp=temp->lchild;
	else
	{
		temp=temp->lchild;
		while(temp->rflag==0)
			temp=temp->rchild;
	}
}
}
main()
{
tbst *root=NULL;
int n,element,i;
printf("enter the number of elements");
scanf("%d",&n);
printf("enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&element);
root=insert(root,element);
}
printf("______inorder sucessor______\n");
inorder_sucessor(root);
printf("______inorder predecessor______\n");
inorder_predecessor(root);
}
