#include <stdio.h>
#include <stdlib.h>

void print1d(int *a, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d ", a[i]);
		i++;
	}
}

int maxInt(int a, int b)
{
	if (a > b)
		return(a);
	return(b);
}

int max(int *col, int row, int n)
{
	if (row == 0)
		return(maxInt(col[row], col[row+1]));
	if (row == n-1)
		return(maxInt(col[row], col[row-1]));
	return(maxInt(col[row-1], maxInt(col[row+1], col[row])));
}

int *make1d(int n)
{
	int *res = malloc(sizeof(int)*n);
	int i = 0;
	while(i < n)
	{
		res[i] = 0;
		i++;
	}
	return(res);
}

void	copy(int *orig, int *new, int n)
{
	int i = 0;
	while(i < n)
	{
		orig[i] = new[i];
		i++;
	}
}


int gold(int **mine, int n)
{
	int *orig = make1d(n);
	int i = 0;
	while (i < n)
	{
		orig[i] = mine[i][n-1];
		i++;
	}

	int j = n-2;
	while (j > -1)
	{
		int *new = make1d(n);
		int k = 0;
		while(k < n)
		{
			int m = max(orig,k,n);
			new[k] += m + mine[k][j];
			k++;
		}
		copy(orig,new,n);
		j--;
	}

	i = 0;
	int res = orig[0];
	while (i < n)
	{
		if (res < orig[i])
			res = orig[i];
		i++;
	}
	return (res);
}


int main()
{
	int n = 3;
	int m[3][3] = {
		{1, 2, 3},
		{3, 4, 8},
		{9, 6, 7}
	};

	int **mine = malloc(sizeof(int*) * n);
	int i = 0;
	while(i < n)
	{
		mine[i] = malloc(sizeof(int)*n);
		int j = 0;
		while(j < n)
		{
			mine[i][j] = m[i][j];
			j++;
		}
		i++;
	}

	i = 0;
	while(i < n)
	{
		print1d(mine[i], n);
		printf("\n");
		i++;
	}

	printf("****************\n");

	printf("%d\n", gold(mine,n));

	return(0);
}
















