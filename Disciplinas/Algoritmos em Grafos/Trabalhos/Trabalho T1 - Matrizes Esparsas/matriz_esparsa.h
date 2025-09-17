#include <stdio.h>
#include <stdlib.h>

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
Tipo_Mat_Esparsa* criar_matriz(int qtd_linhas, int qtd_colunas) {
    Tipo_Mat_Esparsa *matriz = (Tipo_Mat_Esparsa*) malloc(sizeof(Tipo_Mat_Esparsa));
    if (matriz != NULL) {
        matriz->qtd_linhas = qtd_linhas;
        matriz->qtd_colunas = qtd_colunas;
        matriz->inicio = NULL; // A matriz começa vazia, sem colunas.
    }
    return matriz;
}

/**
 * @brief Insere ou atualiza um elemento na matriz esparsa.
 * Se o valor for 0, o elemento é removido se já existir.
 * @param matriz Ponteiro para a matriz onde a inserção ocorrerá.
 * @param linha Linha do elemento a ser inserido.
 * @param coluna Coluna do elemento a ser inserido.
 * @param valor Valor a ser inserido.
 */
void inserir_elemento(Tipo_Mat_Esparsa *matriz, int linha, int coluna, int valor) {

    // --- PARTE 1: VALIDAÇÕES INICIAIS ---

    // Verifica se o ponteiro da matriz é nulo ou se as posições estão fora dos limites definidos para a matriz.
    if (matriz == NULL || linha >= matriz->qtd_linhas || coluna >= matriz->qtd_colunas || linha < 0 || coluna < 0) {
        printf("Erro: Posicao invalida para insercao!\n");
        return;
    }

    // A matriz esparsa não armazena zeros, então se o valor for 0, a função simplesmente retorna.
    if (valor == 0) {
        return;
    }

    // Não permite valores negativos. Informa o usuário e interrompe a execução.
    if (valor < 0) {
        printf("Aviso: A insercao de valores negativos nao e permitida. Valor fornecido: %d\n", valor);
        return;
    }

    // --- PARTE 2: LOCALIZAR OU CRIAR O NÓ DA COLUNA ---

    // O objetivo desta seção é encontrar a coluna onde o elemento deve ser inserido.
    // Se a coluna não existir na lista, uma nova será criada e inserida na posição correta.

    // Ponteiros para percorrer a lista de colunas.
    tipo_coluna *coluna_anterior = NULL;
    tipo_coluna *coluna_atual = matriz->inicio;

    // Este laço avança na lista de colunas até encontrar o local de inserção.
    while (coluna_atual != NULL && coluna_atual->ID_Coluna < coluna) {
        coluna_anterior = coluna_atual;
        coluna_atual = coluna_atual->proximo;
    }

    // Após o laço, verifica se a coluna exata foi encontrada.
    // Se 'coluna_atual' for nulo ou seu ID for diferente do buscado, significa que a coluna não existe e precisa ser criada.
    if (coluna_atual == NULL || coluna_atual->ID_Coluna != coluna) {
        // Aloca memória para o novo nó da coluna.
        tipo_coluna *coluna_nova = (tipo_coluna*) malloc(sizeof(tipo_coluna));
        if (coluna_nova == NULL) { 
            return;
        }

        // Preenche os dados da nova coluna.
        coluna_nova->ID_Coluna = coluna;
        coluna_nova->inicio = NULL; // A lista de elementos começa vazia.
        coluna_nova->proximo = coluna_atual; // A nova coluna aponta para a próxima (que pode ser NULL).

        if (coluna_anterior == NULL) {
            // Inserção no início da lista de colunas.
            matriz->inicio = coluna_nova;
        } else {
            // Inserção no meio ou no fim da lista de colunas.
            coluna_anterior->proximo = coluna_nova;
        }
        // Atualiza `coluna_atual` para apontar para a nova coluna recém-criada,
        // para que a próxima parte da função possa trabalhar com ela.
        coluna_atual = coluna_nova;
    }

    // --- PARTE 3: LOCALIZAR, ATUALIZAR OU CRIAR O NÓ DO ELEMENTO ---

    // Depois de encontrar a coluna correta, esta seção faz o mesmo
    // processo, mas agora na lista de elementos dentro daquela coluna.

    // Ponteiros para percorrer a lista de elementos.
    tipo_elemento *elemento_anterior = NULL;
    tipo_elemento *elemento_atual = coluna_atual->inicio;

    // Laço para encontrar a posição correta do elemento na lista, baseado na linha.
    while (elemento_atual != NULL && elemento_atual->linha < linha) {
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->proximo;
    }

    // Verifica se um elemento para esta linha já existe.
    if (elemento_atual != NULL && elemento_atual->linha == linha) {
        // Se já existe, simplesmente atualiza o seu valor.
        elemento_atual->valor = valor;
    } else {
        // Se não existe, um novo nó de elemento precisa ser criado e inserido.
        // Aloca memória para o novo elemento.
        tipo_elemento *elemento_novo = (tipo_elemento*) malloc(sizeof(tipo_elemento));
        if (elemento_novo == NULL) {
            return;
        }

        // Preenche os dados do novo elemento.
        elemento_novo->valor = valor;
        elemento_novo->linha = linha;
        elemento_novo->proximo = elemento_atual;

        if (elemento_anterior == NULL) {
            // Inserção no início da lista de elementos da coluna.
            coluna_atual->inicio = elemento_novo;
        } else {
            // Inserção no meio ou no fim da lista de elementos da coluna.
            elemento_anterior->proximo = elemento_novo;
        }
    }
}

