#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PIPES 10

struct pipe_info {
  int read_fd[2];
  int write_fd[2];
};

int main() {
  struct pipe_info pipes[MAX_PIPES];
  int pids[MAX_PIPES];
  int status[MAX_PIPES];
  char buffer[1024];
  int num_pipes = 0;

  // Crea le pipe
  for (int i = 0; i < MAX_PIPES; i++) {
    if (pipe(pipes[i].read_fd) == -1) {
      perror("pipe");
      exit(EXIT_FAILURE);
    }
    if (pipe(pipes[i].write_fd) == -1) {
      perror("pipe");
      exit(EXIT_FAILURE);
    }
    num_pipes++;
  }

  // Crea i processi figli
  for (int i = 0; i < num_pipes; i++) {
    pids[i] = fork();
    if (pids[i] == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pids[i] == 0) {
      // Processo figlio
      for (int j = 0; j < num_pipes; j++) {
        // Chiude le estremità di lettura e scrittura delle pipe che non gli servono
        if (j != i) {
          close(pipes[j].read_fd[0]);
          close(pipes[j].write_fd[1]);
        }
      }

      // Scrive sulla pipe
      write(pipes[i].write_fd[1], "Ciao Mondo!\n", sizeof("Ciao Mondo!\n"));

      // Legge dalla pipe
      read(pipes[i].read_fd[0], buffer, sizeof(buffer));
      printf("%s", buffer);

      // Chiude entrambe le estremità della pipe
      close(pipes[i].read_fd[0]);
      close(pipes[i].write_fd[1]);

      exit(EXIT_SUCCESS);
    }
  }

  // Chiude tutte le estremità delle pipe nel processo padre
  for (int i = 0; i < num_pipes; i++) {
    close(pipes[i].read_fd[0]);
    close(pipes[i].write_fd[1]);
  }

  // Attende la terminazione dei processi figli
  for (int i = 0; i < num_pipes; i++) {
    waitpid(pids[i], &status[i], 0);
  }

  return 0;
}