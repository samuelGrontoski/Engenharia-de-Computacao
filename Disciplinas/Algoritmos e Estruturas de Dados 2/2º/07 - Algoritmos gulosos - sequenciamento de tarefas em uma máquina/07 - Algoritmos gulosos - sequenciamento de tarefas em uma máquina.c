#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int e;
    int d;
} Tarefa;

int compararTarefas(const void *a, const void *b) {
    Tarefa *tarefaA = (Tarefa *)a;
    Tarefa *tarefaB = (Tarefa *)b;

    int folgaA = tarefaA->d - tarefaA->e;
    int folgaB = tarefaB->d - tarefaB->e;

    if (folgaA < folgaB) {
        return 1;
    }
    if (folgaA > folgaB) {
        return -1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    Tarefa vetor_tarefas[n];
    int soma_execucao = 0;
    int soma_deadline = 0;

    for (int i = 0; i < n; i++) {
        vetor_tarefas[i].id = i;
        scanf("%d %d", &vetor_tarefas[i].e, &vetor_tarefas[i].d);
        soma_execucao += vetor_tarefas[i].e;
        soma_deadline += vetor_tarefas[i].d;
    }
    
    qsort(vetor_tarefas, n, sizeof(Tarefa), compararTarefas);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor_tarefas[i].id);
    }
    printf("\n");

    int atraso_final = 0;
    if (soma_execucao > soma_deadline) {
        atraso_final = soma_execucao - soma_deadline;
    }
    
    printf("%d\n", atraso_final);

    return 0;
}