#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        return 1;
    }

    long long soma_positivos = 0;
    int tem_positivo = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] > 0) {
            soma_positivos += vetor[i];
            tem_positivo = 1;
        }
    }

    if (tem_positivo) {
        printf("%lld\n", soma_positivos);
    } else {
        printf("0\n");
    }
    
    free(vetor);
    return 0;
}