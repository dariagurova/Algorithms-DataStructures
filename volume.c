#include <stdio.h>

int	highest(int*arr, int size)
{
	int idx = 0;
	int i = 0;
	while (i < size)
	{
		if(arr[i] > arr[idx])
			idx=i;
		i++;
	}
	return(idx);
}

int    volume_histogram(int *arr, int size)
{
	int water_lvl = arr[0];
	int water_volume =0;
	int h = highest(arr, size);
	int i = 0;
	while (i < h)
	{
		if (arr[i] < water_lvl)
			water_volume += water_lvl - arr[i];
		if (arr[i] > water_lvl)
			water_lvl = arr[i];
		i++;
	}
	water_lvl = arr[size-1];
	i = size-1;
	while (i > h)
	{
		if (arr[i] < water_lvl)
			water_volume += water_lvl - arr[i];
		if (arr[i] > water_lvl)
			water_lvl = arr[i];
		i--;

	}
	return(water_volume);

}

int main()
{
	int arr[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int h = volume_histogram(arr, 16);
	printf("%d\n", h);
	return (0);
}



