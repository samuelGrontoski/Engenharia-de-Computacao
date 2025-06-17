#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int lista[], int n) {
    int i, j, temp;
    int troca;

    for (i = 0; i < n - 1; i++) {
        troca = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                troca = 1;
            }
        }

        if (troca == 0)
            break;
    }
}

int selecionarArquivos(int arquivos[], int n, int capacidade, int selecionados[]) {
    bubbleSort(arquivos, n);

    int capacidadeRestante = capacidade;
    int contadorArquivos = 0;
    int indiceSelecionados = 0;

    for (int i = 0; i < n; i++) {
        if (arquivos[i] <= capacidadeRestante) {
            selecionados[indiceSelecionados++] = arquivos[i];
            capacidadeRestante -= arquivos[i];
            contadorArquivos++;
        } else {
            break;
        }
    }
    return contadorArquivos;
}

int main() {
    int arquivos[] = {100, 200, 50, 80, 150, 30, 70};
    int n = sizeof(arquivos) / sizeof(arquivos[0]);
    int capacidade = 300;

    printf("\nArquivos (KB): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arquivos[i]);
    }
    printf("\nCapacidade total: %d KB\n", capacidade);

    int arquivosSelecionados[n];

    int numeroDeArquivosSelecionados = selecionarArquivos(arquivos, n, capacidade, arquivosSelecionados);

    printf("\nNumero maximo de arquivos que podem ser armazenados: %d\n", numeroDeArquivosSelecionados);
    printf("Arquivos selecionados (KB): ");
    
    int somaTamanhos = 0;
    for (int i = 0; i < numeroDeArquivosSelecionados; i++) {
        printf("%d ", arquivosSelecionados[i]);
        somaTamanhos += arquivosSelecionados[i];
    }
    printf("\nEspaco total utilizado: %d KB\n", somaTamanhos);
    printf("Espaco restante: %d KB\n\n", capacidade - somaTamanhos);

    return 0;
}

/* 

Análise de complexidade da solução:

1 – Função bubbleSort 
 
Esta função ordena a lista de arquivos.  
    - Possui dois laços aninhados. O laço externo executa n-1 vezes e o laço interno 
executa, no pior caso, um número de vezes proporcional a n. 
    - A complexidade de tempo do bubbleSort, tanto no caso médio quanto no pior 
caso, é O(n²). 
 
2 - Função selecionarArquivos 
Esta função implementa a estratégia gulosa para selecionar os arquivos. 
    - A primeira operação é a chamada para a ordenação, que tem custo de O(n²). 
    - Laço de seleção: Após a ordenação, a função itera sobre a lista de arquivos uma 
única vez para selecionar quais cabem na capacidade.  

    - for (int i = 0; i < n; i++) 
    - Este laço executa, no máximo, n vezes. As operações dentro dele (if, 
atribuição, subtração) são de tempo constante, O(1). 
    - Portanto, a complexidade desta parte do código é O(n). 
 
Complexidade Total 
A complexidade total da função selecionarArquivos é a soma das complexidades de suas partes: 
    
    T(n) = complexidade(bubbleSort) + complexidade(laço de seleção) 
    T(n) = O(n²) + O(n) 

Ao analisar a complexidade assintótica, consideramos apenas o termo de maior 
crescimento. Portanto, a complexidade geral da solução é dominada pela ordenação. 
A complexidade de tempo da solução é O(n²). 

*/