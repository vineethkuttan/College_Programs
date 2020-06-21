#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
}*root=NULL;
struct node *insert(struct node *root,int ele)
{
if(root==NULL)
{
root=(struct node*)malloc(sizeof(struct node));
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
void inorder(struct node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("%d\n",temp->data);
inorder(temp->right);
}
}
void preorder(struct node *temp)
{
if(temp!=NULL)
{
printf("%d\n",temp->data);
preorder(temp->left);
preorder(temp->right);
}
}
void postorder(struct node *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
printf("%d\n",temp->data);
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
return (lh+1);
else
return (rh+1);
}
}
main()
{
int ele[40],i,n,k,num;
printf("ENTER THE NUMBER OF ELEMENTS\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("ENTER THE ELEMENT\n");
scanf("%d",&ele[i]);
root=insert(root,ele[i]);
}
do
{
printf("1 FOR INORDER\n2 FOR PREORDER\n3 FOR POST ORDER\n4 FOR HEIGHT\n");
scanf("%d",&k);
switch(k)
{
case 1:inorder(root);
break;
case 2:preorder(root);
break;
case 3:postorder(root);
break;
case 4:num=height(root);
printf("%d\n",num-1);
break;
}
}while(k<5);
}
