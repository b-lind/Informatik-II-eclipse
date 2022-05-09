#include <stdio.h>

int main(void) {
    unsigned int iNum = 0;
    
    printf("Bitte geben Sie eine Zahl ein: \n");
    scanf("%d", &iNum);

    int i, i2;

    int iMaske = 15;

    if(iNum == 0) {
        printf("0000");
        return 0;
    }

    for(i = 7; i >= 0; i--) {
        if((iNum & (iMaske << (4*i))) != 0) {
            for(i2 = 0; i2 < (i+1)*4; i2++) {
                if(i2 % 4 == 0 && i2 != 0) {
                    printf(" ");
                }
        
                printf("%d", (iNum >> (((i+1)*4) - 1 - i2)) & 1);
            }
            
            break;
        }
    }

    return 0;
}