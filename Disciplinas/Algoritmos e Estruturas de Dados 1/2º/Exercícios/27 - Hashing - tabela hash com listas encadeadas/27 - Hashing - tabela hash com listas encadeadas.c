#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct HashT HashT;

struct Cell{
    int item;
    Cell *next;
};

struct HashT{
    unsigned int tam;
    Cell **buckets;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;

    return c;
}

HashT* criar(unsigned int tam) {
    HashT *t = malloc(sizeof(HashT));
    int i;
    
    t->tam = tam;
    t->buckets = malloc(tam * sizeof(Cell*));

    for (i = 0; i < tam; i++){
        t->buckets[i] = NULL;
    }

    return t;
}

static int hashingF(int k, int B){
    return k % B;
}

void inserir_ordenado(Cell **head, int item){
    Cell* novaCelula = criar_celula(item);

    if (*head == NULL || (*head)->item >= item){
        novaCelula->next = *head;
        *head = novaCelula;
    } else {
        Cell* atual = *head;
        while (atual->next != NULL && atual->next->item < item) {
            atual = atual->next;
        }
        novaCelula->next = atual->next;
        atual->next = novaCelula;
    }
}

int inserir(int key, HashT *t) {
    int x = hashingF(key, t->tam);

    if (t->buckets[x] == NULL) {
        t->buckets[x] = criar_celula(key);
    } else {
        inserir_ordenado(&(t->buckets[x]), key);
    }

    return x;
}

void imprimir(HashT *t) {
    int i;

    for (i = 0; i < t->tam; i++) {
        Cell* atual = t->buckets[i];
        printf("%d: -> ", i);
        while (atual != NULL) {
            printf("%d", atual->item);
            if (atual->next != NULL)
                printf(" -> ");
            atual = atual->next;
        }
        printf("\n");
    }
}

int liberar(HashT *t) {
    if (t != NULL) {
        int i;
        for (i = 0; i < t->tam; i++) {
            Cell* atual = t->buckets[i];
            while (atual != NULL) {
                Cell* temp = atual;
                atual = atual->next;
                free(temp);
            }
        }

        free(t->buckets);
        free(t);

        return 1;
    }

    return 0;
}

int main() {
    unsigned int tam;
    int num;

    scanf("%u", &tam);
    scanf("%d", &num);

    HashT *t = criar(tam);

    int key;
    for (int i = 0; i < num; i++) {
        scanf("%d", &key);
        int x = inserir(key, t);
        printf("%d\n", x);
    }
    printf("\n");

    imprimir(t);

    liberar(t);

    return 0;
}

