#include <stdio.h>
#include <stdlib.h>

typedef struct CellDE CellDE;

typedef struct ListaDE ListaDE;

// Definição da estrutura de um nó da lista duplamente encadeada
struct CellDE {
    int item;        // Item armazenado no nó
    struct CellDE *previous;  // Ponteiro para o nó anterior
    struct CellDE *next;      // Ponteiro para o próximo nó
};

// Definição da estrutura da lista duplamente encadeada
struct ListaDE {
    CellDE *head;   // Ponteiro para o primeiro nó da lista
};

// Função para criar uma nova célula com o item fornecido
CellDE* criar_celulaDE(int item) {
    // Aloca memória para a nova célula
    CellDE* cell = (CellDE*)malloc(sizeof(CellDE));

    // Inicializa os campos da célula
    cell->item = item;
    cell->previous = NULL;
    cell->next = NULL;

    return cell;  // Retorna o ponteiro para a nova célula
}

// Função para criar uma nova lista duplamente encadeada vazia
ListaDE* criar_listaDE() {
    // Aloca memória para a nova lista
    ListaDE* lista = (ListaDE*)malloc(sizeof(ListaDE));

    // Inicializa o ponteiro para o primeiro nó como NULL
    lista->head = NULL;

    return lista;  // Retorna o ponteiro para a nova lista
}

// Função para inserir um novo elemento no final da lista
void inserir_ultimo(ListaDE* lista, int item) {
    // Cria uma nova célula com o item fornecido
    CellDE* aux = criar_celulaDE(item);

    // Se a lista estiver vazia, o novo nó será o primeiro da lista
    if (lista->head == NULL) {
        lista->head = aux;
        return;
    }

    // Se a lista não estiver vazia, encontra o último nó
    CellDE* ultimo = lista->head;
    while (ultimo->next != NULL) {
        ultimo = ultimo->next;
    }

    // Insere a nova célula após o último nó
    ultimo->next = aux;
    aux->previous = ultimo;
}

// Função para remover elementos duplicados da lista
void remover_duplicados(ListaDE* lista) {
    CellDE *aux = lista->head;
    CellDE *next;

    // Percorre a lista
    while (aux != NULL) {
        next = aux->next;

        // Percorre os elementos subsequentes para verificar duplicatas
        while (next != NULL) {
            if (aux->item == next->item) {
                // Se houver duplicata, remove o próximo nó duplicado
                CellDE *temp = next;
                next = next->next;

                // Atualiza os ponteiros para manter a integridade da lista
                if (next != NULL) {
                    next->previous = temp->previous;
                }
                if (temp->previous != NULL) {
                    temp->previous->next = next;
                }
                free(temp);  // Libera a memória alocada para o nó duplicado
            } else {
                next = next->next;
            }
        }
        aux = aux->next;
    }
}

// Função para imprimir os elementos da lista
void imprimir_listaDE(ListaDE* lista) {
    CellDE *aux = lista->head;

    // Percorre a lista e imprime os elementos
    while (aux != NULL) {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista e seus nós
void liberar_listaDE(ListaDE* lista) {
    CellDE* atual = lista->head;
    CellDE* proximo;

    // Percorre a lista e libera a memória alocada para cada nó
    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    free(lista);  // Libera a memória alocada para a estrutura da lista
}

int main() {
    ListaDE* lista = criar_listaDE();  // Cria uma nova lista vazia
    int item;

    // Lê os elementos da entrada padrão até encontrar -1
    while (item != -1) {
        scanf("%d", &item);
        if (item == -1)
            break;
        inserir_ultimo(lista, item);  // Insere cada elemento na lista
    }

    remover_duplicados(lista);  // Remove os elementos duplicados da lista

    imprimir_listaDE(lista);  // Imprime a lista resultante

    liberar_listaDE(lista);  // Libera a memória alocada para a lista

    return 0;
}
