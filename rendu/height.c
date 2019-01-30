#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node **nodes;
    };
struct s_node *init(int val)
{
	struct s_node *root = malloc(sizeof(struct s_node));
	int i = 0;
	root->value = val;
	root->nodes = malloc(sizeof(struct s_node*)*100);
	while (i < 100)
	{
		root->nodes[i] = NULL;
		i++;
	}
	return(root);
}

struct s_node *add(struct s_node *root, int val)
{
	int i = 0;
	struct s_node *n = init(val);
	while (root->nodes[i] && i < 100)
	{
		i++;
	}
	root->nodes[i] = n;
	return(n);
}

int sterile(struct s_node *root)
{
	int i = 0;
	while(root->nodes[i])
	{
		i++;
	}
	return(i==0);
}

int height_tree(struct s_node *root)
{
	int i = 0;
	int max = 0;
	if (!root)
		return(0);
	if (sterile(root))
		return(0);
	while(root->nodes[i])
	{
		int h = height_tree(root->nodes[i]);
		if (max < h)
			max = h;
		i++;
	}
	return(max+1);
}


int main()
{
	struct s_node *root = init(94);
	struct s_node *n34 = add(root,34);
	struct s_node *n52 = add(root,52);
	struct s_node *n1 = add(n34,1);
	struct s_node *n99 = add(n34,99);
	struct s_node *n11 = add(n34,11);
	struct s_node *n13 = add(n99,13);

	int i = 0;
	printf("%d\n", root->value);
	while (root->nodes[i])
	{
		printf("%d\n", root->nodes[i]->value);
		i++;
	}
	printf("%d\n", height_tree(root));

	return(0);
}







