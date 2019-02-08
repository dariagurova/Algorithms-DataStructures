#include <stdlib.h>

struct s_node {
        void *content;
        struct s_node *next;
    };
    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };


struct s_queue *init(void)
{
	struct s_queue *q;
	q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return(q);
}

struct s_node *initNode(void* val)
{
	struct s_node *new;
	new = malloc(sizeof(struct s_node));
	new->content = val;
	new->next = NULL;
	return (new);
}


void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *ad = initNode(content);
	if (!queue)
		return;
	if(!content)
		return;
	if (!queue->first || !queue->last)
	{	
		
		queue->first = ad;
		queue->last = ad;
		return;

	}
	struct s_node *tmp = queue->last;
	queue->last = ad;
	tmp->next = ad;
	
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->last || !queue->first)
		return (1);

	return(!queue->last);

}
void *peek(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	return(queue->first->content);

}
void *dequeue(struct s_queue *queue)
{
	void *val;
	struct s_node *tmp;
	if (!queue || !queue->first || !queue->last)
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
