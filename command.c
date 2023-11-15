#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "header.h"

/**
 * excCmd - execute command
 * Return: 0
 */
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
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int stat;

		waitpid(pid, &stat, 0);
	}
}
