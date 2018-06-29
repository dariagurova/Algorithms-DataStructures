#include <stdio.h>
#include <stdlib.h>

void	equation(int n)
{
	int a;
	int b;
	int c;
	a = 0;
	while (a<10)
	{
		b = 0;
		while (b<10)
		{
			c = 0;
			while (c<10)
			{
				if (((a*10+b) + (c*10+a)) == n)
					printf("A = %d, B = %d, C = %d\n", a,b,c);
				c++;
			}
			b++;
		}
		a++;
	}
}
int main (int ac, char **av)
{
	equation(atoi(av[1]));
	return (0);
}