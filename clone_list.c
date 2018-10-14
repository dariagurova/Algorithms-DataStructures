#include <stdio.h>
#include <stdlib.h>
struct s_node {
        int           data;
        struct s_node *next;
        struct s_node *other;
    };

typedef struct s_node node;

node *init(int val)
{
	node *n = malloc(sizeof(node));
	n->data = val;
	n->next = NULL;
	n->other = NULL;
	return (n);
}

node *add(node *head, int val)
{
	node *el = init(val);
	while (head->next)
	{
		head = head->next;
	}
	head->next = el;
	return (el);
}

void printer(node *root)
{

	while (root)
	{
		printf("next: %d  ", root->data);
		if (!root->other)
			printf("other: NULL\n");
		else
			printf("other: %d\n", root->other->data);
		root = root->next;
	}
}

node *clone(node *head)
{
	node *cloned = init(head->data);
	node *copyHead = cloned;
	node *l2 = head->next;
	while (l2)
	{
		add(cloned, l2->data);
		l2 = l2->next;
	}
	return (copyHead);
}

int index_(node *root, node *el)
{
	int i = 0;
	if (!el)
		return(0);
	while (root)
	{
		if (root == el)
			return (i);
		i++;
		root = root->next;
	}
	return (-1);
}

node *pointer(node *root, int idx)
{
	if (idx == -1)
		return(NULL);
	while (root && idx > 0)
	{
		root = root->next;
		idx--;
	}
	return (root);
}

void connect(node *head, node *el, int i)
{
	el->other = pointer(head,i);
}



node *clone_list(node *root)
{
	node *l1 = root;
	node *l2 = clone(root);
	node *l2root = l2;
	node *l1root = root;
	while (l1 && l2)
	{
		node *tmp = l1->other;
		int idx = index_(l1root, tmp);
		connect(l2root, l2, idx);

		l1 = l1->next;
		l2 = l2->next;
	}
	return(l2root);
}



int main ()
{
	node *root = init(0);
	node *n1 = add(root,1);
	node *n2 = add(root,2);
	node *n3 = add(root,3);
	node *n4 = add(root,4);
	connect(root, root, 1);
    connect(root, n1, 2);
    connect(root, n2, 0);
    connect(root, n3, 1);
    connect(root, n4, 3);
	printer(root);
	printf("**************************************\n");
	
	node *new = clone_list(root);
	printf("**************************************\n");
	printer(new);

	return(0);

}
