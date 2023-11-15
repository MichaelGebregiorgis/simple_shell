#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

/**
 * hndlExit - exist success check
 * Return: 0
 */
void hndlExit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * hndlEnv - enviroment list check
 * @environ: Data type
 * Return: 0
 */
void hndlEnv(char **environ)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * chngeDir - directory changed
 * @dir: Data type
 * Return: 0
 */
void chngeDir(const char *dir)
{
	if (chdir(dir) != 0)
	{
		perror("chdir failed");
	}
}

/**
 * hndlPwd - path handled
 * Return: 0
 */
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
