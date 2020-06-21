#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *left,*right;
}*root=NULL;
void printlevelorder(struct node *tree,int level)
{
if(tree!=NULL)
{
if(level==0)
printf("%d ",tree->data);
else
{
printlevelorder(tree->left,level-1);
printlevelorder(tree->right,level-1);
}
}
}
int height(struct node *temp)
	{
int lh,rh;
	 if(temp==NULL)
		return -1;
	else
	{
	 lh=height(temp->left);
         rh=height(temp->right);
	 if(lh>rh)
	    return lh+1;
         else
	    return rh+1;
        }
      }
int minimum(struct node *temp)
{
 if(temp==NULL)
printf("the tree is empty");
else
{
while(temp->left!=NULL)
{
temp=temp->left;
}
}
return temp->data;
}
int maximum(struct node *temp)
{
 if(temp==NULL)
printf("the tree is empty");
else
{
while(temp->right!=NULL)
{
temp=temp->right;
}
}
return temp->data;
}
int depth(struct node *temp,int element)
{
if(temp==NULL)
return -1;
else
{
if(temp->data==element)
return 0;
else if(element<temp->data)
return 1+depth(temp->left,element);
else
return 1+depth(temp->right,element);
}
}
void level_order(struct node *tree)
{
int h,i;
h=height(tree);
for(i=0;i<=h;i++)
printlevelorder(tree,i);
}
struct node *insert(struct node *root,int ele)
	{
	 if(root==NULL)
	    {
	     root=(struct node *)malloc(sizeof(struct node));
	     root->data=ele;
	     root->left=NULL;
	     root->right=NULL;
	     }
	 else if(ele<root->data)
		root->left=insert(root->left,ele);
		
	 else if(ele>root->data)
		
                 root->right=insert(root->right,ele);	 
		
	return root;
	}

void inorder(struct node *root)
	    {
	     if(root!=NULL)
		{
		 inorder(root->left);
		 printf("%d--",root->data);
		 inorder(root->right);
		}
	    }

void preorder(struct node *root)
	    {
	     if(root!=NULL)
		{ 
		 printf("%d--",root->data);
		 preorder(root->left);
		 preorder(root->right);
		}
	    }

void postorder(struct node *root)
	    {
	     if(root!=NULL)
		{
		 postorder(root->left);
		 postorder(root->right);
 		 printf("%d--",root->data);
		}
	    }

struct node *search(struct node *temp,int ele)
	{
	 if(temp==NULL)
		 return temp;
        else
	  {
	   
	 if(ele<temp->data)
                return search(temp->left,ele);
        else if(ele>temp->data)
                return search(temp->right,ele);
	else
	    return temp;
           }
	    return temp;
           }


void main()
{
int n,i,num,elem;
printf("ENTER THE NO OF ELEMENTS");
scanf("\n%d",&n);
int ele[n];
for(i=0;i<n;i++)
    {
     printf("ENTER ELEMENTS");
     scanf("%d",&ele[i]);
     root=insert(root,ele[i]);
    }
printf("INORDER IS....\t");
inorder(root);
printf("\n");
printf("PREORDER IS....\t");
preorder(root);
printf("\n");
printf("POSTORDER IS....\t");
postorder(root);
printf("\n");
printf("HEIGHT....\t:%d\n",height(root));
printf("MINIMUM ELEMENT...\t:%d\n",minimum(root));
printf("MAXIMUM ELEMENT...\t:%d\n",maximum(root));
printf("SEARCHING.....\t");
scanf("%d",&elem);
printf("%d",search(root,elem)->data);
printf("ENTER THE ELEMENT TO FIND DEPTH\n");
scanf("%d",&num);
printf("DEPTH OF THE ELEMENT %d..:%d\n",num,depth(root,num));
depth(root,num);
printf("THE LEVEL ORDER IS \n");
level_order(root);
}
