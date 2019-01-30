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
	while(root)
	{
		printf("%d:", root->data);
		if (root->other)
		{
			printf("other->%d\n", root->other->data);
		}
		else
			printf("other->NULL\n");
		root = root->next;
	}
}

node *clone(node *lst)
{
	node *copy = init(lst->data);
	node *head = copy;
	node *l1 = lst->next;
	while (l1)
	{
		add(copy, l1->data);
		l1 = l1->next;
	}
	return(head);
}

int idx(node *lst, node *elem)
{
	if (!elem)
		return(0);
	int i = 0;
	while(lst)
	{
		if (lst == elem)
			return(i);
		i++;
		lst = lst->next;
	}
	return(-1);
}

node *refer(node *lst, int i)
{
	if (i == -1)
		return(NULL);
	
	while (lst && i > 0)
	{
		lst = lst->next;
		i--;
	}
	return(lst);
}

void connect(node *lst, node *elem, int i)
{
	elem->other = refer(lst, i);
}

node *clone_list(struct s_node *l)
{
	node *l1 = l;
	node *l2 = clone(l);
	node *rootl1 = l;
	node *rootl2 = l2;
	while (l1 && l2)
	{
		int i = idx(rootl1,l1-other);
		connect(rootl2, l2, i);


		l1 = l1->next;
		l2 = l2->next;
	}
	return(rootl2);
}

int main()
{
	node *root = init(0);
	node *n1 = add(root,1);
	node *n2 = add(root,2);
	node *n3 = add(root,3);
	node *n4 = add(root,4);
	connect(root, n1, 2);

	node *copy = clone(root);
	printer(copy);
	printf("****************\n");
	// printer(copy);
	return(0);

}













