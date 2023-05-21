#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca(int chave, int *v, int n, int m) {
    int ini = 0;
    int fim = n - 1;

    while (ini <= fim) {
        if (fim - ini + 1 > m) {
            int meio = (ini + fim) / 2;

            if (v[meio] == chave) {
                return meio;
            } else if (v[meio] > chave) {
                fim = meio - 1;
            } else {
                ini = meio + 1;
            }
        } else {
            for (int i = ini; i <= fim; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            for (int i = ini; i <= fim; i++) {
                if (v[i] == chave) {
                    return i;
                }
            }

            break;
        }
    }

    return -1;
}

int main() {
    int num, n, m;

    scanf("%d", &num);
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &m);

    int posicao = busca(num, v, n, m);

    printf("%d\n", posicao);

    return 0;
}