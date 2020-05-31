#include <stdio.h>

int atoi(char str[])
{
	int i, n, sign;
	i = 0;
	n = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	} else 
	{
		sign = 1;
	}

	for (; str[i] != '\0'; ++i)
	{
		n = n * 10 + str[i] - '0';
	}
	return n * sign;
}

int main(int argc, char const *argv[])
{
	char str[] = "-33456";
	int val = atoi(str);
	printf("%d", val);
	return 0;
}