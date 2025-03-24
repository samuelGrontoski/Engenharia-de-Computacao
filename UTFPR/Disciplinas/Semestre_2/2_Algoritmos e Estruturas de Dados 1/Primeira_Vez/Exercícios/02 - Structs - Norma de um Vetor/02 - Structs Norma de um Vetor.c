#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    float norm;
}vetor_t;

vetor_t calculaNorma(vetor_t vetor1){

    vetor1.norm = sqrt(pow(vetor1.x, 2) + pow(vetor1.y, 2));

    return vetor1;
}

int main(){
    int pontos, i;
    vetor_t a;

    scanf("%d", &pontos);

    for(i = 0; i < pontos; i++){
        scanf("%f %f", &a.x, &a.y);
        a = calculaNorma(a);
        printf("Norma = %.1f\n", a.norm);
    }


    return 0;
}
