/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

// Global variable
bool TURNING_PRINT = false; 
  
void handler(int signum) { 
  //signal handler
  printf("Hello World!\n");
  TURNING_PRINT = true;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  while(true) {
    alarm(1);
    if (TURNING_PRINT == true) {
      printf("Turing was right!\n");
      TURNING_PRINT = false;
    }
    sleep(1);
  }
  exit(1);
  return 0; //never reached
}