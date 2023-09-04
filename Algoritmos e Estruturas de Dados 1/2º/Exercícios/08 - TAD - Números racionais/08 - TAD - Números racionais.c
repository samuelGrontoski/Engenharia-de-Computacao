#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num, den;
}RAC;

void simplificar(RAC *r){
    int i, ax = r->num, aux = 0;
    if(r->num != 0 && r->den > 2){
        if(r->num < r->den){
            ax = r->den;
        }
        for(i = 2; i < ax; i++){
            if(r->num % i == 0 && r->den % i == 0){
                aux = i;
            }
        }
        if(aux != 0){
            r->num = r->num / aux;
            r->den = r->den / aux;
        }
    }
};

RAC *criar(int num, int den){
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->num = num;
    r->den = den;
    
    return r;
};

RAC *somar(RAC *r1, RAC *r2){
    
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->den = r1->den * r2->den;
    r->num = ((r->den / r1->den) * r1->num) + ((r->den / r2->den) * r2->num);
    
    if(r->den < 0){
        r->num *= (-1);
        r->den *= (-1);
    }
    simplificar(r);
    
    return r;
};

RAC *subtrair(RAC *r1, RAC *r2){
    
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->den = r1->den * r2->den;
    r->num = ((r->den / r1->den) * r1->num) - ((r->den / r2->den) * r2->num);
    
    if(r->den < 0){
        r->num *= (-1);
        r->den *= (-1);
    }
    simplificar(r);
    
    return r;
};

RAC *multiplicar(RAC *r1, RAC *r2){
    RAC *r = (RAC*) malloc(sizeof(RAC));
    
    r->num = r1->num * r2->num;
    r->den = r1->den * r2->den;
    
    if(r->den < 0){
        r->num *= (-1);
        r->den *= (-1);
    }
    
    return r;
};

RAC *dividir(RAC *r1, RAC *r2){
    RAC *r = (RAC*) malloc(sizeof(RAC));
    
    r->num = r1->num * r2->den;
    r->den = r1->den * r2->num;
    
    if(r->den < 0){
        r->num *= (-1);
        r->den *= (-1);
    }
    
    return r;
};

int main() {
    int num, den;
    
    RAC *r1;
    RAC *r2;
    RAC *r_soma;
    RAC *r_sub;
    RAC *r_mult;
    RAC *r_div;
    
    //entrada
    scanf("%d %d", &num, &den);
    r1 = criar(num, den);
    
    scanf("%d %d", &num, &den);
    r2 = criar(num, den);
    
    //processos
    r_soma = somar(r1, r2);
    r_sub = subtrair(r1, r2);
    r_mult = multiplicar(r1, r2);
    r_div = dividir(r1, r2);
    
    //saida
    printf("r1: %d/%d\n", r1->num, r1->den);
    printf("r2: %d/%d\n", r2->num, r2->den);
    printf("r1+r2=%d/%d\n", r_soma->num, r_soma->den);
    printf("r1-r2=%d/%d\n", r_sub->num, r_sub->den);
    printf("r1*r2=%d/%d\n", r_mult->num, r_mult->den);
    printf("r1/r2=%d/%d\n", r_div->num, r_div->den);
        
    return 0;
}
