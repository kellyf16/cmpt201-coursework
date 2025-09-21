#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *buffer = NULL;
  size_t size = 0;
  char *saveptr;

  while (1) {
    printf("Enter program to run.\n");
    ssize_t _ = getline(&buffer, &size, stdin);
    if (_ == -1) {
      perror("getline failed");
      exit(EXIT_FAILURE);
    }
    char *token = strtok_r(buffer, "\n", &saveptr);
    if (token != NULL) {
      pid_t pid = fork();
      if (pid != 0) {
        int wstatus = 0;
        if (waitpid(pid, &wstatus, 0) == -1) {
        }
      } else {
        if (execl(token, token, NULL) == -1) {
          perror("exec failed");
          exit(EXIT_FAILURE);
        }
      }
    }
  }
  free(buffer);
}
