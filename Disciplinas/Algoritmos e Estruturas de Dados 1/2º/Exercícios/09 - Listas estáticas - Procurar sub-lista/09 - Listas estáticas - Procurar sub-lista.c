#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista{
    int item[MAX_SIZE];
    int tam; 
}Lista;

Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}

int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}

int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++; 

        return 1;
    }
    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];

        l->tam--; 

        return 1;
    }

    return 0;
}

void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

int liberar_lista(Lista *l){
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}

int buscar_sub(Lista *l1, Lista *l2){
    int i, j, count = 1;

    if (!lista_vazia(l1) || !lista_vazia(l2)){
        for (i = 0; i < l1->tam; i++){
            if(l1->item[i] == l2->item[0]){
                for(j = 1; j < l2->tam; j++){
                    if(l1->item[i+j] == l2->item[j]){
                        count++;
                    }
                }
                if(count == l2->tam){
                    return i;
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, p;
    
    Lista *l1;
    Lista *l2;
    l1 = criar_lista();
    l2 = criar_lista();

    do{
        scanf("%d", &n);
        if(n == -1)
            break;
        else
            inserir(l1, n);
    }while(n != -1);
    
    do{
        scanf("%d", &n);
        if(n == -1)
            break;
        else
            inserir(l2, n);
    }while(n != -1);
    
    p = buscar_sub(l1, l2);
    
    printf("%d", p);
    
    return 0;
}
