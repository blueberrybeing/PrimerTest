#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL);
	perror("exec ps");
}
