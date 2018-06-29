#include <stdlib.h>
#include <stdio.h>

	struct s_node {
		void          *content;
		struct s_node *next;
	};

	struct s_stack {
		struct s_node *top;
	};

struct s_stack *init(void)
{
	struct s_stack *st;
	st = malloc(sizeof(struct s_stack));
	st->top = NULL;
	return (st);
}


void	push(struct s_stack *stack, void *content)
{
	if (!stack)
		return;
	struct s_node *new;

	new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

int isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

void *peek(struct s_stack *stack)
{
	if(!stack->top)
		return (NULL);
	return(stack->top->content);
}

void *pop(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	struct s_node *tmp;
	void* item;
	tmp = stack->top;
	item = tmp->content;
	stack->top = tmp->next;
//	if (!stack->top)
//		return (NULL);
	free(tmp);
	return (item);

}
 int main ()
 {
 	struct s_stack *st;
 	st = init();

 	int i = 87;
 	int j = 23;

 	push(st, (void*)(&i));
 	push(st, (void*)(&j));

 	void* pop1 = pop(st);
 	printf("%d\n", (*(int*)pop1));
 	pop1 = pop(st);
 	printf("%d\n", (*(int*)pop1));
 	return (0);
 }