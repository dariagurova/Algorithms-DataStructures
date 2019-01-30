#include <stdio.h>
#include <stdlib.h>

long int permut(int n)
{
	long int res = 1;
	int i = 1;
	while(i < n)
	{
		res *= i;
		i++;
	}
	return(res);
}

int isIn(int *tab, int el)
{
	int i = 0;
	while(tab[i] != -1)
	{
		if (tab[i] == el)
			return(1);
		i++;
	}
	return(0);
}

int *make1d(int n)
{
	int *res = malloc(sizeof(int)*(n+1));
	int i = 0;
	while(i <= n)
	{
		res[i] = -1;
		i++;
	}
	return(res);
}

int **make2d(long int p)
{
	int **res = malloc(sizeof(int*)*(p+1));
	int i = 0;
	while (i <= p)
	{
		res[i] = NULL;
		i++;
	}
	return(res);
}

int *clone(int *tab,int n)
{
	int i = 0;
	int *cl = make1d(n);
	while (tab[i] != -1)
	{
		cl[i] = tab[i];
		i++;
	}
	return(cl);
}

void	addToList(int *arr, int **list,int n)
{
	while(*list)
	{
		list++;
	}
	*list = clone(arr,n);
	return;
}

void	helper(int *arr, int **list, int n, int i)
{
	if (i == n)
	{
		addToList(arr,list,n);
		return;
	}

	int x = 0;
	while(x < n)
	{
		if (!isIn(arr, x))
		{
			arr[i] = x;
			helper(arr,list,n,i+1);
			
		}
		x++;

	}
	arr[i] = -1;
	return;
}


int    **range_comb(int n)
{
	int *arr = make1d(n);
	long int p = permut(n);
	int **list = make2d(p);
	helper(arr,list,n,0);
	return(list);

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

int main()
{

	int **res = range_comb(3);
	printer_2d(res);
	
	return(0);
}









