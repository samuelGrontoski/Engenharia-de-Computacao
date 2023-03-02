#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};

struct FilaE{
    Cell *inicio;
    Cell *fim;
};

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
    int item = -INT_MAX;

    if (!filaE_vazia(f)){

        aux = f->inicio;

        f->inicio = aux->next;

        item = aux->item;

        free(aux);
    }

    return item;
}

void imprimir_fila(FilaE* f){
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

int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

FilaE* intercalar_filaE(FilaE *f1, FilaE *f2){
    int aux1, aux2;
    FilaE *f3 = criar_filaE();
    
    while (!filaE_vazia(f1) && !filaE_vazia(f2)){
        aux1 = desenfileirar(f1);
        aux2 = desenfileirar(f2);
        
        if (aux1 > aux2){
            enfileirar(aux1, f3);
            enfileirar(aux2, f3);
        }else{
            enfileirar(aux2, f3);
            enfileirar(aux1, f3);
        }
    }
    
    while(!filaE_vazia(f1))
        enfileirar(desenfileirar(f1), f3);
    
    while(!filaE_vazia(f2))
        enfileirar(desenfileirar(f2), f3);
    
    return f3;
}

int main() {
    int aux;
    
    FilaE *f1 = criar_filaE();
    FilaE *f2 = criar_filaE();
    FilaE *f3 = criar_filaE();
    
    aux = 0;
    while (aux != -1){
        scanf("%d ", &aux);
            
        if (aux != -1){
            enfileirar(aux, f1);
        }
    }
    
    aux = 0;
    while (aux != -1){
        scanf("%d ", &aux);
            
        if (aux != -1){
            enfileirar(aux, f2);
        }
    }
    
    f3 = intercalar_filaE(f1, f2);
    
    imprimir_fila(f3);
    
    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);
    
    return 0;
}
