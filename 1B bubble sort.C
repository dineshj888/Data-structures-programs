//bubble sort
#include<stdio.h>
#include<conio.h>
#define size 10
void bucket_sort(int n,int a[10]);
void main()
{
	int i,n,a[10];
	clrscr();
	printf("Enter the total number of elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bucket_sort(n,a);
	printf("The sorted elements are\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	getch();
}
void bucket_sort(int n,int a[10])
{
	int i,j,k,b[size];
	for(j=0;j<size;j++)
	{
		b[j]=0;
	}
	for(i=0;i<n;i++)
	{
		b[a[i]]++;
	}
	for(i=0,j=0;j<size;j++)
	{
		for(k=b[j];k>0;k--)
		{
			a[i]=j;
			i=i+1;
		}
	}
}