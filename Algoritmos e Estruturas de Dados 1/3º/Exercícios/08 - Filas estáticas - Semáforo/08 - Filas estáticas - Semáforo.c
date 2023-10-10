#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 100

typedef struct{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
}Fila;


Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}


int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}


int enfileirar(Fila *f, int chave){
    if (f == NULL)
        f = criar_fila();
    
    if (!fila_cheia(f)){
        if (f->ini < 0)
            f->ini = 0;
        
        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }
    
    return 0;
}


int desenfileirar(Fila *f){
    int item = INT_MIN;

    if (!fila_vazia(f)){
        item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}


void imprimir_fila(Fila *f){
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }
    
    printf("\n");
}

void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

Fila *f_rodovia(Fila *est1, Fila *est2, Fila *est3, Fila *R){
    int i=0, aux;
    
    while (!fila_vazia(est1) || !fila_vazia(est2) || !fila_vazia(est3))
    {
        i=0;
        while ((i < 3) && (!fila_vazia(est1))){
            aux = desenfileirar(est1);
            if(aux != 0){
                enfileirar(R, aux);
                i++;
            }
        }
        
        i=0;
        while ((i < 3) && (!fila_vazia(est2))){
            aux = desenfileirar(est2);
            if(aux != 0){
                enfileirar(R, aux);
                i++;
            }
        }
            
        i=0;
        while ((i < 3) && (!fila_vazia(est3))){
            aux = desenfileirar(est3);
            if(aux != 0){
                enfileirar(R, aux);
                i++;
            }
        }
    }
    return R;
}

int main() 
{
    int aux;
    Fila *est1, *est2, *est3;
    Fila *R;
    
    est1 = criar_fila();
    est2 = criar_fila();
    est3 = criar_fila();
    
    do
    {
        scanf("%d", &aux);
        if(aux != -1)
            enfileirar(est1, aux);
    }while(aux != -1);
    
    do
    {
        scanf("%d", &aux);
        if(aux != -1)
            enfileirar(est2, aux);
    }while(aux != -1);
    
    do
    {
        scanf("%d", &aux);
        if(aux != -1)
            enfileirar(est3, aux);
    }while(aux != -1);
    
    R = criar_fila();
    R = f_rodovia(est1,est2,est3,R);
    imprimir_fila(R);
    
    liberar_fila(est1);
    liberar_fila(est2);
    liberar_fila(est3);
    liberar_fila(R);
    
    return 0;
}