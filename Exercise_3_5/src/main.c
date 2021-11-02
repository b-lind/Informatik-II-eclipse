#include <stdio.h>
#include <string.h>
#include <math.h>

long parseHexNumber(char *sIn);

long parseHexNumber(char *sIn) {
        
    if(*sIn != '0' || *(sIn+1) != 'x' || strlen(sIn) < 3) {
        return -1;
    }
    else {
        char sTrim[30] = "";
        strcpy(sTrim, sIn + 2);

        int iExp = strlen(sTrim) - 1;

        long iNum = 0;

        int i;
        for(i = 0; i < strlen(sTrim); i++) {
            if(*(sTrim + i) >= 48 && *(sTrim + i) <= 57) { 
                // 48 bis 57 => 0 bis 9
                iNum += (long)pow(16.0, (double)(iExp - i)) * (*(sTrim + i) - 48);
            }
            else if(*(sTrim + i) >= 65 && *(sTrim + i) <= 70) {  
                // 65 bis 70 => A bis F
                iNum += (long)pow(16.0, (double)(iExp - i)) * (*(sTrim + i) - 65 + 10);
            }
            else if(*(sTrim + i) >= 97 && *(sTrim + i) <= 102) { 
                // 97 bis 102 => a bis f
                iNum += (long)pow(16.0, (double)(iExp - i)) * (*(sTrim + i) - 97 + 10);
            }
            else {
                // invalid input
                return -1;
            }
        }

        return iNum;
    }
}

int main(int argc, char *argv[]){
    
    char sInput[32] = "";

    printf("Input: ");
    fgets(sInput, 32, stdin);

    char sTrimInput[32] = "";
    strncpy(sTrimInput, sInput, strlen(sInput) - 1);

    long iNum = parseHexNumber(sTrimInput);

    if(iNum != -1)
        printf("Decimal: %ld", iNum);
    else
        printf("Invalid Input");
}
