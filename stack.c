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
	struct s_stack *s;
	s = malloc(sizeof(struct s_stack));
	s->top = NULL;
	return(s);
}

struct s_node *initNode(void* val)
{
	struct s_node *new;
	new =  malloc(sizeof(struct s_node));
	new->next = NULL;
	new->content = val;
	return(new);
}

struct s_node *add(struct s_node *head, void* val)
{
	struct s_node *tmp = initNode(val);
	tmp->next = head;
	return(tmp);
}

void push(struct s_stack *stack, void *content)
{
	if (!stack || !content)
		return;
	struct s_node *head = stack->top;
	stack->top=add(head,content); 
}

int isEmpty(struct s_stack *stack)
{
	if(!stack || !stack->top)
		return(1);
	return(0);
}


void *pop(struct s_stack *stack)
{
	struct s_node *tmp;
	if(!stack)
		return(NULL);
	tmp=stack->top;
	if (!tmp)
		return(NULL);
	stack->top = tmp->next;
	void *val = tmp->content;
	free(tmp);
	return(val);
}

void *peek(struct s_stack *stack)
{
	if (isEmpty(stack))
		return(NULL);
	return(stack->top->content);
}


int main ()
{

	int a = 5;
	int b = 6;

	s_stack *s = init();
	push(s, (void*)&a);
	push(s, (void*)&b);
	void* c = pop(s);
	if (c)
		printf("%d\n", *((int*)c));

	c = pop(s);
	if (c)   printf("%d\n", *((int*)c));
	c = pop(s);
	if (c)   printf("%d\n", *((int*)c));
	return (0);

}




















