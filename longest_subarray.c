#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_even(char *s, int start, int sub_len)
{
	char *sub = s+start;
	int counter = 0;
	int i = 0;
	while (i < sub_len)
	{
		if (sub[i] % 2 == 0)
			counter += 1;
		else
			counter -= 1;
		i++;
	}
	return(counter == 0);
}

char *allocate(char *s, int start, int sub_len)
{
	int i = 0;
	char *res;
	char *substr = s+start;
	res = malloc(sizeof(char)*(sub_len+1));
	while (i < sub_len)
	{
		res[i] = substr[i];
		i++;
	}
	res[i] = '\0';
	return(res);
}
char    *longest_subarray(char *arr)
{
	char *res;
	int l = strlen(arr);
	int sub_len = l;
	while (sub_len > 0)
	{
		int j = 0;
		while (j < l-sub_len + 1)
		{
			if (is_even(arr, j, sub_len))
			{
				res = allocate(arr, j, sub_len);
				return (res);
			}
			j++;
		}
		sub_len--;
	}
	return(res);
}

int main ()
{
	char *s = "134";
	printf("%s\n", longest_subarray(s));
	return (0);
}












