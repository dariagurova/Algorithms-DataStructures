#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *s)
{
	int i = 0;
	while(*s++)
	{
		i++;
	}
	return(i);
}
char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A'+'a';
	return(c);
}

void	ft_swap(char **s1, char **s2)
{
	char **tmp;
	tmp = malloc(sizeof(char*));
	*tmp = *s1;
	*s1 = *s2;
	*s2 = *tmp;
	free(tmp);

}
int count_words(char *s)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			count++;
		i++;
	}
	if (s[i-1]!= ' ')
		count++;
	return(count);
}
char **string_to_words(char *s)
{
	int i =0;
	int index=0;
	int word_count = count_words(s);
	char **words = malloc(sizeof(char*)* (word_count+1));
	int start = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			words[index] = &(s[start]);
			s[i]=0;
			index++;
			start = i+1;
		}
		i++;
	}
	if (!(s[i-1] == ' ' || s[i-1] == '\t'))
		{
			words[index] = &(s[start]);
			index++;
		}
	words[index]=NULL;
	return(words);
}

int cmp_chr(char c1, char c2)
{
	c1 = to_lower(c1);
	c2 = to_lower(c2);
	return (c1-c2);
}
int cmp(char *s1, char *s2)
{
	int i = 0;
	
	int tmp;
	while (s1[i])
	{
		tmp = cmp_chr(s1[i],s2[i]);
		if (tmp)
			return(tmp);
		i++;
	}
	if (s2[i] != '\0')
		return(-1);
	return(0);

}

char **ft_sort(char **arr)
{
	int i = 1;
	int j = 0;
	while (arr[i]!=NULL)
	{
		j = i;
		while(j>0 && cmp(arr[j],arr[j-1]) == -1)
		{
			ft_swap(&(arr[j]), &(arr[j-1]));
			j--;
		}
		i++;
	}
	return(arr);
}

void print_ar(char **arr)
{
	int i = 0;
	int old = ft_strlen(arr[0]);
	while (arr[i] != NULL)
	{
		if (ft_strlen(arr[i]) != old)
			printf("\n");
		printf("%s ", arr[i]);
		old = ft_strlen(arr[i]);
		i++;
	}
	printf("\n");
}
int main (int ac, char** av)
{
	 if (ac == 2)
	 {
	 	char **arr=string_to_words(av[1]);
	 	arr = ft_sort(arr);
	 	print_ar(arr);

	 }


	return(0);
}
