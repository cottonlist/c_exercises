#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str[100];
	int sum = 0;
	scanf("%[^\n]s", str);
	for (int i = 0; i < strlen(str); ++i)
	{
		sum += str[i];
	}
	printf("%d\n", sum);
	return 0;
}