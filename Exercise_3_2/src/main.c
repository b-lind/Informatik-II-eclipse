#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void concatStrings(char *sOutput, int iCount, ...);

void concatStrings(char *sOutput, int iCount, ...) {
    va_list argList;
    va_start(argList, iCount);

    int i;
    for(i = 0; i < iCount; i++) {
        strcat(sOutput, va_arg(argList, char*));
    }

    va_end(argList);
}

int main(int argc, char *argv[]){
    char sOut[100] = "";

    // &sOut nicht notwendig da sOut bereits Pointer auf erstes Feld
    concatStrings(sOut, 3, "One", "Two", "Three\n");

    printf("%s", sOut);
}
