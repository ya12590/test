#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	char tmpname[L_tmpnam]; // length of filename, usually is 20 characters
	char *filename;
	FILE *tmpfp;

	filename = tmpnam(tmpname);

	printf("Temporary file name is: %s\n",filename);
	tmpfp = tmpfile();	//open 
	if(tmpfp)
		printf("Opened a temporary file OK\n");
	else
		perror("tmpfile");
	return 0;
}
