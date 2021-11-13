#include "ComplexNumbers.h"

int main(int argc, char *argv[]){
    ComplexNumber_t* pCN = ComplexNumber_create(1);

    ComplexNumber_delete(pCN);
}
