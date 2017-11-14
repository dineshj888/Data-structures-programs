//queues
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define qsize 3
int q[3],item,front=0,rear=-1;
void insertq()
{
	if(rear==qsize-1)
	{
		printf("Q is Full\n");
		return;
	}
	rear=rear+1;
	q[rear]=item;
}
int deleteq()
{
	int item_del;
	if(front>rear)
	{
		printf("Q Empty\n");
		return -1;
	}
	item_del=q[front];
	front=front+1;
	return item_del;
}
void display()
{
	int i;
	if(front>rear)
	{
		printf("Q Empty\n");
		return;
	}
	printf("Queue Contents\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\n",q[i]);
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
			case 1:printf("Enter your item\n");
				scanf("%d",&item);
				insertq();
				break;
			case 2:item_del=deleteq();
				printf("your Deleted item is\n");
				printf("%d\n",item_del);
				break;
			case 3:display();
				break;
			default:exit(0);
				getch();
		}
	}
}

