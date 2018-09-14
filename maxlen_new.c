#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int stratsWith(char *substr, char *string)
{
	if (len(substr) > len(string))
		return (0);
	int i = 0;
	while (i < len(substr))
	{
		if(string[i] != substr[i])
			return(0);
		i++;
	}
	return(1);
}


int subDetect(char *substr, char *string)
{
	if (len(substr) > len(string))
		return (0);
	int i = 0;
	while (i < len(string))
	{
		if (stratsWith(substr, string+i))
			return(1);
		i++;
	}
	return (0);
}

int in_the_list(char *substr, char **list, int list_count)
{
	int i = 0;
	while (i < list_count)
	{
		if (!subDetect(substr, list[i]))
			return(0);
		i++;
	}
	return (1);

}

char *aloc(char *start, int l)
{
	char *res = malloc(sizeof(char)*(l+1));
	int i = 0;
	while (i < l)
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	return(res);
}

void	print(char **av, int ac)
{
	char *s = av[0];
	int l = len(s);
	int sublen = l;

	while (sublen > 0)
	{
		int j = 0;
		while (j < l - sublen + 1)
		{
			char *tmp = aloc(s+j, sublen);
			if (in_the_list(tmp, av+1, ac-1)){
				printf("%s\n", tmp);
				free(tmp);
				return;
			}
			j++;
			free(tmp);
		}
		sublen--;
	}
}

int main (int ac, char **av)
{
	char **s = av+1;
	print(s, ac-1);
	return (0);
}
