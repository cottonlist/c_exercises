#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[32];
	long n;
	printf("Enter a number: ");
	scanf("%li", &n);
	int i = 0;

	for (i = 0; n > 0; ++i)
	{
		a[i] = n % 2;
		n = n / 2;
	}

	printf("Value before: ");
	for (int j = 0; j < i; ++j)
	{
		printf("%d", a[j]);
	}

	for (int x = 0; x < i; ++x)
	{
		if (a[x] == 1)
		{
			a[x] = 0;
		} else
		{
			a[x] = 1;
		}
	}

	printf("\nValue after: ");
	for (int j = 0; j < i; ++j)
	{
		printf("%d", a[j]);
	}
	return 0;
}
