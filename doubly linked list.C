//program to create a circular doubly linked list and
// to display the contents of the list
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("OUT OF MEMORY\n");
		getch();
		exit(0);
	}
	return x;
}

NODE insertfront(int item,NODE head)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;
	cur=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;
	return head;
}

NODE insertleft(int item,NODE head)
{
	NODE temp,cur,prev;
	if(head->rlink==head)
	{
		printf("List is empty\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(item==cur->info)break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("Key not found\n");
		return head;
	}
	prev=cur->llink;
	printf("Enter the item to insert towards left of %d\n",item);
	scanf("%d",&item);
	temp=getnode();
	temp->info=item;
	prev->rlink=temp;
	temp->llink=prev;
	cur->llink=temp;
	temp->rlink=cur;
	return head;
}

NODE deleteitem(int item,NODE head)
{
	NODE cur,prev,next;
	if(head->rlink==head)
	{
		printf("list is empty cannot delete\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(item==cur->info)break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("item not found\n");
		return head;
	}
	prev=cur->llink;
	next=cur->rlink;
	prev->rlink=next;
	next->llink=prev;
	free(cur);
	return head;
}

void display(NODE head)
{
	NODE temp;
	if(head->rlink==head)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	printf("Contents of the circular doubly linked list\n");
	temp=head->rlink;
	while(temp!=head)
	{
		printf("%d\n",temp->info);
		temp=temp->rlink;
	}
}

void main()
{
	NODE head;
	int choice,item;
	clrscr();
	head=getnode();
	head->rlink=head;
	head->llink=head;
	for(;;)
	{
		printf("1:InsertFront\t 2:InsertLeftKey\n 3:DeleteKey\t 4:Display\t 5:Quit\n");
		printf("Enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				head=insertfront(item,head);
				break;
			case 2: printf("Enter the key element\n");
				scanf("%d",&item);
				head=insertleft(item,head);
				break;
			case 3: printf("Enter the item to be deleted\n");
				scanf("%d",&item);
				head=deleteitem(item,head);
				break;
			case 4: display(head);
				break;
			default: exit(0);
		}
	}
}