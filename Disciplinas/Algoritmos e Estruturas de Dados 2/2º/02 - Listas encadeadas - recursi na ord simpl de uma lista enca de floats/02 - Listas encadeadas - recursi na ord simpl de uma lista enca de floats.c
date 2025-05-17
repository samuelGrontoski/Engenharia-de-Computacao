#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;

struct Cell {
    float item;
    Cell *next;
};

struct ListaE {
    Cell *head;
};

Cell* criar_celula(float key) {
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

void inserir_ultimo(float key, ListaE *l) {
    Cell *aux, *novo;
    if (l == NULL) return;

    if (listaE_vazia(l)) {
        l->head = criar_celula(key);
    } else {
        aux = l->head;
        while (aux->next != NULL) {
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
            printf("%.1f ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

void liberar_LE(ListaE *l){
    Cell *aux = NULL;
    if (l != NULL) {
        while(l->head != NULL) {
            aux = l->head;
            l->head = aux->next;
            free(aux);
        }
        free(l);
    }
}

int bubble_run(Cell *node) {
    int trocou = 0;
    if (node == NULL || node->next == NULL)
        return 0;

    if (node->item > node->next->item) {
        float temp = node->item;
        node->item = node->next->item;
        node->next->item = temp;
        trocou = 1;
    }

    return bubble_run(node->next) || trocou;
}

void bubble_sort_recursivo(Cell *head) {
    if (bubble_run(head)) {
        bubble_sort_recursivo(head);
    }
}

int main() {
    ListaE *l = criar_listaE();
    float num;

    scanf("%f", &num);
    while (num != -1) {
        inserir_ultimo(num, l);
        scanf("%f", &num);
    }

    bubble_sort_recursivo(l->head);
    imprimir(l);
    liberar_LE(l);

    return 0;
}
