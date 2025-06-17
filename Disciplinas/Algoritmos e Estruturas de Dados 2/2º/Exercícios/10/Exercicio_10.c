#include <stdio.h>

int multiplicacaoDivisaoConquista(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b == 1) {
        return a;
    }

    int sub_resultado = multiplicacaoDivisaoConquista(a, b / 2);

    if (b % 2 == 0) {
        return sub_resultado + sub_resultado;
    }
    else {
        return a + sub_resultado + sub_resultado;
    }
}

int main() {
    int a, b;

    printf("--- Multiplicacao por Divisao e Conquista ---\n");
    printf("Digite o valor de a (deve ser >= 0): ");
    scanf("%d", &a);
    printf("Digite o valor de b (deve ser >= 0): ");
    scanf("%d", &b);

    if (b < 0 || a < 0) {
        printf("Erro: O valor de a e b devem ser maior ou igual a 0.\n");
        return 1;
    }

    int resultado = multiplicacaoDivisaoConquista(a, b);

    printf("\nO resultado de %d * %d e: %d\n", a, b, resultado);

    return 0;
}

/*

Análise de Complexidade de Tempo:

- Relação de Recorrência: T(b) = T(b/2) + O(1)
- Descrição: O problema de tamanho 'b' (o multiplicador) é reduzido a um único subproblema de tamanho 'b/2'. A divisão e combinação têm custo constante O(1).
- Complexidade de Tempo: O(log b)
- Justificativa: Como o problema é dividido pela metade a cada passo com apenas uma chamada recursiva, a profundidade da recursão é logarítmica. 
Pelo Teorema Mestre (Caso 2), a complexidade é Θ(log b).

*/