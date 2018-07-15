#include <stdio.h>
#include <string.h>

void	printer(char *s, int start, int sub_len)
{
	char *s_ = s+start;
	int l = 0;
	while (l < sub_len)
	{
		printf("%c", *s_);
		l++;
		s_++;
	}
	printf("\n");
}

int balance(char *s, int start, int sub_len)
{
	int counter = 0;
	int i = 0;
	char *s_ = s+start;
	while (i < sub_len)
	{
		if(s_[i] % 2 == 0)
			counter += 1;
		else
			counter -= 1;

		i++;
	}
	return(counter == 0);
}

void	balanced_substr(char *s)
{
	int l = strlen(s);
	int i = l;
	while (i > 0)
	{
		int j = 0;
		while (j < l-i+1)
		{
			
			if (balance(s, j, i))
			{
				printer(s, j, i);
				return;
			}

			
			j++;
		}
		i--;
	}

}


int main (int ac, char **av)
{
	(void)ac;
	balanced_substr(av[1]);
	return(0);
}