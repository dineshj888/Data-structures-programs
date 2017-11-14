//Circular queue
#include<stdio.h>
#include<conio.h>
#define qsize 3
int count,f,r=-1,item,q[3];
void insert_rear()
{
	if(count==qsize)
	{
		printf("Queue overflow\n");
		return;
	}
	r=r+1;
	q[r]=item;
	count=count+1;
}
int del_front()
{
	int item_del;
	{
		if(count==0)
		{
			printf("Queue Empty\n");
			return -1;
		}
		item_del=q[f];
		f=(f+1)%qsize;
		count=count-1;
		return item_del;
	}
}
void display()
{
	int i,temp=f;
	if(count==0)
	{
		printf("Queue empty\n");
		return;
	}
	printf("CQ contents\n");
	for(i=1;i<=count;i++)
	{
		printf("%d\n",q[temp]);
		temp=(temp+1)%qsize;
	}
}
void main()
{
	int choice,item_del;
	clrscr();
	for(;;)
	{
		printf("Enter your choice\n 1.insert\t 2.delete\t 3.display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element to be inserted\n");
				scanf("%d",&item);
				insert_rear();
				break;
			case 2:item_del=del_front();
				if(item_del!=-1);
				printf("The deleted item is %d\n",item_del);
				break;
			case 3:display();
				break;
			default:getch();
				exit(0);
		}
	}
}
