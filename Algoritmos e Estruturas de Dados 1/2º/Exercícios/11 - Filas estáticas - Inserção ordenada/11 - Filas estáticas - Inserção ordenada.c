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
            f->ini = f->fim = 0;
        else if (f->fim < TAM_MAX - 1)
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
        f->tam--;

    if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }else if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;
    }

    return item;
}

int verificar_inicio(Fila *f){
    if (!fila_vazia(f))
        return f->item[f->ini];
    else
        return INT_MIN;
}

int verificar_fim(Fila *f){
    if (!fila_vazia(f))
        return f->item[f->fim];
    else
        return INT_MIN;
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

Fila* inserir_ordenado (int chave, Fila *f){
    Fila *aux = criar_fila();
    
    while (!fila_vazia(f) && (chave < verificar_inicio(f)))
        enfileirar(aux, desenfileirar(f));
    
    enfileirar (aux, chave);
    
    while(!fila_vazia(f))
        enfileirar(aux, desenfileirar(f));
    
    free(f);
    
    return aux;
}

int main() {
    Fila *f = criar_fila();
    int aux = 0;
    
    while (aux != -1){
        scanf("%d", &aux);
        
    if (aux != -1)
        f = inserir_ordenado(aux, f);
    }
    
    imprimir_fila(f);
    
    liberar_fila;
    
    return 0;
}
