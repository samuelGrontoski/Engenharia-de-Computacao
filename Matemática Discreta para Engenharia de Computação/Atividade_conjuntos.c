#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell {
  int item;
  Cell *next;
};

struct ListaE {
  Cell *head;
};

Cell *criar_celula(int key) {
  Cell *c = (Cell *)malloc(sizeof(Cell));
  c->item = key;

  c->next = NULL;

  return c;
}

ListaE *criar_listaE() {
  ListaE *l = (ListaE *)malloc(sizeof(ListaE));

  l->head = NULL;

  return l;
}

int listaE_vazia(ListaE *l) { return (l == NULL) || (l->head == NULL); }

void inserir_primeiro(int key, ListaE *l) {
  Cell *aux;

  if (l == NULL) {
    l = criar_listaE();
  }
  aux = criar_celula(key);
  aux->next = l->head;
  l->head = aux;
}

void inserir_ultimo(int key, ListaE *l) {
  Cell *aux, *novo;

  if (l == NULL) {
    l = criar_listaE();
  }
  if (listaE_vazia(l)) {
    inserir_primeiro(key, l);
  } else {
    aux = l->head;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    novo = criar_celula(key);
    aux->next = novo;
  }
}

void imprimir(ListaE *l) {
  Cell *aux;

  if (!listaE_vazia(l)) {
    aux = l->head;

    while (aux != NULL) {
      printf("%d ", aux->item);
      aux = aux->next;
    }
    printf("\n");
  }
}

int liberar_LE(ListaE *l) {
  Cell *aux = NULL;

  if (l != NULL) {
    while (l->head != NULL) {
      aux = l->head;
      l->head = aux->next;
      free(aux);
    }
    free(l);

    return 1;
  }
  return 0;
}

void criar_subconjuntos(ListaE *A, ListaE *A1, ListaE *A2, int num, int c1,
                        int c2) {
  Cell *aux;
  int i, pos;

  if (listaE_vazia(A)) {
    printf("Conjunto A está vazio!\n");
    return;
  }

  // Inicializa o gerador de números aleatórios
  srand(time(NULL));

  // Preencher subconjunto A1 com c1 elementos aleatórios de A
  for (i = 0; i < c1; i++) {
    pos = rand() % num;  // Escolhe uma posição aleatória no conjunto A
    aux = A->head;

    // Navega até o elemento na posição 'pos'
    for (int j = 0; j < pos; j++) {
      aux = aux->next;
    }

    // Insere o elemento selecionado em A1
    inserir_ultimo(aux->item, A1);
  }

  // Preencher subconjunto A2 com c2 elementos aleatórios de A
  for (i = 0; i < c2; i++) {
    pos = rand() % num;  // Escolhe uma posição aleatória no conjunto A
    aux = A->head;

    // Navega até o elemento na posição 'pos'
    for (int j = 0; j < pos; j++) {
      aux = aux->next;
    }

    // Insere o elemento selecionado em A2
    inserir_ultimo(aux->item, A2);
  }
}

int main() {
  ListaE *A = criar_listaE();
  ListaE *A1 = criar_listaE();
  ListaE *A2 = criar_listaE();

  int num;
  while (num > 10 || num < 1) {
    printf("Informe o numero de elementos do conjunto A (maximo 10): ");
    scanf("%d", &num);
  }

  int i = 0;
  int elemento;
  while (i < num) {
    printf("Informe o elemento %d (deve ser positivo): ", i + 1);
    scanf("%d", &elemento);
    if (elemento < 0) {
      printf("Elemento invalido\n");
      continue;
    } else {
      inserir_ultimo(elemento, A);
      i++;
    }
  }

  int c1;
  while (c1 >= num || c1 < 1) {
    printf("Informe a cardinalidade do subconjunto A1: ");
    scanf("%d", &c1);
  }

  int c2;
  while (c2 >= num || c2 < 1) {
    printf("Informe a cardinalidade do subconjunto A2: ");
    scanf("%d", &c2);
  }

  criar_subconjuntos(A, A1, A2, num, c1, c2);

  int potencia;
  while (potencia != 1 && potencia != 2) {
    printf("Informe o subconjunto que se deve calcular o conjunto potencia: ");
    scanf("%d", &potencia);
  }

  printf("A: ");
  imprimir(A);
  printf("A1: ");
  imprimir(A1);
  printf("A2: ");
  imprimir(A2);

  liberar_LE(A);

  return 0;
}