#include <stdio.h>

typedef struct {

	char* 			sManufacturer;
	char* 			sModel;
	unsigned int 	iYear;
	double 			dDisplacement;
	unsigned int 	iPower;
	unsigned int 	iTopSpeed;

} Automobile_t;

int printAutomobile(Automobile_t vehicle);

int printAutomobile(Automobile_t vehicle)
{
	printf("Manufacturer: 	%s\n", 	vehicle.sManufacturer);
	printf("Model: 		%s\n", 		vehicle.sModel);
	printf("Year: 		%d\n", 		vehicle.iYear);
	printf("Displacement: 	%f\n", 	vehicle.dDisplacement);
	printf("Power: 		%d\n", 		vehicle.iPower);
	printf("Top Speed: 	%d\n\n",	vehicle.iTopSpeed);

	return 0;
}

Automobile_t createVehicle(char* sManuf, char* sType, int iYear, double dDisp, int iPower, int iSpeed);

Automobile_t createVehicle(char* sManuf, char* sType, int iYear, double dDisp, int iPower, int iSpeed)
{
	Automobile_t vehicle;

	vehicle.sManufacturer	= sManuf;
	vehicle.sModel 			= sType;
	vehicle.iYear 			= iYear;
	vehicle.dDisplacement 	= dDisp;
	vehicle.iPower 			= iPower;
	vehicle.iTopSpeed 		= iSpeed;

	return vehicle;
}

int main(int argc, char *argv[]){

	Automobile_t vehicle1, vehicle2;

	vehicle1 = createVehicle(
			"Volkswagen",
			"Passat",
			2020,
			2.0,
			160,
			210);

	vehicle2 = createVehicle(
		"Porsche",
		"Type 356",
		1955,
		1.488,
		51,
		170);

	printf("Vehicle 1:\n");
	printAutomobile(vehicle1);

	printf("Vehicle 2:\n");
	printAutomobile(vehicle2);

	return 0;
}
