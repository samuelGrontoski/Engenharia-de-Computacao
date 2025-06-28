#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

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

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int soma_maxima = vetor[0];
    int soma_maxima_atual = vetor[0];

    for (int i = 1; i < n; i++) {
        soma_maxima_atual = max(vetor[i], soma_maxima_atual + vetor[i]);
        soma_maxima = max(soma_maxima, soma_maxima_atual);
    }

    printf("%d\n", soma_maxima);

    free(vetor);

    return 0;
}