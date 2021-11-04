#include <ComplexNumbers.h>

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
}

// Get Polar representation of complex number
int ComplexNumber_getPolarParameters(ComplexNumber_t *pComplexNumer,
			double *pdRadius,
			double *pdAngle) {

}


// Add two complex numbers
int ComplexNumber_add(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {

    pComplexNumerResult->dRealPart      = pComplexNumerOne->dRealPart       + pComplexNumerTwo->dRealPart;
    pComplexNumerResult->dImaginaryPart = pComplexNumerOne->dImaginaryPart  + pComplexNumerTwo->dImaginaryPart;
}

// Subtract two complex numbers
int ComplexNumber_sub(ComplexNumber_t *pComplexNumerResult,
			ComplexNumber_t *pComplexNumerOne,
			ComplexNumber_t *pComplexNumerTwo) {
    
    pComplexNumerResult->dRealPart      = pComplexNumerOne->dRealPart       - pComplexNumerTwo->dRealPart;
    pComplexNumerResult->dImaginaryPart = pComplexNumerOne->dImaginaryPart  - pComplexNumerTwo->dImaginaryPart;
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
