#include <stdio.h>

void	printer_helper(char *s, int start, int sub_len)
{
	s = s+start;
	while (sub_len > 0)
	{
		printf("%c", *s);
		s++;
		sub_len--;
	}
}

int len(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return(i);
}

int is_start(char *b, char *a, int start, int sub_len)
{
	a = a+start;
	while (*b && *a && sub_len>0)
	{
		if (*b != *a)
			return(0);
		b++;
		a++;
		sub_len--;

	}
	return (sub_len == 0);
}

int	 is_sub(char *b, char *a, int start, int sub_len)
{
	while(*b)
	{
		if (is_start(b, a, start, sub_len))
			return(1);
		b++;
	}
	return(0);
}

void	printer(char *a, char *b)
{
	
	int l = len(a);
	int i = l;
	while (i > 0)
	{
		int j = 0;
		while (j < l + 1 - i)
		{
	
			int flag = 0;
			flag=is_sub(b,a,j, i);
			if (flag)
			{
				printer_helper(a, j, i);
				printf("\n");
	
				return;
			}
			 
			j++;
		}
		i--;
	}
}

int main ()
{
	char *a = "unicorn";
	char *b = "sdcordasd";
	printer(a,b);
	return (0);
}