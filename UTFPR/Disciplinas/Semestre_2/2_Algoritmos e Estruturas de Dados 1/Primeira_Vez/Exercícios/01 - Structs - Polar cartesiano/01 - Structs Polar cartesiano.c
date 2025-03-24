#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    float r;
    float a;
} ponto;

int main() {
    ponto a;

    scanf("%f", &a.r);
    scanf("%f", &a.a);

    a.x = a.r * cos(a.a);

    a.y = a.r * sin(a.a);

    printf("%.1f\n", a.x);
    printf("%.1f\n", a.y);

    return 0;
}
