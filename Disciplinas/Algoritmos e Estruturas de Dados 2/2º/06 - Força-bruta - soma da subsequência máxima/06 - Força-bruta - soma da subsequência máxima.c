#include <stdio.h>

int somaSubsequenciaMaxima(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }

    int soma_maxima = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int soma_atual = 0;
            for (int k = i; k <= j; k++) {
                soma_atual += arr[k];
            }

            if (soma_atual > soma_maxima) {
                soma_maxima = soma_atual;
            }
        }
    }

    return soma_maxima;
}

int main() {
    int n;

    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int resultado = somaSubsequenciaMaxima(vetor, n);

    printf("%d\n", resultado);

    return 0;
}