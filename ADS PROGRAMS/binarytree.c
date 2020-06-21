#include<stdio.h>
#include<stdlib.h>
struct node* create();
void display_paths(struct node* root, int path[], int length);
struct node
{
int data;
struct node *left;
struct node *right;
}*root;
struct node* create()
{
int ele;
struct node *root;
printf("Enter data ( -1 for no data ) :");
scanf("%d",&ele);
if(ele==-1)
return NULL;
root=(struct node*)malloc(sizeof(struct node));
root->data=ele;
printf(" Enter left child of %d : \n",ele);
root->left=create();
printf(" Enter right child of %d : \n",ele);
root->right=create();
return root;
}
void display_paths(struct node* root, int path[], int length)
{
int i;
if (root==NULL)
return;
path[length] = root->data;
length++;
if (root->left==NULL && root->right==NULL)
{
for (i=0; i<length; i++)
{
printf("%d", path[i]);
if (i < length-1)
printf(" -> ");
}
printf("\n");
}
else
{
display_paths(root->left, path, length);
display_paths(root->right, path, length);
}
}
int main()
{
int path[1000];
root=create();
printf("\n All Paths: \n");
display_paths(root,path,0);
return 0;
}
