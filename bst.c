#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };

typedef struct s_node node;

node *init(int val)
{
	node *n = malloc(sizeof(node));
	n->value = val;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

node *add_l(node *root, int val)
{
	node *n = init(val);
	root->left = n;
	return (n);
}

node *add_r(node *root, int val)
{
	node *n = init(val);
	root->right = n;
	return (n);
}

void	printer(node *root, int level)
{
	printf("value: %d\n", root->value);
	if (root->left)
	{
		printf("left ->");
		printer(root->left, level+1);
	}
	else
		printf("left is empty\n");
	if (root->right)
	{
		printf("right ->");
		printer(root->right, level+1);
	}
	else
		printf("right is empty\n");
	printf("level up\n");

}

int is_leaf(node *root)
{
	if (!root->left && !root->right)
		return (1);
	return(0);
}

node *smallest(node *root)
{
	if (!root)
		return (NULL);
	if (!root->left)
		return (NULL);
	if (!root->left->left)
		return (root);
	return (smallest(root->left));
}

node *bst(node *root)
{
	node *depot = NULL;
	while (!is_leaf(root))
	{
		
		node* sm;
		node *p = smallest(root);
		if (p)
		{
			sm=p->left;
			p->left = sm->right;
		}
		else
		{
			sm = root;
			root = root->right;
		}
		sm->left = depot;
		depot = sm;
		sm->right = NULL;
	}
	root->left = depot;
	depot = root;

	node *tmp = depot;
	while (tmp->left)
	{
		node* l= tmp->left;
		l->right=tmp;

		tmp = tmp->left;
	}
	tmp->left=depot;
	depot->right = tmp;
	//printer(depot,0);
	return (depot);
}

void print(node *depot)
{
	node* start=depot;
	depot = depot->left;
	while (depot!=start)
	{
		printf("%d\n", depot->value);

		depot = depot->left;
	}
	//printf("%d\n", depot->value);
}




int main ()
{
	node *root = init(8);
	node *n3 = add_l(root,3);
	add_l(n3,1);
	node *n6 = add_r(n3,6);
	add_l(n6, 4);
	add_r(n6, 7);
	node *n10 = add_r(root,10);
	node *n14 = add_r(n10, 14);
	add_l(n14,13);

	node *sm = bst(root);
	print(sm);

	//printer(root, 0);
	return (0);
}


























