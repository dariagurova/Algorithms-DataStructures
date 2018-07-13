#include <stdio.h>
#include <stdlib.h>

void	printer(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
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

char **str_to_words(char *s)
{
	int l = len(s);
	char *copy;
	copy = malloc(sizeof(char)*(l+1));
	int i = 0;
	int word_count = 0;
	while (s[i])
	{
		copy[i] = s[i];
		if (s[i] == ' ' || s[i] == '\t')
		{
			word_count++;
		}
		i++;
	}
	copy[i] = '\0';
	word_count++;


	char **arr;
	arr = malloc(sizeof(char*)*(word_count+1));
	i = 0;
	int word = 0;
	arr[word] = &(copy[0]);
	while (copy[i])
	{
		if (copy[i] == ' ' || copy[i] == '\t')
		{
			copy[i] = '\0';
			arr[word+1]= &(copy[i+1]);
			word++;
		}
		i++;
	}
	arr[word_count] = NULL;
	return (arr);
}

char tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return(c);
}

int cmp_(char a, char b)
{
	a = tolower(a);
	b = tolower(b);
	return (a>b);

}


int cmp(char *a, char *b)
{
	int i = 0;
	while (a[i] && b[i])
	{
		if (cmp_(a[i], b[i]))
			return(1);
		i++;
	}
	return(a[i]>0);
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
			char *tmp;
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			j--;
		}
		i++;
	}
	i = 0;
	int old_len=len(arr[0]);
	while (arr[i])
	{
		
		if (len(arr[i])!=old_len)
			printf("\n");
		printf("%s ", arr[i]);
		old_len=len(arr[i]);
		i++;
	}
	printf("\n");
}



int main ()
{
	
	char **arr=str_to_words("A a b B cc ca cd");
	sort(arr);
	

	return(0);
}