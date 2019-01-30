#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void printer(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i],1);
		i++;
	}
	write(1,"\n",1);
}

int len(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return(i);
}

int start(char *sub, char *str)
{
	if (len(sub) > len(str))
		return(0);
	int i = 0;
	while(sub[i])
	{
		if(sub[i] != str[i])
			return(0);
		i++;
	}
	return(1);
}

int substr(char *sub, char *str)
{
	if (len(sub) > len(str))
		return(0);
	int i = 0;
	while(str[i])
	{
		if(start(sub, str+i))
			return(1);
		i++;
	}
	return(0);
}

int in_list(char *sub, char **list, int ac)
{
	int i = 0;
	while (i < ac)
	{
		if(!substr(sub,list[i]))
			return(0);
		i++;
	}
	return(1);
}

char *make(char *sub, int len)
{
	char *res = malloc(sizeof(char)*(len+1));
	int i = 0;
	while(i < len)
	{
		res[i] = sub[i];
		i++;
	}
	res[i] = '\0';
	return(res);
}

char	*maxlen(char **av, int ac)
{
	char *first = av[0];
	char **list = av+1;

	int l = len(first);
	int i = l;
	char *tmp = "";
	while(i > 0)
	{
		
		int s = 0;
		while(s < l-i+1)
		{
			tmp = make(first+s, i);
			
			if (in_list(tmp, list, ac-2))
			{
				printer(tmp);
				return (tmp);
			}
			s++;
		}
		i--;
	}
	return(tmp);
}


int main(int ac, char **av)
{
	if (ac >1)
		maxlen(av+1, ac);
	printf("\n");
	return(0);
}
