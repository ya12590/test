#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
	//if((write(1,"Here is some data\n",18)) !=18)
		//write(2, "A write error has occurred on file descriptor 1\n",46);
	open("myfile",O_CREAT, S_IRUSR|S_IXOTH);
	return 0;
}
