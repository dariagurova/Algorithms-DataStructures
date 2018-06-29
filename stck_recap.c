#include <stdlib.h>
#include <stdio.h>
struct s_node {
        void          *content;
        struct s_node *next;
    };
struct s_stack {
        struct s_node *top;
    };

typedef struct s_stack s_stack; 
typedef struct s_node s_node;

s_stack	*init()
{
	s_stack *new;
	new=malloc(sizeof(s_stack));
	new->top=NULL;
	return (new);
}

void	push(s_stack *stack, void* item)
{
	s_node *node;
	node = malloc(sizeof(s_node));
	node->content = item;
	node->next=stack->top;
	stack->top=node;
}

void	*pop(s_stack *stack)
{
	s_node *tmp;
	void* val;
	tmp=malloc(sizeof(s_node));
	if (!stack || !stack->top)
	{
		printf("Error:stack");
		exit(0);
	}
	tmp = stack->top;
	val = tmp->content;
	stack->top = tmp->next;
	free(tmp);
	return(val);
}

void *peek(s_stack *stack)
{
	if (!stack || !stack->top)
		printf("Error:stack top" );
		return (NULL);
	return (stack->top->content);
}
int isEmpty(s_stack *stack)
{
	if (!stack->top)
		return(1);
	return(0);

}


int main ()
{
	s_stack *st;
	st=init();

	void *tmp;
	int i = 543;
	tmp = (void*)(&i);
	push(st, tmp);


	void* tmp1;
	int j=655;
	tmp1 = (void*)(&j);
	push(st,tmp1);

	void* pop1;
	pop1 = pop(st);
	printf("%d\n", (*(int*)pop1) );
}