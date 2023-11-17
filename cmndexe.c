#include "header.h"
#include <sys/wait.h>

void cmdexec(char **argv)
{
	pid_t pid;
	int stat;
	int exStat = WEXITSTATUS(stat);
	int sigNum = WTERMSIG(stat);

	if (argv != NULL)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error: Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(argv[0], argv) == -1)
			{
				perror("Error: Execution failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &stat, 0) == -1)
			{
				perror("Error: Waitpid failed");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(stat))
			{
				if (exStat == 0)
					printf("Command executed successfully\n");
				else
					printf("Command exited with non-zero status: %d\n", exStat);
			}
			else if (WIFSIGNALED(stat))
				printf("Command terminated by signal: %d\n", sigNum);
		}
	}
}
