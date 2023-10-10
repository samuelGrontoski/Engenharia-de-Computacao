#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista{
    char nome[MAX_SIZE][100];
    int tam;
}Lista;

Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->tam = 0;
    return l;
}

int lista_vazia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam > 0)
        return 0;
    else
        return 1;
}

int lista_cheia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam < MAX_SIZE)
        return 0;
    else
        return 1;
}

int inserir(Lista *l, char *nome){
    if (!lista_cheia(l)) {
        strcpy(l->nome[l->tam], nome);
        l->tam++;
        return 1;
    }
    return 0;
}

void imprimir_lista_versao_simples(Lista *l, char *chave) {
    int i;
    if (!lista_vazia(l)) {
        for (i = 0; i < l->tam; i++) {
            if (strstr(l->nome[i], chave) == chave) {
                printf("%s\n", l->nome[i]);
            }
        }
    }
}

void imprimir_lista_versao_complexa(Lista *l, char *chave) {
    int i = 0, j = 0, k = 0;
    if (!lista_vazia(l)) {
        for (i = 0; i < l->tam; i++) {
            j = 0;
            while (l->nome[i][j] != '\0') {
                if (l->nome[i][j] == chave[0]) {
                    k = 0;
                    while (chave[k] != '\0'){
                        if (l->nome[i][j + k] == chave[k]){
                            k++;
                        } else {
                            break;
                        }
                        k++;
                    }
                }
                j++;
            }
            if (chave[k] == '\0') {
                printf("%s\n", l->nome[i]);
            }
        }
    }
}

int main() {
    Lista *contatos = criar_lista();
    char chave[10];
    int n;

    scanf("%s", chave);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char nome[100];
        scanf("%s", nome);
        inserir(contatos, nome);
    }

    for (int i = 0; i < contatos->tam; i++) {
        if (strstr(contatos->nome[i], chave) != NULL) {
            printf("%s\n", contatos->nome[i]);
        }
    }
    
    imprimir_lista_versao_simples(contatos, chave);

    free(contatos);

    return 0;
}
