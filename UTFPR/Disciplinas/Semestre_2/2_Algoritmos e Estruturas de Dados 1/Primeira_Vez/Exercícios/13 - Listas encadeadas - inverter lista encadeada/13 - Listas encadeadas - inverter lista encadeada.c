#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    int item;
    Cell *next;
};

struct ListaE{
    Cell *head;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(int key, ListaE *l){
    Cell *aux;
    
    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void imprimir(ListaE *l){
    Cell *aux;

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

void inverterLista(Cell *head){
    Cell *prev = NULL;
    Cell *cur = head;
    
    while (cur != NULL){
        Cell *next = cur->next;
        
        cur->next = prev;
        
        prev = cur;
        cur = next;
        
        head = prev;
    }
}

int main (){
    int aux;
    
    ListaE *lE;
    
    lE = criar_listaE();
    
    while (aux != -1){
        scanf("%d ", &aux);
            
        if (aux != -1)
            inserir_primeiro(aux, lE);
    }
    
    inverterLista(&lE);
    imprimir(lE);
    liberar_LE(lE);
    
    return 0;
}