#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int item;
    struct Node *left;
    struct Node *right;
};

Node* criar(int item) {
    Node * tree = (Node *) malloc(sizeof(Node));
    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

Node* inserir(int item, Node* tree) {
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);
    return tree;
}

void liberar_arvore(Node* tree) {
    if (tree != NULL) {
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

void imprimir_profundidade(Node *tree, int p, int atual) {
    if (tree == NULL) return;

    if (atual == p) {
        printf("%d ", tree->item);
    } else {
        imprimir_profundidade(tree->left, p, atual + 1);
        imprimir_profundidade(tree->right, p, atual + 1);
    }
}

int main() {
    Node* raiz = NULL;
    int p, N;

    scanf("%d", &p);

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int aux;
        scanf("%d", &aux);
        raiz = inserir(aux, raiz);
    }

    imprimir_profundidade(raiz, p, 0);
    printf("\n");

    liberar_arvore(raiz);
    
    return 0;
}
