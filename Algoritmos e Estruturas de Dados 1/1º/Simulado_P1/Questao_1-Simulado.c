#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// a

flaot *multiplicar(float *f1, float *f2){
    float *p = malloc(sizeof(float));

    *p = (*f1) * (*f2);;

    return p;
}

int main() {
    int a = 10, b = 5;

    int *c = multiplicar(&a, &b);

    return 0;
}

// b

typedef struct P3D{
    int x, y, z;
}P3D;
typedef struct Ponto3D{
    int x, y, z;
}Ponto3D;

int main () {
    Ponto3D a = {1,2,3};
    Ponto3D b;
    P3D c = {3,2,1};
    P3D *p1 = &c;
    Ponto3D *p2 = &a;
    b = a;

    return 0;
}
