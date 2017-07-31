#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int elem;
	struct node *next;
}NODE;

int main()
{
	int i, j, n, e;
	printf("Enter no. of vertices: \n");
	scanf("%d", &n);
	int a[n][n];

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			a[i][j]=0;
		}
	}

	printf("Enter number of edges:\n");
	scanf("%d", &e);

	printf("Enter edge pairs\n");
	for(i=0; i<e; i++)
	{
		int arr[2];
		for(j=0; j<2; j++)
		{
			scanf("%d", &arr[j]);
		}
		a[arr[0]-1][arr[1]-1]=1;
	}
	printf("\nAdjacency Matrix\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	NODE b[n];
	for(i=0; i<n; i++)
	{
		b[i].elem=i+1;
		printf("%d ", b[i].elem);
	}
	printf("\n");
}