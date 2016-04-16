#include <stdio.h>
#include <string.h>
main() {
  int i, res, args, counter, badcounter, noTokens;
  FILE *database;
  char commandString[128]; 
  char command[128]; 
  char arguments[128]; 
  char arg1[128]; 
  char rest[128]; 
  char extra[128]; 
  char line[128]; 
  char rel[128][128];
  char ent1[128][128];
  char ent2[128][128];
  char crel[128], cent1[128], cent2[128];
  counter = 0;
  printf("Grock- ");
  fgets(commandString, sizeof(commandString), stdin);
  while (strncmp("quit\n", commandString, 128))
  {
    res = sscanf(commandString, "%s %[^\n]s", &command, &arguments);
    if (res > 0)
    {
      if (strncmp(command, "setdb",128) == 0)
      {
        if (res > 1)
        {
          args = sscanf(arguments, "%s %s", &arg1, &rest);
          database = fopen(arg1,"r");
          if (database != NULL)
          {
            counter = 0;
            badcounter = 0;
            while (fgets(line, sizeof(line), database)) 
            {
              noTokens = sscanf(line, "%s %s %s %s", crel, cent1, cent2, extra);             
              strncpy(rel[counter],crel,128);
              strncpy(ent1[counter],cent1,128);
              strncpy(ent2[counter],cent2,128);
              if (noTokens == 3)
              {
                counter++;
              }
              else
              {
                badcounter++;
              }
            }
            fclose(database);
            printf("Read %d facts from %s\n", counter, arg1);
            if (badcounter > 0)
              printf("%d malformed lines were ignored.\n", badcounter);
          }
          else
            printf("Unable to read from %s\n", arg1);
          if (args > 1) printf("Extra arguments ignored.\n");
        }
        else
          printf("Missing argument.\n");
      }
      else if (strncmp(command, "printdb",128) == 0)
      {
        int i;
        if (counter == 0)
          printf("Database is empty.\n");
        else
          for (i = 0; i < counter; i++)
          {
            printf("%s %s %s\n", rel[i], ent1[i], ent2[i]);
          } 
      }
      else
        printf("Unrecognized command.\n");
    }
    printf("Grock- ");
    fgets(commandString, sizeof(commandString), stdin);
  }
}
