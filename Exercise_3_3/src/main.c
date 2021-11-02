#include <stdio.h>

unsigned long calculateFibonacci(int iIndex);

unsigned long calculateFibonacci(int iIndex) {
    unsigned long iN1 = 1;
    unsigned long iN2 = 1;
    
    int i;
    for(i = 1; i < iIndex; i++) {
        if(i % 2 == 0)
            iN2 = iN1 + iN2;
        else
            iN1 = iN1 + iN2;
    }

    if(i % 2 == 0)
        return iN1;
    else
        return iN2;
}

int main(int argc, char *argv[]){
    printf("Fibbonacci Index: ");

    int iIndex;
    int iRet = scanf("%d", &iIndex);

    if(iIndex < 0 || iIndex > 49 || iRet != 1) {
        printf("Invalid Input\n");
        return -1;
    }

    printf("Fibonacci Number a_%d: %ld", iIndex, calculateFibonacci(iIndex));

    return 0;
}
