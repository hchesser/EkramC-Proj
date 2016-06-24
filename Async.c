#ifndef _ASYNC_C
#define _ASYNC_C
/*
* File is for testing purposes. 
*/

/* Includes */
#include "../inc/async.h"
#include "../inc/input.h"
#include "../inc/memory.h"
#include <stdint.h>
/* macros */
#define BUF_SIZE 1024 /* MTU of a KISS packet */
static int fd = 0;


/*
* The termios header defines the terminal control structure and the POSIX control functions.
* The two most important POSIX control functions are tcegetattr(3) & tcsetattr(3). These get and
* set a terminal device's attributes.  
*/

volatile int STOP=FALSE;              /* volatile means that the value of STOP may change unexpectedly. This can be due to an interrupt */
         int wait_flag=TRUE;          /* TRUE while no signal received */


 void signal_handler_INT (int signo, siginfo_t *siginfo, void *ucontext) { // should be signal_handler_IO
     int size = 0;
     printf("\nCaught the signal.\n");
     printf("The signal is %d\n", signo);
     if (signo == 29) {
      printf("The signal that was caught was a SIGIO signal.\n");
     } else {
      perror("Bad signal");
     }
     printf("The ID of the sending process is %d\n", siginfo->si_pid);
     
      /*
      * Read the first 5 bytes of what FIPEX returns and do something about it. 
      */

     }
   }

  void signal_handler_SEG (int signo, siginfo_t *siginfo, void *ucontext) {
    printf("Caught a segmentation fault and overriding default action.\n");
    exit(1);
  } 

int open_port(void)
{
 

  static struct termios oldtio, newtio; // Old and new settings for port
  struct sigaction saio; 
  struct sigaction saseg;
  //open the device (com port) to be non-blocking (read will return immediately)
  printf("\nOpening Serial Port %s", "/dev/ttyS2");
  if((fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY | O_NONBLOCK )) == -1)
    { 
      perror("dev/ttyS2"); 
      return -1; 
    }
  printf("\nOpened port %s as %u\n", "/dev/ttyS2", fd);
  // Install the interrupt handler
  saio.sa_sigaction = signal_handler_INT;
  sigemptyset(&saio.sa_mask); //saio.sa_mask = 0;
  saio.sa_flags = SA_SIGINFO;
  saio.sa_restorer = NULL;
  sigaction(SIGIO, &saio, NULL);

  /*User programs have to execute two steps to enable asynchronous notification from an input file. 
   First, they specify a process as the "owner" of the file. When a process invokes the F_SETOWN command
   using the fcntl system call, the process ID of the owner process is saved. In order to get asynchronous notification, 
   the user programs must set the FASYNC flag in the device by means of the F_SETFL fcntl command.
   http://www.makelinux.net/ldd3/chp-6-sect-4
   */
  if(fcntl(fd,F_SETOWN,getpid()) == -1) {perror("/dev/ttyS2");}
  fcntl(fd, F_SETFL, FASYNC); 
  // Set fd signals (needed for siginfo to be populated)
  if(fcntl(fd,10,SIGIO) == -1) {perror("/dev/ttyS2");} 
  tcgetattr(fd, &oldtio); // save current port settings

  saseg.sa_sigaction = signal_handler_SEG;
  sigemptyset(&saseg.sa_mask); //saio.sa_mask = 0;
  saseg.sa_flags = SA_SIGINFO;
  saseg.sa_restorer = NULL;
  sigaction(SIGSEGV, &saseg, NULL);  

  // set new port settings for raw port access
  newtio.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
  newtio.c_iflag = IGNPAR;
  newtio.c_oflag = 0;
  newtio.c_lflag = 0; //ICANON does canonical input processing
  newtio.c_cc[VMIN] = 0; // Wait until x bytes read (blocks!)
  newtio.c_cc[VTIME] = 0; // Wait x * 0.1s for input (unblocks!)
  tcflush(fd, TCIFLUSH);
  tcsetattr(fd, TCSANOW, &newtio);  
  return fd;
}
/* This entry point can take from standard input and write to a serial */

int main(int argc, char**argv) {
       fd = open_port();
       uint8_t buffer[] = {0x7E, 0x00, 0x00, 0x00};      
      // buffer = read_input(stdin);
       write(fd, buffer, 4);
       for ( ;; ) {
       sleep(1);
     }
       return(0);
      
}

#endif
