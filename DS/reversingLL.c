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
void reverse()
{
	struct node *temp,*p1,*p2;
	p1=p2=temp=head;
	p1=p1->next->next;
	p2=p2->next;
	temp->next=NULL;
	p2->next=temp;
	while(p1!=NULL)
	{	
		temp=p2;	
		p2=p1;
		p1=p1->next;
		p2->next=temp;
	}
	temp=head;
	head=tail;
	tail=temp;
}
void main()
{
        int n, data,u,i,a,pos;
	printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT AT END\n ");  
	scanf("%d", &u);
	for (i=0;i<u;i++)
  	{
		printf("\nEnter data to insert at end of the list: \n");
		scanf("%d", &data);
		insert_end(data);
	}
	printf("Before reversing the List\n");
	displayList();	
	reverse();
	printf("After reversing the List\n");
	displayList();
}