/**
 * @brief Pesquisa por um nó de coluna específico.
 * @param matriz Ponteiro para a matriz.
 * @param coluna ID da coluna a ser pesquisada.
 * @return Ponteiro para o nó da coluna ou NULL se não for encontrada.
 */
tipo_coluna* pesquisar_dentro_colunas(Tipo_Mat_Esparsa *matriz, int coluna) {

    // Verifica se o ponteiro da matriz é nulo.
    if (matriz == NULL) {
        return NULL;
    }

    // Inicia um ponteiro 'coluna_atual' que aponta para o começo da lista de colunas.
    // Este ponteiro será usado para "caminhar" pela lista.
    tipo_coluna* coluna_atual = matriz->inicio;

    // Laço que percorre a lista de colunas enquanto o ponteiro não for nulo
    // e o ID da coluna atual for menor que o ID da coluna que estamos procurando.
    while(coluna_atual != NULL && coluna_atual->ID_Coluna < coluna) {
        coluna_atual = coluna_atual->proximo;
    }

    // Após o laço, verifica se o ponteiro 'coluna_atual' não é nulo
    // e se o ID da coluna atual é igual ao ID da coluna que estamos procurando.
    if (coluna_atual != NULL && coluna_atual->ID_Coluna == coluna) {
        // Se encontrar a coluna, retorna o ponteiro para ela.
        return coluna_atual;
    }
    
    // Se não encontrar, retorna NULL.
    return NULL;
}

/**
 * @brief Pesquisa por um elemento em uma linha específica dentro de uma lista de elementos de uma coluna.
 * @param no_coluna Ponteiro para o nó da coluna.
 * @param linha Linha do elemento a ser pesquisado.
 * @return Ponteiro para o elemento ou NULL se não for encontrado.
 */
tipo_elemento* pesquisar_dentro_linhas(tipo_coluna* no_coluna, int linha) {

    // Verifica se o nó da coluna é nulo.
    // Se o ponteiro para o nó da coluna for nulo, significa que a coluna não contém nenhum elemento.
    if (no_coluna == NULL) {
        return NULL;
    }

    // Inicia um ponteiro 'elemento_atual' que aponta para o começo da lista de elementos
    // da coluna fornecida 'no_coluna->inicio'.
    tipo_elemento* elemento_atual = no_coluna->inicio;

    // Laço que percorre a lista de elementos enquanto o ponteiro não for nulo
    // e a linha do elemento atual for menor que a linha que estamos procurando.
    while(elemento_atual != NULL && elemento_atual->linha < linha) {
        elemento_atual = elemento_atual->proximo;
    }

    // Após o laço, verifica se o ponteiro 'elemento_atual' não é nulo
    // e se a linha do elemento atual é igual à linha que estamos procurando.
    if(elemento_atual != NULL && elemento_atual->linha == linha) {
        // Se encontrar o elemento, retorna o ponteiro para ele.
        return elemento_atual;
    }

    // Se não encontrar, retorna NULL.
    return NULL;
}

