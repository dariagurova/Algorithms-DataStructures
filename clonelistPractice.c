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
	n->next=NULL;
	n->other=NULL;
	n->data=val;
	return(n);
}

node *add(node *list, int val)
{
	node *n = init(val);
	while(list->next)
	{
		list=list->next;
	}
	list->next=n;
	return(n);
}

void	printer(node *list)
{
	while(list)
	{
		printf("%d \n", list->data);
		if(!list->other)
			printf("other : NULL\n");
		else
			printf("other: %d\n", list->other->data);
		list = list->next;
	}
}

node *copy(node *list)
{
	node *copy = init(list->data);
	node *head = copy;
	node *l2 = list->next;
	while(l2)
	{
		copy = add(copy, l2->data);
		printf("copying list %d\n", l2->data);
		l2= l2->next;
	}
	return(head);
}

int idx(node *list, node *elem)
{
	int i = 0;
	if(!elem)
		return(0);
	while (list)
	{
		if (list == elem)
		{	return(i);
			printf("index found %d\n",i);
		}
		i++;
		list = list->next;
	}
	return(-1);
}

node *pointer(node *list, int i)
{
	if (i == -1)
		return(NULL);
	while (i >= 0)
	{
		list = list->next;
		i--;
	}
	return(list);
}

void	connect(node *list, node *elem, int i)
{
	elem->other=pointer(list, i);
}

node *clone_list(node *list)
{
	node *orig = list;
	node *clone = copy(list);
	
	node *head = clone;
	while (list && clone)
	{
		int i = idx(orig,list->other);
		connect(orig,clone,i);

		list=list->next;
		clone = clone->next;
	}
	return(clone);
}



int main()
{
	node *root = init(0);
	node *n1 = add(root,1);
	node *n2 = add(root,2);
	node *n3 = add(root,3);
	node *n4 = add(root,4);
    connect(root, n1, 2);
    connect(root, n2, 0);
    connect(root, n3, 1);
    connect(root, n4, 1);
	printer(root);
	printf("**************************************\n");
	//int i = index(root, NULL);
	
	node *new = clone_list(root);
	printf("**************************************\n");
	printer(new);

	return(0);

}
