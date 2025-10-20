#include <stdio.h>
#include <stdlib.h>

// --- Estruturas de Dados ---

// Estrutura para um nó da lista de adjacência (horizontal)
typedef struct NoAdjacente {
    int vertice;    // O vértice vizinho
    struct NoAdjacente *proximo;   // Próximo vizinho na lista
} NoAdjacente;

// Estrutura para um nó da lista de vértices (vertical)
typedef struct NoVertice {
    int vertice;    // O próprio vértice
    struct NoVertice *proximoVertice;   // Próximo vértice na lista principal
    struct NoAdjacente *inicioListaAdjacente;    // Ponteiro para o início da lista de adjacência
} NoVertice;

// Estrutura principal do Grafo
typedef struct Grafo {
    NoVertice *inicio; // Ponteiro para o primeiro vértice da lista
} Grafo;

// --- Funções Auxiliares de Criação ---

// Cria um novo nó de adjacência (vizinho)
NoAdjacente* criarNoAdjacente(int v) {
    NoAdjacente* novoNo = (NoAdjacente*)malloc(sizeof(NoAdjacente));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novoNo->vertice = v;
    novoNo->proximo = NULL;
    return novoNo;
}

// Cria um novo nó de vértice
NoVertice* criarNoVertice(int v) {
    NoVertice* novoNo = (NoVertice*)malloc(sizeof(NoVertice));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novoNo->vertice = v;
    novoNo->proximoVertice = NULL;
    novoNo->inicioListaAdjacente = NULL;
    return novoNo;
}

