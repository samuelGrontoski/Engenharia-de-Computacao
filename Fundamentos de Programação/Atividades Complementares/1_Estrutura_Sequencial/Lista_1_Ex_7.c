#include <stdio.h>
#include <math.h>

int main (void) {

    float x, y, resultado;

    printf ("Informe o valor para X: ");
    scanf ("%f", &x);
    printf ("Informe o valor para Y: ");
    scanf ("%f", &y);

    resultado = ((x+y)/y) * pow(5,2);
    printf ("a) %f\n", resultado);

    resultado = (x+y)/(x-y);
    printf ("b) %f\n", resultado);

    resultado = (pow(x,2) + pow(y,3))/2;
    printf ("c) %f\n", resultado);

    resultado = pow(x,3)/pow(y,2);
    printf ("d) %f\n", resultado);

    resultado = (int)x % (int)y;
    printf ("e1) %.0f\n", resultado);

    resultado = (int)x % 3;
    printf ("e2) %.0f\n", resultado);

    resultado = (int)y % 5;
    printf ("e3) %.0f\n", resultado);

    return 0;
}
