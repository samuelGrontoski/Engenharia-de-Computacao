#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct PilhaE PilhaE;

// Definição da estrutura de célula da pilha
struct Cell {
    char item;           // O item armazenado na célula (um caractere)
    struct Cell *next;   // Ponteiro para a próxima célula na pilha
};

// Definição da estrutura da pilha encadeada
struct PilhaE {
    Cell *topo;   // Ponteiro para o topo da pilha
};

// Função para criar uma nova célula da pilha
Cell* criar_celula(char key) {
    Cell *c = (Cell*) malloc(sizeof(Cell));  // Aloca memória para a célula

    c->item = key;   // Define o item da célula como o caractere fornecido
    c->next = NULL;  // Inicializa o próximo ponteiro como NULL

    return c;
}

// Função para criar uma nova pilha encadeada
PilhaE* criar_pilhaE() {
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));  // Aloca memória para a pilha

    p->topo = NULL;  // Inicializa o topo da pilha como NULL (pilha vazia)

    return p;
}

// Função para verificar se a pilha está vazia
int pilhaE_vazia(PilhaE *p) {
    return (p == NULL) || (p->topo == NULL);
}

// Função para empilhar um caractere na pilha
void empilhar(char key, PilhaE *p) {
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();   // Cria uma nova pilha se ela não existir

    aux = criar_celula(key);  // Cria uma nova célula com o caractere fornecido

    aux->next = p->topo;  // Configura o próximo ponteiro da nova célula para apontar para o antigo topo da pilha
    p->topo = aux;        // Atualiza o topo da pilha para apontar para a nova célula
}

// Função para desempilhar um caractere da pilha e retorná-lo
char desempilhar(PilhaE *p) {
    Cell *aux;
    char item = ' ';

    if (!pilhaE_vazia(p)) {
        aux = p->topo;  // Armazena o ponteiro para o topo da pilha em uma variável auxiliar
        item = aux->item;  // Obtém o caractere armazenado na célula do topo da pilha
        p->topo = aux->next;  // Atualiza o topo da pilha para apontar para a próxima célula
        free(aux);  // Libera a memória alocada para a célula removida da pilha
    }

    return item;  // Retorna o caractere desempilhado
}

// Função para liberar a memória alocada para todos os elementos da pilha
int liberar_pilha(PilhaE *p) {
    if (p != NULL) {
        while (!pilhaE_vazia(p))
            desempilhar(p);  // Desempilha todos os elementos da pilha até que ela fique vazia
        free(p);  // Libera a memória alocada para a estrutura da pilha
        return 1;  // Retorna 1 para indicar que a operação foi realizada com sucesso
    }
    return 0;  // Retorna 0 para indicar que a pilha já estava vazia ou não foi alocada
}

// Função para verificar o balanceamento de parênteses em uma expressão
int balanco_parenteses(char expressao[]) {
    PilhaE *pilha = criar_pilhaE();  // Cria uma nova pilha vazia para o balanceamento de parênteses
    int balanceado = 1;  // Inicializa a variável de controle para indicar o balanceamento da expressão como verdadeira

    // Percorre cada caractere da expressão até encontrar o caractere nulo que indica o final da string
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar('(', pilha);  // Empilha um parêntese de abertura
        } else if (expressao[i] == ')') {
            // Verifica se há um parêntese de abertura correspondente na pilha
            if (!pilhaE_vazia(pilha) && pilha->topo->item == '(') {
                desempilhar(pilha);  // Desempilha o parêntese de abertura correspondente
            } else {
                balanceado = 0;  // Define a variável de controle como falsa (expressão desbalanceada)
                break;  // Interrompe o loop
            }
        }
    }

    // Verifica se ainda há parênteses de abertura na pilha após o término da varredura da expressão
    if (!pilhaE_vazia(pilha)) {
        balanceado = 0;  // Define a variável de controle como falsa (expressão desbalanceada)
    }

    liberar_pilha(pilha);  // Libera a memória alocada para a pilha

    return balanceado;  // Retorna o resultado do balanceamento de parênteses
}

int main() {
    char expressao[100];  // Variável para armazenar a expressão de entrada
    int N;  // Variável para armazenar o número de casos de teste
    scanf("%d", &N);  // Lê o número de casos de teste a partir da entrada padrão

    // Loop para processar cada caso de teste
    while (N--) {
        scanf("%s", expressao);  // Lê a expressão de entrada a partir da entrada padrão

        // Verifica o balanceamento de parênteses na expressão e imprime o resultado
        if (balanco_parenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso
}
