#include <stdlib.h>
#include <stdio.h>

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A'+'a';
	return(c);
}

/* void	ft_swap(int*s1, int*s2)
{
	int *tmp;
	tmp = malloc(sizeof(int));
	*tmp = *s1;
	*s1 = *s2;
	*s2 = *tmp;
	free(tmp);

}*/

void	ft_swap(char **s1, char **s2)
{
	char **tmp;
	tmp = malloc(sizeof(char*));
	*tmp = *s1;
	*s1 = *s2;
	*s2 = *tmp;
	free(tmp);

}
int main ()
{
	char *s1 = "dasha";
	char *s2 = "kasha";



	printf("%s %s\n",s1,s2);
	ft_swap(&s1,&s2);
	printf("%s %s\n",s1,s2 );

	return(0);
}