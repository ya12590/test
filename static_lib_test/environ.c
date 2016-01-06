#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char *var,*value;
	
	if (argc == 1 || argc > 3) {
		fprintf(stderr,"usage: environ var [value]\n");
	}
	var = argv[1];
	value = getenv(var);
	if (value) {
		printf("Variable %s has value %s\n",var,value);
		/* code */
	}
	else
		printf("Variable %s has no value\n",var);
	if (argc == 3) { //examine whether the program has the third argument
		char *string;
		value = argv[2];
		string = malloc(strlen(var)+strlen(value)+2);	//has "=" and "\0"
		if (!string) {
			fprintf(stderr,"out of memory\n");
			exit(1);
			/* code */
		}
		strcpy(string,var);
		strcat(string,"=");
		strcat(string,value);
		printf("Calling putenv with: %s\n",string);
		if (putenv(string)!=0) {
			fprintf(stderr,"putenv failed\n");
			free(string);
			exit(1);
			/* code */
		}
		value = getenv(var);
		if (value) {
			printf("New value of %s is %s\n",var,value);
			/* code */
		}
		else
			printf("New value of %s is null??\n",var);

		/* code */
	}
	return 0;
}
