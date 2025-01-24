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

char *str_join(char *s1, char *s2)
{
    int i;
    int j;

    j = 0;
    char *res;
    i = ft_strlen(s1);
    i += ft_strlen(s2);
    res = malloc(i + 2);
    if(!res)
        error();
    i = 0;
    while(s1[i])
    {
        res[i] = s1[i];
        i++; 
    }
    res[i++] = '/';
    while(s2[j])
    {
        res[i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    return(res);
}

void run_shell(char *cmd, char **paths, char **av, char **envp)
{
    char *full_path = NULL;
    int i;

    i = 0;
    while(paths[i])
    {
        full_path = str_join(paths[i], cmd);
        if(access(full_path, X_OK) == 0)
        {
            execve(full_path, av, envp);
            error();
        }
        i++;
    }
}
void execute(char *cmd, char **envp, char **av)
{
    char **paths = pars(envp);
    char **cmd_args = ft_split(cmd, ' ');
    run_shell(cmd_args[0], paths, av, envp);
    // printf("cmd = %s\n", cmd);    
    // printf("%s", paths[1]);
}

void error(void)
{
    perror("error program exit");
    exit(EXIT_FAILURE);
}

