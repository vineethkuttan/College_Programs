#include<stdio.h>
#include<string.h>
void push(char exp[],int i);
void pop();
int check_paranthesis(char exp[]);
int top=-1,size=15,res,i;
char stack[100];
main()
{
char exp[5];
printf("EXPERSSION");
scanf("%s",exp);
res=check_paranthesis(exp);
printf("%d",res);
}
int check_paranthesis(char exp[])
{
  for(i=0;i<strlen(exp);i++)
{
  if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
  { 
   push(exp,i);
  }
else if (top==-1)
{
return 0;
}
if (exp[i]==')'||exp[i]=='}'||exp[i]==']')
{
 if(((stack[top]=='(')==(exp[i]==')'))||((stack[top]=='{')==(exp[i]=='}'))||((stack[top]=='[')==(exp[i]==')')))
    {
      pop();
    }
 }
}

if(top==-1)
return 1;
else 
return 0;
}
void push(char exp[],int i)
{
if(top!=size-1)
 {
top++; 
stack[top]=exp[i];
}
}
void pop()
{
if(top!=-1)
{
printf("THE DELETED NUMBER IS %c\n",stack[top]);
top--;
}
}
