#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

typedef struct s_node node;

node *initN(int val)
{
	node *root = malloc(sizeof(node));
	root->value = val;
	root->left = NULL;
	root->right =NULL;
	return (root);
}

node *add_r(node *root, int val)
{
	node *r = initN(val);
	root->right = r;
	return (r);
}

node *add_l(node *root, int val)
{
	node *l = initN(val);
	root->left = l;
	return (l);
}

void printer(node *root)
{
	if(!root)
		return;
	printf("value-> %d\n", root->value);
	if (root->left)
	{
		printf("left ");
		printer(root->left);
	}
	else
		printf("right is empty\n");
	if (root->right)
	{
		printf("right ");
		printer(root->right);
	}
	else
		printf("right is empty\n");
}

int height(node *root)
{

	if(root && !root->left && !root->right)
		return(1);
	int l = 0;
	int r = 0;
	if (root->left)
	{
		l = height(root->left);
	}
	if (root->right)
	{
		r = height(root->right);
	}
	if (l>r)
		return(l+1);
	return(r+1);
}

int width(node *root, int *max)
{

	if(root && !root->left && !root->right)
		return(1);
	int l = 0;
	int r = 0;
	if (root->left)
	{
		l = width(root->left,max);
	}
	if (root->right)
	{
		r = width(root->right,max);
	}
	if (*max<(l+r+1))
		*max = l+r+1;
	if (l>r)
		return(l+1);
	return(r+1);
}

int width_tree(node *n)
{
	int max = 0;
	width(n, &max);
	return(max);
}

int main ()
{
	node *root = initN(1);
	node *n1 = add_l(root, 2);
	node *n2 = add_r(root, 5);
	node *n3 = add_l(n1, 3);
	node *n4 = add_r(n1, 4);
	node *n5 = add_l(n4, 6);
	node *n6 = add_l(n2, 7);
	node *n7 = add_r(n2, 8);
	//printer(root);
	printf("%d\n", width_tree(root));
	return (0);

}
















