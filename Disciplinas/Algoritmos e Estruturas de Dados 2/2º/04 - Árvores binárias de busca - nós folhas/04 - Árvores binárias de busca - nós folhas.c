#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

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

void imprimirNosFolha(Node* tree) {
    if (tree == NULL) {
        return;
    }
    
    if (tree->left == NULL && tree->right == NULL) {
        printf(" %i", tree->item);
    }
    
    imprimirNosFolha(tree->left);
    imprimirNosFolha(tree->right);
}

int main() {
    Node* raiz = NULL;
    int N;

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int aux;
        scanf("%d", &aux);
        raiz = inserir(aux, raiz);
    }
    
    imprimirNosFolha(raiz);
    
    liberar_arvore(raiz);
    
    return 0;
}
