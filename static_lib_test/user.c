#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	uid_t uid;
	gid_t gid;

	struct passwd *pw;
	uid = getuid();
	gid = getgid();

	printf("User is %s\n", getlogin());	//the login name now

	printf("User IDs: uid=%d, gid=%d\n",uid,gid);

	pw = getpwuid(uid); //access the uid's password information
	printf("UID passwd entry:\n name:%s, uid=%d, gid=%d, home=%s, shell=%s\n",pw->pw_name,pw->pw_uid, pw->pw_gid,pw->pw_dir,pw->pw_shell);

	return 0;
}
