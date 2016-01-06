#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char buffer[] = {'x','y','z'};
	fp = fopen("test.txt","w");
	fwrite(buffer, sizeof(char), sizeof(buffer),fp);
	fclose(fp);
	return 0;
}

