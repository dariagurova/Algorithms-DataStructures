#include <stdlib.h>
#include <stdio.h>


struct s_node {
        int           data;
        struct s_node *next;
        struct s_node *other;
    };

typedef struct s_node t_node;

t_node *init(int val)

{
	t_node *n = malloc(sizeof(t_node));
	n->data = val;
	n->next = NULL;
	n->other = NULL;
	return (n);
}

t_node *add(t_node *root, int val)
{
	t_node *add_el = init(val);
	while (root->next)
	{
		root = root->next;
	}
	root->next = add_el;
	return(add_el);
}

void printer(t_node *root)
{

	while (root)
	{
		printf("%d  ", root->data);
		if (!root->other)
			printf("other: NULL\n");
		else
			printf("other: %d\n", root->other->data);
		root = root->next;
	}
}

t_node *clone(t_node *head)
{
	t_node *new = init(head->data);
	t_node *l1;
	t_node *l2;
	l1=new;
	l2=head->next;
	while (l2)
	{
		l1 = add(l1,l2->data);
		l2 = l2->next;
	} 
	return (new);
} 

t_node *pointer(t_node *head, int idx)
{

	if(idx == -1)
		return(NULL);
	while (head && idx >= 0)
	{
		head = head->next;
		idx--;
	}
	return (head);
}

int index_(t_node *head, t_node *elem)
{
	int idx = 0;
	if (!elem)
		return(-1);
	while (head)
	{

		if (head == elem)
			return (idx);
		idx++;
		head = head->next;
	}
	return (-1);
}

void connect(t_node *head, t_node *el, int to_other_idx)
{
	el->other = pointer(head, to_other_idx);
}

t_node *clone_list(t_node *node)
{
	t_node *l1 = node;
	t_node *l2 = clone(l1);
	t_node *l2head = l2;
	while (l1 && l2)
	{
		
		
		t_node *tmp = l1->other;
		int i = index_(node, tmp);
		
		l2->other=tmp;

		l1 = l1->next;
		l2 = l2->next;
	}
	return(l2head);
}

int main ()
{
	t_node *root = init(0);
	t_node *n1 = add(root,1);
	t_node *n2 = add(root,2);
	t_node *n3 = add(root,3);
	t_node *n4 = add(root,4);
    connect(root, n1, 2);
    connect(root, n2, 0);
    connect(root, n3, 1);
    connect(root, n4, 1);
	printer(root);
	printf("**************************************\n");
	int i = index_(root, NULL);
	
	t_node *new = clone_list(root);
	printf("**************************************\n");
	printer(new);

	return(0);

}
