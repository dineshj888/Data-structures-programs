//Towers of hanoi
#include<stdio.h>
#include<conio.h>
int count=0;
void tower(int n,char src,char temp,char des)
{
	if(n==1)
	{
		printf("Move dise %d from %c to %c\n",n,src,des);
		count=count+1;
		return;
	}
	tower(n-1,src,des,temp);
	printf("Move disc %d from %c to %c",n,src,des);
	count=count+1;
	tower(n-1,temp,src,des);
}
void main()
{
	int n;
	clrscr();
	printf("Enter the Number of Disc\n");
	scanf("%d",&n);
	tower(n,'s','T','D');
	printf("Total Number of moves: %d\n",count);
	getch();
}