/**
 * @brief Consulta o valor de um elemento em uma dada posição.
 * @param matriz Ponteiro para a matriz.
 * @param linha Linha do elemento.
 * @param coluna Coluna do elemento.
 * @return O valor do elemento. Retorna 0 se o elemento não estiver armazenado.
 */
int consultar_elemento(Tipo_Mat_Esparsa *matriz, int linha, int coluna) {

    // Verifica se o ponteiro da matriz é nulo ou se as posições estão fora dos limites definidos para a matriz.
    if (matriz == NULL || linha >= matriz->qtd_linhas || coluna >= matriz->qtd_colunas) {
        return 0;
    }

    // Utiliza a função auxiliar para tentar encontrar a lista de elementos correspondente à coluna desejada.
    tipo_coluna* no_coluna = pesquisar_dentro_colunas(matriz, coluna);
    // Se a coluna não for encontrada, significa que todos os elementos nessa coluna são zeros.
    if (no_coluna == NULL) {
        return 0;
    }

    // Utiliza a função auxiliar para tentar encontrar o elemento na linha desejada dentro da coluna encontrada.
    tipo_elemento* no_elemento = pesquisar_dentro_linhas(no_coluna, linha);
    // Se o elemento não for encontrado, significa que o valor nessa posição é zero.
    if (no_elemento == NULL) {
        return 0;
    }

    // Se o elemento for encontrado, retorna o valor armazenado.
    return no_elemento->valor;
}

/**
 * @brief Exibe a matriz no formato convencional (com os zeros).
 * @param matriz Ponteiro para a matriz.
 */
void mostrar_matriz(Tipo_Mat_Esparsa *matriz) {

    // Verifica se o ponteiro da matriz é nulo.
    if (matriz == NULL) {
        return;
    }

    printf("Tamanho da Matriz: (%dx%d)\n", matriz->qtd_linhas, matriz->qtd_colunas);

    // Dois laços aninhados para percorrer cada célula da matriz virtual.

    // O laço externo percorre as linhas.
    for (int i = 0; i < matriz->qtd_linhas; i++) {
        // O laço interno percorre as colunas.
        for (int j = 0; j < matriz->qtd_colunas; j++) {
            // Chama a função para consultar o elemento na posição (i, j).
            printf("%4d ", consultar_elemento(matriz, i, j));
        }
        printf("\n");
    }
}

/**
 * @brief Libera toda a memória alocada para a matriz.
 * @param matriz Ponteiro para a matriz a ser destruída.
 */
void apagar_matriz(Tipo_Mat_Esparsa *matriz) {

    // Verifica se o ponteiro da matriz é nulo.
    if (matriz == NULL) {
        return;
    }

    // Ponteiro para percorrer a lista de colunas.
    tipo_coluna *coluna_atual = matriz->inicio;

    // Laço que percorre todas as colunas da matriz.
    while (coluna_atual != NULL) {
        // Para cada coluna, percorre todos os elementos e libera a memória alocada para eles.
        tipo_elemento *elemento_atual = coluna_atual->inicio;
        while(elemento_atual != NULL) {
            tipo_elemento *elemento_temporario = elemento_atual;
            elemento_atual = elemento_atual->proximo;
            free(elemento_temporario);
        }
        
        // Após liberar todos os elementos da coluna, libera a memória alocada para a coluna em si.
        tipo_coluna *coluna_temporaria = coluna_atual;
        coluna_atual = coluna_atual->proximo;
        free(coluna_temporaria);
    }
    // Finalmente, libera a memória alocada para a estrutura da matriz.
    free(matriz);
}

