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
    
    pComplexNumer->dRealPart        = dRealPart;
    pComplexNumer->dImaginaryPart   = dImaginaryPart;
}

// Get Real and Imaginary Part
int ComplexNumber_getCartesianParameters(ComplexNumber_t *pComplexNumer,
			double *pdRealPart,
			double *pdImaginaryPart) {
    
    *pdRealPart         = pComplexNumer->dRealPart;
    *pdImaginaryPart    = pComplexNumer->dImaginaryPart;

	return 0;
}

// Get Polar representation of complex number
int ComplexNumber_getPolarParameters(ComplexNumber_t *pComplexNumer,
			double *pdRadius,
			double *pdAngle) {
	
	if(pComplexNumer->dImaginaryPart == 0 && pComplexNumer->dRealPart == 0)
		return -1;

	*pdRadius = sqrt(pow(pComplexNumer->dRealPart, 2) + pow(pComplexNumer->dImaginaryPart, 2));

	// real part == 0: 90 oder -90
	// imag part == 0: 0 oder 180
	// sonst: atan ggf mit offset
	*pdAngle = atan(pComplexNumer->dImaginaryPart / pComplexNumer->dRealPart);
}


// Add two complex numbers
int ComplexNumber_add(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

    pComplexNumerResult->dRealPart      = pComplexNumerOne->dRealPart       + pComplexNumerTwo->dRealPart;
    pComplexNumerResult->dImaginaryPart = pComplexNumerOne->dImaginaryPart  + pComplexNumerTwo->dImaginaryPart;

	return 0;
}

// Subtract two complex numbers
int ComplexNumber_sub(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {
    
    pComplexNumerResult->dRealPart      = pComplexNumerOne->dRealPart       - pComplexNumerTwo->dRealPart;
    pComplexNumerResult->dImaginaryPart = pComplexNumerOne->dImaginaryPart  - pComplexNumerTwo->dImaginaryPart;

	return 0;
}

// Multiply two complex numbers
int ComplexNumber_mul(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

}

// // Divide two complex numbers
int ComplexNumber_div(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

}
