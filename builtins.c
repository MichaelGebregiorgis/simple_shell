#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"


void hndlExit(void)
{
	exit(EXIT_SUCCESS);
}

void hndlEnv(char **environ)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

void chngeDir(const char *dir)
{
	if (chdir(dir) != 0)
	{
		perror("chdir failed");
	}
}

void hndlPwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd failed");
	}
}
