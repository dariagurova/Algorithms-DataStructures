#include <stdio.h>

int	calc_r0(int *arr, int n)
{
	int r = 0;
	int i = 1;
	while (i < n)
	{
		r +=arr[i];
		i++;
	}
	return(r);
}

int pivot(int *arr, int n)
{
	int l = 0;
	int i  = 1;
	int r = calc_r0(arr,n);

	if (r == l)
		return(0);
	while (i < n)
	{
		l = l + arr[i-1];
		r = r - arr[i];
		if (l == r)
			return (i);
		i++;
	}
	return (-1);
}

int main()
{
	int arr[8] = {6, 1, 2, 4, 5, 2,1,1};
	printf("%d\n", pivot(arr,8));
	return (0);
}