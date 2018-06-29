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
	if (tab[p.y][p.x] != '0')
		return (0);
	return(1);
}

void	paint(t_point p, char **tab)
{
	tab[p.y][p.x] = 'F';
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


/*void	printer(char **area, t_point size)
{

	int leny = size.y;
	int lenx=size.x;
	int i=0;
	
	while (i< leny)
	{
		int j = 0;
		while (j<lenx)
		{
			printf("%c ", area[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


}
char **make(char **zone, t_point size)
{
	int leny = size.y;
	int lenx=size.x;
	int i=0;
	char **res = malloc(sizeof(char*)*leny);
	while (i< leny)
	{
		char *tmp = zone[i];
		char *line = malloc(sizeof(char)*lenx);
		int j = 0;
		while (j<lenx)
		{
			line[j]=tmp[j*2];
			j++;
		}
		res[i]=line;
		i++;
	}
	return (res);

}*/

int main()
{
	char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 1 0 0 0 1",
        "1 1 1 0 0 0 0 1",
    };
    area = make(zone, size);
    //printf("%d\n", legit(begin, size,area));
    printer(area,size);
    fill(begin,size,area);
    printf("************************\n");
    printer(area,size);
    return (0);

}