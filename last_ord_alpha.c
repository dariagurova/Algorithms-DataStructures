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

int	count_words(char *s)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			count++;
		i++;
	}
	count++;
	return (count);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return(c - 'A' + 'a');
	return(c);
}

int cmp_chr(char a, char b)
{
	a = to_lower(a);
	b = to_lower(b);
	return(a>b);
}
int cmp(char *a, char *b)
{
	int i = 0;
	while (a[i] && b[i])
	{
		if(cmp_chr(a[i],b[i]))
			return(1);

		i++;
	}
	return (a[i] > 0);
}


char	**make_arr(char *s)
{
	int l = len(s);
	int i = 0;
	char *copy = malloc(sizeof(char) * (l+1));
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';

	i = 0;
	int word = 0;
	int count = count_words(s);
	char **arr = malloc(sizeof(char*) * (count+1));
	arr[word] = &(copy[0]);
	while(copy[i])
	{
		if (copy[i] == ' ' || copy[i] == '\t')
		{
			copy[i] = '\0';
			arr[word+1] = &(copy[i+1]);
			word++;
		}
		i++;
	}
	arr[count] = NULL;
	return(arr);
}

void	sort(char **arr)
{
	int i = 1;
	int j = 0;

	while(arr[i])
	{
		j = i-1;
		while (j >= 0 && cmp(arr[j], arr[j+1]))
		{
			char *tmp;
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			j--;
		}
		i++;
	}

	int old_l = len(arr[0]);
	i = 0;
	int f = 0;
	while (arr[i])
	{
		if (len(arr[i]) != old_l)
		{
			write(1, "\n", 1);
			f=0;
		}

		if(f)
			write(1, " ", 1);
		printer(arr[i]);
		f = 1;
		
		old_l = len(arr[i]);
				
		i++;
	}
}
int main (int ac, char **av)
{
	
	char **arr = make_arr(av[1]);
	sort(arr);
	
	write(1, "\n", 1);
	return(0);
}



































