#include <stdio.h>

int main(int argc, char *argv[]){
	int i, c;

	for(i = 1; i <= 10; i++) {
		for(c = 1; c <= 10; c++) {
			printf("%3d ", i*c);
		}
		printf("\n");
	}
}
