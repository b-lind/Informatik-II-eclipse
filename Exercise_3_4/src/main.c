#include <stdio.h>
#include <string.h>

// replace zehn/Zehn with sechs/Sechs

int switchWords(char *sIn, char *sOut);

int switchWords(char *sIn, char *sOut) {
    int i;
    char *cLoc;
    char *cResume = sIn;
    for(i = 0; i < 8; i++) {
        cLoc = strstr(*sIn, "zehn");

        if(cLoc != NULL) {
            strncpy(sOut, cResume, cLoc - cResume);
        }
    }
}

int main(int argc, char *argv[]){

}
