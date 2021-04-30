#include <stdlib.h>
#include <stdio.h>

#define MAX_FILE_SIZE (1024*1024*5)

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("this argument not enough\n");
		return 0;	
	}
	char *pathfile = argv[1];
	int key = atoi(argv[2]);

	FILE *fptr;
	char data[MAX_FILE_SIZE];

	//Read file
	fptr = fopen(pathfile, "rb");
	int i = 0;
	while(!feof(fptr))
		data[i++] = fgetc(fptr);
	fclose(fptr);

	//Write file
	fptr = fopen(pathfile, "wb");
	for(int j = 0; j < i-1; j++)
		fputc((data[j] ^ key), fptr);
	fclose(fptr);

	return 0;
}
