#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 5

typedef struct NodeB NodeB;

struct NodeB {
    int nro_chaves;
    int chaves[N - 1];
    struct NodeB *filhos[N];
    int eh_no_folha;
};

NodeB* criar(){
    NodeB *tree = malloc(sizeof(NodeB));
    int i;

    tree->eh_no_folha = 1;
    tree->nro_chaves = 0;

    for (i = 0; i < N; i++)
        tree->filhos[i] = NULL;

    return tree;
}

int liberar(NodeB *tree){
    if (tree != NULL){
        free(tree);

        return 1;
    }

    return 0;
}

NodeB *inserir(NodeB *tree, int key) {
    if (tree == NULL) {
        NodeB *tree = criar();

        tree->chaves[0] = key;
        tree->nro_chaves = 1;

        return tree;
    }

    int i = tree->nro_chaves - 1;
    while (i >= 0 && key < tree->chaves[i]) {
        tree->chaves[i + 1] = tree->chaves[i];
        i--;
    }

    if (tree->nro_chaves < N - 1) {
        tree->chaves[i + 1] = key;
        tree->nro_chaves++;

        return tree;
    } else {
        NodeB *new_tree = criar();
        int split_point = N / 2;

        if (i + 1 < split_point) {
            for (int j = 0; j < split_point - 1; j++) {
                new_tree->chaves[j] = tree->chaves[j];
            }

            new_tree->chaves[split_point - 1] = key;
            new_tree->nro_chaves = split_point;

            for (int j = split_point; j < N - 1; j++) {
                tree->chaves[j - split_point] = tree->chaves[j];
            }

            tree->nro_chaves = N - split_point;
            new_tree->filhos[0] = tree;

            return new_tree;
        }
        else if (i + 1 == split_point) {
            new_tree->chaves[0] = key;
            new_tree->nro_chaves = 1;
            new_tree->filhos[0] = tree;

            return new_tree;
        }
        else {
            for (int j = split_point; j < N - 1; j++) {
                new_tree->chaves[j - split_point] = tree->chaves[j];
            }

            new_tree->chaves[i - split_point + 1] = key;
            new_tree->nro_chaves = N - split_point;

            for (int j = split_point; j < N; j++) {
                tree->chaves[j - split_point] = 0;
            }

            tree->nro_chaves = split_point;
            new_tree->filhos[0] = tree;
            
            return new_tree;
        }
    }
}

int contar_paginas_cheias(NodeB *tree) {
    if (tree == NULL) {
        return 0;
    }

    int count = 0;
    if (tree->nro_chaves == N - 1) {
        count++;
    }

    for (int i = 0; i < tree->nro_chaves + 1; i++) {
        count += contar_paginas_cheias(tree->filhos[i]);
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    NodeB *tree = NULL;
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        tree = inserir(tree, key);
    }

    int paginas_cheias = contar_paginas_cheias(tree);
    printf("%d\n", paginas_cheias);

    liberar(tree);

    return 0;
}
