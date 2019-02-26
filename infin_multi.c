#include <unistd.h>
#include <stdlib.h>
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

int sign(char *num1, char *num2)
	{
		int neg = 0;
		if(*num1 == '-' && *num2 == '-')
		{
			num1++;
			num2++;
		}
		else if(*num1 == '-' && *num2 != '-')
		{
			num1++;
			neg = 1;
		}
		else if(*num1 != '-' && *num2 == '-')
		{
			num2++;
			neg = 1;
		}
		return(neg);
	}

int main(int ac, char **av)
{
	char *num1 = av[1];
	char *num2 = av[2];

	int l1 = len(num1);
	int l2 = len(num2);

	int *ret = malloc(sizeof(int)*(l1+l2));
	for(int i = 0; i < l1+l2; i++)
	{
		ret[i] = 0;
	}

	int neg = 0;
	if(*num1 == '-' && *num2 == '-')
	{
		num1++;
		num2++;
	}
	else if(*num1 == '-' && *num2 != '-')
	{
		num1++;
		neg = 1;
	}
	else if(*num1 != '-' && *num2 == '-')
	{
		num2++;
		neg = 1;
	}

	printf("num1 --> %s\n", num1);
	printf("num2 --> %s\n", num2);

	int idx1 = 0; int idx2 = 0;

	for (int k = l1-1; k >= 0; k--)
	{
		int leftover = 0;
		int n1 = num1[k] - '0';
		printf("n1 == %d; k == %d\n", n1, k);
		idx2 = 0;
		for(int j = l2-1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			printf("n2 == %d; j == %d\n", n2, j);
			int sum = (n1*n2)+ret[idx1+idx2]+leftover;
			leftover = sum/10;
			ret[idx1+idx2] = sum%10;

			idx2++;
		}
		if (leftover)
			ret[idx1+idx2] += leftover;
		idx1++;

	}

	int idx = l1+l2-1;
	while(idx >= 0 && ret[idx] == 0)
		idx--;
	if(idx == -1)
	{
		write(1, "0",1);
		write(1, "\n", 1);
		return(0);
	}
	if(neg == 1)
		write(1, "-", 1);
	while(idx >= 0)
	{
		char c = ret[idx] + '0';
		write(1, &c, 1);
		idx--;
	}
	write(1, "\n",1);
	return(0);
}
