#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
  int pid, i;

  // Create 3 child processes.
  for (i = 0; i < 3; i++) {
    pid = fork();
    if (pid == 0) {
      // This is the child process.
      kill(getppid(), SIGINT); // Send an interrupt signal to the parent process.
      printf("Child %d: Interrupt message\n", i);
      exit(0);
    }
  }

  // This is the parent process.
  printf("Parent: Message\n");
  for (i = 0; i < 3; i++) {
    wait(NULL); // Wait for the child processes to terminate.
  }

  return 0;
}

