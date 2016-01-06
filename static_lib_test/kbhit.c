#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>

static struct termios initial_settings, new_settings;
static int peek_char = -1;
void init_kb();
void close_kb();
int kbhit();
int readch();

int kbhit(){
	char ch;
	int nread;

	if (peek_char != -1) {
		return 1;
		/* code */
	}
	new_settings.c_cc[VMIN]=0;
	tcsetattr(0,TCSANOW, &new_settings);	//let MIN,TIME=0. read func. will return now.
	nread = read(0,&ch,1);	//read from 0, and read one byte
	new_settings.c_cc[VMIN]=1; //reset the MIN
	tcsetattr(0,TCSANOW, &new_settings);
	if (nread == 1) {
		peek_char = ch;
		return 1;
		
	}
	return 0;
}

int readch(){
	char ch;
	if (peek_char != -1) {
		ch = peek_char;
		peek_char = -1;
		return ch;
		/* code */
	}
	//read(0,&ch,1);
	//return ch;
}

void init_kb(){
	tcgetattr(0,&initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;	// non-canonical mode
	new_settings.c_lflag &= ~ECHO; 	//avoid echo input
	//new_settings.c_lflag &= ~ISIG;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	tcsetattr(0,TCSANOW,&new_settings);
}
void close_kb(){
	tcsetattr(0,TCSANOW, &initial_settings);
}

int main(int argc, const char *argv[])
{
	int ch = 0;
	init_kb();
	while(ch != 'q'){
		printf("looping\n");
		sleep(1);
		if (kbhit()) {
			ch = readch();
			printf("you hit %c\n",ch);
			/* code */
		}
	}
	close_kb();
	return 0;
}




