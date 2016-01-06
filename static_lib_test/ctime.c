#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	time_t timeval; //time function 
	(void)time(&timeval); //access the low time.
	printf("The date is %s\n", ctime(&timeval));
	return 0;
}
