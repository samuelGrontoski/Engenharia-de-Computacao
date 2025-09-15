#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct tipo_elemento tipo_elemento;
typedef struct tipo_coluna tipo_coluna;
typedef struct Tipo_Mat_Esparsa Tipo_Mat_Esparsa;

// Estrutura que representa um elemento (valor) não-nulo na matriz.
// Contém o valor, a linha em que se encontra e um ponteiro para o próximo elemento na mesma coluna.
struct tipo_elemento {
    int valor;
    int linha;
    tipo_elemento *proximo;
};

// Estrutura que representa uma coluna que possui pelo menos um elemento não-nulo.
// Contém o ID da coluna, um ponteiro para a próxima coluna e um ponteiro para o início da lista de elementos.
struct tipo_coluna {
    int ID_Coluna;
    tipo_coluna *proximo;
    tipo_elemento *inicio;
};

// Estrutura que representa a matriz esparsa.
// Contém as dimensões e um ponteiro para o início da lista de colunas.
struct Tipo_Mat_Esparsa {
    int qtd_linhas;
    int qtd_colunas;
    tipo_coluna *inicio;
};

/**
 * @brief Aloca e inicializa uma matriz esparsa.
 * @param qtd_linhas Número de linhas da matriz.
 * @param qtd_colunas Número de colunas da matriz.
 * @return Ponteiro para a matriz criada ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* criar_matriz(int qtd_linhas, int qtd_colunas);

/**
 * @brief Insere ou atualiza um elemento na matriz esparsa.
 * Se o valor for 0, o elemento é removido se já existir.
 * @param matriz Ponteiro para a matriz.
 * @param linha Linha do elemento.
 * @param coluna Coluna do elemento.
 * @param valor Valor a ser inserido.
 */
void inserir_elemento(Tipo_Mat_Esparsa *matriz, int linha, int coluna, int valor);

/**
 * @brief Consulta o valor de um elemento em uma dada posição.
 * @param matriz Ponteiro para a matriz.
 * @param linha Linha do elemento.
 * @param coluna Coluna do elemento.
 * @return O valor do elemento. Retorna 0 se o elemento não estiver armazenado.
 */
int consultar_elemento(Tipo_Mat_Esparsa *matriz, int linha, int coluna);

/**
 * @brief Exibe a matriz no formato convencional (com os zeros).
 * @param matriz Ponteiro para a matriz.
 */
void mostrar_matriz(Tipo_Mat_Esparsa *matriz);

/**
 * @brief Pesquisa por um nó de coluna específico.
 * @param matriz Ponteiro para a matriz.
 * @param coluna ID da coluna a ser pesquisada.
 * @return Ponteiro para o nó da coluna ou NULL se não for encontrada.
 */
tipo_coluna* pesquisar_dentro_colunas(Tipo_Mat_Esparsa *matriz, int coluna);

/**
 * @brief Pesquisa por um elemento em uma linha específica dentro de uma lista de elementos de uma coluna.
 * @param no_coluna Ponteiro para o nó da coluna.
 * @param linha Linha do elemento a ser pesquisado.
 * @return Ponteiro para o elemento ou NULL se não for encontrado.
 */
tipo_elemento* pesquisar_dentro_linhas(tipo_coluna* no_coluna, int linha);

/**
 * @brief Libera toda a memória alocada para a matriz.
 * @param matriz Ponteiro para a matriz a ser destruída.
 */
void apagar_matriz(Tipo_Mat_Esparsa *matriz);

/**
 * @brief Cria a matriz transposta de uma matriz dada.
 * @param matriz Ponteiro para a matriz original.
 * @return Ponteiro para uma nova matriz que é a transposta da original, ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* criar_transposta(Tipo_Mat_Esparsa *matriz);

/**
 * @brief Soma duas matrizes esparsas.
 * As matrizes devem ter as mesmas dimensões.
 * @param matriz_A Ponteiro para a primeira matriz.
 * @param matriz_B Ponteiro para a segunda matriz.
 * @return Ponteiro para uma nova matriz contendo o resultado da soma, ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* somar_matrizes(Tipo_Mat_Esparsa *matriz_A, Tipo_Mat_Esparsa *matriz_B);

/**
 * @brief Multiplica duas matrizes esparsas (matriz_A * matriz_B).
 * O número de colunas da matriz_A deve ser igual ao número de linhas da matriz_B.
 * @param matriz_A Ponteiro para a primeira matriz.
 * @param matriz_B Ponteiro para a segunda matriz.
 * @return Ponteiro para uma nova matriz com o resultado da multiplicação, ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* multiplicar_matrizes(Tipo_Mat_Esparsa *matriz_A, Tipo_Mat_Esparsa *matriz_B);

#endif