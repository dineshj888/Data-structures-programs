//stacks
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 5
int top=-1,s[5],item;

void push()
{
	if(top==size-1)
	{
		printf("Stack overflow\n");
		return;
	}
	top=top+1;
	s[top]=item;
}
int pop()
{
	int item_del;
	if(top==-1)
	{
		printf("Stack Empty\n");
		return -1;
	}
	item_del=s[top];
	top=top-1;
	return item_del;
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack Empty\n");
		return;
	}
	for(i=0;i<=top;i++)
	{
		printf("%d\n",s[i]);
	}
}
void main()
{
	int item_del,choice;
	clrscr();
	for(;;)
	{
		printf("Enter your choice\n 1.push\t 2.pop\t 3.display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the Element to be inserted\n");
				scanf("%d",&item);
				push();
				break;
			case 2:item_del=pop();
				if(item_del!=-1)
				printf("Popped Element is %d\n",item_del);
				break;
			case 3:display();
				break;
			default:getch();
				exit(0);
		}
	}
}