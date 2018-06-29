#include <stdlib.h>
#include <stdio.h>

struct s_node
{
        int           value;
        struct s_node **nodes;
};

typedef struct s_node s_node;

s_node*	init(int i)
{
	s_node *tmp;

	tmp = malloc(sizeof(s_node));
	tmp->value = i;
	tmp->nodes = malloc(sizeof(s_node)*1000);

	int n=999;
	while(n>=0)
	{
		(tmp->nodes)[n]=NULL;
		n--;
	}

	return (tmp);
}


void free_node(s_node * tmp)
{
	
	int n=999;
	while(n>=0)
	{
		if (!(tmp->nodes)[n])
			free_node((tmp->nodes)[n]);
		n--;
	}
	free(tmp->nodes);
	free(tmp);
	return;
}


s_node* add(s_node* parent, int j)
{

s_node *t;

int i=0;
t = (parent->nodes)[i];
while(t)
{
	i++;
	t=(parent->nodes)[i];
}
t=init(j);
(parent->nodes)[i]=t;
return (t);

}

void	print(s_node *parent)
{
	int p_value=parent->value;

	printf("PARENT VALUE:%d\n", p_value);
	int i=0;
	s_node* t;
	t = (parent->nodes)[i];
	while(t)
	{
		int ch_value;
		ch_value=t->value;

		printf("ch value = %d\n",ch_value);
		i++;
		t=(parent->nodes)[i];
	}
}

int height(s_node *tree, int l)
{
	printf("height l=%d\n",l);

	int i = 0;
	int max=0;
	int p_value=tree->value;
	printf("p_value =%d\n",p_value);

	s_node* kid;
	kid = (tree->nodes)[i];
	if (!kid)
		return 0;
	while(kid)
	{
		int kid_value=kid->value;
	printf("kid_value =%d\n",kid_value);

		int h=height(kid,l+1);
		printf("h =%d max=%d\n",h,max);

		if (h>max)
			{
				max=h;
				printf("new max= %d\n",max );
			}
		i++;
		kid=(tree->nodes)[i];
	}
	printf("ready to exit value=%d\n",max+1);
	return(max+1);

}
int main ()
{
	s_node * head;
	head = init(94);
	s_node *baby;
	s_node *baby2;
	s_node *baby3;
	baby = add(head, 34);
	baby2 = add(head, 52);
	s_node *baby1;
	baby1 = add(baby, 11);
	baby3 = add(baby, 99);
	baby1 = add(baby, 1);
	add(baby3,13);
	
	
	int h = height(head,0);
	printf("%d\n", h);
	
	//free_node(head);
	return (0);
}