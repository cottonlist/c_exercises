#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// struct info {
// 	char file_name[30];
// 	int size;
// };

// comparator used in qsort as the 4th parameter
int comparator(const void *p, const void *q)
{
	int i = ((struct info *)p)->size;
	int j = ((struct info *)q)->size;
	return (i - j);
}

int main(int argc, char const *argv[])
{
	// struct info infos[20]; 
	int i = 0;

	DIR *d;
	struct dirent *dir;

	d = opendir(".");

	int file_count = 0;
	int max_name_len = 0;

	// Trying to find how many files are in the directory and maximum length of among file names
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			FILE *fp;
			fp = fopen(dir->d_name, "r");
			if (strlen(dir->d_name) > max_name_len)
			{
				max_name_len = strlen(dir->d_name);
			}
			file_count++;
		}
	}

	struct info {
		char file_name[max_name_len+1];
		int size;
	};

	struct info infos[file_count];

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

	// replaced sort part with qsort()
	qsort(infos, i, sizeof(struct info), comparator);

	for (int x = 0; x < i; ++x)
	{
		printf("%s\t%d\n", infos[x].file_name, infos[x].size);
	}

	return 0;
}