#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int busca_binaria_iterativa(int x, int *v, int ini, int fim) {
    int meio;

    do {
        meio = (ini + fim) / 2;

        if (x == v[meio]) {
            return meio;
        }
        if (x < v[meio]) {
            fim = meio - 1;   
        } else {
            ini = meio + 1;   
        }
    } while (ini <= fim);

    return -1;
}

int main() {
    int n, c, posicao;
    
    scanf("%d", &n);
    int *v = malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);   
    }

    scanf("%d", &c);
    int *x = malloc(sizeof(int) * c);
    
    for (int i = 0; i < c; i++) {
        scanf("%d", &x[i]);
        posicao = busca_binaria_iterativa(x[i], v, 0, n-1);
        printf("%d\n", posicao);
    }
       
    free(v);
    free(x);

    return 0;
}