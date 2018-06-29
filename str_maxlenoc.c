#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i =0;
	while (s[i])
		i++;
	return (i);
}

char *substr(char *start, int len)
{
	char *sub;
	int i = 0;
	sub = malloc(sizeof(char) * (len+1));
	while (i < len && start[i])
	{
		sub[i] = start[i];
		i++;
	}
	sub[i] = '\0';
	return(sub);
}

int	starts_with(char *s, char *sub)
{
	int i = 0;
	int len = ft_strlen(sub);
	if (ft_strlen(sub) > ft_strlen(s))
		return(0);
	while (i < len)
	{
		if(s[i] != sub[i])
			return(0);
		i++;
	}
return(1);
}

int	 is_in(char *s, char *sub)
{
	while(*s)
	{
		if(starts_with(s,sub))
		return (1);
		s++;
	}
	return (0);
}

int	is_in_multiple(char**args, int ac, char *sub)
{
	int i = 0;
	while(i < ac)
	{
		if(!(is_in(args[i], sub)))
			return (0);
		i++;
	}
	return(1);
}

char *find_sub(char *first, char **rest, int ac)
{
	int len = ft_strlen(first);
	int l = len;

	while (l>0)
	{
		int b = 0;
		while (b <= len-l)
		{
			char *tmp = substr(first+b, l);
			if(is_in_multiple(rest, ac, tmp))
			{
				printf("Found %s\n", tmp);
				return(tmp);
			}
			b++;
		}
		l--;
	}
	return("");
}

int main (int ac, char **av)
{
	if (ac > 2)
	{
		find_sub(av[1], &(av[2]),ac-2);
	}

	
	return (0);

}