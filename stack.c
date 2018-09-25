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

s_stack *init(void)
{
	s_stack *s;
	s = malloc(sizeof(s_stack));
	s->top = NULL;
	return(s);
}

s_node *initNode(void* val)
{
	s_node *new;
	new =  malloc(sizeof(s_node));
	new->next = NULL;
	new->content = val;
	return(new);
}

s_node *add(s_node *head, void* val)
{
	s_node *tmp = initNode(val);
	tmp->next = head;
	return(tmp);
}

void push(s_stack *stack, void *content)
{
	if (!stack)
		return;
	s_node *head = stack->top;
	stack->top=add(head,content); 
}

int isEmpty(s_stack *stack)
{
	if(!stack || !stack->top)
		return(1);
	return(0);
}


void *pop(struct s_stack *stack)
{
	s_node *tmp;
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

void *peek(s_stack *stack)
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




















