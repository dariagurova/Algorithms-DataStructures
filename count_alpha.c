#include <stdio.h>
#include <stdlib.h>

void	to_lower(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
}

int *histo(char *s)
{
	int i = 0;
	int j = 0;
	int ind = 0;
	int *tab;
	tab = malloc(sizeof(int)*26);
	while (i<=26)
	{
		tab[i] = 0;
		i++;
	}
	while (s[j])
	{
		ind = s[j]-'a';
		if (s[j] >= 'a' && s[j] <= 'z')
			tab[ind]++;
		j++;
	}
	return (tab);

}

void	printer(int *tab)
{
	int j = 0;
	int flag = 0;
	while (j < 26)
	{
		if (tab[j])
		{
			if (flag)
			{
				printf(", ");
			}
			flag = 1;
			printf("%d%c", tab[j], j + 'a');

		}

		j++;
	}
}
int main (int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		char* s = av[1];
		to_lower(s);
		int * h=histo(s);
		printer(h);

	}
	return(0);
}