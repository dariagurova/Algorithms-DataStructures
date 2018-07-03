#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

typedef struct s_node s_node;

s_node *init(int val)
{
	s_node *root;
	root = malloc(sizeof(s_node));
	root->value=val;
	root->left = NULL;
	root->right = NULL;
	return(root);
}

s_node *addleft(s_node *parent, int val)
{
	s_node *tmp = init(val);
	parent->left = tmp;
	return(tmp);
}

s_node *addright(s_node *parent, int val)
{
	s_node *tmp = init(val);
	parent->right = tmp;
	return(tmp);
}

void	printer(s_node *root, int level)
{
	if (!root)
		return;
	printf("Current val: %d level: %d\n", root->value,level);
	if(root->left)
	{
		printf("left child \n");
		printer(root->left, level+1);
	}
	if(root->right)
	{
		printf("left child \n");
		printer(root->right,level+1);
	}
	printf("LEVEL UP \n");
}

int count(s_node *root)
{
	int l=0;
	int r=0;
	if (!root)
		return (0);
	if (root->left)
	{
		l = count(root->left);
	}
	if (root->right)
	{
		r = count(root->right);
	}
	return (l+r+1);
}

int can_split_helper(s_node *root,int size,int *flag)
{
	int l=0;
	int r=0;
	if (!root)
		return (0);
	if (root->left)
	{
		l = count(root->left);
		if (size==l*2)
		{
			*flag = 1;
		}
	}
	if (root->right)
	{
		r = count(root->right);
		if (size==r*2)
		{
			*flag=1;
		}
	}
	return (l+r+1);

}

int can_split(struct s_node *n)
{
	int flag = 0;
	int size = count(n);
	if (size%2!=0)
		return(0);
	can_split_helper(n, size, &flag);
	return(flag);

}

int main ()
{
	s_node *root = init(27);
	s_node *n1 = addleft(root, 3);
	s_node *n2 = addright(root, 5);
	s_node *n3 = addleft(n2, 4);
	s_node *n4 = addright(n2, 9);
	s_node *n5 =  addright(n4, 7);
	s_node *n6 = addleft(n3, 23);
	s_node *n7 = addright(n3, 56);

	printf("%d\n", can_split(root));
	//printer(root, 0);
	return (0);
}