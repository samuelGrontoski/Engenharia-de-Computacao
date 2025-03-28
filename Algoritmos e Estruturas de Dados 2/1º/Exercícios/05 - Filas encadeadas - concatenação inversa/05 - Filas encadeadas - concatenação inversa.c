#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct Cell{
    int item;
    Cell *next;
}Cell;

typedef struct FilaE{
    Cell *inicio;
    Cell *fim;
}FilaE;

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}

int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}

void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}

int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        if (f->inicio == NULL)
            f->fim = NULL;

        item = aux->item;

        free(aux);
    }

    return item;
}

int verificar_inicio(FilaE *f){
    if (!filaE_vazia(f))
        return f->inicio->item;
    else
        return INT_MIN;
}

int verificar_fim(FilaE *f){
    if (!filaE_vazia(f))
        return f->fim->item;
    else
        return INT_MIN;
}

void imprimir_fila(FilaE *f){
    Cell *aux;
    
    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}

int liberar_filaE(FilaE *f){
    if (!filaE_vazia(f)){
        while (!filaE_vazia(f))
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

void inverter_fila(FilaE *f){
    if(filaE_vazia(f)){
        return;
    }
    
    Cell* aux1 = NULL;
    Cell* aux2 = f->inicio;
    Cell* next = NULL;

    f->fim = f->inicio;

    while (aux2 != NULL) {
        next = aux2->next;
        aux2->next = aux1;
        aux1 = aux2;
        aux2 = next;
    }

    f->inicio = aux1;
}

FilaE* concatenar_filas(FilaE *f1, FilaE *f2) {
    FilaE* f3 = criar_filaE();

    Cell* aux = f1->inicio;
    while (aux != NULL) {
        enfileirar(aux->item, f3);
        aux = aux->next;
    }

    aux = f2->inicio;
    while (aux != NULL) {
        enfileirar(aux->item, f3);
        aux = aux->next;
    }

    return f3;
}

int main() {
    FilaE *f1 = criar_filaE();
    FilaE *f2 = criar_filaE();
    int aux = 0;
    
    while(aux != -1){
        scanf("%d", &aux);
        if(aux != -1)
            enfileirar(aux, f1);
    }
    
    aux = 0;
    
    while(aux != -1){
        scanf("%d", &aux);
        if(aux != -1)
            enfileirar(aux, f2);
    }
    
    inverter_fila(f1);
    inverter_fila(f2);

    FilaE *f3 = concatenar_filas(f1, f2);
    
    imprimir_fila(f3);
    
    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);
      
    return 0;
}
