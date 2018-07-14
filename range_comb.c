#include <stdio.h>
#include <stdlib.h>

int is_in(char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return(1);
		i++;
	}
	return(0);
}

void	rec_print(char *s, int n, int i)
{
	int flag = 0;
	int c = 0;
	int j = 0;
	if (i==n)
	{
		printf("{");
		while (s[j])
		{
			if (flag)
				printf(", ");
			printf("%c", s[j]);
			flag=1;
			j++;
		}
		//printf("}");

		return;
	}


	char x = 0;
	while(x < n)
	{
		if(!is_in(s, x+'0'))
		{
			s[i] = x + '0';
			s[i+1] = '\0';
			rec_print(s, n, i+1);
		}
		x++;
	}
	s[i] = '\0';

}

int main ()
{	
	int n = 3;
	char *s = malloc(sizeof(char)*4*n);
	int i = 0;
	while(i < n*4)
	{
		s[i] = '\0';
		i++;
	}
	printf("{");
	rec_print(s, n, 0);
	printf("}\n");

	return(0);
}