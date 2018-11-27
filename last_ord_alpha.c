#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int count_words(char *s)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			count++;
		}
		i++;
	}
	count++;
	return (count);
}

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}

int cmp_chr(char a, char b)
{
	a = to_lower(a);
	b = to_lower(b);
	if (a>b)
		return (1);
	if (a<b)
		return(-1);
	return(0);
}

int cmp(char *a, char *b)
{
	if (len(a) > len(b))
		return (1); 
	if (len(a) < len(b))
		return (0);
	
	int i = 0;
	while (a[i] && b[i])
	{
		if (cmp_chr(a[i],b[i])==1)
			return(1);
		if (cmp_chr(a[i],b[i])==-1)
			return 0;

		i++;
	}
	if (a[i]==0 && b[i] == 0)
		return (0);
	if (a[i] > 0)
		return(1);
	return(0);
}

char **ret_arr(char *s)
{
	int i = 0;
	int l = len(s);
	int c_words = count_words(s);
	char *copy = malloc(sizeof(char)*(l+1));
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	i = 0;
	int w = 0;
	char **res = malloc(sizeof(char*)*(c_words+1));
	res[0] = &copy[0];
	while (copy[i])
	{
		if (copy[i] == ' ' || copy[i] == '\t')
		{
			copy[i] = '\0';
			res[w+1] = &copy[i+1];
			w++;
		}
		i++;
	}
	res[c_words] = NULL;
	return (res);
}


void	sort(char **arr)
{
	int i = 1;
	int j = 0;

	while (arr[i])
	{
		j = i-1;
		while (j >= 0 && cmp(arr[j], arr[j+1]))
		{
			char *tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			j--;
		}
		i++;
	}
}

void arr_printer(char **arr)
{
	int i = 0;
	int old_len = len(arr[0]);
	int flag = 0;
	while (arr[i])
	{
		if (old_len != len(arr[i]))
		{
			old_len = len(arr[i]);
			write(1, "\n", 1);
			flag=0;
		}
		if(flag)
			write(1, " ", 1);
		printer(arr[i]);
		flag = 1;
		i++;
	}
}


int main (int ac, char **av)
{
	char **res = ret_arr(av[1]);
	
	sort(res);
	arr_printer(res);
	write(1, "\n", 1);
	return (0);

}
