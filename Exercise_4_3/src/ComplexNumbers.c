#include "ComplexNumbers.h"
#include <math.h>
#include <stdlib.h>


// Allocate Memory for num complex numbers
ComplexNumber_t *ComplexNumber_create(int num) {
    return (ComplexNumber_t*)calloc(num, sizeof(ComplexNumber_t));
}

// Free Memory
void ComplexNumber_delete(ComplexNumber_t *pComplexNumers) {
    free(pComplexNumers);
}


// Set Real and Imaginary Part
void ComplexNumber_setCartesian(ComplexNumber_t *pComplexNumer,
			double dRealPart,
			double dImaginaryPart) {
    
    if(pComplexNumer != NULL)
	{
		pComplexNumer->dRealPart        = dRealPart;
    	pComplexNumer->dImaginaryPart   = dImaginaryPart;
	}
}

// Get Real and Imaginary Part
int ComplexNumber_getCartesianParameters(ComplexNumber_t *pComplexNumer,
			double *pdRealPart,
			double *pdImaginaryPart) {
    
    if(pComplexNumer != NULL && pdRealPart != NULL && pdImaginaryPart != NULL)
	{
		*pdRealPart         = pComplexNumer->dRealPart;
    	*pdImaginaryPart    = pComplexNumer->dImaginaryPart;

		return 0;
	}
	else
		return -1;
}

// Get Polar representation of complex number
int ComplexNumber_getPolarParameters(ComplexNumber_t *pComplexNumer,
			double *pdRadius,
			double *pdAngle) {
	
	if(pComplexNumer == NULL || pdRadius == NULL || pdAngle == NULL)
		return -1;
	
	if(pComplexNumer->dImaginaryPart == 0 && pComplexNumer->dRealPart == 0)
		return -1;

	*pdRadius = sqrt(pow(pComplexNumer->dRealPart, 2.0) + pow(pComplexNumer->dImaginaryPart, 2.0));

	if(pComplexNumer->dRealPart == 0)
		*pdAngle = M_PI / 2.0;
	else if(pComplexNumer->dImaginaryPart == 0 && pComplexNumer->dRealPart < 0)
		*pdAngle = M_PI;
	else if(pComplexNumer->dImaginaryPart < 0)
		*pdAngle = -1.0 * atan(pComplexNumer->dImaginaryPart / pComplexNumer->dRealPart);
	else
		*pdAngle = atan(pComplexNumer->dImaginaryPart / pComplexNumer->dRealPart);

	return 0;
}


// Add two complex numbers
int ComplexNumber_add(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

	if(pComplexNumerOne == NULL || pComplexNumerTwo == NULL || pComplexNumerResult == NULL)
		return -1;

    pComplexNumerResult->dRealPart      = pComplexNumerOne->dRealPart       + pComplexNumerTwo->dRealPart;
    pComplexNumerResult->dImaginaryPart = pComplexNumerOne->dImaginaryPart  + pComplexNumerTwo->dImaginaryPart;

	return 0;
}

// Subtract two complex numbers
int ComplexNumber_sub(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {
    
	if(pComplexNumerOne == NULL || pComplexNumerTwo == NULL || pComplexNumerResult == NULL)
		return -1;

    pComplexNumerResult->dRealPart      = pComplexNumerOne->dRealPart       - pComplexNumerTwo->dRealPart;
    pComplexNumerResult->dImaginaryPart = pComplexNumerOne->dImaginaryPart  - pComplexNumerTwo->dImaginaryPart;

	return 0;
}

// Multiply two complex numbers
int ComplexNumber_mul(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

	if(pComplexNumerOne == NULL || pComplexNumerTwo == NULL || pComplexNumerResult == NULL)
		return -1;

	double a = pComplexNumerOne->dRealPart;
	double b = pComplexNumerOne->dImaginaryPart;

	double c = pComplexNumerTwo->dRealPart;
	double d = pComplexNumerTwo->dImaginaryPart;

	pComplexNumerResult->dRealPart = a*c - b*d;
	pComplexNumerResult->dImaginaryPart = a*d + b*c;

	return 0;
}

// // Divide two complex numbers
int ComplexNumber_div(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

	if(pComplexNumerOne == NULL || pComplexNumerTwo == NULL || pComplexNumerResult == NULL)
		return -1;

	double a = pComplexNumerOne->dRealPart;
	double b = pComplexNumerOne->dImaginaryPart;

	double c = pComplexNumerTwo->dRealPart;
	double d = pComplexNumerTwo->dImaginaryPart;

	if(c == 0 && d == 0)
		return -1;

	pComplexNumerResult->dRealPart = (a*c + b*d) / (c*c + d*d);
	pComplexNumerResult->dImaginaryPart = (b*c - a*d) / (c*c + d*d);

	return 0;
}
