//Insertion sort
#include<stdio.h>
#include<conio.h>
void insertion(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while((temp<a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	printf("Elements after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void main()
{
	int a[30],n,k;
	clrscr();
	printf("Enter total no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(k=0;k<n;k++)
	{
		scanf("%d",&a[k]);
	}
	printf("Elements before sorting\n");
	for(k=0;k<n;k++)
	{
		printf("%d\n",a[k]);
	}
	insertion(a,n);
	getch();
}
