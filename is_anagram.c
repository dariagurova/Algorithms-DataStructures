#include <stdio.h>

int	compare(int *ah, int *bh)
{
	int i = 0;
	while (i < 255)
	{
		if (ah[i] != bh[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_anagram(char *a, char *b)
{
	int ah[255];
	int bh[255];
	int i=0;

	while (i < 255)
	{
		int j = 0;
		ah[i] = 0;
		while (a[j] != '\0')
		{
			if (i == a[j])
				ah[i] += 1;
			j++;
		}
		i++;
	}


	int k = 0;
	while (k < 255)
    {
        int j = 0;
        bh[k] = 0;
        while (b[j] != '\0')
        {
            if (((char)k) == b[j])
                bh[k] += 1;
            j++;
        }
        k++;
    }


	int f = 0;
	while (f < 255)
	{
		if (ah[f] != bh[f])
			return (0);
		f++;
    }
	return (1);
}

int main ()
{
	char *b = "aaa";
	char *a = "aaa";
	printf("%d\n", is_anagram(a,b));
	return (0);
}

