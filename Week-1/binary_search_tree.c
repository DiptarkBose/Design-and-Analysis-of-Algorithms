#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
	int elem;
	struct bst *left;
	struct bst *right;
}BST;

BST* addNode(int elem, BST *root)
{
	BST* temp= (BST*) malloc(sizeof(BST));
	temp->elem=elem;
	temp->left=NULL;
	temp->right=NULL;

	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		if(root->elem>elem)
			root->left=addNode(elem, root->left);
		else 
			root->right=addNode(elem, root->right);
	}
	return(root);
}

int search(BST *root, int elem)
{
	if(root!=NULL)
	{
		if(root->elem>elem)
			return search(root->left, elem);
		else if(root->elem<elem)
			return search(root->right, elem);
		else if(root->elem==elem)
		{
			printf("Found");
			return 1;
		}
		return 0;
	}
}
void inorder(BST *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d", root->elem);
		inorder(root->right);
	}
}
void preorder(BST *root)
{
	if(root!=NULL)
	{
		printf("%d", root->elem);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(BST *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->elem);
	}
}

int main()
{
	int ch, elem;
	BST* root=NULL;
	do
	{
		printf("\n1. Add Node\n2. Inorder\n3. Search\n4. Quit\n");
		scanf("%d", &ch);
		if(ch==1)
		{
			printf("Enter Element\n");
			scanf("%d", &elem);
			root= addNode(elem, root);
		}
		else if(ch==2)
		{
			printf("Inorder\n");
			inorder(root);
			printf("\nPreorder\n");
			preorder(root);
			printf("\nPostorder\n");
			postorder(root);
		}
		if(ch==3)
		{
			printf("Enter Element\n");
			scanf("%d", &elem);
			int m= search(root, elem);
			if(m==0)
				root=addNode(elem, root);
		}
	}while(ch!=4);
}