#include <stdio.h>
#include <stdint.h>

#include "ComplexNumbers.h"

int main(int argc, char *argv[]){

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int iNumberOfObjects = 0;

	/*
	 * Open input and output file
	 */
	FILE *inputFile = fopen("resources/ComplexNumbersCartesian.txt","r");
	FILE *outputFile = fopen("resources/ComplexNumbersPolar.txt","w");

	/*
	 * Determine number of lines
	 */
	while ((read = getline(&line, &len, inputFile)) != -1) {
		iNumberOfObjects++;
	}

	free(line);

	/*
	* Set cursor back to beginnng of file
	*/
	fseek(inputFile, 0, SEEK_SET);

	/*
	 * Create objects
	 */

	ComplexNumber_t *pComplexNumbers = ComplexNumber_create(iNumberOfObjects);

	/*
	 * Read data and fill objects
	 */
	double dRealPart;
	double dImaginaryPart;

	for(int i=0;i<iNumberOfObjects;i++){

		fscanf(inputFile,"%lf%lfi",&dRealPart,&dImaginaryPart);

		//printf("%lf %lf\n\r",dRealPart,dImaginaryPart);
		ComplexNumber_setCartesian(&pComplexNumbers[i],dRealPart,dImaginaryPart);

	}

	/*
	 * Convert objects and write them to file
	 */
	for(int i=0;i<iNumberOfObjects;i++){

		double dRadius;
		double dAngle;

		if(ComplexNumber_getPolarParameters(&pComplexNumbers[i],&dRadius,&dAngle) == 0){

			fprintf(outputFile,"%lf * exp(%lfi)\n",dRadius, dAngle);

		}else{

			fprintf(outputFile,"Not clearly defined!\n");

		}

	}

	fclose(inputFile);
	fclose(outputFile);


	return 0;
}
