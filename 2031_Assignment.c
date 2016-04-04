#include <stdio.h>


main() {
  // program variables i, res
  int i, number_stored;
  char commandString[128]; 
  char command_from_stdin[128]; 
  char arguments[128]; 
  
  // The command line will ask 5 times and no more
  for (i=0; i < 5; i++)
  {
    printf("Grock- ");
	/*fgets is a routine where parameters passed are a input stream, how much we want to
	scan from the input stream and the pointer which points to the memory block that
	we store it in*/
	
    fgets(commandString, sizeof(commandString), stdin);
    printf("%s", commandString);
	   
	// output is the number of character pointer spaces that was stored into 
	res = sscanf(commandString, "%s %[^\n]s", &command_from_stdin, &arguments)
    
	if (number_stored > 0)
    {
      printf("Command entered: %s\n", command_from_stdin);
      if (number_stored > 1)
        printf("Arguments entered: %s\n", arguments);
      else
        printf("Arguments entered: \n");
    }
    else
    {
      printf("Command entered: \n");
      printf("Arguments entered: \n");
    }
  }
}

