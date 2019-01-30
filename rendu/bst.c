#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };

struct s_node *init(int val)
{
	struct s_node *root = malloc(sizeof(struct s_node));
	root->value = val;
	root->left = NULL;
	root->right = NULL;
	return(root);
}

struct s_node *l(struct s_node *root, int val)
{
	struct s_node *n = init(val);
	root->left = n;
	return(n);
}

struct s_node *r(struct s_node *root, int val)
{
	struct s_node *n = init(val);
	root->right = n;
	return(n);
}

int isLeaf(struct s_node *root)
{
	if (!root->left && root->right)
		return(1);
	return(0);
}

struct s_node *parent(struct s_node *root)
{
	if (!root)
		return(NULL);
	if (!root->left)
		return(NULL);
	if (!root->left->left)
		return(root);
	return(parent(root->left));
}

struct s_node *convert_bst(struct s_node *root)
{
	if (!root)
		return(NULL);
	struct s_node *res = NULL;
	while (!isLeaf(root))
	{
		struct s_node *small;
		struct s_node *pre = parent(root);
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

	struct s_node *tmp = res;
	while (tmp->left)
	{
		struct s_node *l = tmp->left;
		l->right = tmp;

		tmp = tmp->left;
	}
	tmp->left = res;
	res->right = tmp;

	return(res);

}

void	print(struct s_node *root)
{
	struct s_node *start = root;
	printf("%d\n",start->value);
	root = root->right;

	while(root != start)
	{
		printf("%d\n", root->value);
		root = root->right;
	}
}


// #include <stdio.h>
// #include <stdlib.h>

// struct s_node {
// 		int           value;
// 		struct s_node *right;
// 		struct s_node *left;
// 	};

// typedef struct s_node tree;

// tree *init(int val)
// {
// 	tree *n = malloc(sizeof(tree));
// 	n->value = val;
// 	n->right = NULL;
// 	n->left = NULL;
// 	return(n);
// }

// tree *l(tree *root, int val)
// {
// 	tree *n = init(val);
// 	root->left = n;
// 	return(n);
// }

// tree *r(tree *root, int val)
// {
// 	tree *n = init(val);
// 	root->right = n;
// 	return(n);
// }

// int isLeaf(tree *root)
// {
// 	if (!root->left && !root->right)
// 		return(1);
// 	return(0);
// }

// tree *descen(tree *root)
// {
// 	if (!root)
// 		return(NULL);
// 	if (!root->left)
// 		return(NULL);
// 	if (!root->left->left)
// 		return(root);
// 	return(descen(root->left));
// }

// tree *convert_bst(tree *root)
// {
// 	if (!root)
// 		return(NULL);
// 	tree *res = NULL;
// 	while (!isLeaf(root))
// 	{
// 		tree *small;
// 		tree *pre = descen(root);
// 		if (pre)
// 		{
// 			small = pre->left;
// 			pre->left = small->right;
// 		}
// 		else
// 		{
// 			small = root;
// 			root = root->right;
// 		}
// 		small->left = res;
// 		res = small;
// 		small->right = NULL;
// 	}

// 	root->left = res;
// 	res = root;


// 	tree *tmp = res;
// 	while (tmp->left)
// 	{
// 		tree *l = tmp->left;
// 		l->right = tmp;
// 		tmp = tmp->left;
// 	}

// 	tmp->left = res;
// 	res->right = tmp;

// 	return(tmp);

// }

// void	print(tree *root)
// {
// 	tree *start = root;
// 	printf("%d\n",start->value);
// 	root = root->right;

// 	while(root != start)
// 	{
// 		printf("%d\n", root->value);
// 		root = root->right;
// 	}
// }


// int main()
// {
// 	tree *root = init(9);
// 	tree *n6 = l(root,6);
// 	tree *n11 = r(root,11);
// 	tree *n5 = l(n6,5);
// 	tree *n7 = r(n6,7);

// 	tree *n10 = l(n11,10);
// 	tree *n12 = r(n11,12);

// 	tree *res = convert_bst(root);

// 	print(res);

// 	return(0);

// }


int main()
{
	struct s_node *root = init(9);
	struct s_node *n6 = l(root,6);
	struct s_node *n11 = r(root,11);
	struct s_node *n5 = l(n6,5);
	struct s_node *n7 = r(n6,7);

	struct s_node *n10 = l(n11,10);
	struct s_node *n12 = r(n11,12);

	struct s_node *res = convert_bst(root);

	print(res);

	return(0);

}










