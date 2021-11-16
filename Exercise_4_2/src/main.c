#include <stdio.h>
#include <string.h>

#define FILE_PATH_IN "./resources/hamlet.txt"
#define FILE_PATH_OUT "hamlet-result.txt"

// Datei hamlet.txt öffnen und Buchstaben getrennt nach Klein-/Großbuchstaben zählen
// Ergbenis in Datei schreiben

int main(int argc, char *argv[]){
    FILE *fInput;
    FILE *fOutput;
    
    int iUppers[26];
    int iLowers[26];

    memset(iUppers, 0, sizeof(iUppers));
    memset(iLowers, 0, sizeof(iLowers));

    fInput = fopen(FILE_PATH_IN, "r");

    if(fInput == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return -1;
    }
    
    char cChar;
        
    do {
        cChar = fgetc(fInput);

        if(cChar >= 65 && cChar <= 90)
            iUppers[cChar - 65] += 1;
        else if (cChar >= 97 && cChar <= 122)
            iLowers[cChar - 97] += 1;

    } while (cChar != EOF);

    fclose(fInput);

    fOutput = fopen(FILE_PATH_OUT, "w");

    if(fOutput == NULL) {
        printf("Fehler beim Öffnen der Ergebnisdatei. Fallback zu Standardausgabe.\n");
        fOutput = stdout;
    }

    int i;
    for(i = 0; i < 26; i++) {
        fprintf(fOutput, "%c: %d \t %c: %d\n", (char)(i+65), *(iUppers+i), (char)(i+97), *(iLowers+i));
    }

    fclose(fOutput);
}
