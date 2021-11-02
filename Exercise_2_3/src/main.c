#include <stdio.h>

int heinz(int i) {
    return ((i >> 3) & 1);
}

int frieda(int i) {
    return ((i >> 2) & 1);
}

int alexander(int i) {
    return ((i >> 1) & 1);
}

int sophie(int i) {
    return (i & 1);
}


int main(int argc, char *argv[]){

	int i;

	for(i = 0; i < 16; i++) {

		printf("%d%d%d%d: ", heinz(i), frieda(i), alexander(i), sophie(i));

	    if(i == 0) {
	    	printf("Impossible, violates rule 1\n");
	    }
	    else if(heinz(i) && alexander(i)) {
	    	printf("Impossible, violates rule 2\n");
	    }
	    else if((frieda(i) && !sophie(i))) {
	    	printf("Impossible, violates rule 3\n");
	    }
	    else if((heinz(i) && sophie(i)) && frieda(i)) {
	    	printf("Impossible, violates rule 4\n");
	    }
	    else if(!heinz(i) && !(sophie(i) ^ alexander(i))) {
	    	printf("Impossible, violates rule 5\n");
	    }
	    else {
	    	printf("Possible \n");
	    }
	}

	return 0;
}
