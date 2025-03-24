#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

    int a = 10;
    int *pa = &a;
    void *p;

    p = &a;

    *pa = (int*) p;

    printf("%d", *pa);

    return 0;
}