/**
 * @brief Cria a matriz transposta de uma matriz dada.
 * @param matriz Ponteiro para a matriz original.
 * @return Ponteiro para uma nova matriz que é a transposta da original, ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* criar_transposta(Tipo_Mat_Esparsa *matriz) {

    // Verifica se o ponteiro da matriz é nulo.
    if (matriz == NULL) {
        printf("Erro: Matriz de entrada eh nula.\n");
        return NULL;
    }

    // Cria uma nova matriz com as dimensões invertidas (linhas viram colunas e vice-versa).
    Tipo_Mat_Esparsa *matriz_transposta = criar_matriz(matriz->qtd_colunas, matriz->qtd_linhas);

    // Verifica se a alocação da matriz transposta foi bem-sucedida.
    if (matriz_transposta == NULL) {
        printf("Erro: Falha ao alocar a matriz transposta.\n");
        return NULL;
    }

    // Ponteiro para percorrer a lista de colunas da matriz original.
    tipo_coluna *coluna_original = matriz->inicio;

    // Percorre todas as colunas que contém elementos não-nulos da matriz original.
    while (coluna_original != NULL) {
        // Para cada coluna, prepara um ponteiro para percorrer sua lista de elementos.
        tipo_elemento *elemento_original = coluna_original->inicio;

        // Percorre todos os elementos da coluna atual.
        while (elemento_original != NULL) {
            // Extrai os dados do elemento atual da matriz original.
            int linha_original = elemento_original->linha;
            int coluna_original_id = coluna_original->ID_Coluna;
            int valor = elemento_original->valor;

            // Insere o elemento na posição transposta na nova matriz.
            // A linha da matriz original vira a coluna na transposta e vice-versa.
            inserir_elemento(matriz_transposta, coluna_original_id, linha_original, valor);

            // Avança para o próximo elemento na lista da coluna atual.
            elemento_original = elemento_original->proximo;
        }
        // Após processar todos os elementos da coluna, avança para a próxima coluna.
        coluna_original = coluna_original->proximo;
    }

    // Retorna o ponteiro para a matriz transposta criada.
    return matriz_transposta;
}

/**
 * @brief Soma duas matrizes esparsas.
 * As matrizes devem ter as mesmas dimensões.
 * @param matriz_A Ponteiro para a primeira matriz.
 * @param matriz_B Ponteiro para a segunda matriz.
 * @return Ponteiro para uma nova matriz contendo o resultado da soma, ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* somar_matrizes(Tipo_Mat_Esparsa *matriz_A, Tipo_Mat_Esparsa *matriz_B) {

    // Verifica se os ponteiros das matrizes são nulos.
    if (matriz_A == NULL || matriz_B == NULL) {
        printf("Erro: Uma das matrizes eh nula.\n");
        return NULL;
    }
    // Verifica se a quantidade de linhas e colunas de ambas as matrizes é a mesma.
    if (matriz_A->qtd_linhas != matriz_B->qtd_linhas || matriz_A->qtd_colunas != matriz_B->qtd_colunas) {
        printf("Erro: As dimensoes das matrizes sao incompativeis para a soma.\n");
        return NULL;
    }

    // Cria uma nova matriz vazia com as mesmas dimensões das matrizes de entrada.
    Tipo_Mat_Esparsa *matriz_resultado = criar_matriz(matriz_A->qtd_linhas, matriz_A->qtd_colunas);
    // Verifica se a alocação da matriz de resultado foi bem-sucedida.
    if (matriz_resultado == NULL) {
        printf("Erro: Falha ao alocar a matriz de resultado.\n");
        return NULL;
    }

    // Ponteiro para percorrer a matriz_A.
    tipo_coluna *coluna_matriz_A = matriz_A->inicio;

    // Primeiro, insere todos os elementos da matriz_A na matriz_resultado.
    while (coluna_matriz_A != NULL) {
        tipo_elemento *elem_matriz_A = coluna_matriz_A->inicio;
        while (elem_matriz_A != NULL) {
            inserir_elemento(matriz_resultado, elem_matriz_A->linha, coluna_matriz_A->ID_Coluna, elem_matriz_A->valor);
            elem_matriz_A = elem_matriz_A->proximo;
        }
        coluna_matriz_A = coluna_matriz_A->proximo;
    }

    // Ponteiro para percorrer a matriz_B.
    tipo_coluna *coluna_matriz_B = matriz_B->inicio;

    while (coluna_matriz_B != NULL) {
        tipo_elemento *elem_matriz_B = coluna_matriz_B->inicio;
        while (elem_matriz_B != NULL) {
            // Consulta o valor existente na matriz_resultado.
            int valor_existente = consultar_elemento(matriz_resultado, elem_matriz_B->linha, coluna_matriz_B->ID_Coluna);
            
            // Insere a soma do valor existente com o valor do elemento da matriz_B.
            inserir_elemento(matriz_resultado, elem_matriz_B->linha, coluna_matriz_B->ID_Coluna, valor_existente + elem_matriz_B->valor);

            elem_matriz_B = elem_matriz_B->proximo;
        }
        coluna_matriz_B = coluna_matriz_B->proximo;
    }

    // Retorna a matriz resultante da soma.
    return matriz_resultado;
}

/**
 * @brief Multiplica duas matrizes esparsas (matriz_A * matriz_B).
 * O número de colunas da matriz_A deve ser igual ao número de linhas da matriz_B.
 * @param matriz_A Ponteiro para a primeira matriz.
 * @param matriz_B Ponteiro para a segunda matriz.
 * @return Ponteiro para uma nova matriz com o resultado da multiplicação, ou NULL em caso de erro.
 */
