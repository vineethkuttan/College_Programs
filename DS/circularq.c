#include<stdio.h>
#include<stdlib.h>
void en(int ele);
int de();
void display();
#define size 6
int que[size];
int rear=-1,front=-1;


void en(int ele)
{
    rear=(rear+1)%size;
    
    if (rear==front)
    {
        printf("stack overfull");
        if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear=rear-1;
            
        }
    }
    else
    {
	if (front==-1)
	front=0;
     que[rear]=ele;
     printf("\n Inserted -> %d", ele);
    }
display();
}
int de()
{
    int item;
    if((rear==front)||(front==-1))
    {
        printf("empty");
    }
    else
    {
        front=(front+1)%size;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("empty");
    }
    else
    {
        
        for( i = front; i<=rear; i++) {
            printf("\n%d \n",que[i]);
        }
      printf("\n%d \n",que[i]);  
    }
}
void main()
 {
int c,e;
	while(1)
	{
	printf("\nenter choice");
	scanf("%d",&c);
		switch(c)
		{		
			case 1:
			printf("\nenter the element\n");
			scanf("%d",&e);
			en(e);
			break;
			case 2:
			de();
			break;
			case 3:
			display();
			break;
			default :
			printf("\nexit...............");
			exit(0);
		}
	}
}
