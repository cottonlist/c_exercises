#include <stdio.h>

int main(int argc, char const *argv[])
{
	int count;
	for (int i = 2; i < 101; ++i)
	{
		count = 0;
		for (int j = 1; j < i+1; ++j)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}