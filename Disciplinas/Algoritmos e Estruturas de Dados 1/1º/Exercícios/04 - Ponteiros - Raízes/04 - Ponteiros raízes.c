#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void raizes(float A, float B, float C, float *X1, float *X2){
    float delta;

    delta = (pow(B, 2) - (4 * A * C));

    *X1 = ((-B) + sqrt(delta)) / (2*A);

    *X2 = ((-B) - sqrt(delta)) / (2*A);

    if(*X1 == -0.0)
        *X1 = 0.0;

    printf("%.1f %.1f",*X1, *X2);

}

int main() {

    float A, B, C, X1, X2;

    scanf("%f %f %f", &A, &B, &C);

    raizes(A, B, C, &X1, &X2);

    return 0;
}

