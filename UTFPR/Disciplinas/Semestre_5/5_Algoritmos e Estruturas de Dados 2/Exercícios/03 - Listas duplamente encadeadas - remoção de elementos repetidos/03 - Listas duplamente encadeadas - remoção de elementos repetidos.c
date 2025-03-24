#include <stdio.h>
#include <stdlib.h>

typedef struct CellDE CellDE;

typedef struct ListaDE ListaDE;

struct CellDE {
    int item;
    CellDE *previous;
    CellDE *next;
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

void append(ListaDE* lista, int item) {
    CellDE* new_cell = criar_celulaDE(item);
    if (lista->head == NULL) {
        lista->head = new_cell;
        return;
    }
    CellDE* last = lista->head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_cell;
    new_cell->previous = last;
}

void removeDuplicates(ListaDE* lista) {
    CellDE *current = lista->head;
    CellDE *next;

    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            if (current->item == next->item) {
                CellDE *temp = next;
                next = next->next;
                if (next != NULL)
                    next->previous = temp->previous;
                if (temp->previous != NULL)
                    temp->previous->next = next;
                free(temp);
            } else {
                next = next->next;
            }
        }
        current = current->next;
    }
}

void display(ListaDE lista) {
    CellDE *current = lista.head;
    while (current != NULL) {
        printf("%d ", current->item);
        current = current->next;
    }
    printf("\n");
}

int main() {
    ListaDE lista;
    lista.head = NULL;
    int item;

    while (1) {
        scanf("%d", &item);
        if (item == -1)
            break;
        append(&lista, item);
    }

    removeDuplicates(&lista);

    display(lista);

    return 0;
}
