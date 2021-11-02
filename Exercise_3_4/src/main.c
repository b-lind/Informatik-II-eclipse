#include <stdio.h>
#include <string.h>

// replace zehn/Zehn with sechs/Sechs

int switchWord(char *sIn, char *sOut, char *sOld, char *sNew);

int switchWord(char *sIn, char *sOut, char *sOld, char *sNew) {
    int i;
    char *cLoc;
    char *cLocNew;

    for(i = 0; i < 7; i++) {
        char *cLocNew = strstr(sIn, sOld);

        if(cLocNew != NULL) {
            strncat(sOut, sIn, strlen(sIn) - strlen(cLocNew));
            strcat(sOut, sNew);

            sIn = cLocNew + strlen(sOld);
        }
        else {
            strcat(sOut, sIn);
            return 0;
        }
    }

    cLoc = strstr(sIn, sOld);
    
    if(cLoc != NULL)
        return -1;
    else
        return 0;
}

int main(int argc, char *argv[]){
    char sOutput1[100] = "";
    char sOutput2[100] = "";
    char sInput[100] = "";

    printf("Input:  ");
    fgets(sInput, 100, stdin);

    switchWord(sInput, sOutput1, "zehn", "sechs");
    switchWord(sOutput1, sOutput2, "Zehn", "Sechs");

    printf("Output: %s\n", sOutput2);
}
