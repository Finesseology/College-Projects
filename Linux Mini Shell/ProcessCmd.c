/* ----------------------------------------------------------------- */
/*                          ProcessCmd                               */
/* Author: Chris Lemke                                               */
/* Fall 2021                                                         */
/* ----------------------------------------------------------------- */

#include "lab9_10.h"

void ProcessCmd(int argc, char **argv) {  
    int ret;

    Redirection(argc, argv);
    ret = execvp(argv[0], argv);

    if(ret == -1){
        fprintf(stderr, "Error on the exec call.\n");
        _exit(EXIT_FAILURE);
    }
}