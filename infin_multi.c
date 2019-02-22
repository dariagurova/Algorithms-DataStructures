#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int len(char *s)
{
	int i = 0;
	while(s[i])
	{
		i++;
	}
	return(i);
}

int checkSign(char *a, char *b)
{
	int i = 0;
	int j = 0;
	int neg = 0;
	if(a[i] == '-' && b[j] == '-')
	{
		i++;
		j++;
	}
	else if(a[i] == '-' && b[j] != '-')
	{
		i++;
		neg=1;
	}
	else if(a[i] != '-' && b[j] == '-')
	{
		j++;
		neg = 1;
	}
	
	return(neg);
}


 int main()
{
	// if(ac > 3 || ac == 1)
	// {
	// 	write(1, "\n", 1);
	// 	return(0);
	// }

	char *num1 = "2123";
	char *num2 = "-6521";

	int l1 = len(num1);
	int l2 = len(num2);
	long total = l1+l2;

	int *res = malloc(sizeof(int)*total);
	for (int i = 0; i <= total; i++){
		res[i] = 0;
	}

	int idx1 = 0;
	int idx2 = 0;
	for(int i = l1-1; i >= 0; i--)
	{
		int leftover = 0;
		int n1 = num1[i] - '0';
		idx2 = 0;
		for(int j = l2-1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			int sum = (n1*n2) + res[idx1 + idx2] + leftover;
			leftover = sum/10;
			res[idx1+idx2] = sum%10;
			idx2++;
		}

		if (leftover)
			res[idx1+idx2] += leftover;
		idx1++;
	}

	int idx = total-1;
	while(idx && res[idx] == 0)
		idx--;
	if(idx == -1)
	{
		write(1, "0\n", 1);
		return(0);
	}

	int neg = checkSign(num1, num2);
	if (neg)
		write(1, "-", 1);
	while(idx >= 0)
	{
		char c = res[idx] + '0';
		
		write(1, &c, 1);
		idx--;
	}
	write(1, "\n", 1);
	return(0);

}
