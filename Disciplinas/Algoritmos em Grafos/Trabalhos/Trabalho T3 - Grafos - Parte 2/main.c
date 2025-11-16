#include <stdio.h>
#include <stdlib.h>

// Define os códigos de cores ANSI
#define ANSI_COLOR_RED     "\x1b[31m"  // Vermelho
#define ANSI_COLOR_GREEN   "\x1b[32m"  // Verde
#define ANSI_COLOR_YELLOW  "\x1b[33m"  // Amarelo
#define ANSI_COLOR_BLUE    "\x1b[34m"  // Azul
#define ANSI_COLOR_CYAN    "\x1b[36m"  // Ciano
#define ANSI_COLOR_RESET   "\x1b[0m"   // Reseta a cor para o padrão

// --- Estruturas de Dados ---

// Estrutura para um nó da lista de adjacência (horizontal)
typedef struct NoAdjacente {
    int vertice;    // O vértice adjacente
    int peso;       // O peso da aresta
    struct NoAdjacente *proximo;   // Próximo adjacente na lista
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

// Estrutura auxiliar para rastrear nós visitados
typedef struct NoVisitado {
    int vertice;
    struct NoVisitado *proximo;
} NoVisitado;

// --- Funções Auxiliares de Criação ---

// Cria um novo nó de adjacência (vizinho)
NoAdjacente* criarNoAdjacente(int v, int peso) {
    NoAdjacente* novoNo = (NoAdjacente*)malloc(sizeof(NoAdjacente));
    if (novoNo == NULL) {
        printf(ANSI_COLOR_RED "Erro de alocacao de memoria!\n" ANSI_COLOR_RESET);
        exit(1);
    }
    novoNo->vertice = v;
    novoNo->peso = peso;
    novoNo->proximo = NULL;
    return novoNo;
}

// Cria um novo nó de vértice
NoVertice* criarNoVertice(int v) {
    NoVertice* novoNo = (NoVertice*)malloc(sizeof(NoVertice));
    if (novoNo == NULL) {
        printf(ANSI_COLOR_RED "Erro de alocacao de memoria!\n" ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_RED "Erro de alocacao de memoria!\n" ANSI_COLOR_RESET);
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
void adicionarVizinho(NoVertice* no, int vizinho, int peso) {
    NoAdjacente* novoNo = criarNoAdjacente(vizinho, peso);

    if (no->inicioListaAdjacente == NULL || no->inicioListaAdjacente->vertice > vizinho) {
        novoNo->proximo = no->inicioListaAdjacente;
        no->inicioListaAdjacente = novoNo;
    } else {
        NoAdjacente* temp = no->inicioListaAdjacente;
        while (temp->proximo != NULL && temp->proximo->vertice < vizinho) {
            temp = temp->proximo;
        }
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
    }
}

// Função auxiliar para remover um vizinho da lista de adjacência
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

// Função interna para inserir vértice
NoVertice* inserirVerticeNoGrafo(Grafo* grafo, int v) {
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

// Função interna para inserir aresta
void inserirArestaNoGrafo(Grafo* grafo, int v1, int v2, int peso) {
    NoVertice* no1 = buscarVertice(grafo, v1);
    NoVertice* no2 = buscarVertice(grafo, v2);

    if (no1 == NULL || no2 == NULL || v1 == v2) {
        return;
    }

    NoAdjacente* temp = no1->inicioListaAdjacente;
    while (temp != NULL) {
        if (temp->vertice == v2) {
            return; // Aresta já existe
        }
        temp = temp->proximo;
    }

    // Adiciona a aresta com peso nos dois sentidos
    adicionarVizinho(no1, v2, peso);
    adicionarVizinho(no2, v1, peso);
}

// Helper para limpar todos os vértices e arestas do grafo
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

// --- Helpers para Travessia, Grau e Ciclos ---

// Adiciona um vértice à lista de visitados
NoVisitado* adicionarVisitado(NoVisitado* inicio, int vertice) {
    NoVisitado* novoNo = (NoVisitado*)malloc(sizeof(NoVisitado));
    if (novoNo == NULL) {
        printf(ANSI_COLOR_RED "Erro de alocacao de memoria ao visitar!\n" ANSI_COLOR_RESET);
        exit(1);
    }
    novoNo->vertice = vertice;
    novoNo->proximo = inicio;
    return novoNo;
}

// Verifica se um vértice já foi visitado
int estaVisitado(NoVisitado* inicio, int vertice) {
    NoVisitado* temp = inicio;
    while (temp != NULL) {
        if (temp->vertice == vertice) {
            return 1; // True
        }
        temp = temp->proximo;
    }
    return 0; // False
}

// Libera a lista de visitados
void liberarListaVisitados(NoVisitado* inicio) {
    while (inicio != NULL) {
        NoVisitado* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

// Algoritmo de Busca em Profundidade
void visitarBuscaProfundidade(Grafo* grafo, int vertice, NoVisitado** listaVisitados) {
    // Marca o vértice atual como visitado
    *listaVisitados = adicionarVisitado(*listaVisitados, vertice);

    NoVertice* noVertice = buscarVertice(grafo, vertice);
    if (noVertice == NULL) return; // Segurança

    // Itera por todos os vizinhos
    NoAdjacente* vizinho = noVertice->inicioListaAdjacente;
    while (vizinho != NULL) {
        // Se o vizinho ainda não foi visitado, visita recursivamente
        if (!estaVisitado(*listaVisitados, vizinho->vertice)) {
            visitarBuscaProfundidade(grafo, vizinho->vertice, listaVisitados);
        }
        vizinho = vizinho->proximo;
    }
}

// Busca em Profundidade modificada para contar Vértices (V) e Arestas (E) de um componente
void buscaProfundidadeCiclos(Grafo* grafo, int v, NoVisitado** visitadosGeral, int* V_i, int* E_i_duplicado) {
    *V_i += 1; // Conta o vértice
    *visitadosGeral = adicionarVisitado(*visitadosGeral, v);
    
    NoVertice* noV = buscarVertice(grafo, v);
    if (noV == NULL) return;

    NoAdjacente* vizinho = noV->inicioListaAdjacente;
    while (vizinho != NULL) {
        *E_i_duplicado += 1; // Conta aresta (será contada 2x)
        
        if (!estaVisitado(*visitadosGeral, vizinho->vertice)) {
            buscaProfundidadeCiclos(grafo, vizinho->vertice, visitadosGeral, V_i, E_i_duplicado);
        }
        vizinho = vizinho->proximo;
    }
}

// Conta e retorna o número de componentes conexas
int analisarComponentes(Grafo* grafo) {
    NoVisitado* visitados = NULL;
    int componentes = 0;
    NoVertice* temp = grafo->inicio;

    while (temp != NULL) {
        if (!estaVisitado(visitados, temp->vertice)) {
            componentes++;
            visitarBuscaProfundidade(grafo, temp->vertice, &visitados);
        }
        temp = temp->proximoVertice;
    }
    
    liberarListaVisitados(visitados);
    return componentes;
}

// Calcula o grau de um nó (quantos vizinhos ele tem)
int calcularGrau(NoVertice* no) {
    int grau = 0;
    NoAdjacente* temp = no->inicioListaAdjacente;
    while (temp != NULL) {
        grau++;
        temp = temp->proximo;
    }
    return grau;
}


// --- Funções do Menu ---

// 1. Inserir Vértice
void inserirVertice(Grafo* grafo) {
    int v;
    printf(ANSI_COLOR_BLUE "Digite o numero do vertice a ser inserido: " ANSI_COLOR_RESET);
    scanf("%d", &v);

    // Verifica se o vértice já existe
    if (buscarVertice(grafo, v) != NULL) {
        printf(ANSI_COLOR_RED "Erro: O vertice %d ja existe no grafo.\n" ANSI_COLOR_RESET, v);
        return;
    }
    
    // Chama a função interna para fazer a inserção
    inserirVerticeNoGrafo(grafo, v);
    printf(ANSI_COLOR_GREEN "Vertice %d inserido com sucesso.\n" ANSI_COLOR_RESET, v);
}

// 2. Inserir Aresta
void inserirAresta(Grafo* grafo) {
    int v1, v2, peso;
    printf(ANSI_COLOR_BLUE "Digite os dois vertices e o PESO da aresta (ex: 3 5 10): " ANSI_COLOR_RESET);
    scanf("%d %d %d", &v1, &v2, &peso);

    if (v1 == v2) {
        printf(ANSI_COLOR_RED "Erro: Nao sao permitidos lacos.\n" ANSI_COLOR_RESET);
        return;
    }
    NoVertice* no1 = buscarVertice(grafo, v1);
    NoVertice* no2 = buscarVertice(grafo, v2);
    if (no1 == NULL || no2 == NULL) {
        printf(ANSI_COLOR_RED "Erro: Um ou ambos os vertices (%d, %d) nao existem.\n" ANSI_COLOR_RESET, v1, v2);
        return;
    }
    NoAdjacente* temp = no1->inicioListaAdjacente;
    while (temp != NULL) {
        if (temp->vertice == v2) {
            printf(ANSI_COLOR_RED "Erro: A aresta %d - %d ja existe.\n" ANSI_COLOR_RESET, v1, v2);
            return;
        }
        temp = temp->proximo;
    }

    inserirArestaNoGrafo(grafo, v1, v2, peso);
    printf(ANSI_COLOR_GREEN "Aresta %d - %d (Peso: %d) inserida com sucesso.\n" ANSI_COLOR_RESET, v1, v2, peso);
}

// 3. Remover Vértice
void removerVertice(Grafo* grafo) {
    int v;
    printf(ANSI_COLOR_BLUE "Digite o numero do vertice a ser removido: " ANSI_COLOR_RESET);
    scanf("%d", &v);

    NoVertice *verticeParaRemover = buscarVertice(grafo, v);
    if (verticeParaRemover == NULL) {
        printf(ANSI_COLOR_RED "Erro: O vertice %d nao foi encontrado.\n" ANSI_COLOR_RESET, v);
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
    printf(ANSI_COLOR_GREEN "Vertice %d e todas as suas arestas foram removidos.\n" ANSI_COLOR_RESET, v);
}

// 4. Remover Aresta
void removerAresta(Grafo* grafo) {
    int v1, v2;
    printf(ANSI_COLOR_BLUE "Digite os dois vertices da aresta a ser removida (ex: 3 5): " ANSI_COLOR_RESET);
    scanf("%d %d", &v1, &v2);

    NoVertice* no1 = buscarVertice(grafo, v1);
    NoVertice* no2 = buscarVertice(grafo, v2);

    if (no1 == NULL || no2 == NULL) {
        printf(ANSI_COLOR_RED "Erro: Um ou ambos os vertices (%d, %d) nao existem.\n" ANSI_COLOR_RESET, v1, v2);
        return;
    }

    // Tenta remover 'v1' e 'v2' das listas de adjacência
    int sucesso1 = removerVizinho(no1, v2);
    int sucesso2 = removerVizinho(no2, v1);

    if (sucesso1 && sucesso2) {
        printf(ANSI_COLOR_GREEN "Aresta %d - %d removida com sucesso.\n" ANSI_COLOR_RESET, v1, v2);
    } else {
        printf(ANSI_COLOR_RED "Erro: A aresta %d - %d nao foi encontrada.\n" ANSI_COLOR_RESET, v1, v2);
    }
}

// 5. Visualizar Grafo
void visualizarGrafo(Grafo* grafo) {
    NoVertice* verticeTemp = grafo->inicio; 
    if (verticeTemp == NULL) {
        printf(ANSI_COLOR_YELLOW "O grafo esta vazio.\n" ANSI_COLOR_RESET);
        return;
    }
    printf("\n" ANSI_COLOR_CYAN "--------------- Representacao do Grafo ---------------\n");
    while (verticeTemp != NULL) {
        printf("Vertice [%d] -> ", verticeTemp->vertice);
        NoAdjacente* arestaTemp = verticeTemp->inicioListaAdjacente; 
        while (arestaTemp != NULL) {
            // Imprime o vértice vizinho e seu peso
            printf("%d(p:%d) -> ", arestaTemp->vertice, arestaTemp->peso); 
            arestaTemp = arestaTemp->proximo;
        }
        printf("NULL\n");
        verticeTemp = verticeTemp->proximoVertice; 
    }
    printf("-----------------------------------------------------\n" ANSI_COLOR_RESET);
}

// 6. Informar grau de um vértice
void informarGrauVertice(Grafo* grafo) {
    int v;
    printf(ANSI_COLOR_BLUE "Digite o vertice para consultar o grau: " ANSI_COLOR_RESET);
    scanf("%d", &v);
    
    NoVertice* no = buscarVertice(grafo, v);
    if (no == NULL) {
        printf(ANSI_COLOR_RED "Erro: O vertice %d nao foi encontrado.\n" ANSI_COLOR_RESET, v);
        return;
    }

    int grau = calcularGrau(no);
    printf(ANSI_COLOR_YELLOW "O grau do vertice %d eh: %d\n" ANSI_COLOR_RESET, v, grau);
}

// 7. Informar se o grafo é Euleriano
void informarGrafoEuleriano(Grafo* grafo) {
    if (grafo->inicio == NULL) {
        printf(ANSI_COLOR_GREEN "O grafo eh Euleriano (trivialmente, pois esta vazio).\n" ANSI_COLOR_RESET);
        return;
    }

    int todosGrauPar = 1;
    NoVertice* primeiroNaoIsolado = NULL; // Primeiro vértice que tem arestas
    NoVertice* tempV = grafo->inicio;

    // 1. Verifica se todos os vértices têm grau par
    while(tempV != NULL) {
        int grau = calcularGrau(tempV);
        if (grau % 2 != 0) {
            todosGrauPar = 0;
        }
        // Guarda o primeiro vértice com arestas para iniciar a verificação de conectividade
        if (grau > 0 && primeiroNaoIsolado == NULL) {
            primeiroNaoIsolado = tempV;
        }
        tempV = tempV->proximoVertice;
    }

    if (primeiroNaoIsolado == NULL) {
        printf(ANSI_COLOR_GREEN "O grafo eh Euleriano (trivialmente, nao possui arestas).\n" ANSI_COLOR_RESET);
        return;
    }
    
    if (!todosGrauPar) {
        printf(ANSI_COLOR_YELLOW "O grafo NAO eh Euleriano (existe vertice de grau impar).\n" ANSI_COLOR_RESET);
        return;
    }

    // 2. Verifica se todos os vértices COM ARESTAS estão na mesma componente
    NoVisitado* visitados = NULL;
    visitarBuscaProfundidade(grafo, primeiroNaoIsolado->vertice, &visitados);

    tempV = grafo->inicio;
    int conectado = 1;
    while (tempV != NULL) {
        // Se um vértice tem arestas (grau > 0) e não foi visitado,
        // significa que ele está em outra componente.
        if (calcularGrau(tempV) > 0 && !estaVisitado(visitados, tempV->vertice)) {
            conectado = 0;
            break;
        }
        tempV = tempV->proximoVertice;
    }
    
    liberarListaVisitados(visitados);
    
    if (conectado) {
        printf(ANSI_COLOR_GREEN "O grafo eh Euleriano.\n" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_YELLOW "O grafo NAO eh Euleriano (os vertices com arestas nao sao conexos).\n" ANSI_COLOR_RESET);
    }
}

// 8. Informar se o grafo é conexo
void informarConectividade(Grafo* grafo) {
    if (grafo->inicio == NULL) {
        printf(ANSI_COLOR_YELLOW "O grafo esta vazio.\n" ANSI_COLOR_RESET);
        return;
    }
    
    int numComponentes = analisarComponentes(grafo);
    
    if (numComponentes == 1) {
        printf(ANSI_COLOR_GREEN "O grafo eh conexo.\n" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_YELLOW "O grafo NAO eh conexo. Possui %d componentes conexas.\n" ANSI_COLOR_RESET, numComponentes);
    }
}

// 9. Informar se o grafo possui ciclos
void informarCiclos(Grafo* grafo) {
    NoVisitado* visitadosGeral = NULL;
    NoVertice* tempV = grafo->inicio;
    int componenteID = 0;
    int totalCiclos = 0;

    printf(ANSI_COLOR_YELLOW "--- Analise de Ciclos (Formula de Euler: C = E - V + 1 por componente) ---\n");

    while(tempV != NULL) {
        if (!estaVisitado(visitadosGeral, tempV->vertice)) {
            componenteID++;
            int V_i = 0; // Vértices na componente
            int E_i_duplicado = 0; // Arestas contadas duas vezes

            // Usa Busca em Profundidade para contar V e E da componente
            buscaProfundidadeCiclos(grafo, tempV->vertice, &visitadosGeral, &V_i, &E_i_duplicado);
            
            int E_i = E_i_duplicado / 2; // Número real de arestas
            
            // Fórmula de Euler para grafos planares/ciclos
            int ciclosComp = E_i - V_i + 1; 

            if (ciclosComp > 0) {
                printf("A componente conexa %d (iniciando em %d) possui %d ciclo(s) fundamental(is).\n", componenteID, tempV->vertice, ciclosComp);
                totalCiclos += ciclosComp;
            } else if (V_i > 0) {
                printf("A componente conexa %d (iniciando em %d) eh aciclica.\n", componenteID, tempV->vertice);
            }
        }
        tempV = tempV->proximoVertice;
    }

    if (totalCiclos == 0 && componenteID > 0) {
        printf(ANSI_COLOR_GREEN "O grafo NAO possui ciclos.\n" ANSI_COLOR_RESET);
    } else if (componenteID == 0) {
        printf(ANSI_COLOR_YELLOW "O grafo esta vazio.\n" ANSI_COLOR_RESET);
    } else {
         printf(ANSI_COLOR_YELLOW "Total de %d ciclos fundamentais no grafo.\n" ANSI_COLOR_RESET, totalCiclos);
    }
    
    liberarListaVisitados(visitadosGeral);
}

// 10. Inserir Grafo Padrão (Euleriano)
void inserirGrafoPadraoEuleriano(Grafo* grafo) {
    limparGrafo(grafo);
    printf(ANSI_COLOR_YELLOW "Inserindo Grafo Padrao EULERIANO...\n" ANSI_COLOR_RESET);
    // Propriedades: Conexo e todos os graus pares.
    // Grafo: Triângulo (1-2-3-1)
    inserirVerticeNoGrafo(grafo, 1);
    inserirVerticeNoGrafo(grafo, 2);
    inserirVerticeNoGrafo(grafo, 3);
    
    inserirArestaNoGrafo(grafo, 1, 2, 1); // grau(1)=1, grau(2)=1
    inserirArestaNoGrafo(grafo, 2, 3, 1); // grau(2)=2, grau(3)=1
    inserirArestaNoGrafo(grafo, 1, 3, 1); // grau(1)=2, grau(3)=2
    // Resultado: grau(1)=2, grau(2)=2, grau(3)=2. Conexo. É Euleriano.
    
    printf(ANSI_COLOR_GREEN "Grafo Euleriano inserido com sucesso.\n" ANSI_COLOR_RESET);
    visualizarGrafo(grafo);
}

// 11. Inserir Grafo Padrão (Conexo, Não-Euleriano)
void inserirGrafoPadraoConexo(Grafo* grafo) {
    limparGrafo(grafo);
    printf(ANSI_COLOR_YELLOW "Inserindo Grafo Padrao CONEXO (Nao-Euleriano)...\n" ANSI_COLOR_RESET);
    // Propriedades: Conexo, pelo menos 2 graus ímpares.
    // Grafo: Caminho (1-2-3-4)
    inserirVerticeNoGrafo(grafo, 1);
    inserirVerticeNoGrafo(grafo, 2);
    inserirVerticeNoGrafo(grafo, 3);
    inserirVerticeNoGrafo(grafo, 4);
    
    inserirArestaNoGrafo(grafo, 1, 2, 1); // grau(1)=1, grau(2)=1
    inserirArestaNoGrafo(grafo, 2, 3, 1); // grau(2)=2, grau(3)=1
    inserirArestaNoGrafo(grafo, 3, 4, 1); // grau(3)=2, grau(4)=1
    // Resultado: grau(1)=1, grau(2)=2, grau(3)=2, grau(4)=1. Conexo. Não-Euleriano.

    printf(ANSI_COLOR_GREEN "Grafo Conexo inserido com sucesso.\n" ANSI_COLOR_RESET);
    visualizarGrafo(grafo);
}

// 12. Inserir Grafo Padrão (Não-Conexo e Não-Euleriano)
void inserirGrafoPadraoNaoConexoNaoEuleriano(Grafo* grafo) {
    limparGrafo(grafo);
    printf(ANSI_COLOR_YELLOW "Inserindo Grafo Padrao NAO-CONEXO e NAO-EULERIANO...\n" ANSI_COLOR_RESET);
    // Propriedades: Pelo menos 2 componentes, pelo menos 2 graus ímpares.
    // Grafo: (1-2) e (3-4-5)
    inserirVerticeNoGrafo(grafo, 1);
    inserirVerticeNoGrafo(grafo, 2);
    inserirVerticeNoGrafo(grafo, 3);
    inserirVerticeNoGrafo(grafo, 4);
    inserirVerticeNoGrafo(grafo, 5);
    
    // Componente 1
    inserirArestaNoGrafo(grafo, 1, 2, 1); // grau(1)=1, grau(2)=1
    
    // Componente 2
    inserirArestaNoGrafo(grafo, 3, 4, 1); // grau(3)=1, grau(4)=1
    inserirArestaNoGrafo(grafo, 4, 5, 1); // grau(4)=2, grau(5)=1
    // Resultado: 2 componentes. Graus ímpares em 1, 2, 3, 5.
    
    printf(ANSI_COLOR_GREEN "Grafo Nao-Conexo e Nao-Euleriano inserido com sucesso.\n" ANSI_COLOR_RESET);
    visualizarGrafo(grafo);
}

// 13. Sair (e liberar toda a memória)
void liberarGrafo(Grafo* grafo) {
    limparGrafo(grafo);
    free(grafo);
    printf(ANSI_COLOR_YELLOW "Memoria do grafo liberada. Saindo...\n" ANSI_COLOR_RESET);
}

// --- Funções de Interface ---

// Limpa o buffer de entrada (para evitar problemas com scanf)
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Mostra o menu de opções
void mostrarMenu() {
    printf(ANSI_COLOR_CYAN "\n--- Gerenciador de Grafo Ponderado (Listas de Adjacencia) ---\n" ANSI_COLOR_RESET);
    printf("1. Inserir Vertice\n");
    printf("2. Inserir Aresta (Ponderada)\n");
    printf("3. Remover Vertice\n");
    printf("4. Remover Aresta\n");
    printf("5. Visualizar Grafo\n");
    printf("6. Informar grau de um vertice\n");
    printf("7. Informar se o grafo e Euleriano\n");
    printf("8. Informar se o grafo e conexo\n");
    printf("9. Informar se o grafo possui ciclos\n");
    printf("10. Inserir Grafo Padrao (Euleriano)\n");
    printf("11. Inserir Grafo Padrao (Conexo, Nao-Euleriano)\n");
    printf("12. Inserir Grafo Padrao (Nao-Conexo, Nao-Euleriano)\n");
    printf("13. Sair\n");
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
            printf(ANSI_COLOR_RED "Entrada invalida. Por favor, digite um numero.\n" ANSI_COLOR_RESET);
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
                removerVertice(meuGrafo);
                break;
            case 4:
                removerAresta(meuGrafo);
                break;
            case 5:
                visualizarGrafo(meuGrafo);
                break;
            case 6:
                informarGrauVertice(meuGrafo);
                break;
            case 7:
                informarGrafoEuleriano(meuGrafo);
                break;
            case 8:
                informarConectividade(meuGrafo);
                break;
            case 9:
                informarCiclos(meuGrafo);
                break;
            case 10:
                inserirGrafoPadraoEuleriano(meuGrafo);
                break;
            case 11:
                inserirGrafoPadraoConexo(meuGrafo);
                break;
            case 12:
                inserirGrafoPadraoNaoConexoNaoEuleriano(meuGrafo);
                break;
            case 13:
                liberarGrafo(meuGrafo);
                break;
            default:
                printf(ANSI_COLOR_RED "Opcao invalida. Tente novamente.\n" ANSI_COLOR_RESET);
        }

    } while (escolha != 13);

    return 0;
}