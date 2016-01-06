#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>


void printdir(char *dir, int depth){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf; //the buffer stores the data of the file.

	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr,"cannot open directory.");
		return;
	}
	chdir(dir);	//change directory to destination
	while((entry = readdir(dp)) != NULL){
		lstat(entry->d_name, &statbuf);	
		//statbuf stores the data of the file
		if (S_ISDIR(statbuf.st_mode)) {
			if (strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0) {
				continue;
			} // filter the . and ..
			printf("%*s%s/\n",depth,"",entry->d_name);
			printdir(entry->d_name,depth+4);
			
		}
		else  printf("%*s%s\n",depth,"",entry->d_name);
	}
	chdir("..");
	closedir(dp);
		
}

int main(int argc, const char *argv[])
{
	printf("directory scan of /home:\n");
	printdir("/home",0);
	printf("done.");

	return 0;
}
