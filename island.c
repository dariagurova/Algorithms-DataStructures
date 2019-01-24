#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	flood(char **grid, int row, int col, int h, int w, char f);


void	fill(char **grid, int row, int col, int h, int w, char f)
{
	if (row >= 0 && col >= 0 && row < h && col < w)
	{
		if (grid[row][col] == 'X')
		{
			grid[row][col] = f;
			flood(grid, row, col,h, w,f);
		}
	}
}

void	flood(char **grid, int row, int col, int h, int w, char f)
{
	fill(grid,row,col+1,h,w,f);
	fill(grid,row,col-1,h,w,f);
	fill(grid,row+1,col,h,w,f);
	fill(grid,row-1,col,h,w,f);
}


void printer(char **grid)
{
	int i = 0;
	while (grid[i])
	{
		printf("%s\n", grid[i]);
		i++;
	}

}


int main (int ac, char **av)
{
	char **grid = malloc(sizeof(char*)*5000);
	int i = 0;
	while (i < 5000)
	{
		grid[i] = NULL;
		i++;
	}

	int fd = open(av[1], O_RDONLY);
	char *buf = malloc(sizeof(char)*100000);
	read(fd, buf,100000);
	int ln_num=1;
	int ind=0;
	int flag=0;
	int w;
	int h;
	grid[0]=buf;
	while(buf[ind])
	{
		
		if (buf[ind] == '\n')
		{
			if (!flag){
				w=ind;
				flag=1;
			}
			buf[ind] = '\0';
			
			grid[ln_num] = &(buf[ind+1]);
			
			ln_num++;
		}
		ind++;
	}
	h=ln_num;
	int j = 0;
	
	char islnd_num = '0';
	while (j < h)
	{
		int k = 0;
		while (k < w)
		{
			char c = grid[j][k];
			if (c == 'X')
			{
				fill(grid, j,k,h,w, islnd_num);
				islnd_num++;
			}
			k++;

		}
		j++;
	}

	
	printer(grid);
	return (0);





}
