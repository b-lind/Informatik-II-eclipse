#include <stdio.h>
#include <math.h>

int calculateCube(double dSideLength, double *dVolume, double *dSurface);

int calculateCube(double dSideLength, double *dVolume, double *dSurface) {
    if(dSideLength >= 0) {
        *dVolume = pow(dSideLength, 3);
        *dSurface = dSideLength * dSideLength * 6;
        return 0;
    }
    else {
        return -1;
    }
}

int main(int argc, char *argv[]){
    printf("Side Length: ");

    double dSide, dVolume, dSurface;
    
    if(scanf("%lf", &dSide) != 1) {
        printf("Error: Invalid Syntax\n");
        return -1;
    }

    if(calculateCube(dSide, &dVolume, &dSurface) == 0) {
        printf("Volume: %lf\n", dVolume);
        printf("Surface: %lf\n", dSurface);

        return 0;
    }
    else {
        printf("Error: Invalid Side Length\n");
        return -1;
    }    
}
