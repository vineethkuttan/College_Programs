#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct standardtries
{
int flag;
char data;
struct standardtries *addr[26];
};
typedef struct standardtries tries;
tries* insert(tries *tree,char str[])
{
tries *temp=tree;
int len=strlen(str),i,j,index;
for(i=0;i<len;i++)
{
	index=str[i]-'a';
	if(temp->addr[index]==NULL)
	{
		temp->addr[index]=(tries*)malloc(sizeof(tries));
		temp=temp->addr[index];
		temp->data=str[i];
		temp->flag=0;
		for(j=0;j<26;j++)
			temp->addr[j]=NULL;
	}
	else
		temp=temp->addr[index];
}
temp->flag=1;
return tree;
}
int search(tries *tree,char str[])
{
tries *temp=tree;
int len=strlen(str),i,index;
for(i=0;i<len;i++)
{
	index=str[i]-'a';
	if(temp->addr[index]==NULL)
		return 0;
	else
		temp=temp->addr[index];
}
if(temp->flag==1)
	return 1;
else
	return 0;
}
void main()
{
tries *root=(tries*)malloc(sizeof(tries));
root->flag=0;
int i;
for(i=0;i<26;i++)
root->addr[i]=NULL;
int n;
printf("Enter the number of string\n");
scanf("%d",&n);
char str[15];
for(i=0;i<n;i++)
{
	printf("Enter the string to the dictionary\n");
	scanf("%s",str);
	root=insert(root,str);
}
printf("Enter the no of string to be searched\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the search string\n");
scanf("%s",str);
if(search(root,str))
	printf("STRING %s WAS FOUND\n",str);
else
	printf("STRING %s WAS NOT FOUND\n",str);
}
}