#ifndef INCLUDE_COMPLEXNUMBERS_H_
#define INCLUDE_COMPLEXNUMBERS_H_

#include <stdlib.h>
#include <math.h>

//
// Definition des Datentyps ComplexNumber_t
//
typedef struct{

	double dRealPart;
	double dImaginaryPart;

} ComplexNumber_t;

// ------------------------------------------------------------------------------
// Funktionsdeklarationen
// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_create
// Beschreibung : Reserviert Speicherplatz für insgesamt "num" komplexe Zahlen
// und gibt einen Pointer auf das Array zurück.
// Return : Pointer auf das Array von komplexen Zahlen, NULL bei Fehler
ComplexNumber_t *ComplexNumber_create(int num);

// ------------------------------------------------------------------------------
// Funktionsdeklarationen
// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_delete
// Beschreibung : Gibt den Speicherplatzt der komplexen Zahlen frei,
// die an der Adresse "*pComplexNumbers" stehen.
// Return : 0=Erfolg, -1=Fehler
void ComplexNumber_delete(ComplexNumber_t *pComplexNumers);

// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_setCartesian
// Beschreibung : Setz den realen und komplexen Teil der Zahl.
// Return : -
void ComplexNumber_setCartesian(ComplexNumber_t *pComplexNumer,
			double dRealPart,
			double dImaginaryPart);

// ------------------------------------------------------------------------------
// Funktionsdeklarationen
// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_getCartesianParameters
// Beschreibung : Gibt die Argumente der komplexen Zahl in der kartesischen Form
// zurück.
// Return : 0=Erfolg, -1=Fehler
int ComplexNumber_getCartesianParameters(ComplexNumber_t *pComplexNumer,
			double *pdRealPart,
			double *pdImaginaryPart);

// ------------------------------------------------------------------------------
// Funktionsdeklarationen
// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_getPolarParameters
// Beschreibung : Gibt die Argumente der komplexen Zahl in der Polarform zurück.
// Return : 0=Erfolg, -1=Fehler
int ComplexNumber_getPolarParameters(ComplexNumber_t *pComplexNumer,
			double *pdRadius,
			double *pdAngle);

// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_add
// Beschreibung : Addiert zwei komplexe Zahlen:
// 	pComplexNumberResult = pComplexNumerOne + pComplexNumerTwo
// Return : 0=Erfolg, -1=Fehler
int ComplexNumber_add(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo);

// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_sub
// Beschreibung : Subtrahiert zwei komplexe Zahlen:
// 	pComplexNumberResult = pComplexNumerOne - pComplexNumerTwo
// Return : 0=Erfolg, -1=Fehler
int ComplexNumber_sub(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo);

// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_mul
// Beschreibung : Multipliziert zwei komplexe Zahlen:
// 	pComplexNumberResult = pComplexNumerOne * pComplexNumerTwo
// Return : 0=Erfolg, -1=Fehler
int ComplexNumber_mul(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo);

// ------------------------------------------------------------------------------
// Funktion : ComplexNumber_div
// Beschreibung : Dividiert zwei komplexe Zahlen:
// 	pComplexNumberResult = pComplexNumerOne / pComplexNumerTwo
// Return : 0=Erfolg, -1=Fehler
int ComplexNumber_div(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo);

#endif /* INCLUDE_COMPLEXNUMBERS_H_ */
