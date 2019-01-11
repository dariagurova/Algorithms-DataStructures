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
	s_node *new;
	new = malloc(sizeof(s_node));
	new->content = val;
	new->next = NULL;
	return (new);
}

s_node	*add(s_node *list, void *val)
{

	if (!list)
		return(NULL);
	s_node *tmp;
	tmp = initNode(val);
	while (list->next)
	{
		list = list->next;
	}
	list->next = tmp;
	return(tmp);
}

void enqueue(s_queue *queue, void *content)
{
	s_node *ad;
	if (!queue)
		queue = init();
	if (!queue->first || !queue->last)
	{	
		ad = initNode(content);
		queue->first = ad;
		queue->last = ad;

	} 
	else
	{
		ad = add(queue->last,content);
		queue->last = ad;
	}
}

int isEmpty(s_queue *queue)
{
	if (!queue)
		return (1);

	return(!queue->last);

}
void *peek(s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	return(queue->first->content);

}
void *dequeue(s_queue *queue)
{
	void *val;
	s_node *tmp;
	if (!queue || !queue->first)
		return (NULL);
	tmp = queue->first;
	queue->first = tmp->next;
	if (!queue->first)
		queue->last = NULL;
	val = tmp->content;
	
	free(tmp);
	return (val);
}

int main ()
{
	s_queue *q = init();
	int f = 45;
	int k = 2;
	void *l;
	enqueue(q,(void*)&f);
	enqueue(q,(void*)&k);
	l = dequeue(q);
	printf("%d\n", *(int*)l);
	l = dequeue(q);
	printf("%d\n", *(int*)l);
	l = dequeue(q);
	printf("%d\n", *(int*)l);

	return(0);

}
