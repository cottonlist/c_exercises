#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *filename = "file.txt";
	FILE *fp = fopen(filename, "r");
	char str1[20][10];
	//char str2[30] = "moon fire water banana";
	char c;
	int index = 0;
	while((c=fgetc(fp))!=EOF)
	{
		//str1[index] = '';
		if (c == ' ')
		{
			index++;
		} else 
		{
			strncat(str1[index], &c, 1);
		}
	}

	int randArray[index];

	int x = 0;
	int isDrew = 0;

	while(x < index)
	{
		isDrew = 0;
		int num = rand()%(index+1);
		for (int i = 0; i < index; ++i)
		{
			if (num == randArray[i])
			{
				isDrew=1;
			}
		}
		if (isDrew == 0)
		{
			randArray[x] = num;
			x++;
		}
	}

	int order = 1;

	while(order < 8)
	{
		for (int i = 0; i < index; ++i)
		{
			if (randArray[i]==order)
			{
				printf("%s\n", str1[i]);
			}
		}
		order++;
	}

	

	for (int i = 0; i < index; ++i)
	{
		printf("%d\n", randArray[i]);
	}

	int num = rand()%(index+1);

	for (int i = 0; i <= index; ++i)
	{
		printf("%s\n", str1[i]);
	}
	// strcpy(str1[0], "earth");
	// char str[20] = "nihao";
	// // for (int i = 0; i < strlen(str1); ++i)
	// // {
	// // 	strncat(str, &ch[i], 1);
	// // }
	// printf("%s", str1[0]);
	return 0;
}