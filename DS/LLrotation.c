#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;           
    struct node *next;  
}*head=NULL,*tail=NULL;
void middle(int data,int pos)
{
    int i;
    struct node *newNode,*temp,*temp1;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head == NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else 
    {temp=head;
        for(i=1;i<pos-1;i++)
		{
		temp=temp->next;
    		}
	newNode->next=temp->next;
	temp->next=newNode;
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
        while(temp!= NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
void rotate(int start,int end)
{
	struct node *temp=head,*p,*k,*y;
	int c=1;
	while(temp->next!=NULL)
	{
		if(c==start)
		{
			p=temp;
			if(temp!=head)
				k->next=temp->next;
			else
 				head=head->next;
		}
		k=temp;
		c+=1;
		temp=temp->next;	
	}
	middle(p->data,end);
}
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
int main()
{
        int data,u,i,a,b;
	printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT at end\n ");  
	scanf("%d", &u);
	for (i=0;i<u;i++)
	{
	printf("Enter data to insert at end of the list: \n");
	scanf("%d", &data);
	insert_end(data);
	}
	printf("Enter the start value and stop value for the rotation\n");
	scanf("%d%d",&a,&b);
	printf("Before rotation\n");
	displayList();
	rotate(a,b);
	printf("After rotation\n");
	displayList();
}


