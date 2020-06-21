#include<stdio.h>
#include<stdlib.h>
#define max 100
void push(int num);
void pop();
void display();
int top=-1;
int stack[max];
void push(int num)
{
if(top==max-1)
	printf("Stack is full");
else{ 
	top++;
	stack[top]=num;
	printf("Pushed element are %d\n",num);
	}
}
void pop()
{
if(top==-1)
	printf("Stack is empty\n");
else{
	printf("Poped element is %d \n",stack[top]);
	top--;
	}
}
void display()
{
if(top==-1){
	printf("Stack is empty\n");
	}
else{
	int i;
	for(i=top;i>=0;i--)
		{
		printf("%d\n",stack[i]);
		}
	}
}


void main()
{
int choice;
int number;

	while(1){
	printf("Enter choice 1 for push 2 for pop 3 for display\n");
	scanf("%d",&choice);
		switch (choice)
				{
		case 1:
			{
			printf("Enter the number ");
			
			scanf("%d",&number);
			push(number);break;
			}
		case 2:
			{
			pop();break;
			}
		case 3:
			{
			display();break;
			}
		case 4 :
			{
			exit (0);
			}	
		}		
}
	
}	
