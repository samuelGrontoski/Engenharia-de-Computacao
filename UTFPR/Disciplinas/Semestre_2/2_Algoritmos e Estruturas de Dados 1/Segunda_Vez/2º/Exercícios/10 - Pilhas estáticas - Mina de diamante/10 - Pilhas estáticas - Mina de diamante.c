#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    char item[MAX_SIZE];
    int topo;
}Pilha;

Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo == (MAX_SIZE - 1))
        return 1;
    else
        return 0;
}

int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

int empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}

int desempilhar (Pilha *p){
    char item;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}
int main() {
    int N, i, j, diamante;
    char carga[MAX_SIZE];
    
    scanf("%d", &N);
    
    for(i = 0; i < N; i++){
        Pilha *p = criar_pilha();
        diamante = 0;
        
        scanf("%s", carga);
        
        for(j = 0; carga[j] != '\0'; j++){
            if(carga[j] == '<'){
                empilhar(p, carga[j]);
            }
            if(carga[j] == '>'){
                if(p->topo >= 0 && p->item[p->topo] == '<'){
                    desempilhar(p);
                    diamante++;
                }
            }
        }
        printf("%d\n", diamante);
        liberar_pilha(p);
    }
    
    return 0;
}
