#include <stdio.h>
#include <term.h>
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int nrows,ncolumns;

	setupterm(NULL,fileno(stdout), (int *)0);	
	//NULL:referrence to env. var. fileno:link to the terminal which will be written.
	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	printf("This terminal has %d columns and %d rows\n",ncolumns,nrows);
	return 0;
}
