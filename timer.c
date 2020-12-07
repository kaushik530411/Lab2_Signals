/*Program a new program timer.c that after exiting (via CTRL-C), 
 * will print out the total time the program was executing in seconds.
 * To accomplish this task, you will need to register a second signal handler
 * for the SIGINT signal, the signal that is delivered when CTRL-C is pressed.
 * Conceptually, your program will request a SIGALRM signal to occur every second,
 * tracking the number of alarms delivered, and when the program exits via CTRL-C,
 * it will print how many alarms occurred, or the number of seconds it was executed.
 */

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

// Global Variable
int ELAPESED_NUM_SECONDS = 0;

void sigalarmHandler(int signum) { 
  // Signal handler
  printf("Adding a second!\n");
  ELAPESED_NUM_SECONDS += 1;
}

void sigintHandler(int signum) {
  printf("Total seconds executed : %d", ELAPESED_NUM_SECONDS);
  printf("\n");
  exit(1);
}

int main(int argc, char * argv[])
{
  // Register handler to handle SIGALRM
  signal(SIGALRM, sigalarmHandler);
  signal(SIGINT, sigintHandler);
  while(true) {
    // Schedule a SIGALRM for 1 second
    alarm(1); 
    sleep(1);
  } // busy wait for signal to be delivered
  exit(1); // exit after printing (moved from handler function)
  return 0; // never reached
}