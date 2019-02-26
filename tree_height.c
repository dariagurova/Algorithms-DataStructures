#include <stdio.h>
#include <stdlib.h>
struct s_node {
	int           value;
    struct s_node **nodes;
};

typedef struct s_node s_node;

s_node *init(int val)
{
	int i = 0;
	s_node *tree;
	tree=malloc(sizeof(s_node));
	tree->nodes=malloc(sizeof(s_node*)*100);
	while (i < 100)
	{
		tree->nodes[i] = NULL;
		i++;
	}
	tree->value=val;
	return(tree);
}

s_node	*add(int val, s_node *tree)
{
	s_node *new;
	int i = 0;
	new = init(val);
	while (tree->nodes[i] && i<100)
		{
			i++;
		}
	tree->nodes[i]=new;
	return (new);
}


int childless(s_node *tree)
{
	int i = 0;
	while (tree->nodes[i] && i<100)
	{
		i++;
	}
	return(i==0);
}
int height_tree(struct s_node *root)
{
	int max=0;
	int i = 0;

	if(childless(root))
	{
		return(0);
	}
	while (root->nodes[i] && i<100)
	{
		int h = height_tree(root->nodes[i],level+1);
		if (h>max)
		{
			max=h;	
		}
		i++;
	}
		
	return (max+1);

}

int main ()
{
	s_node *root;
	root = init(87);
	
	s_node *t1=add(34,root);
	add(1, t1);

	s_node *t2 = add(99, t1);
	add(11, t1);
	add(13, t2);


	add(52,root);
	int h=height_tree(root,0);
	printf("heigth is %d\n", h);
	return(0);

}
