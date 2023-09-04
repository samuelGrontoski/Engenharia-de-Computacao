#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;

struct Cell{
        int item;
        int col;
        Cell *next;
};

struct ListaE{
        Cell *head;
};

struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
};

Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE) * l);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}

Cell* criar_celula(int item, int col){
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}

int validar_pos_matriz(int lin, int col, Spa_Mat* mat){
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}

int buscar_pos(int l, int c, Spa_Mat* mat){
    Cell *aux;
    int valor = 0;

    if ((mat != NULL) && validar_pos_matriz(l, c, mat)){
        aux = mat->lin[l]->head;

        while ((aux != NULL) && (c < aux->col))
            aux = aux->next;

        if ((aux != NULL) && (c == aux->col))
            valor = aux->item;
    }

    return valor;
}
 
void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;
 
    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
 
    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head;  
        auxP = auxA;

        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }
     
        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
 
        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next;  
            auxA->next = novo;
        }
    }
}
 
void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;
    
    if (l->head != NULL){
 
        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA;  
            while ((auxP != NULL) && (auxP->col < col)){
                auxA = auxP;
                auxP = auxP->next;
            }
            
            if ((auxP != NULL) && (col == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}
 
void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}

void imprimir(Spa_Mat* mat){
    int i, j;
    Cell* aux;

    for (i = 0; i < mat->n_lin; i++){
        aux = mat->lin[i]->head;
        j = 0;

        while (aux != NULL){
            while (j < aux->col){
                printf("0 ");
                j++;
            }

            printf("%d ", aux->item);
            j++;
            aux = aux->next;
        }

        for (j=0; j < mat->n_col; j++)
            printf("0 ");

        printf("\n");
    }
}

int mat_triangular(Spa_Mat* matriz){
    int i, j;
    Cell* aux;
    
    j = 0;
    for (i = 0; i < matriz->n_lin; i++){
        aux = matriz->lin[i]->head;

        while (aux != NULL){
            if(i > aux->col)
              j++;
            
            aux = aux->next;
        }
    }
    if(j != 0){
        for (i = 0; i < matriz->n_lin; i++){
            aux = matriz->lin[i]->head;

            while (aux != NULL){
                if(i < aux->col)
                  return 0;

                aux = aux->next;
            }
       }
    }
    return 1;
}


int main() {
    int i, j, l_c, valor;
    
    scanf("%d", &l_c);
    
    Spa_Mat *mat_esp = criar(l_c, l_c);
    
    for (i = 0; i < l_c; i++){
            for(j = 0; j < l_c; j++){
                scanf("%d", &valor);
                
                trocar(valor, i, j, mat_esp);
            }
    }
    
    if(mat_triangular(mat_esp) == 1)
        printf("triangular");
    
    else
        printf("nao triangular");
    
    free(mat_esp);
    
    return 0;
}