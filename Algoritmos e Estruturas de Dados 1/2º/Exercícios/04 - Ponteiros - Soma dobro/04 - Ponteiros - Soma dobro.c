#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void dobra_soma(float A, float B, float C, float *A_d, float *B_d, float *C_d){
    float soma;
    
    *A_d = (2*A);
    *B_d = (2*B);
    *C_d = (2*C);
    soma = *A_d + *B_d + *C_d;
    
    printf("A=%.1f B=%.1f C=%.1f SOMA=%.1f\n", *A_d, *B_d, *C_d, soma);
}

int main() {
    int N, i = 0;
    
    scanf("%d", &N);
    float A, B, C, A_d, B_d, C_d;
    
    do{
        scanf("%f %f %f", &A, &B, &C);
        dobra_soma(A, B, C, &A_d, &B_d, &C_d);
        i++;
    }while(i < N);
    
    return 0;
}
