#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };

typedef struct s_node s_node;

s_node *init(int val)
{
	s_node *root;
	root = malloc(sizeof(s_node));
	root->value = val;
	root->right = NULL;
	root->left = NULL;
	return(root);
}

s_node *addleft(s_node *root, int val)
{
	root->left = init(val);
	return(root->left);
}
s_node *addright(s_node *root, int val)
{
	root->right = init(val);
	return(root->right);
}

void	printer(s_node *root,int level)
{
	printf("value:%d  level : %d\n ", root->value, level);
	if (root->left){
		printf("left:\n");
		printer(root->left,level+1);
	}
	else
		printf("left is NULL\n");
	if(root->right){
		printf("right:\n");
		printer(root->right, level+1);
	}
	else
		printf("right is NULL\n");
 	printf("exit value:%d  level : %d\n",root->value, level);
}


void	swap(s_node *root)
{
	s_node *tmp;
	tmp = root->right;
	root->right = root->left;
	root->left = tmp;
}

void	reverse(s_node *root)
{
	if (!root)
		return;
	if (root->left)
	{
		reverse(root->left);
	}
	if (root->right)
	{
		reverse(root->right);
	}

swap(root);
}

int main ()
{
	s_node *root = init(94);
	s_node *l = addleft(root,34);
	s_node *r = addright(root,52);
	s_node *l1 = addleft(l,1);
	s_node *r1 = addright(l,99);
	s_node *l2 = addleft(l1,20);
	s_node *l3 = addleft(r1,83);
	s_node *r3 = addright(r1,39);
	s_node *r5 = addright(l3,61);
	s_node *l4 = addleft(r3,37);
	s_node *r4 = addright(r3,67);
	printer(root, 0);
	reverse(root);
	printf("******************");
	printer(root, 0);
	return (0);
}