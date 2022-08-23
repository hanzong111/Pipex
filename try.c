#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pipex.h>
#include "pipex.h"

int     main(int ac, char **av)
{
	av[0] = "haha";
	if (ac > 4)
	{
		printf("More than 4 arguments\n");
		return (0);
	}
	char *const argv[] = {"ls", "-l", NULL};
	char *const envp[] = {NULL};

	printf("Start of system call\n");
	if (execve("/usr/bin/ls", argv, envp) == -1 )
	{
		perror("KENNOT EXECUTE\n");
	}
    return (0);
}
