#include <stdlib.h>
#include <unistd.h>

int len(char *s) {
	int ret = 0;
	while (*s++)
		ret++;
	return ret;
}

int checkSign(char *num1, char *num2)
{
	int neg = 0;
	int i = 0;
	int j = 0;
	if (num1[i] == '-' && num2[j] == '-')
		{
			i++;
			j++;
			neg = 0;
		}
	if (num1[i] == '-' && num2[j] != '-')
	{
		i++;
		neg = 1;
	}

	if (num1[i] != '-' && num2[j] == '-')
	{
		j++;
		neg = 1;
	}

	return(neg);

}

int main(int ac, char **av)
{
	if (ac != 3)
		return(0);
	char *num1 = av[1];
	char *num2 = av[2];
	int neg = checkSign(num1, num2);

	long l1 = len(num1);
	long l2 = len(num2);

	long totLen = l1+l2;
	int *res = malloc(sizeof(int)*totLen);
	for(int i = 0; i < totLen; i++)
		res[i] = 0;

	int i1 = l1-1;
	int idx1 = 0;
	while(i1 >= 0)
	{
		int leftOver = 0;
		int n1 = num1[i1] - '0';

		int i2 = l2-1;
		int idx2 = 0;
		while(i2 >= 0)
		{
			int n2 = num2[i2] - '0';
			int sum = (n1*n2) + res[idx1+idx2] + leftOver;
			leftOver = sum/10;
			res[idx1+idx2] = sum%10;
			idx2++;
			i2--;
		}
		if (leftOver)
			res[idx1+idx2] = leftOver;
		i1--;
		idx1++;
	}

	for(int j = 0; j < totLen; j++)
	{
		char c = res[j]+'0';
		write(1,&c,1);
		j++;
	}
	write(1, "\n", 1);
	return(0);
}


