// Inicializa e cria o grafo
Grafo* criarGrafo() {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if (grafo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    grafo->inicio = NULL;
    return grafo;
}

// --- Funções Auxiliares de Busca e Helpers Internos ---

// Busca por um vértice na lista principal (vertical)
NoVertice* buscarVertice(Grafo* grafo, int v) {
    NoVertice* temp = grafo->inicio;
    while (temp != NULL) {
        if (temp->vertice == v) {
            return temp;
        }
        temp = temp->proximoVertice;
    }
    return NULL;
}

// Função auxiliar para inserir um vizinho na lista de adjacência (ordenado)
// (Usada por inserirAresta e inserirArestaAutomatico)
void adicionarVizinho(NoVertice* no, int vizinho) {
    NoAdjacente* novoNo = criarNoAdjacente(vizinho);

    // Insere o novo vizinho na lista de adjacência de forma ordenada
    if (no->inicioListaAdjacente == NULL || no->inicioListaAdjacente->vertice > vizinho) {
        // Insere o novo nó no início da lista de adjacência.
        novoNo->proximo = no->inicioListaAdjacente;
        no->inicioListaAdjacente = novoNo;
    } else {
        // Se não for inserido no início, percorre a lista para achar a posição.
        NoAdjacente* temp = no->inicioListaAdjacente;
        while (temp->proximo != NULL && temp->proximo->vertice < vizinho) {
            temp = temp->proximo;
        }
        // Insere o 'novoNo' após 'temp' e antes do nó seguinte a 'temp'.
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
    }
}

// Função auxiliar para remover um vizinho da lista de adjacência
// (Usada por removerVertice e removerAresta)
int removerVizinho(NoVertice* no, int vizinho) {
    NoAdjacente *temp = no->inicioListaAdjacente, *prev = NULL;

    // Percorre a lista de adjacência para encontrar o vizinho a ser removido
    while (temp != NULL && temp->vertice != vizinho) {
        prev = temp;
        temp = temp->proximo;
    }

    // Se o vizinho não foi encontrado
    if (temp == NULL) {
        return 0;
    }

    // Remove o vizinho encontrado
    if (prev == NULL) {
        // Se o vizinho a ser removido é o primeiro da lista
        no->inicioListaAdjacente = temp->proximo;
    } else {
        // Se o vizinho a ser removido não é o primeiro
        prev->proximo = temp->proximo;
    }

    free(temp); 
    return 1;
}

// Função interna para inserir vértice (sem input do usuário)
// Retorna o nó criado ou o nó existente
NoVertice* inserirVerticeAutomatico(Grafo* grafo, int v) {
    NoVertice* existente = buscarVertice(grafo, v);
    if (existente != NULL) {
        return existente; // Vértice já existe, apenas retorna
    }

    // Cria o novo nó de vértice
    NoVertice* novoNo = criarNoVertice(v);

    // Insere o novo vértice na lista principal de forma ordenada
    if (grafo->inicio == NULL || grafo->inicio->vertice > v) {
        // Insere no início
        novoNo->proximoVertice = grafo->inicio;
        grafo->inicio = novoNo;
    } else {
        // Insere em posição correta
        NoVertice* temp = grafo->inicio;
        while (temp->proximoVertice != NULL && temp->proximoVertice->vertice < v) {
            temp = temp->proximoVertice;
        }
        // Insere após 'temp' e antes do próximo
        novoNo->proximoVertice = temp->proximoVertice;
        temp->proximoVertice = novoNo;
    }
    return novoNo;
}

// Função interna para inserir aresta (sem input do usuário)
void inserirArestaAutomatico(Grafo* grafo, int v1, int v2) {
    NoVertice* no1 = buscarVertice(grafo, v1);
    NoVertice* no2 = buscarVertice(grafo, v2);

    // Não insere se vértices não existem ou é laço
    if (no1 == NULL || no2 == NULL || v1 == v2) {
        return;
    }

    // Verifica se a aresta já existe
    NoAdjacente* temp = no1->inicioListaAdjacente;
    while (temp != NULL) {
        if (temp->vertice == v2) {
            return; // Aresta já existe
        }
        temp = temp->proximo;
    }

    // Adiciona a aresta nos dois sentidos
    adicionarVizinho(no1, v2);
    adicionarVizinho(no2, v1);
}

// Helper para limpar todos os vértices e arestas do grafo
// Usado por liberarGrafo() e inserirGrafoPadrao()
void limparGrafo(Grafo* grafo) {
    NoVertice* verticeTemp = grafo->inicio;
    
    while (verticeTemp != NULL) {
        // 1. Libera a lista de adjacência (horizontal)
        NoAdjacente* arestaTemp = verticeTemp->inicioListaAdjacente;
        while (arestaTemp != NULL) {
            NoAdjacente* liberar = arestaTemp;
            arestaTemp = arestaTemp->proximo;
            free(liberar);
        }
        
        // 2. Libera o nó do vértice (vertical)
        NoVertice* verticeParaLiberar = verticeTemp;
        verticeTemp = verticeTemp->proximoVertice;
        free(verticeParaLiberar);
    }
    
    // 3. Reseta o ponteiro principal do grafo
    grafo->inicio = NULL;
}


// --- Funções do Menu ---

// 1. Inserir Vértice
void inserirVertice(Grafo* grafo) {
    int v;
    printf("Digite o numero do vertice a ser inserido: ");
    scanf("%d", &v);

    // Verifica se o vértice já existe
    if (buscarVertice(grafo, v) != NULL) {
        printf("Erro: O vertice %d ja existe no grafo.\n", v);
        return;
    }
    
    // Chama a função interna para fazer a inserção
    inserirVerticeAutomatico(grafo, v);

    printf("Vertice %d inserido com sucesso.\n", v);
}

// 2. Inserir Aresta
void inserirAresta(Grafo* grafo) {
    int v1, v2;
    printf("Digite os dois vertices da aresta (ex: 3 5): ");
    scanf("%d %d", &v1, &v2);

    if (v1 == v2) {
        printf("Erro: Nao sao permitidos lacos (aresta de um vertice para ele mesmo).\n");
        return;
    }

    NoVertice* no1 = buscarVertice(grafo, v1);
    NoVertice* no2 = buscarVertice(grafo, v2);

    if (no1 == NULL || no2 == NULL) {
        printf("Erro: Um ou ambos os vertices (%d, %d) nao existem no grafo.\n", v1, v2);
        return;
    }

    NoAdjacente* temp = no1->inicioListaAdjacente;
    while (temp != NULL) {
        if (temp->vertice == v2) {
            printf("Erro: A aresta %d - %d ja existe.\n", v1, v2);
            return;
        }
        temp = temp->proximo;
    }

    // Chama a função interna para inserir
    inserirArestaAutomatico(grafo, v1, v2);

    printf("Aresta %d - %d inserida com sucesso.\n", v1, v2);
}

// 3. Visualizar Grafo
void visualizarGrafo(Grafo* grafo) {
    NoVertice* verticeTemp = grafo->inicio; 

    if (verticeTemp == NULL) {
        printf("O grafo esta vazio.\n");
        return;
    }

    printf("\n--------------- Representacao do Grafo ---------------\n");
    while (verticeTemp != NULL) {
        printf("Vertice [%d] -> ", verticeTemp->vertice);
        
        NoAdjacente* arestaTemp = verticeTemp->inicioListaAdjacente; 
        while (arestaTemp != NULL) {
            printf("%d -> ", arestaTemp->vertice);
            arestaTemp = arestaTemp->proximo;
        }
        printf("NULL\n");
        
        verticeTemp = verticeTemp->proximoVertice; 
    }
    printf("-----------------------------------------------------\n");
}

// 4. Remover Vértice
void removerVertice(Grafo* grafo) {
    int v;
    printf("Digite o numero do vertice a ser removido: ");
    scanf("%d", &v);

    NoVertice *verticeParaRemover = buscarVertice(grafo, v);
    if (verticeParaRemover == NULL) {
        printf("Erro: O vertice %d nao foi encontrado.\n", v);
        return;
    }

    // Remove todas as arestas conectadas ao vértice 'v'
    NoVertice* verticeTemp = grafo->inicio;
    while (verticeTemp != NULL) {
        if (verticeTemp->vertice != v) {
            removerVizinho(verticeTemp, v); 
        }
        verticeTemp = verticeTemp->proximoVertice;
    }

    // Libera a lista de adjacência do próprio vértice 'v'
    NoAdjacente* arestaTemp = verticeParaRemover->inicioListaAdjacente;
    while (arestaTemp != NULL) {
        NoAdjacente* liberar = arestaTemp;  // Guarda o nó atual
        arestaTemp = arestaTemp->proximo;   // Avança para o próximo
        free(liberar);  // Libera o nó guardado
    }
    verticeParaRemover->inicioListaAdjacente = NULL;

    // Remove o vértice da lista principal
    NoVertice *prev = NULL;
    verticeTemp = grafo->inicio;

    // Encontra o vértice anterior
    while (verticeTemp != NULL && verticeTemp->vertice != v) {
        prev = verticeTemp;
        verticeTemp = verticeTemp->proximoVertice;
    }

    // Remove o vértice da lista
    if (prev == NULL) {
        // Se o vértice a ser removido é o primeiro da lista
        grafo->inicio = verticeParaRemover->proximoVertice;
    } else {
        // Se o vértice a ser removido não é o primeiro da lista
        prev->proximoVertice = verticeParaRemover->proximoVertice;
    }

    free(verticeParaRemover); 
    printf("Vertice %d e todas as suas arestas foram removidos.\n", v);
}

// 5. Remover Aresta
void removerAresta(Grafo* grafo) {
    int v1, v2;
    printf("Digite os dois vertices da aresta a ser removida (ex: 3 5): ");
    scanf("%d %d", &v1, &v2);

    NoVertice* no1 = buscarVertice(grafo, v1);
    NoVertice* no2 = buscarVertice(grafo, v2);

    if (no1 == NULL || no2 == NULL) {
        printf("Erro: Um ou ambos os vertices (%d, %d) nao existem.\n", v1, v2);
        return;
    }

    // Tenta remover 'v1' e 'v2' das listas de adjacência
    int sucesso1 = removerVizinho(no1, v2);
    int sucesso2 = removerVizinho(no2, v1);

    if (sucesso1 && sucesso2) {
        printf("Aresta %d - %d removida com sucesso.\n", v1, v2);
    } else {
        printf("Erro: A aresta %d - %d nao foi encontrada.\n", v1, v2);
    }
}

// 6. Inserir Grafo Padrão
void inserirGrafoPadrao(Grafo* grafo) {
    // Limpa o grafo atual para evitar duplicatas
    limparGrafo(grafo); 
    printf("Limpando grafo atual e inserindo grafo padrao...\n");

    // Inserir todos os vértices
    int vertices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numVertices = sizeof(vertices) / sizeof(vertices[0]);
    for (int i = 0; i < numVertices; i++) {
        inserirVerticeAutomatico(grafo, vertices[i]);
    }

    // Inserir as arestas
    // [1] -> 2 -> 6
    // [2] -> 1 -> 4 -> 3
    // [3] -> 2 -> 5
    // [4] -> 6 -> 2 -> 5 -> 7
    // [5] -> 3 -> 4
    // [6] -> 1 -> 4
    // [7] -> 4 -> 9 -> 8
    // [8] -> 7
    // [9] -> 7
    inserirArestaAutomatico(grafo, 1, 2);
    inserirArestaAutomatico(grafo, 1, 6);
    inserirArestaAutomatico(grafo, 2, 4);
    inserirArestaAutomatico(grafo, 2, 3);
    inserirArestaAutomatico(grafo, 3, 5);
    inserirArestaAutomatico(grafo, 4, 6);
    inserirArestaAutomatico(grafo, 4, 5);
    inserirArestaAutomatico(grafo, 4, 7);
    inserirArestaAutomatico(grafo, 7, 9);
    inserirArestaAutomatico(grafo, 7, 8);
    
    printf("Grafo padrao inserido com sucesso.\n");
    // Mostra o resultado automaticamente
    visualizarGrafo(grafo); 
}

// 7. Sair (e liberar toda a memória)
void liberarGrafo(Grafo* grafo) {
    limparGrafo(grafo); // Chama a nova função de limpeza
    free(grafo); // Libera a estrutura do grafo em si
    printf("Memoria do grafo liberada. Saindo...\n");
}

// --- Funções de Interface ---

// Limpa o buffer de entrada (para evitar problemas com scanf)
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Mostra o menu de opções
void mostrarMenu() {
    printf("\n--- Gerenciador de Grafo (Listas de Adjacencia) ---\n");
    printf("1. Inserir Vertice\n");
    printf("2. Inserir Aresta\n");
    printf("3. Visualizar Grafo\n");
    printf("4. Remover Vertice\n");
    printf("5. Remover Aresta\n");
    printf("6. Inserir Grafo Padrao (TESTE)\n");
    printf("7. Sair\n");
    printf("--------------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

// --- Função Principal ---

int main() {
    Grafo* meuGrafo = criarGrafo();
    int escolha = 0;

    do {
        mostrarMenu();
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (escolha) {
            case 1:
                inserirVertice(meuGrafo);
                break;
            case 2:
                inserirAresta(meuGrafo);
                break;
            case 3:
                visualizarGrafo(meuGrafo);
                break;
            case 4:
                removerVertice(meuGrafo);
                break;
            case 5:
                removerAresta(meuGrafo);
                break;
            case 6:
                inserirGrafoPadrao(meuGrafo);
                break;
            case 7:
                liberarGrafo(meuGrafo);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 7);

    return 0;
}