#include <stdio.h>

void	count_alpha(char *s)
{
	int tab[26];
	int order[26];
	int j = 0;
	while (j<26)
	{
		tab[j] = 0;
		order[j]=26;
		j++;
	}

	j = 0;
	int counter=0;
	while (s[j])
	{
		if (s[j] >= 'a' && s[j] <= 'z')
		{
			int idx = s[j] - 'a';
			if(tab[idx]==0)
			{
				order[idx]=counter;
				counter++;
			}
			tab[idx]++;
		}
		if (s[j] >= 'A' && s[j] <= 'Z')
		{
			int idx = s[j] - 'A';
			if(tab[idx]==0)
			{
				order[idx]=counter;
				counter++;
			}
			tab[idx]++;
		}
		j++;
	}
	int flag = 1;
	j = 0;
	int i = 0;
	while (i < 26)
	{
		j=0;
		while (j < 26)
		{
			if (tab[j] != 0 && order[j] == i)
				{
					if (!flag)
						printf(", ");
					printf("%d%c", tab[j], j + 'a');
					flag=0;

				}
			j++;
		}
		i++;
	}
	printf("\n");
}

int main (int ac, char **av)
{
	if (ac > 1)
	{
		count_alpha(av[1]);
	}
	return (0);
}