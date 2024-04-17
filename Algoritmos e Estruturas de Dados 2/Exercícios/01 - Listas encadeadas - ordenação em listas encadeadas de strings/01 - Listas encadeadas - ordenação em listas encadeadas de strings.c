#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell {
    char item[100];
    Cell *next;
};

struct ListaE {
    Cell *head;
};

Cell* criar_celula(char item[]) {
    Cell* nova = (Cell*)malloc(sizeof(Cell));

    strcpy(nova->item, item);
    nova->next = NULL;

    return nova;
}

ListaE* criar_listaE() {
    ListaE* l = (ListaE*)malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

void inserir(ListaE* lista, char item[]) {
    Cell* nova = criar_celula(item);

    if (lista->head == NULL) {
        lista->head = nova;
    } else {
        Cell* atual = lista->head;

        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = nova;
    }
}

void trocar_celula(Cell* a, Cell* b) {
    char aux[100];

    strcpy(aux, a->item);
    strcpy(a->item, b->item);
    strcpy(b->item, aux);
}

void ordenar_listaE(ListaE* lista) {
    int troca;
    Cell *aux1;
    Cell *aux2 = NULL;

    if (lista->head == NULL)
        return;

    do {
        troca = 0;
        aux1 = lista->head;

        while (aux1->next != aux2) {
            if (strcmp(aux1->item, aux1->next->item) > 0) {
                trocar_celula(aux1, aux1->next);
                troca = 1;
            }
            aux1 = aux1->next;
        }
        aux2 = aux1;
    } while (troca);
}

void imprimir_lista(ListaE* lista) {
    Cell* aux = lista->head;

    while (aux != NULL) {
        printf("%s\n", aux->item);
        aux = aux->next;
    }
}

int main() {
    ListaE* lista = criar_listaE();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char item[100];
        scanf("%s", item);
        inserir(lista, item);
    }

    ordenar_listaE(lista);

    imprimir_lista(lista);
    
    free(lista);

    return 0;
}
