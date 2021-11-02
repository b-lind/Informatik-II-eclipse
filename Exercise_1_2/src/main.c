#include <stdio.h>

int main(int argc, char *argv[]){

	printf("Bitte geben Sie eine ganze Zahl ein:\n");

	int iInput;

	scanf("%d", &iInput);

	printf("Dez: %d, ASCII: %c, Oct: %o, Hex: %#x\n", iInput, (char)iInput, iInput, iInput);

	return 0;
}
