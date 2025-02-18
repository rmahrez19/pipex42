#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void error(void);
void execute(char *cmd, char **envp, char **av);

#endif
