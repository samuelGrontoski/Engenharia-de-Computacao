#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct Cell{
    float item;
    Cell *next;
}Cell;

typedef struct ListaE{
    Cell *head;
}ListaE;

Cell* criar_celula(float key){
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

int procurar(float key, ListaE *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}

void inserir_primeiro(float key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void inserir_ultimo(float key, ListaE *l){
    Cell *aux, *nova;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        nova = criar_celula(key);

        aux->next = nova;
    }
}

int remover(float key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }
    }

    return 0;
}

void imprimir(ListaE *l){
    Cell *aux;

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%.1f ", aux->item);

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

void selectionSortRec(Cell *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Cell *menor = head;
    Cell *aux = head;

    while (aux != NULL) {
        if (aux->item < menor->item) {
            menor = aux;
        }
        aux = aux->next;
    }

    if (menor != head) {
        float temp = menor->item;
        menor->item = head->item;
        head->item = temp;
    }

    selectionSortRec(head->next);
}

void selectionSort(ListaE *lE) {
    selectionSortRec(lE->head);
}

int main() {
    ListaE *lE = criar_listaE();
    float aux = 0;
    
    while(aux != -1){
        scanf("%f", &aux);
        if(aux != -1)
            inserir_ultimo(aux, lE);
    }
    
    selectionSort(lE);
    
    imprimir(lE);
    
    liberar_LE(lE);
    
    return 0;
}
