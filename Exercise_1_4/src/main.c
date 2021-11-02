#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){

	//const double pi = 3.1415;

	int dRadius, dHeightCone, dHeightCylinder;

	printf("Radius [m]:\n");
	scanf(" %d", &dRadius);

	printf("Height Cone [m]:\n");
	scanf("%d", &dHeightCone);

	printf("Height Cylinder [m]:\n");
	scanf("%d", &dHeightCylinder);

	double dBasePlane = M_PI * pow(dRadius, 2);

	double dVolumeCone = (1.0 / 3.0) * dBasePlane * dHeightCone;

	double dS = sqrt(pow(dRadius, 2) + pow(dHeightCone, 2));
	double dSurfaceCone = M_PI * dRadius * dS; // ohne dBasePlane, da zusammengesetzter Körper

	double dVolumeCylinder = dBasePlane * dHeightCylinder;
	double dSurfaceCylinder = dBasePlane + 2.0 * M_PI * dRadius * dHeightCylinder; // nur 1x dBasePlane, da zusammengesetzt

	printf("Volume [m^3]: %f\n", dVolumeCylinder + dVolumeCone);
	printf("Surface [m^2]: %f\n", dSurfaceCone + dSurfaceCylinder);

	return 0;
}
