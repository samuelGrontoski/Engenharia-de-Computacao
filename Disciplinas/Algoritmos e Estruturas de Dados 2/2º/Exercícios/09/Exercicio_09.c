#include <stdio.h>

int somaVetorDivisaoConquista(int vetor[], int inicio, int fim) {
    if (inicio == fim) {
        return vetor[inicio];
    }
    
    if (inicio > fim) {
        return 0;
    }

    int meio = inicio + (fim - inicio) / 2;

    int soma_esquerda = somaVetorDivisaoConquista(vetor, inicio, meio);
    int soma_direita = somaVetorDivisaoConquista(vetor, meio + 1, fim);

    return soma_esquerda + soma_direita;
}

int main() {
    int meuVetor[] = {5, 8, 2, 9, 4, 7, 1, 3, 6, 10};
    int n = sizeof(meuVetor) / sizeof(meuVetor[0]);

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", meuVetor[i]);
    }
    printf("\n");

    int resultado = somaVetorDivisaoConquista(meuVetor, 0, n - 1);

    printf("A soma dos elementos do vetor e: %d\n", resultado);

    return 0;
}

/*

Análise de Complexidade de Tempo:

Divisão: Encontrar o índice do meio. Esta é uma operação de tempo constante, O(1).
Conquista: São feitas duas chamadas recursivas, cada uma para um subproblema de tamanho aproximadamente n/2. O tempo gasto nesta etapa é 2T(n/2).
Combinação: Somar os dois resultados retornados pelas chamadas recursivas. Esta é uma operação de tempo constante, O(1).

A relação de recorrência para o algoritmo é:

T(n) = 2T(n/2​) + O(1)

Como visto no exercício anterior, isso resulta em uma complexidade de tempo de Θ(n).

*/