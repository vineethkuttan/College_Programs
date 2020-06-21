#include<stdio.h>
#include<stdlib.h>
typedef struct node avl;
struct node
{
struct node *lchild,*rchild;
int data;
};
void inorder(avl *temp)
{
if(temp!=NULL)
{
inorder(temp->lchild);
printf("%d\t",temp->data);
inorder(temp->rchild);
}
}
avl* LL(avl *tree)
{
avl *k2=tree,*k1=k2->lchild;
k2->lchild=k1->rchild;
k1->rchild=k2;
return k1;
}
avl* RR(avl *tree)
{
avl *k1=tree,*k2=k1->rchild;
k1->rchild=k2->lchild;
k2->lchild=k1;
return k1;
}
avl* LR(avl *tree)
{
avl *k3=tree,*k1=k3->lchild,*k2=k1->rchild;
k1->rchild=k2->lchild;
k3->lchild=k2->rchild;
k2->lchild=k1;
k2->rchild=k3;
return k2;
}
avl *RL(avl *tree)
{
avl *k1=tree,*k3=k1->rchild,*k2=k2->lchild;
k1->rchild=k2->lchild;
k3->lchild=k2->rchild;
k2->lchild=k1;
k2->rchild=k2;
return k2;
}
avl* balance(avl* tree)
{
int heightdiff=height(tree->lchild)-height(tree->rchild);
if(heightdiff==2)
{
	int x=height(tree->lchild->lchild)-height(tree->lchild->rchild);
	if(x==1||x==0)
		tree=LL(tree);
	else
		tree=LR(tree);
}
else if(heightdiff==-2)
{
	int y=height(tree->rchild->lchild)-height(tree->rchild->rchild);
	if(y==-1||y==0)
		tree=RR(tree);
	else
		tree=RL(tree);
}
return tree;
} 
avl* insert(avl *tree,int ele)
{
if(tree==NULL)
{
	tree=(avl*)malloc(sizeof(avl));
	tree->data=ele;
	tree->rchild=tree->lchild=NULL;
}
else
{
	if(ele<tree->data)
	{
		tree->lchild=insert(tree->lchild,ele);
		tree=balance(tree);
	}
	else if(ele>tree->data)
	{
	tree->rchild=insert(tree->rchild,ele);
	tree=balance(tree);
	}
}
return tree;
}
int height(avl *tree)
{
if(tree==NULL)
return -1;
else
{
int lh=height(tree->lchild);
int rh=height(tree->rchild);
if(lh>rh)
	return lh+1;
else
	return rh+1;
}
}
int main()
{
avl *root=NULL;
int ele,i=1;
while(i<3 &&  i>0)
{
printf("\nEnter 1 to insert\nEnter 2 to display.");
scanf("%d",&i);
switch(i)
{
case 1:printf("\nEnter the element  :    ");
	    scanf("%d",&ele);
	    root=insert(root,ele);
	    break;
case 2:inorder(root);
	     break;
default:
           printf("Wrong choice");	
}
}
return 0;
}