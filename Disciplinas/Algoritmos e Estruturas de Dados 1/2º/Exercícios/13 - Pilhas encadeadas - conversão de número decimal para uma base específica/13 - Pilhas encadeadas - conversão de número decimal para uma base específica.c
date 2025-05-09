#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct Cell{
    int item;
    Cell *next;
}Cell;

typedef struct{
    Cell *topo;
}PilhaE;

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}

void empilhar(int key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}

int desempilhar(PilhaE *p){
    Cell *aux;
    int item = INT_MIN;

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}

int acessar_valor_topo(PilhaE *p){
    if (!pilhaE_vazia(p))
        return p->topo->item;
    else
        return INT_MIN;
}

void imprimir_pilha(PilhaE *p){
    Cell *aux;

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d", aux->item);

            aux = aux->next;
        }
        
        printf("\n");
    }
}

int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

PilhaE *dec2base(int dec, int base){
    PilhaE *pE = criar_pilhaE();
    
    do{
        empilhar(dec % base, pE);
        dec /= base;
    }while(dec != 0);
    
    return pE;
}

int main() {
    int dec, base;
    PilhaE *pE;
    
    scanf("%d %d", &dec, &base);
    
    pE = dec2base(dec, base);
    
    imprimir_pilha(pE);
    
    liberar_pilha(pE);
    
    return 0;
}
