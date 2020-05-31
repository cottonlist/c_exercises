#include <stdio.h>
#include <dirent.h>
#include <string.h>

struct info {
	char file_name[30];
	int size;
};

int main(int argc, char const *argv[])
{
	struct info infos[20]; 
	int i = 0;

	DIR *d;
	struct dirent *dir;

	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			FILE *fp;
			int len;

			fp = fopen(dir->d_name, "r");
			strcpy(infos[i].file_name, dir->d_name);
			fseek(fp, 0, SEEK_END);
			len = ftell(fp);
			infos[i].size = len;
			i++;
			fclose(fp);
		}
		closedir(d);
	}

	struct info temp;
	for (int j = 1; j < i; ++j)
	{
		for (int m = 0; m < i - 1; m++)
		{
			if (infos[m].size > infos[m+1].size)
			 {
			 	temp = infos[m];
			 	infos[m] = infos[m + 1];
			 	infos[m+1] = temp;
			 } 
		}
	}

	for (int x = 0; x < i; ++x)
	{
		printf("%s\t%d\n", infos[x].file_name, infos[x].size);
	}

	return 0;
}