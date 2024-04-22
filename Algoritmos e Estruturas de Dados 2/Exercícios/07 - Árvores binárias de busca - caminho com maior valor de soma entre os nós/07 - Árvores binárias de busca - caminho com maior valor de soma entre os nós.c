#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

struct Node{
    int item;
    struct Node *left;
    struct Node *right;
};


Node* criar(int item){
    Node * tree = (Node *) malloc(sizeof(Node));
    
    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
        
    return tree;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maiorSoma(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int soma_left = maiorSoma(node->left);
        int soma_right = maiorSoma(node->right);
        return node->item + max(soma_left, soma_right);
    }
}

Node* inserir(int item, Node* tree){
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);
        
    return tree;
}

void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

int main() {
    Node* tree = NULL;
    int N, aux;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &aux);
        tree = inserir(aux, tree);
    }

    int max_sum = maiorSoma(tree);
    printf("%d\n", max_sum);

    liberar_arvore(tree);
    
    return 0;
}
