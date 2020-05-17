#include <stdio.h>
#include <stdlib.h>

#define range 20
#define number 5

int main(int argc, char const *argv[])
{
	int drew[number];
	int i = 0;
	int isDrew = 0;
	while(i<5)
	{
		isDrew = 0;
		int num = rand() % (range+1);
		for (int j = 0; j < number; ++j)
		{
			if (num == drew[j])
			{
				isDrew = 1;
			}
		}
		if (isDrew == 0)
		{
			drew[i] = num;
			i++;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", drew[i]);
	}
	return 0;
}