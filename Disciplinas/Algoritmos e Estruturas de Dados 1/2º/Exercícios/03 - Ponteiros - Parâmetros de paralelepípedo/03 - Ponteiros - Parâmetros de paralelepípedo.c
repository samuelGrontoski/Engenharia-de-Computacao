#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void param_paralelepipedo (float alt, float larg, float compr, float *area, float *volume, float *compr_d){
    *area = (2 * alt * larg) + (2 * alt * compr) + (2 * larg * compr);
    *volume = alt * larg * compr;
    *compr_d = sqrtf(pow(alt,2) + pow(larg,2) + pow(compr,2));
}

int main() {
    float alt, larg, compr, area, volume, compr_d;
    
    scanf("%f %f %f", &alt, &larg, &compr);
    
    param_paralelepipedo(alt, larg, compr, &area, &volume, &compr_d);
    
    printf("area: %.1f\n", area);
    printf("volume: %.1f\n", volume);
    printf("comprimento da diagonal: %.1f\n", compr_d);
    
    return 0;
}
