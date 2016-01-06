#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void work(){
	FILE *f;
	int i;
	double x=4.5;

	f = tmpfile();
	for (i = 0; i < 1000000; i++) { //system CPU time
		fprintf(f,"Do some output\n");
		if (ferror(f)) {
			fprintf(stderr,"Error writing to temporary file\n");
			exit(1);
			/* code */
		}
		/* code */
	}
	for (i = 0; i < 1000000; i++) {	//user CPU time
		x = log(x*x+3.21);
		/* code */
	}

}


int main(int argc, const char *argv[])
{
	struct rusage r_usage;	//the CPU time information will be recorded in 
	struct rlimit r_limit;  //read or set the system source limits
	

	work();
	getrusage(RUSAGE_SELF, &r_usage); //SELF: Current use info//write CPU info to struct r_usage

	printf("CPU usage: User = %ld.%06ld, System = %ld.%06ld\n", r_usage.ru_utime.tv_sec,r_usage.ru_utime.tv_usec,r_usage.ru_stime.tv_sec,r_usage.ru_stime.tv_usec);
	
	getrlimit(RLIMIT_FSIZE,&r_limit); //FSIZE is limitting file size
	printf("Current FSIZE limit: soft = %ld, hard = %ld\n",r_limit.rlim_cur,r_limit.rlim_max);
	r_limit.rlim_cur = 2048;	// soft limit
	r_limit.rlim_max = 4096;	// hard limit
	printf("Setting a 2K file size limit\n");
	setrlimit(RLIMIT_FSIZE, &r_limit);	//set new limit settings

	work();
	exit(0);
	
	return 0;
}
