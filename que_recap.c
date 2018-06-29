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

s_queue* init(void)
{
	s_queue *queue;
	queue = malloc(sizeof(s_queue));
	queue->first=NULL;
	queue->last=NULL;
	return (queue);
}

s_node	*initNode(void *val)
{
	s_node *node;
	node = malloc(sizeof(s_node));
	node->content = val;
	node->next=NULL;
	return (node);
}

void	enqueue(s_queue *queue, void *content)
{
	s_node *toadd;
	toadd = initNode(content);
	if (!queue->last || !queue->first)
	{
		queue->last = toadd;
		queue->first = toadd;
		return;
	}
	s_node *tmp;
	tmp = queue->last;
	tmp->next=toadd;
	queue->last=toadd;
}

int isEmpty(s_queue *queue)
{
	if (!queue->first || !queue->last)
		return(1);
	return(0);
}
void *dequeue(s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	s_node *tmp;
	tmp = queue->first;
	queue->first=tmp->next;
	void *val = tmp->content;
	free(tmp);
	if(!queue->first)
		queue->last = NULL;
	return (val);

}

int main ()
{
	int i = 32, j=98, k=12;
	int tmp;
	void *store;
	s_queue *queue=init();
	enqueue(queue,(void*)&i);
	enqueue(queue,(void*)&j);
	store = dequeue(queue);
	printf("%d\n",(*(int*)store));
	return (0);

}