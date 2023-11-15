#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header.h"

#define MAX_COMMAND_LENGTH 100

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) 
	{
		printf("$ ");
		fflush(stdout);


		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		snline(command);

		if (strcmp(command, "exit") == 0)
		{
			hndlExit();
			break;
		}

		if (strcmp(command, "env") == 0)
		{
			hndlEnv();
			continue;
		}

		if (strncmp(command, "cd ", 3) == 0)
		{
			const char* dir = command + 3;
			chngeDir(directory);
			continue;
		}

		if (strcmp(command, "pwd") == 0)
		{
			hndlePwd();
			continue;
		}

		exeCmd(command);
	}

	return (0);
}
