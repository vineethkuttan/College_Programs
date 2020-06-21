#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;           
    struct node *next;  
}*head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
void displayList1()
{
    struct node *temp;
    if(head1== NULL)
    {
        printf("Empty.");
    }
    else
    {
        temp = head1;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
void displayList2()
{
    struct node *temp;
    if(head2 == NULL)
    {
        printf("Empty.");
    }
    else
    {
        temp = head2;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
int search(int ele)
{
	struct node *temp=head1;
	while(temp!=NULL)
	{
		if(temp->data==ele)
			return 0;
		temp=temp->next;
	}
	return 1;
}
void insert_end1(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head1 == NULL)
    {
        head1=newNode;
        tail1=newNode;
    }
    else
    {
        tail1->next=newNode;
        tail1=newNode;
    }
}
void insert_end2(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head2== NULL)
    {
        head2=newNode;
        tail2=newNode;
    }
    else
    {
        tail2->next=newNode;
        tail2=newNode;
    }
}
void main()
{
	struct node *temp;
        int n, data,u,i,a,pos;
	printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT AT END OF LIST 1\n ");  
	scanf("%d", &u);
	for (i=0;i<u;i++)
	{
		printf("\nEnter data to insert at end of the list: \n");
		scanf("%d", &data);
		insert_end1(data);
	}
	printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT AT END OF LIST 2\n ");  
	scanf("%d", &u);
	for (i=0;i<u;i++)
	{
		printf("\nEnter data to insert at end of the list: \n");
		scanf("%d", &data);
		insert_end2(data);
	}
	printf("LIST 1 IS \n");
	displayList1();
	printf("\nLIST 2 IS \n");
	displayList2();
	temp=head2;
	while(temp!=NULL)
	{
		if(search(temp->data))
				insert_end1(temp->data);
		temp=temp->next;
	}
	printf("\nUnion is\n"); 
	displayList1();
}

