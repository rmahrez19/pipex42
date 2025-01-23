#include "../includes/pipex.h"


void child_process(char **av, char **envp, int *fd)
{
    int filein;
    
    filein = open(av[1], O_RDONLY);
    // dup2(fd[1], STDOUT_FILENO);
    // dup2(filein, STDIN_FILENO);
    execute(av[2], envp);
}

int main(int ac, char ** av, char **envp)
{
    int pipefd[2];

    pid_t pid;
    char buf;

    if (ac == 5)
    {
        if(pipe(pipefd) == -1)
            error();
        pid = fork();
        if(pid == -1)
            error();
        child_process(av, envp, pipefd);
        
    }
    else
    {
        perror("fail nuber argument");
        exit(EXIT_FAILURE);
    }
}

//  ./pipex infile "ls -l" "wc -l" outfile
