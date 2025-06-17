#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 10

int matriz[N][N] = {
    {  0, 12, 10, 19,  8, 15, 14, 20, 18, 11 },
    { 12,  0,  7,  9, 13, 16, 11, 10, 14, 17 },
    { 10,  7,  0,  5,  9, 12, 18, 14, 11, 13 },
    { 19,  9,  5,  0,  6, 10, 17, 13, 12, 15 },
    {  8, 13,  9,  6,  0, 11, 15,  9,  7, 10 },
    { 15, 16, 12, 10, 11,  0,  6, 13, 14, 12 },
    { 14, 11, 18, 17, 15,  6,  0,  8, 10,  9 },
    { 20, 10, 14, 13,  9, 13,  8,  0,  6,  7 },
    { 18, 14, 11, 12,  7, 14, 10,  6,  0,  5 },
    { 11, 17, 13, 15, 10, 12,  9,  7,  5,  0 } 
};

void imprimirPercurso(int percurso[], int n, int distancia) {
    printf("Percurso encontrado: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", percurso[i]);
    }
    printf("%d\n", percurso[0]);
    printf("Distancia total percorrida: %d km\n", distancia);
}

void resolverMetodoGuloso() {
    printf("\n--- Solucao com Metodo Guloso ---\n");

    int percurso[N];
    bool visitado[N] = {false};
    int distanciaTotal = 0;
    int cidadeAtual = 0;
    int contadorCidades = 0;

    percurso[contadorCidades++] = cidadeAtual;
    visitado[cidadeAtual] = true;

    while (contadorCidades < N) {
        int proximaCidade = -1;
        int menorDistancia = INT_MAX;

        for (int i = 0; i < N; i++) {
            if (!visitado[i] && matriz[cidadeAtual][i] < menorDistancia) {
                menorDistancia = matriz[cidadeAtual][i];
                proximaCidade = i;
            }
        }

        if (proximaCidade != -1) {
            distanciaTotal += menorDistancia;
            cidadeAtual = proximaCidade;
            percurso[contadorCidades++] = cidadeAtual;
            visitado[cidadeAtual] = true;
        }
    }

    distanciaTotal += matriz[cidadeAtual][0];

    imprimirPercurso(percurso, N, distanciaTotal);
}

int menorDistanciaBruta = INT_MAX;
int melhorPercursoBruto[N + 1];

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gerarPermutacoes(int cidades[], int inicio, int fim) {
    if (inicio == fim) {
        int distanciaAtual = 0;

        distanciaAtual += matriz[0][cidades[0]];

        for (int i = 0; i < fim; i++) {
            distanciaAtual += matriz[cidades[i]][cidades[i+1]];
        }

        distanciaAtual += matriz[cidades[fim]][0];

        if (distanciaAtual < menorDistanciaBruta) {
            menorDistanciaBruta = distanciaAtual;
            melhorPercursoBruto[0] = 0;
            for(int i = 0; i <= fim; i++) {
                melhorPercursoBruto[i+1] = cidades[i];
            }
        }
        return;
    }

    for (int i = inicio; i <= fim; i++) {
        trocar(&cidades[inicio], &cidades[i]);
        gerarPermutacoes(cidades, inicio + 1, fim);
        trocar(&cidades[inicio], &cidades[i]);
    }
}

void resolverForcaBruta() {
    printf("\n--- Solucao com Forca Bruta ---\n");

    int cidadesParaVisitar[N - 1];
    int j = 0;

    for (int i = 1; i < N; i++) {
        cidadesParaVisitar[j++] = i;
    }

    gerarPermutacoes(cidadesParaVisitar, 0, N - 2);

    imprimirPercurso(melhorPercursoBruto, N, menorDistanciaBruta);
}

int main() {
    resolverMetodoGuloso();

    resolverForcaBruta();

    printf("\n--- Conclusao ---\n");
    printf("O percurso otimo, encontrado por forca bruta, tem uma distancia de %d km.\n", menorDistanciaBruta);
    printf("O percurso encontrado pelo metodo guloso NAO e o otimo neste caso.\n\n");

    return 0;
}