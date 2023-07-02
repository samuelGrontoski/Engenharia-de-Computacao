#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct Spa_Mat Spa_Mat;

struct Cell {
    int item, l, c;
    Cell *next, *down;
};

struct Spa_Mat {
    int n_lin, n_col;
    Cell **lin, **col;
};

Spa_Mat* criar(int l, int c) {
    Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
    int i;

    mat->n_lin = l;
    mat->n_col = c;
    mat->lin = (Cell**) malloc(sizeof(Cell*) * l);
    mat->col = (Cell**) malloc(sizeof(Cell*) * c);

    for (i = 0; i < l; i++) {
        mat->lin[i] = NULL;
    }

    for (i = 0; i < c; i++) {
        mat->col[i] = NULL;
    }

    return mat;
}

Cell* criar_celula(int item, int l, int c) {
    Cell* nova = (Cell*) malloc(sizeof(Cell));
    nova->item = item;
    nova->l = l;
    nova->c = c;
    nova->next = NULL;
    nova->down = NULL;

    return nova;
}

static void inserir_na_linha(Cell* nova, Cell** linha) {
    if (*linha == NULL || nova->c < (*linha)->c) {
        nova->next = *linha;
        *linha = nova;
    } else {
        Cell* atual = *linha;

        while (atual->next != NULL && atual->next->c < nova->c) {
            atual = atual->next;
        }

        nova->next = atual->next;
        atual->next = nova;
    }
}

static void inserir_na_coluna(Cell* nova, Cell** coluna) {
    if (*coluna == NULL || nova->l < (*coluna)->l) {
        nova->down = *coluna;
        *coluna = nova;
    } else {
        Cell* atual = *coluna;

        while (atual->down != NULL && atual->down->l < nova->l) {
            atual = atual->down;
        }

        nova->down = atual->down;
        atual->down = nova;
    }
}

void trocar(int item, int l, int c, Spa_Mat* mat) {
    if (l >= 0 && l < mat->n_lin && c >= 0 && c < mat->n_col) {
        Cell* nova = criar_celula(item, l, c);

        inserir_na_linha(nova, &(mat->lin[l]));
        inserir_na_coluna(nova, &(mat->col[c]));
    }
}

int procurar_lista(int item, Cell* linha) {
    while (linha != NULL) {
        if (linha->item == item) {
            return 1;
        }
        linha = linha->next;
    }
    return 0;
}

int buscar(int item, Spa_Mat* mat) {
    int i;

    for (i = 0; i < mat->n_lin; i++) {
        if (procurar_lista(item, mat->lin[i])) {
            return 1;
        }
    }

    return 0;
}

int buscar_pos(int l, int c, Spa_Mat* mat) {
    if (l >= 0 && l < mat->n_lin && c >= 0 && c < mat->n_col) {
        Cell* atual = mat->lin[l];

        while (atual != NULL && atual->c < c) {
            atual = atual->next;
        }

        if (atual != NULL && atual->c == c) {
            return atual->item;
        }
    }

    return 0;
}

void remover_na_lista(int l, int c, Spa_Mat* mat) {
    if (l >= 0 && l < mat->n_lin && c >= 0 && c < mat->n_col) {
        Cell* atual = mat->lin[l];
        Cell* anterior = NULL;

        while (atual != NULL && atual->c < c) {
            anterior = atual;
            atual = atual->next;
        }

        if (atual != NULL && atual->c == c) {
            if (anterior == NULL) {
                mat->lin[l] = atual->next;
            } else {
                anterior->next = atual->next;
            }

            if (mat->col[c] == atual) {
                mat->col[c] = atual->down;
            } else {
                Cell* coluna = mat->col[c];
                Cell* coluna_anterior = NULL;

                while (coluna != atual) {
                    coluna_anterior = coluna;
                    coluna = coluna->down;
                }

                coluna_anterior->down = atual->down;
            }

            free(atual);
        }
    }
}

void imprimir(Spa_Mat* mat) {
    int i, j;

    for (i = 0; i < mat->n_lin; i++) {
        Cell* atual = mat->lin[i];
        j = 0;

        while (atual != NULL) {
            while (j < atual->c) {
                printf("0 ");
                j++;
            }

            printf("%d ", atual->item);
            j++;
            atual = atual->next;
        }

        for (j; j < mat->n_col; j++) {
            printf("0 ");
        }

        printf("\n");
    }
}

void liberar(Spa_Mat* mat) {
    int i;

    for (i = 0; i < mat->n_lin; i++) {
        Cell* atual = mat->lin[i];
        Cell* temp;

        while (atual != NULL) {
            temp = atual;
            atual = atual->next;
            free(temp);
        }
    }

    free(mat->lin);
    free(mat->col);
    free(mat);
}