#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;           
    struct node *next;  
}*head,*tail;
void insert_begin(int data);
void middle(int data);
void insert_end(int data);
void delete_begin();
void delete_middle(int data);
void delete_end();
void displayList();
int main()
{
        int n, data,u,i,a,pos;
	printf("\n 1 ,2,3 for insert begin ,middle,and end ...4,5,6 for delete at begin,middle and end and finally 7 for display the list,8for exit/n");
	while(1)
		{
     		printf("\nEnter cases\n");scanf("%d",&a);
			switch(a)
		     		{
		      		case 1:
					{	
						printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT\n ");
						scanf("%d", &u);
		     				for (i=0;i<u;i++)
		     				{
		     	  			printf("\nEnter data to insert at beginning of the list:\n ");
		     	  			scanf("%d", &data);
			  			insert_begin(data);
			 			}
						break;
					}
				case 2:
					{      int data;
						printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT at middel \n");  
						scanf("%d", &u);
		     				for (i=0;i<u;i++)
		     				{
		     	  			printf("\nEnter data to insert at middle of the list:\n ");
		     	  			scanf("%d", &data);
			  			middle(data);
			 			}
						break;
					}
				case 3:		
					{   printf("\nENTER HOW MANY ELEMENTS  WANTS TO INSERT at end\n ");  
						scanf("%d", &u);
		     				for (i=0;i<u;i++)
		     				{
		     	  			printf("\nEnter data to insert at end of the list: \n");
		     	  			scanf("%d", &data);
			  			insert_end(data);
			 			}
						break;
					}
				case 4:
					{
						delete_begin();
						break;
					}
				case 5:	
					{
						printf("\nENTER THE POSITION TO DELETE\n");
						int position;
						scanf("%d",&position);	
						delete_middle(position);
						break;
					}
				case 6:
					{
						delete_end();
						printf("\nDELETED AT END OF LIST SUCESS FOR DISPLAY CLICK 7\n");
						break;
					}
				
				case 7:
					{ printf("\nData in the list \n");
						displayList();
					 
					 break;
					}				
				default:
					{
						printf("\nThnak you exiting.........\n");
						exit(0);
					}
				}
		}
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
	printf("NEW NODE CREATED\n");
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
void insert_begin(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head == NULL)
    {
        head=newNode;
        tail=newNode;
	printf("NEW NODE CREATED\n");
    }
    else
    {
        newNode->next = head; 
        head = newNode;          
        printf("DATA INSERTED SUCCESSFULLY\n");
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
void middle(int data)
{
    int i,pos;
printf("\nEnter thee position\n");
scanf("%d",&pos);
    struct node *newNode,*temp,*temp1;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head == NULL)
    {
        head=newNode;
        tail=newNode;
	printf("NEW NODE CREATED\n");
    }
    else 
    {temp=head;
        for(i=1;i<pos-1;i++)
		{
		temp=temp->next;
    		}
	newNode->next=temp->next;
	temp->next=newNode;
	printf("\nInserted element in %d position sucess\n",pos);
}
}

void delete_begin()
{
if(head==NULL)
printf("EMPTY LINKED LIST");
else
{
struct node *delnode;
delnode=head;
head=head->next;
free(delnode);
}
}
void delete_middle(int pos)
{int i;
if(head==NULL)
printf("\nEMPTY LINKED LIST\n");
else 
    {
	struct node *delnode,*temp;
	temp=head;
        	for(i=1;i<pos-1;i++)
		{
		temp=temp->next;
    		}
	delnode=temp->next;
	temp->next=delnode->next;
	delnode->next=NULL;
	free(delnode);
	printf("\nDeleted  element in %d position sucess\n",pos);
	}
}
void delete_end()
{
	if(head==NULL)
		printf("EMPTY LINKED LIST");
	else
		{
		struct node *delnode,*temp;
		delnode=tail;
		temp=head;
			while(temp->next!=tail)
			{
			temp=temp->next;
			}
			temp->next=NULL;
			tail=temp;
			printf("\nDELETED ELEMENT IS %d\n",delnode->data);
			free(temp->next);
		}
}
