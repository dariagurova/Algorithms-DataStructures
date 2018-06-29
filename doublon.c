#include <stdio.h>
void print_doublon(int *a, int na, int *b, int nb) {

	int i = 0;
	int j = 0;
	int start = 1;
	while (i < na && j < nb) 
	{

		if (a[i] == b[j]) 
		{
			if (start) 
			{
				start = 0;
				printf("%d", a[i]);
			} 
			else 
			{
				printf(" %d", a[i]);
			}
			i++;
			j++;
		}
		else
		{
			if (a[i] > b[j])
				j++;
			else
				i++;
		}
	}
	printf("\n");
}

int main ()
{
	int a[] = {2, 3, 5, 8};
	int b[] = {3, 8, 10};
	print_doublon(a,4,b,3);
	return (0);

}