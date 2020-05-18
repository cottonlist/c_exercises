#include <stdio.h>

int main(int argc, char const *argv[])
{
	int ch;
	while ((ch = getchar()) != EOF)
		printf("%x ", ch);
	return 0;
}