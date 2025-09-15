#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

Tipo_Mat_Esparsa* criar_matriz(int qtd_linhas, int qtd_colunas) {
    Tipo_Mat_Esparsa *matriz = (Tipo_Mat_Esparsa*) malloc(sizeof(Tipo_Mat_Esparsa));
    if (matriz != NULL) {
        matriz->qtd_linhas = qtd_linhas;
        matriz->qtd_colunas = qtd_colunas;
        matriz->inicio = NULL;
    }
    return matriz;
}

void inserir_elemento(Tipo_Mat_Esparsa *matriz, int linha, int coluna, int valor) {
    if (matriz == NULL || linha >= matriz->qtd_linhas || coluna >= matriz->qtd_colunas || linha < 0 || coluna < 0) {
        printf("Erro: Posicao invalida para insercao!\n");
        return;
    }

    if (valor == 0) return;

    tipo_coluna *coluna_anterior = NULL;
    tipo_coluna *coluna_atual = matriz->inicio;

    while (coluna_atual != NULL && coluna_atual->ID_Coluna < coluna) {
        coluna_anterior = coluna_atual;
        coluna_atual = coluna_atual->proximo;
    }

    if (coluna_atual == NULL || coluna_atual->ID_Coluna != coluna) {
        tipo_coluna *coluna_nova = (tipo_coluna*) malloc(sizeof(tipo_coluna));
        if (coluna_nova == NULL) return;
        coluna_nova->ID_Coluna = coluna;
        coluna_nova->inicio = NULL;
        coluna_nova->proximo = coluna_atual;

        if (coluna_anterior == NULL) {
            matriz->inicio = coluna_nova;
        } else {
            coluna_anterior->proximo = coluna_nova;
        }
        coluna_atual = coluna_nova;
    }

    tipo_elemento *elemento_anterior = NULL;
    tipo_elemento *elemento_atual = coluna_atual->inicio;

    while (elemento_atual != NULL && elemento_atual->linha < linha) {
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->proximo;
    }

    if (elemento_atual != NULL && elemento_atual->linha == linha) {
        elemento_atual->valor = valor;
    } else {
        tipo_elemento *elemento_novo = (tipo_elemento*) malloc(sizeof(tipo_elemento));
        if (elemento_novo == NULL) return;
        elemento_novo->valor = valor;
        elemento_novo->linha = linha;
        elemento_novo->proximo = elemento_atual;

        if (elemento_anterior == NULL) {
            coluna_atual->inicio = elemento_novo;
        } else {
            elemento_anterior->proximo = elemento_novo;
        }
    }
}

tipo_coluna* pesquisar_dentro_colunas(Tipo_Mat_Esparsa *matriz, int coluna) {
    if (matriz == NULL) return NULL;
    tipo_coluna* coluna_atual = matriz->inicio;
    while(coluna_atual != NULL && coluna_atual->ID_Coluna < coluna) {
        coluna_atual = coluna_atual->proximo;
    }

    if (coluna_atual != NULL && coluna_atual->ID_Coluna == coluna) {
        return coluna_atual;
    }
    
    return NULL;
}

tipo_elemento* pesquisar_dentro_linhas(tipo_coluna* no_coluna, int linha) {
    if (no_coluna == NULL) return NULL;
    tipo_elemento* elemento_atual = no_coluna->inicio;
    while(elemento_atual != NULL && elemento_atual->linha < linha) {
        elemento_atual = elemento_atual->proximo;
    }

    if(elemento_atual != NULL && elemento_atual->linha == linha) {
        return elemento_atual;
    }

    return NULL;
}

int consultar_elemento(Tipo_Mat_Esparsa *matriz, int linha, int coluna) {
    if (matriz == NULL || linha >= matriz->qtd_linhas || coluna >= matriz->qtd_colunas) {
        return 0;
    }

    tipo_coluna* no_coluna = pesquisar_dentro_colunas(matriz, coluna);
    if (no_coluna == NULL) {
        return 0;
    }

    tipo_elemento* no_elemento = pesquisar_dentro_linhas(no_coluna, linha);
    if (no_elemento == NULL) {
        return 0;
    }

    return no_elemento->valor;
}

void mostrar_matriz(Tipo_Mat_Esparsa *matriz) {
    if (matriz == NULL) {
        return;
    }

    printf("Tamanho da Matriz: (%dx%d)\n", matriz->qtd_linhas, matriz->qtd_colunas);

    for (int i = 0; i < matriz->qtd_linhas; i++) {
        for (int j = 0; j < matriz->qtd_colunas; j++) {
            printf("%4d ", consultar_elemento(matriz, i, j));
        }
        printf("\n");
    }
}

void apagar_matriz(Tipo_Mat_Esparsa *matriz) {
    if (matriz == NULL) return;

    tipo_coluna *coluna_atual = matriz->inicio;
    while (coluna_atual != NULL) {
        tipo_elemento *elemento_atual = coluna_atual->inicio;
        while(elemento_atual != NULL) {
            tipo_elemento *elemento_temporario = elemento_atual;
            elemento_atual = elemento_atual->proximo;
            free(elemento_temporario);
        }
        
        tipo_coluna *coluna_temporaria = coluna_atual;
        coluna_atual = coluna_atual->proximo;
        free(coluna_temporaria);
    }
    free(matriz);
}

