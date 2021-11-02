#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	double dA, dB, dC;

	printf("Bitte geben Sie die Koeffizienten einer quadratische Gleichung der Form a*x²+b*x+c=0 an.\n");

	printf("a = "); scanf("%lf", &dA);
	printf("b = "); scanf("%lf", &dB);
	printf("c = "); scanf("%lf", &dC);

	//printf("%lf %lf %lf", dA, dB, dC);

	if(dA == 0 && dB == 0) {
		printf("x = %lf\n", -1.0 * dC);
	}
	else if(dA == 0) {
		printf("x = %lf\n", -1.0 * dC / dB);
	}
	else {
		double p = dB / dA;
		double q = dC / dA;
		double dD = pow(p / 2.0, 2.0) - q;

		if(dD < 0) {
			double drX = -0.5 * p;
			double diX = sqrt(dD * -1.0);

			printf("x1 = %lf + %lf i\n", drX, diX);
			printf("x1 = %lf - %lf i\n", drX, diX);
		}
		else {
			double dX1 = -0.5 * p + sqrt(dD);
			double dX2 = -0.5 * p - sqrt(dD);

			printf("x1 = %lf\n", dX1);
			printf("x2 = %lf\n", dX2);
		}
	}

}
