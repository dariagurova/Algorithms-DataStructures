#include <stdio.h>
#include <stdlib.h>
struct s_node {
    int value;
    struct s_node *next;
};
typedef struct s_node s_node;

s_node *init(int val)
{
	s_node *tmp;
	tmp = malloc(sizeof(s_node));
	tmp->value = val;
	tmp->next=NULL;
	return(tmp);
}

s_node *add_node(s_node *parent, int val)
{
	if(parent)
	{
		s_node *new = init(val);
		parent->next = new;
		return (new);
	}
	return (NULL);
}

void	printer(s_node *list)
{
	while (list)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

int is_looping(struct s_node *list)
{
	s_node *trash;
	trash = malloc(sizeof(s_node));
	s_node *tmp;
	while(list && list != trash)
	{
		tmp = list;
		list = list->next;
		tmp->next = trash;
	}
	if (list == trash)
		return(1);
	return(0);

}

int main ()
{
	s_node *head = init(25);
	s_node *tail;
	tail = add_node(head,32);
	tail = add_node(tail,42);
	tail = add_node(tail,87);
	tail->next = head;
	//printer(head);
	printf("%d\n", is_looping(head));

	return (0);
}