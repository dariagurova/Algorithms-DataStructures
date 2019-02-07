#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define LIM 100000

void	printer(char **grid)
{
	int i = 0;
	while(grid[i])
	{
		int j = 0;
		while(grid[i][j])
		{
			write(1,&grid[i][j],1);
		}
		
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

	for (int i = 0; i < size; i++)
	{
		if(buf[i] != '.' || buf[i] != 'X')
		{
			printf("char chaeck fail\n");
			return(1);
		}
	}
	return(0);
}

void	copyBuf(char *buf, int size)
{
	int i = 0;
	int ln_num = 1;
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

	int width = 1;
	for(int i = 0; buf[i] != '\n'; i++)
		width++;
	int height = size/width;
	printf("size-->%d height-->%d  width-->%d\n", size, height, width);

	if(errors(buf, size, width, height))
	{
		write(1,"\n",1);
		return;
	}

	copyBuf(buf, size);
}



int main(int ac, char **av)
{
	
	if (ac == 2)
	{
		count_isl(av[1]);
	}
	return(0);

}


























