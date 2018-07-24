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
	n->right = NULL;
	n->left = NULL;
	return(n);
}

node *add_l(node *root, int val)
{
	node *l = init(val);
	return(root->left = l);
}

node *add_r(node *root, int val)
{
	node *r = init(val);
	return(root->right = r);
}

void printer(node *root, int level)
{
	printf("value: %d\n", root->value);
	if (root->left)
	{
		printf("left ");
		printer(root->left, level+1);
	}
	else
		printf("left is empty\n");
	if (root->right)
	{
		printf("right ");
		printer(root->right, level+1);
	}
	else
		printf("right is empty\n");
	printf("level up\n");
}

void	print_leaves(node *root)
{
	if(!root->left && !root->right)
	{
		//printf("this is a leaf \n");
		printf(" %d", root->value);
	}
	
	if (root->left)
	{
		print_leaves(root->left);
	}
	if (root->right)
	{
		print_leaves(root->right);
	}
}



void	print_l_b(node *root,int f)
{
	if (!root->left && !root->right)
		return;
	if (f)
	printf(" %d", root->value);
	
	if (root->left)
	{
		print_l_b(root->left,1);
	}
}

void	print_back(node *root, int flag)
{
	if (!root->left && !root->right)
		return;
	
	if (root->right)
		print_back(root->right, 1);
	if (flag==1)
		printf(" %d", root->value);
}

void	perimeter(struct s_node *root)
{
	printf("%d", root->value);
	print_l_b(root,0);
	print_leaves(root);
	print_back(root,0);
	printf("\n");
}

int main ()
{
	node *root = init(92);
	node *n85 = add_l(root, 85);
	node *n26 = add_r(root, 26);
	node *n79 = add_l(n85, 79);
	node *n10 = add_r(n79, 10);
	node *n39 = add_l(n10, 39);
	node *n35 = add_l(n39, 35);
	node *n96 = add_l(n35, 96);

	node *n64 = add_r(n26, 64);
	node *n40 = add_l(n64, 40);
	node *n88 = add_l(n40, 88);
	node *n12 = add_l(n88, 12);
	node *n55 = add_r(n88, 55);
	node *n58 = add_l(n12, 58);
	node *n58_ = add_l(n55, 58);
	node *n41 = add_r(n55, 41);


	node *n10_ = add_r(n40, 10);
	node *n52 = add_l(n10_, 52);
	node *n87 = add_r(n10_, 87);
	node *n22 = add_l(n52, 22);
	node *n35_ = add_r(n52, 35);
	node *n31 = add_r(n87, 31);

	node *n78 = add_r(n64, 78);
	node *n2 = add_l(n78, 2);
	node *n85_ = add_r(n78, 85);
	node *n51 = add_r(n85_, 51);
	node *n33 = add_l(n2, 33);
	node *n11 = add_r(n2, 11);
	node *n55_ = add_r(n33, 55);
	node *n99 = add_l(n11, 99);

	perimeter(root);
	return (0);
}






