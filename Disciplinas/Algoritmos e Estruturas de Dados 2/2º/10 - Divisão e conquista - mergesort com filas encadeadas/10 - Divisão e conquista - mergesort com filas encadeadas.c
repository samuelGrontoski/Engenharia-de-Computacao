#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No {
    int valor;
    struct No *next;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

Fila* criar_fila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(Fila *f) {
    return (f->inicio == NULL);
}

void enfileirar(Fila *f, int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->next = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo_no;
        f->fim = novo_no;
    } else {
        f->fim->next = novo_no;
        f->fim = novo_no;
    }
}

int desenfileirar(Fila *f) {
    if (fila_vazia(f)) {
        return INT_MIN;
    }
    No *temp = f->inicio;
    int valor = temp->valor;
    f->inicio = f->inicio->next;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return valor;
}

int frente(Fila *f) {
    if (fila_vazia(f)) {
        return INT_MIN;
    }
    return f->inicio->valor;
}

void liberar_fila(Fila *f) {
    if (f != NULL) {
        while (!fila_vazia(f)) {
            desenfileirar(f);
        }
        free(f);
    }
}

void intercalar(int vetor[], int p, int q, int r) {
    Fila *fila_esq = criar_fila();
    Fila *fila_dir = criar_fila();

    for (int i = p; i <= q; i++) {
        enfileirar(fila_esq, vetor[i]);
    }

    for (int i = q + 1; i <= r; i++) {
        enfileirar(fila_dir, vetor[i]);
    }

    for (int k = p; k <= r; k++) {
        if (!fila_vazia(fila_esq) && (fila_vazia(fila_dir) || frente(fila_esq) <= frente(fila_dir))) {
            vetor[k] = desenfileirar(fila_esq);
        } else {
            if (!fila_vazia(fila_dir)) {
                vetor[k] = desenfileirar(fila_dir);
            }
        }
    }

    liberar_fila(fila_esq);
    liberar_fila(fila_dir);
}

void mergesort(int vetor[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergesort(vetor, p, q);
        mergesort(vetor, q + 1, r);
        intercalar(vetor, p, q, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    int *vetor = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    mergesort(vetor, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", vetor[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(vetor);
    return 0;
}