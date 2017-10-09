#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "wrap-socket.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, n;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
    
	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 20);

	printf("Accepting connections ...\n");
	while (1) {
		cliaddr_len = sizeof(cliaddr);
		connfd = Accept(listenfd, 
				(struct sockaddr *)&cliaddr, &cliaddr_len);

		int pid = fork();
		if (-1 == pid) {
			perror("call to fork");
			exit(1);
		} else if (0 == pid) {
			close(listenfd);
			while (1) {
				n = Read(connfd, buf, MAXLINE);
				if (n == 0) {
					printf("the other side has been closed.\n");
					break;
				}
    
				for (i = 0; i < n; i++)
					buf[i] = toupper(buf[i]);
				Write(connfd, buf, n);
			}
			Close(connfd);
			exit(0);
		} else {
			Close(connfd);
			int stat_val;
			waitpid(pid, &stat_val, WNOHANG);
			if (WIFEXITED(stat_val))
				printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
			else if (WIFSIGNALED(stat_val))
				printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
		}
	}
}
