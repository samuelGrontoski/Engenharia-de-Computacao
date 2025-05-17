#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell {
    int item;
    
    Cell *next;
};

struct ListaE {
    Cell *head;
};

Cell* criar_celula(int key) {
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;
    
    c->next = NULL;
    
    return c;
}

ListaE* criar_listaE() {
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));
    
    l->head = NULL;
    
    return l;
}

int listaE_vazia(ListaE *l) {
    return (l == NULL) || (l->head == NULL);
}

int procurar(int key, ListaE *l) {
    Cell *aux;
    
    if (l != NULL) {
        aux = l->head;
        
        while (aux != NULL) {
            if (aux->item == key) {
                return 1;
            }
            aux = aux->next;
        }
    }
    return 0;
}

void inserir_primeiro(int key, ListaE *l) {
    Cell *aux;
    
    if (l == NULL) {
        l = criar_listaE();
    }
    aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l) {
    Cell *aux, *novo;
    
    if (l == NULL) {
        l = criar_listaE();
    }
    if (listaE_vazia(l)) {
        inserir_primeiro(key, l);
    }
    else {
        aux = l->head;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        novo = criar_celula(key);
        aux->next = novo;
    }
}

void imprimir(ListaE *l) {
    Cell *aux;
    
    if (!listaE_vazia(l)) {
        aux = l->head;
        
        while (aux != NULL) {
            printf("%d ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    
    if (l != NULL) {
        while(l->head != NULL) {
            aux = l->head;
            l->head = aux->next;
            free(aux);
        }
        free(l);
        
        return 1;
    }
    return 0;
}

int main() {
    ListaE *l1 = criar_listaE();
    ListaE *l2 = criar_listaE();
    ListaE *comum = criar_listaE();
    
    int num;
    
    scanf("%d", &num);
    while (num != -1) {
        inserir_ultimo(num, l1);
        scanf("%d", &num);
    }

    scanf("%d", &num);
    while (num != -1) {
        inserir_ultimo(num, l2);
        scanf("%d", &num);
    }

    Cell *aux = l1->head;
    while (aux != NULL) {
        if (procurar(aux->item, l2) && !procurar(aux->item, comum)) {
            inserir_ultimo(aux->item, comum);
        }
        aux = aux->next;
    }

    imprimir(comum);

    liberar_LE(l1);
    liberar_LE(l2);
    liberar_LE(comum);

    return 0;
}

