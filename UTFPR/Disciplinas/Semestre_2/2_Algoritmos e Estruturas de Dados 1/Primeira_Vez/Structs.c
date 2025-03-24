#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int dia, mes, ano;
}Nasc;

typedef struct {
    char Nome[101];
    int RA;
    float coef;
    Nasc data_nasc;
}Aluno;

int main () {
    
    Nasc a;
    a.dia = 26;
    a.mes = 02;
    a.ano = 2003;

    Aluno a1;
    strcpy(a1.Nome, "Samuel");
    a1.RA = 2018098;
    a1.coef = 0.75;

    printf("%s\n", a1.Nome);
    printf("%d\n", a1.RA);
    printf("%.2f\n", a1.coef);
    printf("%d/%d/%d\n", a.dia, a.mes, a.ano);

    return 0;
}