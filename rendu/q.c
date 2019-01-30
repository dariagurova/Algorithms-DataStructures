#include <unistd.h>
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

void	printer(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1,&s[i],1);
		i++;
	}
}

char to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		return(c - 'A' + 'a');
	return(c);
}

int count_words(char *s)
{
	int count = 0;
	int i = 0;
	while (s[i])
	{
		if(s[i] == ' ' || s[i] == '\t')
			count++;
		i++;
	}
	count++;
	return(count);
}

int cmp_chr(char a, char b)
{
	if (a>b)
		return(1);
	if (b>a)
		return(-1);
	return(0);
}

int cmp(char *s1, char *s2)
{
	int l1 = len(s1);
	int l2 = len(s2);
	if (l1 > l2)
		return(1);
	if (l2 > l1)
		return(0);
	int i = 0;
	while(s1[i] && s2[i])
	{
		if (cmp_chr(s1[i], s2[i])==1)
			return(1);
		if (cmp_chr(s1[i], s2[i])==-1)
			return(0);
		i++;
	}
	if (s1[i]==0 && s2[i]==0)
		return(0);
	if (s1[i] > 0)
		return(1);
	return(0);
}

char **to_array(char *s)
{
	int words = count_words(s);
	int i = 0;
	
}

































