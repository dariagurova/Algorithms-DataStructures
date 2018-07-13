#include <stdio.h>
#include <stdlib.h>


  struct s_node {
        void *content;
        struct s_node *next;
    };
typedef struct s_node s_node;

s_node *init(void *val)
{
	s_node *n;
	n = malloc(sizeof(s_node));
	n->content = val;
	n->next = NULL;
	return(n);
}

s_node *add(s_node *list, void *val)
{
	s_node *n = init(val);
	if(!list)
		return(n);
	while(list->next)
	{
		list = list->next; 
	}
	list->next = n;
	return(n);
}


void print_node(s_node *list)
{
	if(list && list->content)
			{
				int v=*((int*)list->content);
				printf("%d\n", v);
			}
		else
			printf("node is empty\n");
}

void	printer(s_node *list)
{
	print_node(list);
	while (list)
	{
		list=list->next;
		print_node(list);
	}
}

void *intersection(s_node *l1, s_node *l2)
{
	while(l1)
	{
		s_node *node2=l2; 
	
		while(node2)
		{
			if (l1 == node2)
			{
				printf("intersect detected\n");
				return((void *)node2);
			}

			node2 = node2->next;
		}
		l1 = l1->next;
	}
	printf("intersect NOT detected\n");
	return(NULL);

}

int main()
{
	int a = 5;
	int b = 6;
	int c = 7;
	int d = 8;
	int e = 9;
	s_node *l1 = init((void*)&a);
	add(l1, (void*)&b);
	add(l1, (void*)&c);
	s_node *intrs = add(l1, (void*)&d);
	add(l1, (void*)&e);

	int j = 10;
	int k = 11;
	s_node *l2 = init((void*)&j);
	s_node *tail = add(l2, (void*)&k);

	//tail->next=intrs;
	intersection(l1,l2);
	return(0);
}