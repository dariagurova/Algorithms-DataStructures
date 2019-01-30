#include <stdio.h>
#include <stdlib.h>

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
	int **res = malloc(sizeof(int*)*(n+1));
	int i = 0;
	while (i <= n)
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



int main()
{
	char *av = "1357913579024680213579";

	engine(av);
	return(0);
}





























