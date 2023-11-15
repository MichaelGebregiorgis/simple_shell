#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

extern char **environ;

void hndlExit()
{
	exit(EXIST_SUCCESS);
}

void hndlEnv()
{
	char **env = environ;
	while (*env) 
	{
		printf("%s\n", *env);
		env;
	}
}

void chngeDir(const char* dir)
{
	if (chdir(directory) != 0)
	{
		perror("chdir failed");
	}
}

void hndlPwd()
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%sn", cwd);
	}
	else
	{
		perror("getcwd failed");
	}
}
