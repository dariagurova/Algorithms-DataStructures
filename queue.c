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
	struct s_queue *q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return(q);
}

struct s_node *initnode(void* val)
{
	struct s_node *n = malloc(sizeof(struct s_node));
	n->content = val;
	n->next = NULL;
	return(n);
}

void enqueue(struct s_queue *queue, void *content)
{
	if (!queue)
		queue = init();
	struct s_node *n = initnode(content);
	if (!queue->first || !queue->last)
	{
		queue->first = n;
		queue->last = n;
	}

	struct s_node *tmp;
	tmp = queue->last;
	tmp->next = n;
	queue->last = n;
}

void *dequeue(struct s_queue *queue)
{
	if (!queue->first)
		return(NULL);
	void *data;

	struct s_node *tmp;
	tmp = queue->first;
	data = tmp->content;
	queue->first = tmp->next;
	if (!queue->first)
		queue->last = NULL;
	
	free(tmp);
	return(data);

}

int isEmpty(struct s_queue *queue)
{
	if (!queue->first || !queue->last)
		return(1);
	return(0);
}

void *peek(struct s_queue *queue)
{
	if (isEmpty(queue))
		return(NULL);
	return(queue->first->content);
}












