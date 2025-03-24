#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int**create_matrix(int l, int c){
    int i;
    int**mat;

    mat = malloc(l * sizeof(int*));

    for(i = 0; i < l; i++)
        mat[i] = malloc(sizeof(int) * c);

    return mat;
}

int main(void) {
    int i, j;
    int n = 4;
    int**mat = create_matrix(n,n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat[i][j] = i + j;
            printf("%.2d ", mat[i][j]);
        }
        printf("\n");
    }
    
    free(mat);
    return 0;
}