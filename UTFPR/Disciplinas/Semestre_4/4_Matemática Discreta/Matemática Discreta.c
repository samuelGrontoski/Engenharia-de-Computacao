#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int l1, c1, l2, c2;

    do{
        printf("Digite o numero de linhas e colunas da matriz 1 (tamanho maximo 4x4): \n");
        do{
            scanf("%d %d", &l1, &c1);
        } while (l1 > 4 && c1 > 4);

        printf("Digite o numero de linhas e colunas da matriz 2 (tamanho maximo 4x4): \n");
        do{
            scanf("%d %d", &l2, &c2);
        } while (l2 > 4 && c2 > 4);
    } while (c1 != l2);
    
    int mat1[l1][c1], mat2[l2][c2], prod[l1][c1], i, j, k;

    // leitura da primeira matriz
    printf("Digite a primeira matriz booleana:\n");
    for (i = 0; i < l1; i++) {
        for (j = 0; j < c1; j++) {
            do{
                scanf("%d", &mat1[i][j]);
                if (mat1[i][j] != 0 && mat1[i][j] != 1)
                {
                    printf("O valor deve ser 0 ou 1\n");
                }
            } while(mat1[i][j] != 0 && mat1[i][j] != 1);
        }
    }

    // leitura da segunda matriz
    printf("Digite a segunda matriz booleana:\n");
    for (i = 0; i < l2; i++) {
        for (j = 0; j < c2; j++) {
            do{
                scanf("%d", &mat2[i][j]);
                if (mat2[i][j] != 0 && mat2[i][j] != 1)
                {
                    printf("O valor deve ser 0 ou 1\n");
                }
                
            } while(mat2[i][j] != 0 && mat2[i][j] != 1);
        }
    }

    // cálculo do produto das matrizes
    for (i = 0; i < l1; i++) {
        for (j = 0; j < c2; j++) {
            prod[i][j] = 0;
            for (k = 0; k < c2; k++) {
                prod[i][j] = prod[i][j] || (mat1[i][k] && mat2[k][j]);
            }
        }
    }

    // exibição da matriz produto
    printf("Matriz produto:\n");
    for (i = 0; i < l1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", prod[i][j]);
        }
        printf("\n");
    }

    return 0;
}
