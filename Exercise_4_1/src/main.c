#include <stdio.h>
#include <string.h>

#define STR_LEN 100


int stringlen(char *sIn);

int stringlen(char *sIn) {
    int i = 0;

    while (*(sIn+i) != 0)
    {
        i++;
    }

    return i;
}

int main(int argc, char *argv[]){
    
    char sInput[STR_LEN] = "";

    printf("Input: ");
    
    fgets(sInput, STR_LEN, stdin);

    printf("Länge: %d\n", stringlen(sInput));
}
