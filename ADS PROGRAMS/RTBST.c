#include<stdio.h>
#include<stdlib.h>
typedef struct node TBST; 
struct node
{
int data,lf,rf;
struct node *lc,*rc;
};
TBST* insert(TBST *tree,int elem)
{
TBST *nn,*temp;
nn=(TBST*)malloc(sizeof(TBST));
nn->lf=nn->rf=1;
nn->data=elem;
if(tree==NULL)
{
	nn->lc=nn->rc=NULL;
		tree=nn;
}
else
{
	temp=tree;
	while(temp!=NULL)
	{
	if(elem<temp->data)
	{
		if(temp->lf==0)
			temp=temp->lc;
		else
		{
		nn->lc=NULL;
		nn->rc=temp;
		temp->lf=0;
		temp->lc=nn;
		break;
		}
	}
        else if(elem>temp->data)
	{
		if(temp->rf==0)
			temp=temp->rc;
		else
		{
		nn->lc=NULL;
		nn->rc=temp->rc;
		temp->rf=0;
		temp->rc=nn;
		break;
		}
	}
	else
	{
	printf("The element is already exist %d",elem);
	break;
	}
}
}
return tree;
}
void inordersuccessor(TBST *tree)
{
TBST *temp=tree;
while(temp->lf==0)
	temp=temp->lc;
while(temp!=NULL)
{
printf("%d\t",temp->data);
if(temp->rf==1)
	temp=temp->rc;
else
{
 	temp=temp->rc;
	while(temp->lf==0)
	temp=temp->lc;
}
}
}

main()
{
TBST *root=NULL;
int elem,i,n;
printf("Enter the no of values\n");
scanf("%d",&n);
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&elem);
root=insert(root,elem);
}
inordersuccessor(root);
}
