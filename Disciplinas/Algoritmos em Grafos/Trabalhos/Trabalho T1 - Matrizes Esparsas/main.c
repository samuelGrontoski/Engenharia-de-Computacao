#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

// Função auxiliar para ler uma matriz de um arquivo .txt
Tipo_Mat_Esparsa* ler_matriz_de_arquivo(const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    int linhas, colunas;
    fscanf(arquivo, "%d %d", &linhas, &colunas);

    Tipo_Mat_Esparsa *matriz = criar_matriz(linhas, colunas);
    if (matriz == NULL) {
        fclose(arquivo);
        return NULL;
    }

    int r, c, v;
    while (fscanf(arquivo, "%d %d %d", &r, &c, &v) == 3) {
        inserir_elemento(matriz, r, c, v);
    }

    fclose(arquivo);
    return matriz;
}

int main() {
    Tipo_Mat_Esparsa *matriz_A = ler_matriz_de_arquivo("Matrizes/matriz_3.txt");
    Tipo_Mat_Esparsa *matriz_B = ler_matriz_de_arquivo("Matrizes/matriz_4.txt");

    if (matriz_A) {
        printf("--- Matriz A ---\n");
        mostrar_matriz(matriz_A);
    }

    printf("\n----------------------------------------\n\n");

    if (matriz_B) {
        printf("--- Matriz B ---\n");
        mostrar_matriz(matriz_B);
    }
    
    printf("\n----------------------------------------\n\n");

    if (matriz_A && matriz_B) {
        printf("--- Soma da Matriz A + Matriz B ---\n");
        Tipo_Mat_Esparsa *matriz_soma = somar_matrizes(matriz_A, matriz_B);

        if (matriz_soma) {
            mostrar_matriz(matriz_soma);
            apagar_matriz(matriz_soma);
        }
    }

    printf("\n----------------------------------------\n\n");

    if (matriz_A) {
        printf("--- Transposta da Matriz A ---\n");
        Tipo_Mat_Esparsa *matriz_transposta = criar_transposta(matriz_A);

        if (matriz_transposta) {
            mostrar_matriz(matriz_transposta);
            apagar_matriz(matriz_transposta);
        }
    }

    printf("\n----------------------------------------\n\n");

    if (matriz_B) {
        printf("--- Transposta da Matriz B ---\n");
        Tipo_Mat_Esparsa *matriz_transposta = criar_transposta(matriz_B);

        if (matriz_transposta) {
            mostrar_matriz(matriz_transposta);
            apagar_matriz(matriz_transposta);
        }
    }

    printf("\n========================================\n\n");

    if (matriz_A && matriz_B) {
        printf("--- Multiplicacao (Matriz A * Matriz B) ---\n");
        Tipo_Mat_Esparsa *matriz_multiplicacao = multiplicar_matrizes(matriz_A, matriz_B);

        if (matriz_multiplicacao) {
            mostrar_matriz(matriz_multiplicacao);
            apagar_matriz(matriz_multiplicacao);
        }
    }

    apagar_matriz(matriz_A);
    apagar_matriz(matriz_B);

    return 0;
}