#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int elem;
	struct node *next;
	struct node *prev;
}NODE;

NODE* addNode(int elem, NODE *list)
{
	NODE* temp= (NODE*) malloc (sizeof(NODE));
	temp->next=NULL;
	temp->prev=NULL;
	temp->elem=elem;
	NODE *p=list;
	if(list==NULL)
	{
		list=temp;
		return list;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		return list;
	}
}
void display(NODE *list)
{
	NODE *p=list;
	printf("Next Implemented\n");
	do
	{
		printf("%d ", p->elem);
		p=p->next;
	}while(p->next!=NULL);
	printf("%d ",p->elem);
	printf("\nPrevious Implemented\n");
	while(p!=NULL)
	{
		printf("%d ", p->elem);
		p=p->prev;
	}
}
int main()
{
	int ch, elem;
	NODE *root=NULL;
	/*do
	{
		printf("1. Add Elem\n2. Display\n3. Exit\n");
		scanf("%d", &ch);
		if(ch==1)
		{
			printf("Enter element:\n");
			scanf("%d", &elem);
			root=addNode(elem, root);
		}
		else if(ch==2)
			display(root);
	}while(ch!=3);*/
	root = addNode(1,root);
	root = addNode(2,root);
	root = addNode(3,root);
	display(root);
}