Tipo_Mat_Esparsa* multiplicar_matrizes(Tipo_Mat_Esparsa *matriz_A, Tipo_Mat_Esparsa *matriz_B) {

    // Verifica se os ponteiros das matrizes são nulos.
    if (matriz_A == NULL || matriz_B == NULL) {
        printf("Erro: Uma das matrizes eh nula.\n");
        return NULL;
    }

    // Verifica se as dimensões são compatíveis para multiplicação.
    // O número de colunas da matriz_A deve ser igual ao número de linhas da matriz_B.
    if (matriz_A->qtd_colunas != matriz_B->qtd_linhas) {
        printf("Erro: Dimensoes incompativeis para multiplicacao.\n");
        printf("(Colunas da matriz_A: %d, Linhas da matriz_B: %d)\n", matriz_A->qtd_colunas, matriz_B->qtd_linhas);
        return NULL;
    }

    // Cria a matriz de resultado. Suas dimensões serão (linhas de A x colunas de B).
    Tipo_Mat_Esparsa *matriz_resultado = criar_matriz(matriz_A->qtd_linhas, matriz_B->qtd_colunas);
    if (matriz_resultado == NULL) {
        return NULL;
    }

    // Cria a transposta da matriz_A para facilitar o acesso às linhas.
    Tipo_Mat_Esparsa *matriz_A_t = criar_transposta(matriz_A);
    // Se a criação da transposta falhar, libera a memória que já foi alocada para a matriz_resultado antes de sair da função.
    if (matriz_A_t == NULL) {
        apagar_matriz(matriz_resultado);
        return NULL;
    }

    // Ponteiro para percorrer as colunas da matriz transposta de A (que são as linhas de A).
    tipo_coluna *coluna_matriz_A_t = matriz_A_t->inicio;

    // Laço que percorre cada coluna da matriz transposta de A.
    while (coluna_matriz_A_t != NULL) {
        int i = coluna_matriz_A_t->ID_Coluna;

        // Ponteiro para percorrer as colunas da matriz B.
        tipo_coluna *coluna_matriz_B = matriz_B->inicio;

        // Laço que percorre cada coluna da matriz B.
        while (coluna_matriz_B != NULL) {
            int j = coluna_matriz_B->ID_Coluna;
            
            // Ponteiros para percorrer as listas de elementos das duas colunas.
            tipo_elemento *elemento_1 = coluna_matriz_A_t->inicio;
            tipo_elemento *elemento_2 = coluna_matriz_B->inicio;
            // Variável para armazenar o resultado da soma dos produtos.
            int soma_produto = 0;

            // Laço que percorre ambas as listas de elementos simultaneamente.
            // Ele só precisa somar os produtos quando os índices de linha são iguais.
            while (elemento_1 != NULL && elemento_2 != NULL) {
                if (elemento_1->linha < elemento_2->linha) {
                    elemento_1 = elemento_1->proximo; // Avança a lista 1.
                } else if (elemento_2->linha < elemento_1->linha) {
                    elemento_2 = elemento_2->proximo; // Avança a lista 2.
                } else {
                    soma_produto += elemento_1->valor * elemento_2->valor;
                    // Avança ambos os ponteiros para procurar o próximo par correspondente.
                    elemento_1 = elemento_1->proximo;
                    elemento_2 = elemento_2->proximo;
                }
            }

            // Se a soma dos produtos for diferente de zero, insere o valor na matriz resultado.
            if (soma_produto != 0) {
                inserir_elemento(matriz_resultado, i, j, soma_produto);
            }
            coluna_matriz_B = coluna_matriz_B->proximo;
        }
        coluna_matriz_A_t = coluna_matriz_A_t->proximo;
    }

    // Libera a memória alocada para a matriz transposta de A, que não é mais necessária.
    apagar_matriz(matriz_A_t);

    // Retorna a matriz resultante da multiplicação.
    return matriz_resultado;
}