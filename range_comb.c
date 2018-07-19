#include <stdio.h>
#include <stdlib.h>

long int perms(int n)
{
	int i = 1;
	long int res = 1;
	while (i <= n)
	{
		res = res * i;
		i++;
	}
	return (res);
}

int is_in(int el, int *l)
{
	int i = 0;
	while(l[i]!=-1)
	{
		if (l[i] == el)
			return (1);
		i++;
	}
	return (0);
}

int **init_ll(long int p)
{
	int **ll;
	ll = malloc(sizeof(int*) * (p + 1));
	int i = 0;
	while (i <= p)
	{
		ll[i] = NULL;
		i++;
	}
	return(ll);
}

int *init_l(int n)
{
	int *l;
	l = malloc(sizeof(int) * (n + 1));
	int i = 0;
	while (i <= n)
	{
		l[i] = -1;
		i++;
	}
	return(l);

}


int *clone(int *ar, int n)
{
	int *res =  init_l(n);
	int i = 0;
	while (i <= n)
	{
		res[i] = ar[i];
		i++;
	}
	return(res);
}

void add_l(int *l, int **l_l,int n)
{
	int i = 0;
	while (*l_l)
	{
		l_l++;
	}
	*l_l = clone(l, n);
	return;
}

void	printer(int *l)
{
	int i = 0;
	while (l[i] != -1)
	{
		printf("%d ", l[i]);
		i++;
	}
	
}


void _range_comb(int n, int *l, int **l_l, int i)
{
	if (n == i)
	{
		add_l( l,  l_l,n);
		printer(l);
		printf("\n");
		return;
	}
	int x = 0;
	while (x < n)
	{
		if(!is_in(x, l))
		{
			l[i] = x;
			_range_comb(n, l, l_l, i+1);
		}
		x++;

	}
	l[i] = - 1;
	return ;
}

void	printer_2d(int **ll)
{
	while(*ll)
	{
		printf("{");
		printer(*ll);
		printf("}, ");
		ll++;
	}
}

int    **range_comb(int n)
{
	long int perm = perms(n);
	int **res = init_ll(perm);
	int *l = init_l(n);
	_range_comb(n, l, res, 0);
	return(res);
}

int main ()
{
	int n = 9;
	int **res = range_comb(n);
	printer_2d(res);
	//printf("%d\n", perms(3));

	return(0);
}