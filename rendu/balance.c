#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int len(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return(i);
}

int **make2d(int n)
{
	int **res = malloc(sizeof(int*)*(n));
	int i = 0;
	while (i < n)
	{
		res[i] = malloc(sizeof(int)*3);
		int j = 0;
		while (j <= 2)
		{
			res[i][j] = -1;
			j++;
		}
		i++;
	}
	res[i] = NULL;
	return(res);
}

int max_pair(int **arr, int *num_line, int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if(arr[i][1] != -1)
		{
			int diff = arr[i][1] - arr[i][0];
			if(diff > max)
			{
				max = diff;
				*num_line = i;
			}
		}
	}
	return(max);

}

void	print(char *s, int len)
{
	int i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	engine(char *s)
{
	int l = strlen(s);
	int **pos = make2d(l);

	int **neg = make2d(l);
	int balance = 0;
	for(int i = 0; i < l; i++)
	{
		if ((s[i] % 2) == 1)
			balance++;
		else
			balance--;
		if (balance > 0)
		{
			if(pos[balance][0] != -1)
				pos[balance][1] = i;
			else
				pos[balance][0] = i;
		}
		else
			if(neg[balance][0] != -1)
				neg[balance][1] = i;
			else
				neg[balance][0] = i;
	}

	int num_lineP=0;
	int num_lineN = 0;
	int n = max_pair(neg, &num_lineN, l);
	int p = max_pair(pos, &num_lineP, l);
	// printf("line=%d:n=%d: p=%d\n",num_lineP,n,p );
	if (p > n)
		print(s+pos[num_lineP][0], p);
}



int main()
{
	char *av = "1357913579024680213579";

	engine(av);
	return(0);
}





























