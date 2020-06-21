#include<stdio.h>
void push(char i);
void pop(char c);
int paranthesis(char exp[]);
int top=-1;
char stack[100];
main()
{
char exp[4];
int res;
printf("ENTER THE CHARACTERS\n");
scanf("%s",exp);
res=paranthesis(exp);

if(res==0)
printf("SOLVED\n");
else
{
printf("UNSOLVED\n");
}
}
int paranthesis(char exp[])
{
int i;
for(i=0;i<strlen(exp);i++)
{
if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
{
push(exp[i]);
}
else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
{
if((stack[top]=='(')==(exp[i]==')')||(stack[top]=='[')==(exp[i]==']')||(stack[top]=='{')==(exp[i]=='}'))
{
pop(stack[top]);
}
else
{
return 0;
}
}
else
{
if(top==-1)
return 0;
}
}
}
void pop(char c)
{
if(top==-1)
printf("STACK IS EMPTY\n");
else
{

top--;
}
}
void push(char i)
{
if(top==3)
printf("STACK OVERFLOW\n");
else
{
top++;
stack[top]=i;
}
}




