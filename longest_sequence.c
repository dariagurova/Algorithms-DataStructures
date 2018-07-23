
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void longest_sequence_util(struct s_node *n, int currLength, int expected, int *res)
{
	if(!n)
		return;
	if (n->value == expected)
		currLength++;
	else
		currLength = 1;
	if (currLength > *res)
		*res = currLength;
	longest_sequence_util(n->left, currLength, n->value+1, res);
	longest_sequence_util(n->right, currLength, n->value+1, res);
	
}

int	longest_sequence(struct s_node *node)
{
	if(!node)
		return(0);
	int res = 0;
	longest_sequence_util(node, 0, node->value, &res);
	return(res);
}

