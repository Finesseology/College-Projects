/*
Chris Lemke
Handled the redirection of files in the mini shell
*/

#include "lab9_10.h"

void Redirection(int argc, char *argv[]){
    int i, fd, OutLoc = 0, InLoc = 0;

    for(i = 0; i < argc; i++){
        if(strcmp(argv[i], ">") == 0){
            if(OutLoc != 0){
                fprintf(stderr, "Error: Cannot output to more than one file.\n");
                _exit(EXIT_FAILURE);
            }
            else if(i == 0){
                fprintf(stderr, "Error: No command entered.\n");
                _exit(EXIT_FAILURE);
            }
            OutLoc = i;
        }
        else if(strcmp(argv[i], "<") == 0){
            if(InLoc != 0){
                fprintf(stderr, "Error: Cannot input from more than one file.\n");
                _exit(EXIT_FAILURE);
            }
            else if(i == 0){
                fprintf(stderr, "Error: No command entered.\n");
                _exit(EXIT_FAILURE);
            }
            InLoc = i;
        }
    }

    if(OutLoc != 0){
        if(argv[OutLoc + 1] == NULL){
            fprintf(stderr, "Error: There is no file.\n");
            _exit(EXIT_FAILURE);
        }

        fd = open(argv[OutLoc + 1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

        if(fd == -1){
            perror(argv[OutLoc + 1]);
            _exit(EXIT_FAILURE);
        }

        dup2(fd, 1);

        if(close(fd) == -1){
            _exit(EXIT_FAILURE);
        }

        argv[OutLoc] = NULL;
    }

    if(InLoc != 0){
        if(argv[InLoc + 1] == NULL){
            fprintf(stderr, "Error: There is no file.\n");
            _exit(EXIT_FAILURE);
        }

        fd = open(argv[InLoc + 1], O_RDONLY);

        if(fd == -1){
            perror(argv[InLoc + 1]);
            _exit(EXIT_FAILURE);
        }

        dup2(fd, 0);

        argv[InLoc] = NULL;
    }
    
}