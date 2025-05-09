#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int** create_matrix(int l, int c){
    int i;
    int** mat;

    mat = malloc(l * sizeof(int*));
    
    for (i = 0; i < l; i++)
        mat[i] = malloc(sizeof(int) * c);

    return mat;
}

void mat_soma(int l, int c, int matriz_A[l][c], int matriz_B[l][c]){
    int **matriz_soma, i, j;
    matriz_soma = create_matrix(l, c);
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++)
            matriz_soma[i][j] = matriz_A[i][j] + matriz_B[i][j];
    }
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%d ", matriz_soma[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int l, c, i, j;
    
    scanf("%d %d", &l, &c);
    
    int matriz_A[l][c];
    int matriz_B[l][c];
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &matriz_A[i][j]);
        }
    }
    
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &matriz_B[i][j]);
        }
    }
    
    mat_soma(l, c, matriz_A, matriz_B);
        
    return 0;
}
