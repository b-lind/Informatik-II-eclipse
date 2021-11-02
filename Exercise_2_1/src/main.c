#include <stdio.h>

int main(int argc, char *argv[]){
    int iNum = 0;

    printf("Bitte geben Sie eine Zahl ein: \n");
    scanf("%d", &iNum);

    int iCount = 0;

    int i;
    for(i = 0; i < 32; i++) {
        if(((iNum >> i) & 1) == 1) {
            iCount++;
        }
    }

    printf("%d\n", iCount);
}
