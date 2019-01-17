#include <stdio.h>
#include <stdlib.h>

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

typedef struct s_node tree;

tree *init(int val)
{
	tree *n = malloc(sizeof(tree));
	n->value = val;
	n->right = NULL;
	n->left = NULL;
	return(n);
}

tree *addL(tree *root, int val)
{
	tree *n = init(val);
	root->left = n;
	return(n);
}

tree *addR(tree *root, int val)
{
	tree *n = init(val);
	root->right = n;
	return(n);
}

int isLeaf(tree *root)
{
	if (!root->left && !root->right)
		return(1);
	return(0);
}

tree *descen(tree *root)
{
	if (!root)
		return(NULL);
	if (!root->left)
		return(NULL);
	if (!root->left->left)
		return(root);
	return(descen(root->left));
}

tree *convert_bst(tree *root)
{
	if (!root)
		return(NULL);
	tree *res = NULL;
	while (!isLeaf(root))
	{
		tree *small;
		tree *pre = descen(root);
		if (pre)
		{
			small = pre->left;
			pre->left = small->right;
		}
		else
		{
			small = root;
			root = root->right;
		}
		small->left = res;
		res = small;
		small->right = NULL;
	}

	root->left = res;
	res = root;


	tree *tmp = res;
	while (tmp->left)
	{
		tree *l = tmp->left;
		l->right = tmp;
		tmp = tmp->left;
	}

	tmp->left = res;
	res->right = tmp;

	return(tmp);

}

void	print(tree *root)
{
	tree *start = root;
	printf("%d\n",start->value);
	root = root->right;

	while(root != start)
	{
		printf("%d\n", root->value);
		root = root->right;
	}
}

int main ()
{
	tree *root = init(8);
	tree *n3 = addL(root,3);
	addL(n3,1);
	tree *n6 = addR(n3,6);
	addL(n6, 4);
	addR(n6, 7);
	tree *n10 = addR(root,10);
	tree *n14 = addR(n10, 14);
	addL(n14,13);

	tree *sm = convert_bst(root);
	print(sm);

	return (0);
}





















