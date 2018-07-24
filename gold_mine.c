#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a>b)
		return(a);
	return(b);
}

int get_max(int *line, int row, int n)
{
	if (row==0)
		return(max(line[row], line[row+1]));
	if (row==n-1)
		return(max(line[row], line[row-1]));
	return(max(max(line[row],line[row-1]), line[row+1]));
}
int *init_l(int n)
{
	int i = 0;
	int *l = malloc(sizeof(int)*n);
	while (i < n)
	{
		l[i] = 0;
		i++;
	}
	return(l);
}

void copy_l(int *l, int *new_l, int n)
{
	int i = 0;
	while (i < n)
	{
		l[i] = new_l[i];
		i++;
	}
}

void	printer(int *l, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d \n", l[i]);
		i++;
	}
}

int gold_gain(int **mine, int n)
{
	int *l = init_l(n);
	int i = 0;
	while (i < n)
	{
		int tmp = mine[i][n-1];
		l[i] = tmp;
		i++;
	}
	int j = n-2;
	while (j > - 1)
	{
		
		
		int *new_l = init_l(n);
		int k = 0;
		while (k < n)
		{
			int g_m=get_max(l, k, n);
			
			new_l[k] = mine[k][j] + g_m;
			
			k++;
		}
		copy_l(l, new_l, n);
		
		
		j--;
	}
	
	i = 0;
	int max_ = l[0];
	while(i < n)
	{
		if (l[i] > max_)
			max_ = l[i];
		i++;
	}
	return(max_);
}


int main ()
{
	int mein[4][4]= {
		{1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};

	int **m;
	int n=4;
	int i=0;
	m=malloc(sizeof(int*)*n);
	while (i<n)
	{
		int j=0;
		m[i]=malloc(sizeof(int)*n);
		while(j<n)
		{
			m[i][j]=mein[i][j];
			j++;
		}
		i++;
	}

	
	int res = gold_gain(m, n);
	printf("%d\n", res);
	
	return (0);
}