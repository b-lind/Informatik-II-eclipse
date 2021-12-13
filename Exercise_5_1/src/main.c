#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	double dRadius;
	double dArea;
	double dCircumference;
} Circle_t;

int processData(char* data, Circle_t* circle);

int main(int argc, char *argv[]){

	FILE *input  = fopen("resources/Input.txt", "r");
	FILE *output = fopen("resources/Output.txt", "w");

	if(input == NULL || output == NULL) {
		fprintf(stderr, "Error opening file.");
		return -1;
	}

	// Determining Line Count

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	int iLines = 0;

	while ((read = getline(&line, &len, input)) != -1) {
		iLines++;
	}

	rewind(input);

	// Reading Lines & Calculating Data

	Circle_t* circles = calloc(iLines, sizeof(Circle_t));

	for(int i = 0; i < iLines; i++) {
		getline(&line, &len, input);
		int iErr = processData(line, circles+i);

		if(iErr == 0) {
			fprintf(output, "r=%.3lf F=%.3lf U=%.3lf\n", (circles+i)->dRadius, (circles+i)->dArea, (circles+i)->dCircumference);
		}
		else if(iErr == -1) {
			fprintf(output, "Error: Invalid Input\n");
		}
		else {
			fprintf(output, "Error: Invalid Syntax\n");
		}
	}

	fclose(input);
	fclose(output);

	free(circles);
	free(line);
}

int processData(char* data, Circle_t* circle) {

	double dRadius;

	int iErr = sscanf(data, "r=%lf", &dRadius);

	if(iErr == 1) {
		if(dRadius > 0) {
			circle->dRadius = dRadius;
			circle->dArea	= M_PI * dRadius * dRadius;
			circle->dCircumference = 2 * M_PI * dRadius;
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return -2;
	}
}
