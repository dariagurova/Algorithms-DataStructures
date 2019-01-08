#include <stdio.h>
#include <stdlib.h>


long int permut(int n)
{
	int i = 1;
	long int res = 1;
	while(i <= n)
	{
		res *= i;
		i++;
	}
	return(res);
}

int is_in(int *arr, int el)
{
	int i = 0;
	while(arr[i] != -1)
	{
		if (arr[i] == el)
			return(1);
		i++;
	}
	return(0);
}

int *make1d(int n)
{
	int *arr = malloc(sizeof(int)*n);
	int i = 0;
	while (i <= n)
	{
		arr[i] = -1;
		i++;
	}
	return(arr);
}

int **make2d(long p)
{
	int **res = malloc(sizeof(int*)*(p+1));
	int i = 0;
	while(i <= p)
	{
		res[i] = NULL;
		i++;
	}
	return(res);
}

int *clone(int *arr, int n)
{
	int *res = make1d(n);
	int i = 0;
	while(arr[i] != -1)
	{
		res[i] = arr[i];
		i++;
	}
	return(res);
}

void	addToList(int **list, int *toadd, int n)
{
	while(*list)
	{
		list++;
	}
	*list = clone(toadd,n);
	return;
}

void	printer(int *arr)
{
	int i = 0;
	while (arr[i] != -1)
	{
		printf("%d", arr[i]);
		i++;
	}
}

void util(int **arr2d, int *arr1d, int n, int i)
{
	if (i == n)
	{
		addToList(arr2d, arr1d,n);
		
		return;
	}

	int el = 0;
	while(el < n)
	{
		if(!is_in(arr1d,el))
		{
			arr1d[i] = el;
			util(arr2d, arr1d, n, i+1);
		}
		
		el++;
	}
	arr1d[i] = -1;
	return;

}

int    **range_comb(int n)
{
	int *arr = make1d(n);
	long int p = permut(n);
	int **res = make2d(p);
	util(res, arr,n,0);
	return(res);
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
	int n = 4;
	int **res = range_comb(n);
	int i = 0;
	long int p = permut(n);
	printer_2d(res);
	return(0);
}


























