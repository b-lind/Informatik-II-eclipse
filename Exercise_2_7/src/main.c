#include <stdio.h>

typedef struct {
    int iKontonummer;
    int iPin;
    float iKontostand;
} Konto_t;

int chooseAction(Konto_t konto);

int chooseAction(Konto_t konto) {
	printf("Bitte wählen Sie eine Aktion.\n");
	printf("1. Kontostand\n2. Geld abheben\n3. Geld einzahlen\n0. Abbrechen\n");

	int iAction;
	scanf("%d", &iAction);

	switch(iAction) {
		case 1:
			printf("Ihr aktueller Kontostand: %f€\n\n", konto.iKontostand);
			break;
		case 2:
			printf("Wie viel Geld möchten Sie abheben?\n");
			float fDeposit = 0;
			scanf("%f", &fDeposit);
			konto.iKontostand -= fDeposit;
			printf("Ihr neuer Kontostand: %f€\n\n", konto.iKontostand);
			break;
		case 3:
			printf("Wie viel Geld möchten Sie einzahlen?\n");
			float fInput = 0;
			scanf("%f", &fInput);
			konto.iKontostand += fInput;
			printf("Ihr neuer Kontostand: %f€\n\n", konto.iKontostand);
			break;
		case 0:
			return 0;
		default:
			printf("Aktion nicht unterstützt.\n");
	}

	return chooseAction(konto);
}

int checkCredentials(Konto_t konto);

int pinfalseC = 0;
int checkCredentials(Konto_t konto) {
    printf("Bitte geben Sie ihre PIN ein: ");
    int iInput;
    scanf("%d", &iInput);

    if(iInput != konto.iPin) {
        pinfalseC++;

        printf("PIN falsch! %d Versuche verbleibend!\n", 3 - pinfalseC);

        if(pinfalseC == 3) {
        	printf("Ihr Account wurde gesperrt.");
            return -1;
        }
        else {
        	return checkCredentials(konto);
        }
    }
    else {
    	printf("Willkommen!\n");
		return chooseAction(konto);
    }
}

int main(int argc, char *argv[]){
	Konto_t konto1;

	konto1.iKontonummer = 12345;
	konto1.iPin = 1234;
	konto1.iKontostand = 1234.5;

	Konto_t konto2;

	konto2.iKontonummer = 54321;
	konto2.iPin = 4321;
	konto2.iKontostand = 436735.5;

	Konto_t konten[2] = { konto1, konto2 };

	printf("Willkommen bei der Sparkasse Hannover!\nBitte geben Sie ihre Kontonummer ein.\n");

	int iAccountNumber = 0;

	scanf("%d", &iAccountNumber);

	int i;
	for(i = 0; i < sizeof(konten)/sizeof(konten[0]); i++) {
		if((*(konten+i)).iKontonummer == iAccountNumber) {
			return checkCredentials(*(konten+i));
		}
	}

	printf("Kontonummer nicht bekannt.\n");
}
