#include <stdio.h>

int somaDivisaoConquista(int inicio, int fim) {
    if (inicio == fim) {
        return inicio;
    }
    
    if (inicio > fim) {
        return 0;
    }

    int meio = inicio + (fim - inicio) / 2;

    int soma_esquerda = somaDivisaoConquista(inicio, meio);
    int soma_direita = somaDivisaoConquista(meio + 1, fim);

    return soma_esquerda + soma_direita;
}

int main() {
    int n;

    printf("\nDigite um numero natural (n >= 0): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: O numero precisa ser natural (maior ou igual a 0).\n");
        return 1;
    }

    int resultado = somaDivisaoConquista(0, n);

    printf("\nUsando o metodo de divisao e conquista:\n");
    printf("A soma dos numeros de 0 ate %d e: %d\n\n", n, resultado);

    return 0;
}

/*

Análise da Eficiência da Estratégia:

A abordagem de divisão e conquista adiciona uma complexidade desnecessária e uma sobrecarga computacional para um 
problema que pode ser resolvido de maneira muito mais eficiente com uma fórmula matemática (O(1)) ou um laço simples (O(n)).

=============================================
Análise de Complexidade de Tempo:

Teorema Mestre: T(n) = aT(n/b​) + f(n)

a = 2 (número de subproblemas)
b = 2 (fator pelo qual o tamanho do problema é reduzido)
f(n) = O(1) (trabalho de divisão/combinação)

Calculamos n^(logb​ a) = n^(log₂ ​2) = n¹ = n

Agora, comparamos f(n) com n^(logb ​a):

    f(n) = O(1) é menor que n^(logb a) = n
    Isso corresponde ao Caso 1 do Teorema Mestre

O resultado, segundo o Teorema Mestre, é que T(n) = Θ(n^(logb ​a)).

Portanto, a complexidade de tempo do algoritmo é Θ(n).

*/