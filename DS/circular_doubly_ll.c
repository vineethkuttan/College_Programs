#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head=NULL, *tail=NULL;
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteb();
void delete_middle(int pos);
void deleteend();

int main()
{
    int n, data, choice=1;
    head = NULL;
    tail = NULL;
      while(choice != 0)
    {
        printf("1. Insert node - at beginning\n");
        printf("2. Insert node - at end\n");
        printf("3. Insert node - at N\n");
        printf("4. Display list\n");
        printf("5. Delete at Begin\n");
	printf("6. Delete at middel\n");
	printf("7. Delete at end\n");
	printf("8. EXIT\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice); 
        switch(choice)
        {
            
            case 1:
                printf("Enter data of first node : ");
                scanf("%d", &data);

                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data of tail node : ");
                scanf("%d", &data);

                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);

                insertAtN(data, n);
                break;
            case 4:
                displayList();
                break;
	case 5:
		{
		deleteb();
		printf("Element deleted");
		break;
		}
	case 6:
		{
		int pos;
		printf("\nEnter the position to delete\n");
		scanf("%d",&pos);
		delete_middle(pos);
		printf("\nElement deleted ...\n");
		break;
		}

	case 7:
		{
		deleteend();
		
		break;
		}
        default:
                printf("\nThank...you\nExiting......\n"); exit(0);
        }
        printf("\n\n\n\n\n");
    }
    return 0;
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
        temp = head->next;
	printf("Data = %d\n", head->data);
        while(temp != head)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                 
        }
    }
}
void insertAtBeginning(int data)
{
	struct node * newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->prev=NULL;
	newNode->data=data;
	
	if(head==NULL)
	{
	head=newNode;
	tail=newNode;
	tail->next=head;
	}
	else
	{
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
	tail->next=head;
	}   
}
void insertAtEnd(int data)
{
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next=NULL;
    
    newNode->data=data;
    if(head ==NULL)
    {
        head=newNode;
        tail=newNode;
	tail->next=head;
    }
    else
    {
        newNode->prev = tail;
        tail->next=newNode;
	tail=newNode;
	tail->next=head;
        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}
void insertAtN(int data, int position)
{
	int i;
	struct node * newNode, *temp,*temp1;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->prev=NULL;
	newNode->data=data;
		if(head==NULL)
		{
		tail=newNode;
		head=newNode;
		}
		else
		{
		temp=head;
		for(i=1;i<position-1;i++)
			{
			temp=temp->next;
			}temp1=temp->next;
		newNode->prev=temp;
		temp->next=newNode;
		newNode->next=temp1;
		temp->prev=newNode;
		printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
		}
}
		
void deleteb()
{
	if(head==NULL)
		printf("List is empty");
	else 
	{
	if(head==tail)
		{
		tail->next=head;
		printf("only one element is there\n");
		head=NULL;
		}
	else{
	struct node *delnode;
	delnode=head;
	head=head->next;
	head->prev=NULL;
	tail->next=head;
	free(delnode);
	}
	}
}	
void delete_middle(int pos)
{
struct node *temp;
int i;
temp=head;
for(i=1;i<pos;i++)
{
temp=temp->next;
}
if (pos==1)
deleteb();
else if (temp==tail)
deleteend();
else if(temp!=NULL)
{
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
free(temp);
}

}
void deleteend()
{
	if(head==NULL)
		{
		printf("Empty");}
	else  {
		if(head==tail)
		{
		printf("only one element is there\n");
		head=NULL;
		}
		else{
		struct node *temp;
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		tail->next=head;
		free(temp);
		printf("\nElement deleted success\n");
		}
	}
}