Tipo_Mat_Esparsa* criar_transposta(Tipo_Mat_Esparsa *matriz) {
    if (matriz == NULL) {
        printf("Erro: Matriz de entrada eh nula.\n");
        return NULL;
    }

    Tipo_Mat_Esparsa *matriz_transposta = criar_matriz(matriz->qtd_colunas, matriz->qtd_linhas);
    if (matriz_transposta == NULL) {
        printf("Erro: Falha ao alocar a matriz transposta.\n");
        return NULL;
    }

    tipo_coluna *coluna_original = matriz->inicio;
    while (coluna_original != NULL) {
        tipo_elemento *elemento_original = coluna_original->inicio;
        while (elemento_original != NULL) {
            
            int linha_original = elemento_original->linha;
            int coluna_original_id = coluna_original->ID_Coluna;
            int valor = elemento_original->valor;

            inserir_elemento(matriz_transposta, coluna_original_id, linha_original, valor);

            elemento_original = elemento_original->proximo;
        }
        coluna_original = coluna_original->proximo;
    }

    return matriz_transposta;
}

Tipo_Mat_Esparsa* somar_matrizes(Tipo_Mat_Esparsa *matriz_A, Tipo_Mat_Esparsa *matriz_B) {
    if (matriz_A == NULL || matriz_B == NULL) {
        printf("Erro: Uma das matrizes eh nula.\n");
        return NULL;
    }
    if (matriz_A->qtd_linhas != matriz_B->qtd_linhas || matriz_A->qtd_colunas != matriz_B->qtd_colunas) {
        printf("Erro: As dimensoes das matrizes sao incompativeis para a soma.\n");
        return NULL;
    }

    Tipo_Mat_Esparsa *matriz_resultado = criar_matriz(matriz_A->qtd_linhas, matriz_A->qtd_colunas);
    if (matriz_resultado == NULL) {
        printf("Erro: Falha ao alocar a matriz de resultado.\n");
        return NULL;
    }

    tipo_coluna *coluna_matriz_A = matriz_A->inicio;
    while (coluna_matriz_A != NULL) {
        tipo_elemento *elem_matriz_A = coluna_matriz_A->inicio;
        while (elem_matriz_A != NULL) {
            inserir_elemento(matriz_resultado, elem_matriz_A->linha, coluna_matriz_A->ID_Coluna, elem_matriz_A->valor);
            elem_matriz_A = elem_matriz_A->proximo;
        }
        coluna_matriz_A = coluna_matriz_A->proximo;
    }

    tipo_coluna *coluna_matriz_B = matriz_B->inicio;
    while (coluna_matriz_B != NULL) {
        tipo_elemento *elem_matriz_B = coluna_matriz_B->inicio;
        while (elem_matriz_B != NULL) {
            int valor_existente = consultar_elemento(matriz_resultado, elem_matriz_B->linha, coluna_matriz_B->ID_Coluna);
            
            inserir_elemento(matriz_resultado, elem_matriz_B->linha, coluna_matriz_B->ID_Coluna, valor_existente + elem_matriz_B->valor);

            elem_matriz_B = elem_matriz_B->proximo;
        }
        coluna_matriz_B = coluna_matriz_B->proximo;
    }

    return matriz_resultado;
}

Tipo_Mat_Esparsa* multiplicar_matrizes(Tipo_Mat_Esparsa *matriz_A, Tipo_Mat_Esparsa *matriz_B) {
    if (matriz_A == NULL || matriz_B == NULL) {
        printf("Erro: Uma das matrizes eh nula.\n");
        return NULL;
    }
    if (matriz_A->qtd_colunas != matriz_B->qtd_linhas) {
        printf("Erro: Dimensoes incompativeis para multiplicacao.\n");
        printf("(Colunas da matriz_A: %d, Linhas da matriz_B: %d)\n", matriz_A->qtd_colunas, matriz_B->qtd_linhas);
        return NULL;
    }

    Tipo_Mat_Esparsa *matriz_resultado = criar_matriz(matriz_A->qtd_linhas, matriz_B->qtd_colunas);
    if (matriz_resultado == NULL) return NULL;

    Tipo_Mat_Esparsa *matriz_A_t = criar_transposta(matriz_A);
    if (matriz_A_t == NULL) {
        apagar_matriz(matriz_resultado);
        return NULL;
    }

    tipo_coluna *coluna_matriz_A_t = matriz_A_t->inicio;
    while (coluna_matriz_A_t != NULL) {
        int i = coluna_matriz_A_t->ID_Coluna;

        tipo_coluna *coluna_matriz_B = matriz_B->inicio;
        while (coluna_matriz_B != NULL) {
            int j = coluna_matriz_B->ID_Coluna;
            
            tipo_elemento *elem1 = coluna_matriz_A_t->inicio;
            tipo_elemento *elem2 = coluna_matriz_B->inicio;
            int soma_produto = 0;

            while (elem1 != NULL && elem2 != NULL) {
                if (elem1->linha < elem2->linha) {
                    elem1 = elem1->proximo;
                } else if (elem2->linha < elem1->linha) {
                    elem2 = elem2->proximo;
                } else {
                    soma_produto += elem1->valor * elem2->valor;
                    elem1 = elem1->proximo;
                    elem2 = elem2->proximo;
                }
            }

            if (soma_produto != 0) {
                inserir_elemento(matriz_resultado, i, j, soma_produto);
            }
            coluna_matriz_B = coluna_matriz_B->proximo;
        }
        coluna_matriz_A_t = coluna_matriz_A_t->proximo;
    }

    apagar_matriz(matriz_A_t);

    return matriz_resultado;
}