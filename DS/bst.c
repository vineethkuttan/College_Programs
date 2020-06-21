#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left,*right;
}*root=NULL;

struct node *insert(struct node *root ,int);
void inorder(struct node *root);
void min(struct node *);
void max(struct node *);



struct node *insert(struct node *root ,int data )
{

	if(root==NULL)
	{
	root =(struct node *)malloc(sizeof(struct node)); 
	root->left=NULL;
	root->right=NULL;
	root->data=data;
	printf(" node created %d\n",data);
	return root;
	}
else
{
	 if(data<root->data)
	root->left=insert(root->left,data);
	else if(data > root->data)
	root->right=insert(root->right,data);
	else 
	printf("Same element u enterd\ntry different\n");
	return(root);
}
}
void inorder(struct node *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d\n",root->data);
inorder(root->right);
}
}
void postorder(struct node *root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d\n",root->data);
}
}
void preorder(struct node *root)
{
if(root!=NULL)
{
printf("%d\n",root->data);
preorder(root->left);
preorder(root->right);
}
}
int main()
{
	int choice;
	int i,n,data;
	printf("\n....................BINARY TREES IMPLEMENTATIONS....................................");
	while(1)
	{
		printf("\n\nBinary Search Tree Operations\n");
		printf("\n1. Creation of BST");
		printf("\n2. Traverse in Inorder");
		printf("\n3. Traverse in Preorder");
		printf("\n4. Traverse in Postorder");
		printf("\n5. Find maximum element in the node");
		printf("\n6. Find minumum element in the node");
		printf("\n7. Exit\n");
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
			switch(choice)
			{
				case 1 :
					printf("Enter how many nodes wants to create\n");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("\nEnter data for node %d : ", i);
						scanf("%d",&data);
						root=insert(root,data);
					}
					printf("\nBST with %d nodes is ready to Use!!\n", n);
					break;
				case 2 :
					inorder(root);
					break;
				case 3:
					preorder(root);
					break;
				case 4:
					postorder(root);
					break;
				case 5 :
					printf("The maximum element\n");
					max(root);
					break;
				case 6:
					printf("The minimum element");
					min(root);
					break;
				case 7:
					exit(1);

			}
	}
}

void min(struct node *root)
{
while(root->left !=NULL)
{
root=root->left;
}
printf("%d ",root->data);
}

void  max(struct node *root)
{
while(root->right !=NULL)
{
root=root->right;
}
printf("%d ",root->data);
}
