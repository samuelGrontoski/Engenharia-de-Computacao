#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float** criar_matriz(int l, int c){
    int i;
    float** mat;

    mat = malloc(sizeof(float*) * l);
    
    for (i = 0; i < l; i++)
        mat[i] = malloc(sizeof(float) * c);

    return mat;
}

void imprimir_matriz(int l, int c, float **matriz){
    int i, j;
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ordenar_matriz(int l, int c, float **matriz){
    int i, j, k;
    float aux;
    
    for(i = 0; i < c; i++) {
        for(j = 0; j < l - 1; j++) {
            for(k = 0; k < l - j - 1; k++) {
                if(matriz[k][i] < matriz[k + 1][i]) {
                    aux = matriz[k][i];
                    matriz[k][i] = matriz[k+1][i];
                    matriz[k+1][i] = aux;
                }
            }
        }
    }
}

int main() {
    int l, c, i, j;
    
    scanf("%d %d", &l, &c);
    
    float **matriz = criar_matriz(l, c);
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
    
    ordenar_matriz(l, c, matriz);
    
    imprimir_matriz(l, c, matriz);
    
    return 0;
}