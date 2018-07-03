#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	fill(t_point p, t_point size, char **tab);

int legit(t_point p, t_point size, char **tab)
{
	if (p.x < 0 || p.y < 0)
		return (0);
	if (p.x >= size.x || p.y >= size.y)
		return (0);
	if (tab[p.y][p.x*2] != '0')
		return (0);
	return(1);
}

void	paint(t_point p, char **tab)
{
	tab[p.y][p.x*2] = 'F';
}

int left(t_point p, t_point size, char **tab)
{
	t_point p_={p.x-1,p.y};
	if (legit(p_, size, tab) == 1)
	{
		fill(p_,size,tab);
		return(1);
	}
	return(0);
}

int right(t_point p, t_point size, char **tab)
{
	t_point p_={p.x+1,p.y};
	if (legit(p_, size, tab) == 1)
	{
		fill(p_,size,tab);
		return(1);
	}
	return(0);
}

int up(t_point p, t_point size, char **tab)
{
	t_point p_={p.x,p.y+1};
	if (legit(p_, size, tab) == 1)
	{
		fill(p_,size,tab);
		return(1);
	}
	return(0);
}

int down(t_point p, t_point size, char **tab)
{
	t_point p_={p.x,p.y-1};
	if (legit(p_, size, tab) == 1)
	{
		fill(p_,size,tab);
		return(1);
	}
	return(0);
}

void	fill(t_point p, t_point size, char **tab)
{
	if(!legit(p, size, tab))
		return;
	paint(p,tab);
	left(p, size, tab);
	right(p, size, tab);
	up(p, size, tab);
	down(p, size, tab);

}


void	printer(char **area, t_point size)
{

	int leny = size.y;
	int i=0;
	while (i< leny)
	{
		int j = 0;
		printf("%s\n",area[i]);
		i++;
	}
}
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return(i);
}
int main(int ac, char** av)
{
	char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 1 0 0 0 1",
         ,
    };

    area=av+1;
    size.y=ac-1;
    size.x=(ft_strlen(area[0])+1)/2; 

    //printf("%d\n", legit(begin, size,area));
    printer(area,size);
    fill(begin,size,area);
    printf("************************\n");
    printer(area,size);
    return (0);

}