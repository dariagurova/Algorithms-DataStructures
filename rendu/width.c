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

int width(struct s_node *root, int *res)
{
	if (root && !root->left && !root->right)
		return(1);
	int l = 0;
	int r = 0;
	if (root->left)
		l = width(root->left, res);
	if (root->right)
		r = width(root->right, res);
	if (*res < l+r+1)
		*res = l+r+1;
	if (l>r)
		return(l+1);
	return(r+1);
}


int	util(struct s_node *root, int *res)
{
	if (root && !root->left && root->right)
		return(1);
	int l = 0;
	int r = 0;
	if (root->left)
		l = util(root->left, res);
	if (root->right)
		r = util(root->right,res);
	if (*res < l+r+1)
		*res = l+r+1;
	if (l > r)
		return(l+1);
	return(r+1);
}

int width_tree(struct s_node *n)
{
	int res = 0;
	util(n, &res);
	return(res);
}



// int	width_tree(struct s_node *n)
// {
// 	int res = 0;
// 	width(n, &res);
// 	return(res);

// }

int main()
{
	struct s_node *root = init(1);
	struct s_node *n2 = l(root,2);
	r(root,3);
	struct s_node *n4 = l(n2,5);
	struct s_node *n7 = r(n2,7);

	struct s_node *n5 = l(n4,5);
	struct s_node *n6 = r(n4,6);
	struct s_node *n8 = r(n5,8);

	struct s_node *n9 = l(n7,9);
	struct s_node *n10 = r(n7,10);

	l(n9,5);
	r(n9,6);
	r(n10,13);

	printf("%d\n", width_tree(root));
	

	return(0);
}