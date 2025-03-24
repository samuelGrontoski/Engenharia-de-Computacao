#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int main(void){

    /*int x = 15;
    int *p, *pi;

    p = &x;

    *p = 18;

    printf("%i\n", x);
    printf("%i\n", &x);
    printf("%i\n", p);
    printf("%i\n", *p);
    printf("%i\n", &p);*/

    /*int a = 10, b = 15;
    int *pa = &a;
    char c = 'A';
    char *pc = &a;

    pc--;
    pa++;

    troca(&a, &b);

    printf("a=%d b=%d\n", a, b);*/

    int v[5] = {1,2,3,4,5};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(v+i));
        printf("%d\n", (v+i));
    }
    
    return 0;
}