#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    char* item;
    Cell *next;
};

struct ListaE{
    Cell *head;
};


Cell* criar_celula(char* key){
    Cell *c = (Cell*) malloc(sizeof(Cell)+1);
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

void inserir_primeiro(char* key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void inserir_ultimo(char* key, ListaE *l){
    Cell *aux = malloc(sizeof(Cell));
    Cell *novo = malloc(sizeof(Cell));
    
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}

int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux){
            printf("%s\n", aux->item);

            aux = aux->next;
        }
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

void trocar_items(Cell *a, Cell *b) {
    char *temp = a->item;
    a->item = b->item;
    b->item = temp;
}

void ordenar_listaE(ListaE *l) {
    Cell *i, *j, *min;

    for (i = l->head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->item, min->item) < 0) {
                min = j;
            }
        }
        if (min != i) {
            trocar_items(min, i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    ListaE* listaE = criar_listaE();
    
    for(int i = 0; i < n; i++) {
        char palavra[100];
        scanf("%s", palavra);
        inserir_ultimo(palavra, listaE);
    }
    
    ordenar_listaE(listaE);
    imprimir(listaE);
    
    liberar_LE(listaE);
    
    return 0;
}

// https://stackoverflow.com/questions/33116474/linked-lists-with-strings
