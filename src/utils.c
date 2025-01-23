#include "../includes/pipex.h"

char **pars(char **envp)
{
    int i;

    i = 0;
    while(envp[i] != NULL)
    {
        if(ft_strncmp((envp[i]), "PATH", 4)== 0)
            return(ft_split((envp[i] + 5), ':'));
        i ++;
    }
    error();
    return((char **)'a');
}

void execute(char *cmd, char **envp)
{
    char **res = pars(envp);
    printf("%s", res[1]);
}

void error(void)
{
    perror("error program exit");
    exit(EXIT_FAILURE);
}

