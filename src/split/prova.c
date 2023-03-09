#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pfd[2];
    int pfd2[2];
    pid_t pid;

    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Primo processo figlio
        close(pfd[0]);
        if (pipe(pfd2) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        if ((pid = fork()) == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Secondo processo figlio
            close(pfd2[0]);
            dup2(pfd[1], STDOUT_FILENO);
            close(pfd[1]);
            dup2(pfd2[1], STDOUT_FILENO);
            close(pfd2[1]);
            execlp("ls", "ls", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            close(pfd[1]);
            close(pfd2[1]);
            dup2(pfd2[0], STDIN_FILENO);
            close(pfd2[0]);
            execlp("grep", "grep", "e", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    } else {
        close(pfd[1]);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);
        execlp("sort", "sort", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    return 0;
}
