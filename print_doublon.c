#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int f = 0;

	while (i < na && j < nb)
	{
		if (a[i] > b[j])
			j++;
		else if (a[i] < b[j])
			i++;
		else
		{
			if (f)
				printf(" ");
			printf("%d",a[i]);
			f=1;
			i++;
			j++;
		}
	}
	printf("\n");
}

int main ()
{
	int a[] = {1,3,5,6,6};
	int b[] = {0,2,3,5,6,7,8};
	print_doublon(a, 5, b, 7);
	return (0);
}