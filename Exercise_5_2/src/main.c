#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

typedef struct {
	char sGerman[MAX_STRING];
	char sEnglish[MAX_STRING];
} DictEntry_t;

int translate(DictEntry_t* dict, int iDictSize, char* input, char* output);

int main(int argc, char *argv[]) {

	FILE *dict = fopen("resources/dict_german_english.txt", "r");
	FILE *input = fopen("resources/german_input.txt", "r");
	FILE *output = fopen("resources/english_output.txt", "w");

	if (dict == NULL ||input == NULL || output == NULL) {
		fprintf(stderr, "Error opening file.");
		return -1;
	}

	// Determining Dictionary Entry Count

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	int iLines = 0;

	while ((read = getline(&line, &len, dict)) != -1) {
		iLines++;
	}

	rewind(dict);

	// Load Dictionary

	DictEntry_t* dictionary = calloc(iLines, sizeof(DictEntry_t));

	for(int i = 0; i < iLines; i++) {
		getline(&line, &len, dict);

		char* pChar = strchr(line, ':');

		strncpy((dictionary+i)->sGerman, line, pChar - line);
		strncpy((dictionary+i)->sEnglish, pChar + 1, strlen(line) - (pChar - line) - 2);
	}

	free(line);

	fclose(dict);

	// Read German Input & Translate

	fseek(input, 0, SEEK_END);
	int iLength = ftell(input);
	rewind(input);

	char* sInput = calloc(iLength + 1, sizeof(char));

	fgets(sInput, iLength + 1, input);

	char* pSpace = strchr(sInput, ' ');
	char* pOld = sInput;

	while(pSpace != NULL) {
		char* sNew = calloc(MAX_STRING, sizeof(char));
		char* sOld = calloc(MAX_STRING, sizeof(char));

		strncpy(sOld, pOld, pSpace - pOld);

		printf("%s\n", sOld);

		if(translate(dictionary, iLines, sOld, sNew) == 0) {
			fprintf(output, "%s ", sNew);
		}
		else {
			printf("No Translation for %s.\n", sOld);
			fprintf(output, "%s ", sOld);
		}

		free(sNew);
		free(sOld);

		pOld = pSpace + 1;
		pSpace = strchr(pOld, ' ');
	}

	free(sInput);
	free(dictionary);

	fclose(input);
	fclose(output);
}

int translate(DictEntry_t* dict, int iDictSize, char* input, char* output) {
	for(int i = 0; i < iDictSize; i++) {
		if(strcmp((dict+i)->sGerman, input) == 0) {
			strcpy(output, (dict+i)->sEnglish);
			return 0;
		}
	}

	return -1;
}
