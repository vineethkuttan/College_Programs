#include<stdio.h>
#include<string.h>
void push(char var);
void pop ();
void display();
int top=-1;
int stack[100];

void main()
{
printf("Enter the expression");
int  i;
char exp[100];
gets(exp);
    for(i=0;i<strlen(exp);i++)
    {
		if( exp[i]=='(' || exp[i] =='[' || exp[i] == '{' )
		{
			top++;
			stk[top]= exp[i];
		}
		else
		if ( exp[i] == ')' )
		{
			if( stk[top] == '(' )
			top--;
		}
		else
		{
			printf("Unbalanced exp");
			exit(0);
		}
		}
		else
		if ( exp[i] == ']' )
		{
		if( stk[top] == '[' )
			top--;
		else
		{
			printf("Unbalanced exp");
			exit(0);
		}
		}
		else
		if ( exp[i] == '}' )
		{
		if( stk[top] == '{' )
			top--;
		else
		{
			printf("Unbalanced exp");
			exit(0);
		}
		}
	} 
display();
}
void fun(char muk)
{
if muk==(((a[i]==')')||(a[i]=='}')||(a[i]==']')))
{
return 1;
}
else 
{
return 0;
}
}

void push(char var)
{
stack[top]=var;
top++;
}

void pop()
{
top--;
}
void display()
{
    if (top==-1)
    {
    printf("Its valid ");
    }
    else 
    {
    printf("Its invalid");
    }
}
