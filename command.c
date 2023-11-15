#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "header.h"

void excCmd(const char *cmd)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		ececl("/bin/sh", "sh", "-c", cmd, NULL);
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int stat;
		waitpid(pid, &stat, 0);
	}
}
