#include <stdio.h>
#include <stdlib.h>

typedef struct CellDE CellDE;

typedef struct ListaDE ListaDE;

struct CellDE {
    int item;
    struct CellDE *previous;
    struct CellDE *next;
};

struct ListaDE {
    CellDE *head;
};

CellDE* criar_celulaDE(int item) {
    CellDE* cell = (CellDE*)malloc(sizeof(CellDE));

    cell->item = item;
    cell->previous = NULL;
    cell->next = NULL;

    return cell;
}

ListaDE* criar_listaDE() {
    ListaDE* lista = (ListaDE*)malloc(sizeof(ListaDE));

    lista->head = NULL;

    return lista;
}

void inserir_ultimo(ListaDE* lista, int item) {
    CellDE* aux = criar_celulaDE(item);

    if (lista->head == NULL) {
        lista->head = aux;
        return;
    }

    CellDE* ultimo = lista->head;
    while (ultimo->next != NULL) {
        ultimo = ultimo->next;
    }

    ultimo->next = aux;
    aux->previous = ultimo;
}

void remover_duplicados(ListaDE* lista) {
    CellDE *aux = lista->head;
    CellDE *next;

    while (aux != NULL) {
        next = aux->next;

        while (next != NULL) {
            if (aux->item == next->item) {
                CellDE *temp = next;
                next = next->next;

                if (next != NULL) {
                    next->previous = temp->previous;
                }
                if (temp->previous != NULL) {
                    temp->previous->next = next;
                }
                free(temp);
            } else {
                next = next->next;
            }
        }
        aux = aux->next;
    }
}

void imprimir_listaDE(ListaDE* lista) {
    CellDE *aux = lista->head;
    while (aux != NULL) {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    printf("\n");
}

void liberar_listaDE(ListaDE* lista) {
    CellDE* atual = lista->head;
    CellDE* proximo;

    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    free(lista);
}

int main() {
    ListaDE* lista = criar_listaDE();
    int item;

    while (item != -1) {
        scanf("%d", &item);
        if (item == -1)
            break;
        inserir_ultimo(lista, item);
    }

    remover_duplicados(lista);

    imprimir_listaDE(lista);

    liberar_listaDE(lista);

    return 0;
}
