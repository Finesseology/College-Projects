/* Author(s): Ruthann Biel & Chris Lemke                  	 
 * This is csc60mshell.c
 * This is lab10.c the csc60mshell
 * This program serves as the base for doing labs 9 and 10.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in the directions.
 * Date: Fall 2021
 */

#include "lab9_10.h"


/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void)
{
    char CmdLine[MAXLINE];
    char *argv[MAXARGS];
    int argc;

    // Loop forever to wait and process commands 
    while (TRUE) 
    {
        printf("\ncsc60msh> ");

        /* read the command the user types in */
        fgets(CmdLine, MAXLINE, stdin);

        /* Call ParseLine to build argc/argv; their limits declared above */
        argc = ParseCmd(CmdLine, argv);

        // REQUIRED: Just-to-make-sure printfs 
        printf("Argc = %i \n",  argc);
        int i;
        for(i = 0; i < argc; i++)
        {
            printf ("Argv %i = %s \n", i, argv[i]);
        }

        // If user hits enter key without a command, continue to loop again at the beginning 
        //handle no command command
        if(argc == 0){
            continue;
        }

        // Handle build-in command: exit, pwd, or cd 
        //handle exit command
        if(strcmp(argv[0], "exit") == 0){
            exit(EXIT_SUCCESS); 
        }
        else if(strcmp(argv[0], "pwd") == 0){
            char PathBuf[MAX_PATH_LENGTH]; 
            getcwd(PathBuf, MAX_PATH_LENGTH); //returns cwdbuf on success, NULL on error; skip checking
            printf("%s\n", PathBuf);
            continue;
        }
        else if(strcmp(argv[0], "cd") == 0){
            char *dir;
            int returnResponse;

            if(argc == 1){
                dir = getenv("HOME");
            } 
            else{
                dir = argv[1];
            }
            returnResponse = chdir(dir);
            
            //check to ensure we changed
            if(returnResponse < 0){
                printf("Error changing directory.\n");
                exit(EXIT_FAILURE);
            }

            continue;
        }


        /* Else, fork off a process */
        else
        {
            RunExtCmd(argc, argv);
        }      /* end of the if-else-if */

    }	   /* end of the while loop */
}   	   /* end of main */

