#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;           
    struct node *next;  
}*head=NULL,*tail=NULL;
void insert_end(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head == NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
void deldup()
{
struct node *temp=head,*delnode;
while(temp->next!=NULL)
	{
	if(temp->data==temp->next->data)
	{
		delnode=temp->next;
		temp->next=temp->next->next;
		delnode->next=NULL;
		free(delnode);
	}
	else
		temp=temp->next;
	}
	
}
void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
int main()
{
        int n, data,u,i,a,pos;
	 printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT at end\n ");  
	scanf("%d", &u);
	for (i=0;i<u;i++)
	{
		printf("\nEnter data to insert at end of the list: \n");
		scanf("%d", &data);
		insert_end(data);
	}
      deldup();
      displayList();
}

