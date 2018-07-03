#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return(i);
}

int is_start(char *s, char *start)
{
	int i = 0;
	if (ft_strlen(s) < ft_strlen(start))
		return(0);
	while (i < ft_strlen(start))
		{
			if (s[i] != start[i])
				return(0);
			i++;
		}
	return (1);

}

int is_sub(char *s, char *sub)
{
	if (ft_strlen(s) < ft_strlen(sub))
		return (0);
	int i = 0;
	while (i < ft_strlen(s))
	{
		if (is_start(s+i, sub))
			return(1);
		i++;
	}
	return(0);
}

int in_list(char *sub, char **av, int ac)
{
	int i = 0;
	while (i < ac)
	{
		if (!is_sub(av[i], sub))
			return(0);
		i++;
	}
	return(1);
}

char *sub(char *start, int len)
{
	char *sub;
	sub = malloc(sizeof(char)*(len+1));
	int i = 0;
	while (i < len)
	{
		sub[i] = start[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);

}

void	print(char **av, int ac)
{
	char *s=av[0];
	int len = ft_strlen(s);
	int i = len;

	while (i > 0)
	{
		int j = 0;
		while (j < len-i+1)
		{
			char *tmp = sub(s+j, i);
			if (in_list(tmp, av+1, ac-1))
			{
				printf("Found: %s\n", tmp);
				free(tmp);
				return;
			}
			j++;
			free(tmp);

		}
		i--;
	}

}
int main (int ac, char **av)
{
	print(av+1, ac-1);
	return (0);
}