#include <stdlib.h>
#include <stdio.h>
struct s_node {
        void *content;
        struct s_node *next;
    };
    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };
typedef struct s_node s_node;
typedef struct s_queue s_queue;

s_queue *init(void)
{
	s_queue *q;
	q = malloc(sizeof(s_queue));
	q->first = NULL;
	q->last = NULL;
	return(q);
}

s_node *initNode(void* val)
{
	s_node	*new;
	new = malloc(sizeof(s_node));
	new->content = val;
	new->next = NULL;
	return(new);
}

s_node *add(s_node *head, void* val)
{
	if (!head)
	  return(initNode(val));

	while(head->next)
	{
		head = head->next;
	}
	head->next=initNode(val);
	return(head->next);
}

int isEmpty(s_queue *q)
{
	if(!q || !q->first)
		return(1);
	return(0);
}

void enqueue(s_queue *q, void *content)
{
	if (isEmpty(q))
	{
		s_node *node = initNode(content);
		q->first=node;
		q->last=node;
		return;
	}
	q->last=add(q->last,content);
	return;
}

void *dequeue(s_queue *q)
{
	void* val;
	s_node *tmp;
	if(isEmpty(q))
		return(NULL);
	tmp = q->first;
	q->first = tmp->next;
	val = tmp->content;
	if(isEmpty(q))
		q->last=NULL;
	free(tmp);
	return(val);
}

void *peek(s_queue *q)
{
	if (isEmpty(q))
		return(NULL);
	return(q->first->content);
}


int main ()
{
	s_queue *q = init();
	int a = 4;
	int b = 5;
	enqueue(q,(void*)&a);
	enqueue(q,(void*)&b);
	void* d = dequeue(q);
	if(d)
		printf("%d\n", *((int*)d));
	
	d = dequeue(q);
	if(d)
		printf("%d\n", *((int*)d));
	d = dequeue(q);
	if(d)
		printf("%d\n", *((int*)d));

	return(0);
}



















