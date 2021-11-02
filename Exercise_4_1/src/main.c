#include <stdio.h>
#include <string.h>

#define STR_LEN 100

int stringlen(char *sIn);

int stringlen(char *sIn) {
    int i;

    for(i = 0; i < STR_LEN; i++) {
        // includes trailing newline
        if(*(sIn+i) == 0) // || *(sIn+i) == 10)
            return i;
    }

    return -1;
}

int main(int argc, char *argv[]){
    
    char sInput[STR_LEN] = "";

    printf("Input: ");
    
    fgets(sInput, STR_LEN, stdin);

    printf("Länge: %d\n", stringlen(sInput));
}
