#include <stdio.h>

int main(int argc, char *argv[]){

	unsigned int iNum;

	printf("Bitte geben Sie eine Zahl ein: \n");
	scanf("%d", &iNum);

	int i;

	if(iNum == 0 || iNum == 1) {
		printf("Not a prime number. By definition.\n");
	}
	else {

		for(i = 2; i < iNum; i++) {
			if(iNum % i == 0) {
				printf("Not a prime number. Divisible by %d\n", i);
				return 0;
			}
		}

		printf("Prime Number\n");
	}

	return 0;
}
