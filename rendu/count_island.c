#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define LIM 100000
void	fill(char **grid, int line, int row, int h, int w, char replace);
void	printer(char **grid)
{
	int i = 0;
	while(grid[i])
	{
		int j = 0;
		while(grid[i][j])
		{
			write(1,&grid[i][j],1);
			j++;
		}
		write(1, "\n", 1);
		
		i++;
	}
	
}

char **makeGrid()
{
	char **res = malloc(sizeof(char *)*1000);
	int i = 0;
	while(i < LIM)
	{
		res[i] = NULL;
		i++;
	}
	return(res);
}

int	errors(char *buf, int size, int w, int h)
{
	if (size/h != w)
	{
		printf("width chaeck fail\n");
		return(1);
	}
	int i = 0;
	while(i < size)
	{
		if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n' && buf[i] != '\0')
		{
			printf("char check\n");
			return (1);
		}
		i++;
	}
	return(0);
}

char**	copyBuf(char *buf, int size)
{
	int i = 0;
	int ln_num = 0;
	char **grid = makeGrid();
	grid[0] = buf;
	while(i < size)
	{
		if(buf[i] == '\n')
		{
			buf[i] = '\0';
			grid[ln_num+1] = &buf[i+1];
			ln_num++;
		}
		i++;
	}
	return(grid);
}

void	flood(char **grid, int line, int row, int h, int w, char replace)
{
	if(line > 0 && row > 0 && line < h && row < w)
	{
		if(grid[row][line] == 'X')
		{
			grid[row][line] = replace;
			fill(grid,line,row, h, w, replace);
		}	
	}
}

void	fill(char **grid, int line, int row, int h, int w, char replace)
{
	flood(grid, line+1, row, h, w, replace);
	flood(grid, line-1, row, h, w, replace);
	flood(grid, line, row+1, h, w, replace);
	flood(grid, line, row-1, h, w, replace);
}

void	startFill(char **grid, int h, int w)
{
	int i = 0;
	char replace = '0';
	while(i < h)
	{
		int j = 0;
		while(j < w)
		{
			char c = grid[i][j];
			if(c == 'X')
			{
				flood(grid, i, j, h, w, replace);
				replace++;
			}
			j++;
		}
		i++;
	}
	printer(grid);
}

void	count_isl(char *file)
{
	char *buf = malloc(sizeof(char)*LIM);
	int fd = open(file, O_RDONLY);
	int size = read(fd,buf,LIM);

	if (size < 0)
	{
		printf("read bytes fail\n");
		write(1, "/n", 1);
		return;
	}
	size++;
	int width = 1;
	for(int i = 0; buf[i] != '\n'; i++)
		width++;
	
	int height = size/width;
	
	printf("size-->%d height-->%d  width-->%d\n", size, height, width);

	if(errors(buf, size, width, height))
	{
		write(1, "/n",1);
		return;
	}
	
	char **grid = copyBuf(buf,size);
	startFill(grid, height, width);
	printer(grid);

	
}

int main(int ac, char **av)
{
	
	if (ac == 2)
	{
		count_isl(av[1]);
	}
	
	return(0);

}


























