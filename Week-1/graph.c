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
	NODE* arr[n];
	int a[n][n];

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			a[i][j]=0;
		}
		NODE* temp=(NODE*) malloc(sizeof(NODE));
		temp->elem=i+1;
		temp->next=NULL;
		arr[i]=temp;
	}

	printf("Enter number of edges:\n");
	scanf("%d", &e);

	printf("Enter edge pairs\n");
	for(i=0; i<e; i++)
	{
		int ar[2];
		for(j=0; j<2; j++)
		{
			scanf("%d", &ar[j]);
		}
		a[ar[0]-1][ar[1]-1]=1;

		NODE* temp1=(NODE*) malloc(sizeof(NODE));
		temp1->elem=ar[1];
		temp1->next=NULL;

		int pos1=ar[0]-1;
		NODE *p;
		p=(arr[pos1]);
		while(p->next!=NULL)
			p=p->next;
		p->next=temp1;

		NODE* temp2=(NODE*) malloc(sizeof(NODE));
		temp2->elem=ar[0];
		temp2->next=NULL;

		int pos2=ar[1]-1;
		p=(arr[pos2]);
		while(p->next!=NULL)
			p=p->next;
		p->next=temp2;

	}
	printf("Adjacency Matrix\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("Adjacency List\n");
	for(i=0; i<n; i++)
	{
		printf("%d", ((arr[i]))->elem);
		NODE *p=(arr[i])->next;
		while(p!=NULL)
		{
			printf("->%d", p->elem);
			p=p->next;
		}
		printf("\n");
	}
	printf("\n");
	
}
