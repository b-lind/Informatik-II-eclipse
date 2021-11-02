#include <stdio.h>

int main(int argc, char *argv[]){

	printf("Equation:\n");

	int iOp1;
	int iOp2;
	char cOperator;

	int iReturn = scanf("%d %c %d", &iOp1, &cOperator, &iOp2);

	if(iReturn != 3)
	{
		printf("Error: Wrong Syntax!\n");
		return -1;
	}

	switch(cOperator)
	{
		case '+':
			printf("Result: %d %c %d = %d\n", iOp1, cOperator, iOp2, iOp1 + iOp2);
			break;
		case '-':
			printf("Result: %d %c %d = %d\n", iOp1, cOperator, iOp2, iOp1 - iOp2);
			break;
		case '*':
			printf("Result: %d %c %d = %d\n", iOp1, cOperator, iOp2, iOp1 * iOp2);
			break;
		case '/':
			if(iOp2 != 0)
				printf("Result: %d %c %d = %d\n", iOp1, cOperator, iOp2, iOp1 / iOp2);
			else
				printf("Error: Division through zero!\n");
			break;
		default:
			printf("Error: Unsupported operator %c!\n", cOperator);
	}

	return 0;
}
