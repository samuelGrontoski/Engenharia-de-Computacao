#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int *v; 
    int n; 
    int q;  
}Vetor;

Vetor* iniciar(int n){
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));

    v->n = n;

    v->v = (int*) malloc(sizeof(int) * n);
    
    v->q = 0;

    return v;
}

int inserir(Vetor *v, int x){
    
    if((v != NULL) && (v->q < v->n)){
        v->v[v->q] = x;
        v->q++;
        
        return 1;
    }
    
    return 0;   
}

Vetor* concatenar(Vetor *v1, Vetor *v2){
    Vetor *v3 = NULL;
    int i;
    
    if(v1 == NULL)
        return v2;
    else if(v2 == NULL)
        return v1;
    else{
        v3 = iniciar(v1->q + v2->q);
        
        for(i=0; i<v1->q; i++)
            inserir(v3, v1->v[i]);
        for(i=0; i<v2->q; i++)
            inserir(v3, v2->v[i]);
        
        return v3;
    }
}

Vetor* soma(Vetor *v1, Vetor *v2){
    int nMaior, nMenor, i;
    Vetor *v3;

    if (v1->n > v2->n){
        nMaior = v1->n;
        nMenor = v2->n;
    }else{
        nMaior = v2->n;
        nMenor = v1->n;
    }

    v3 = iniciar(nMaior);

    for (i = 0; i < nMenor; i++)
        v3->v[i] = v1->v[i] + v2->v[i];

    for (i = nMenor; i < v1->n; i++)
        v3->v[i] = v1->v[i];

    for (i = nMenor; i < v2->n; i++)
        v3->v[i] = v2->v[i];
    
    if (v1->n > v2->n){
        v3->q = v1->q;
        v3->n = v1->n;
    }else{
        v3->q = v2->q;
        v3->n = v2->n;
    }

    return v3;
}

void imprimir(Vetor *v){
    int i;
    
    if(v != NULL){
        for(i=0; i<v->q; i++)
            printf("%d ", v->v[i]);
        
        printf("\n");
    }
}

int main() {
    
    Vetor *a, *b, *v1, *v2;
    int i, n, x;
    
    scanf("%d", &n);
    a = iniciar(n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        inserir(a, x);   
    }
    
    scanf("%d", &n);
    b = iniciar(n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        inserir(b, x);
    }
    
    v1 = iniciar(a->n + b->n);
    v1 = concatenar(a, b);
    imprimir(v1);
    
    v2 = soma(a, b);
    imprimir(v2);
    
    
    return 0;
}
