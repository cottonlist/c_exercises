#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int numberCount[6];
	int roll;
	int finished = 0;
	while (finished == 0)
	{
		for (int i = 0; i < 6; ++i)
		{
			numberCount[i] = 0;
		}
		for (int i = 0; i < 6; ++i)
		{
			roll = rand() % 6;
			printf("%d ", roll + 1);
			numberCount[roll]++;
		}
		printf("\n");
		for (int i = 0; i < 6; ++i)
		{
			printf("%d ", numberCount[i]);
			if (numberCount[i] >= 4)
			{
				finished = 1;
			}
		}
		printf("\n\n");
	}
	
	return 0;
}