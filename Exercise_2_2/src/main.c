#include <stdio.h>


int main(int argc, char **argv) {
	unsigned int iNum = 0;

	printf("Bitte geben Sie eine Zahl ein: \n");
	scanf("%d", &iNum);

	int iPrintSwitch = 0;

	int iNibble[4] = { 0, 0, 0, 0 };

	int i;

	for(i = 0; i < 32; i++) {

		if(i % 4 == 0 && i != 0 && iPrintSwitch == 1) {
			printf("%d%d%d%d ", *iNibble, *(iNibble+1), *(iNibble+2), *(iNibble+3));
	    }

	    *(iNibble + (i % 4)) = (iNum >> (31 - i)) & 1;

	    if(*(iNibble + (i % 4)) == 1) {
	    	iPrintSwitch = 1;
	    }
	}

	printf("%d%d%d%d \n", *iNibble, *(iNibble+1), *(iNibble+2), *(iNibble+3));
}


