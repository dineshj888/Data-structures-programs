//sparse matrix
#include<stdio.h>
#include<conio.h>
#include<process.h>
typedef struct
{
	int row;
	int col;
	int val;
}term;
int k;
void read_sparse_matrix(term a[],int m,int n)
{
	int i,j,item;
	k=1;
	a[0].row=m;
	a[0].col=n;
	printf("Enter the Elements\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&item);
			if(item==0)
				continue;
			a[k].row=i;
			a[k].col=j;
			a[k].val=item;
			printf("Non zero element stored at location %d is %d\n",k,a[k].val);
			k++;
		}
	}
	a[0].val=k-1;
}
void print_sparse_matrix(term a[])
{
	int p;
	for(p=1;p<k;p++)
		printf("Row=%d\t Column=%d\t value=%d\n",a[p].row,a[p].col,a[p].val);
}
void search_sparse_matrix(term a[],int item)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(item==a[i].val)
		{
			printf("Search successful\n Element found at position %d\n",i);
			getch();
			exit(0);
		}
	}
	printf("Search Unsuccessful\n");
}
void main()
{
	int m,n,item;
	term a[10];
	clrscr();
	printf("Enter Number of rows and columns\n");
	scanf("%d%d",&m,&n);
	read_sparse_matrix(a,m,n);
	print_sparse_matrix(a);
	printf("Enter Element to be searched\n");
	scanf("%d",&item);
	search_sparse_matrix(a,item);
	getch();
}
