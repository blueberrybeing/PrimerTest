/*
#include <stdio.h>
int bar(int c, int d)
{
	int e = c + d;
	return e;
}

int foo(int a, int b)
{
	return bar(a, b);
}

#define STR(s) #s

int main(void)
{
	
	printf("%s\n", STR(hill shfdf   dkk));
	return 0;
}
*/

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char buf[10];
	int n;
	n = read(STDIN_FILENO, buf, 10);
	if (n < 0) {
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDOUT_FILENO, buf, n);
	return 0;
}
*/

/*
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <strin.h>
#include <stdio.h>
#include <stdlib.h>

#define MSG_TRY "try again\n"

int main(void)
{
	char buf[10];
	int fd, n;
	fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
	if (fd < 0) {
		perror("open /dev/tty");
		exit(1);
	}
tryagain:
	n = read(fd, buf, 10);
	if (n < 0) {
		if (errno != EAGAIN) {
			perror("read /dev/tty");
			exit(1);
		}
		sleep(1);
		write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
		goto tryagain;
	}
	write(STDOUT_FILENO, buf, n);
	close(fd);
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("PATH=%s\n", getenv("PATH"));
	setenv("PATH", "fuck", 1);
	printf("PATH=%s\n", getenv("PATH"));
	return 0;
}
*/

/* fork() */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	char *message;
	int n;
	pid = fork();
	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}
	if (pid == 0) {
		message = "This is the child\n";
		n = 6;
	} else {
		message = "This is the parent\n";
		n = 3;
	}
	for (; n > 0; n--) {
		printf("%s", message);
		sleep(1);
	}
	return 0;
}

