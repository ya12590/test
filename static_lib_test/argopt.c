#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
	int opt;

	while((opt = getopt(argc,argv,":if:lr")) != -1){
		switch(opt){
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n", opt);
				break;
			case 'f':
				printf("filename: %s\n", optarg); 
			//if there has a variable after the option, optarg will point to this.
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("unknown option: %c\n",optopt);
				// if the option can't be distinguished, the optopt will save this.
				break;
		}
		
	}
	for (; optind < argc; optind++) { 
		//when all option is done, optind will point the lest argv.
		printf("argument: %s\n",argv[optind]);
	}
	printf("argc: %d\n",argc);
	return 0;
}
