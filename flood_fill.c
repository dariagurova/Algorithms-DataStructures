#include "flood_fill.h"
#include <string.h>
#include <stdio.h>


void  flood_fill_helper(char **tab, t_point size, t_point begin, char sym);
void  flood_fill(char **tab, t_point size, t_point begin);

int	is_good(char **tab, t_point size, t_point p,char sym)
{
	if (p.x < 0 || p.y < 0)
		return (0);
	if (p.x >= size.x || p.y >= size.y)
		return (0);
	if (tab[p.y][p.x*2] != sym)
		return (0);
	return (1);
}

void	putF(char **tab, t_point p)
{
	tab[p.y][p.x*2] = 'F';
}

int left(char **tab, t_point size, t_point p, char sym)
{
	t_point p_ = {p.x-1, p.y};

	if (is_good(tab, size, p_,sym) == 1)
	{
		flood_fill_helper(tab, size, p_, sym);
		return (1);
	}
	return (0);
}

int right(char **tab, t_point size, t_point p, char sym)
{
    t_point p_ = {p.x+1, p.y};
    if (is_good(tab, size, p_, sym) == 1)
    {
        flood_fill_helper(tab, size, p_, sym);
        return (1);
    }
    return (0);
}

int up(char **tab, t_point size, t_point p, char sym)
{
    t_point p_ = {p.x, p.y+1};
    if (is_good(tab, size, p_, sym) == 1)
    {
        flood_fill_helper(tab, size, p_, sym);
        return (1);
    }
    return (0);
}

int down(char **tab, t_point size, t_point p, char sym)
{
    t_point p_ = {p.x, p.y-1};
    if (is_good(tab, size, p_, sym) == 1)
    {
        flood_fill_helper(tab, size, p_, sym);
        return (1);
    }
    return (0);
}

void  flood_fill_helper(char **tab, t_point size, t_point begin, char sym)
{
	if (!is_good(tab, size, begin, sym))
		return;
	putF(tab, begin);
	left(tab, size, begin, sym);
	right(tab, size, begin, sym);
	up(tab, size, begin, sym);
	down(tab, size, begin, sym);	
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
	char sym=tab[begin.y][begin.x*2];
	flood_fill_helper(tab, size, begin, sym);
}

void	printer(char **av)
{
	int i = 0;
	while(av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
}
int	main(int ac, char **av)
{
	char **s = av+1;
	t_point size;
	t_point begin={0,0};
	size.x = (strlen(s[0])+1)/2;
	size.y = ac-1;

	printer(s);
	flood_fill(s, size, begin);
	printer(s);
	return (0);


}













