#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_PATH "./resources/Input.txt"
#define OUTPUT_PATH "./resources/Output.txt"

/*
 * Struktur
 */
typedef struct {
	// FirstOperand
	int iFirstOperand;
	
	// SecondOperand
	int iSecondOperand;
	
	// Operation
	char cOperator;
	
	// Error Flag
	int iErrorFlag;
} Equation_t;

/*
 * Funktionen
 */
int determineNumberOfLines(FILE *pInputFile);
void readInputData(FILE *pInputFile, Equation_t *pEquations, int iNumberOfLines);
void processEquations(Equation_t *pEquations, int iNumberOfLines, FILE *pOutputFile);
char* transformDecimalToBinary(int iNumber);

/*
 * Main-Funktion
 */
int main(int argc, char *argv[]) {

	// Open Input and Output files
	FILE* pInput = fopen(INPUT_PATH, "r");
	FILE* pOutput = fopen(OUTPUT_PATH, "w");

	// Confirm if fopen(...) was successful
	if(pInput == NULL) {
		fprintf(stderr, "Fehler beim Öffnen der Eingabedatei.\n");
		return -1;
	}

	if(pOutput == NULL) {
		fprintf(stderr, "Fehler beim Öffnen der Ausgabedatei. Fallback zu Standardausgabe.\n");
		pOutput = stdout;
	}

	// Count lines in Input file and allocate the necessary memory
	int iLines = determineNumberOfLines(pInput);

	Equation_t* pEquations = calloc(iLines, sizeof(Equation_t));

	// Read equations from Input file
	readInputData(pInput, pEquations, iLines);

	// Calculate equations and write results to Output file
	processEquations(pEquations, iLines, pOutput);

	printf("%d equations from %s successfully evaluated.\n", iLines, INPUT_PATH);
	printf("Results written to %s\n", (pOutput == stdout) ? "standard output" : OUTPUT_PATH);

	// Cleanup
	free(pEquations);

	fclose(pInput);
	fclose(pOutput);

	return 0;
}

/*
 * Counts the number of lines in pInputFile
 */
int determineNumberOfLines(FILE *pInputFile) {
	
	if(pInputFile == NULL) {
		return -1;
	}
	
	char *pcLine = NULL;
	size_t iLen = 0;
	ssize_t iRead;

	int iLines = 0;

	while ((iRead = getline(&pcLine, &iLen, pInputFile)) != -1) {
		iLines++;
	}

	rewind(pInputFile);

	return iLines;
}

/*
 * Reads equations from pInputFile into pEquations
 */
void readInputData(FILE *pInputFile, Equation_t *pEquations, int iNumberOfLines) {

	char *pcLine = NULL;
	size_t iLen = 0;

	for(int i = 0; i < iNumberOfLines; i++) {
		getline(&pcLine, &iLen, pInputFile);

		int iFirstOp, iSecondOp = 0;
		char cOperator;

		int iRead = sscanf(pcLine, "%d %c %d", &iFirstOp, &cOperator, &iSecondOp);

		(pEquations + i)->iFirstOperand  = iFirstOp;
		(pEquations + i)->iSecondOperand = iSecondOp;
		(pEquations + i)->cOperator 	 = cOperator;

		if(iRead != 3) {
			(pEquations + i)->iErrorFlag = 1;
		}
		else {
			(pEquations + i)->iErrorFlag = 0;
		}
	}
}

/*
 * Validates and calculates equations and writes the results to pOutputFile
 */
void processEquations(Equation_t *pEquations, int iNumberOfLines, FILE *pOutputFile) {

	for(int i = 0; i < iNumberOfLines; i++) {
		
		int iResult = 0;

		if((pEquations+i)->iErrorFlag != 0) {
			fprintf(pOutputFile, "Syntax not correct!\n");
		}
		else {
			switch((pEquations+i)->cOperator) {
				case '+':
					iResult = (pEquations+i)->iFirstOperand + (pEquations+i)->iSecondOperand;
					break;
				case '-':
					iResult = (pEquations+i)->iFirstOperand - (pEquations+i)->iSecondOperand;
					break;
				case '*':
					iResult = (pEquations+i)->iFirstOperand * (pEquations+i)->iSecondOperand;
					break;
				case '/':
					if((pEquations+i)->iSecondOperand != 0) {
						iResult = (pEquations+i)->iFirstOperand / (pEquations+i)->iSecondOperand;
					}
					else {
						fprintf(pOutputFile, "Division through zero!\n");
						continue;
					}					
					break;
				default:
					fprintf(pOutputFile, "Unknown operator!\n");
					continue;
					break;
			}

			char* pcBinary = transformDecimalToBinary(iResult);

			fprintf(pOutputFile, "%s\n", pcBinary);

			free(pcBinary);
		}
	}
}

/*
 * Transforms a given integer into its 8bit binary representation
 */
char* transformDecimalToBinary(int iNumber) {

	char* pcBinary = calloc(9, sizeof(char));

	int iMask = 128;

    for(int i = 0; i < 8; i++) {
        *(pcBinary + i) = ((iNumber & iMask) != 0) ? '1' : '0';
		iMask /= 2;
    }

    // Add zero-termination
    *(pcBinary+8) = '\0';

	return pcBinary;
}
