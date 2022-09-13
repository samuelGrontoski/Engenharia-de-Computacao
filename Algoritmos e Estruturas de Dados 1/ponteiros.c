#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main ()
{
    void *p;
    int i = 10;
    char c = 'a';
    char b;

    p = &i;
    printf("%x\n", p);
    printf("%d\n", i);
    
    p = &c;
    b = *(char*)p;

    printf("%x\n", p);
    printf("%c\n", c);
    printf("%c\n", *(char*)p);


    return 0;
}