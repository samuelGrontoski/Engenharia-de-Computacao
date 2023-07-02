#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int** criar_matriz(int l, int c){
    int i;
    int** mat;

    mat = malloc(l * sizeof(int*));
    
    for (i = 0; i < l; i++)
        mat[i] = malloc(sizeof(int) * c);

    return mat;
}

void imprimir_matriz(int l, int c, int **matriz){
    int i, j;
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ordenar_matriz(int l, int c, int **matriz){
    int i, j, k, aux;
    
    for(i = 0; i < l; i++) {
        for(j = 0; j < c - 1; j++) {
            for(k = 0; k < c - j - 1; k++) {
                if(matriz[i][k] < matriz[i][k + 1]) {
                    aux = matriz[i][k];
                    matriz[i][k] = matriz[i][k + 1];
                    matriz[i][k + 1] = aux;
                }
            }
        }
    }
}

int main() {
    int l, c, i, j;
    
    scanf("%d %d", &l, &c);
    
    int **matriz = criar_matriz(l, c);
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    ordenar_matriz(l, c, matriz);
    
    imprimir_matriz(l, c, matriz);
    
    return 0;
}
