#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutacoes(int *arr, int l, int r, int *count) {
    if (l == r) {
        for (int i = 0; i <= r; i++) {
            printf("%d", arr[i]);
        }
        printf(" - ");
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;

            permutacoes(arr, l + 1, r, count);

            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}

void permutacoes_tamanho_m(int *arr, int n, int m, int *count, int *tempArr, int tempSize, int *used) {
    if (tempSize == m) {
        for (int i = 0; i < m; i++) {
            printf("%d", tempArr[i]);
        }
        printf(" - ");

        (*count)++;

        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue; // Verifica se o elemento já foi usado

        tempArr[tempSize] = arr[i];
        used[i] = 1; // Marca o elemento como usado
        permutacoes_tamanho_m(arr, n, m, count, tempArr, tempSize + 1, used);
        used[i] = 0; // Desmarca o elemento para uso futuro
    }
}


void combinacoes(int *arr, int n, int m, int start, int *tempArr, int tempSize, int *count) {
    if (tempSize == m) {
        for (int i = 0; i < m; i++) {
            printf("%d", tempArr[i]);
        }
        printf(" - ");

        (*count)++;

        return;
    }

    for (int i = start; i < n; i++) {
        tempArr[tempSize] = arr[i];
        combinacoes(arr, n, m, i + 1, tempArr, tempSize + 1, count);
    }
}

void combinacoes_com_repeticao(int *arr, int n, int q, int start, int *tempArr, int tempSize, int *count) {
    if (tempSize == q) {
        for (int i = 0; i < q; i++) {
            printf("%d", tempArr[i]);
        }
        printf(" - ");

        (*count)++;

        return;
    }

    for (int i = start; i < n; i++) {
        tempArr[tempSize] = arr[i];
        combinacoes_com_repeticao(arr, n, q, i, tempArr, tempSize + 1, count);
    }
}

int main() {
    int n, m, q;
    int arr[10];
    char input[100];

    while (1) {
        printf("Informe os numeros de elementos n, m, q separados por virgula: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d,%d,%d", &n, &m, &q);

        if (n < 3 || n > 4 || m >= n || q <= n) {
            printf("Valores invalidos. Tente novamente.\n");
            continue;
        }

        printf("Informe os %d elementos separados por virgula: ", n);
        fgets(input, sizeof(input), stdin);
        char *token = strtok(input, ",");
        for (int i = 0; i < n; i++) {
            arr[i] = atoi(token);
            token = strtok(NULL, ",");
        }

        printf("a) ");
        int count = 0;
        permutacoes(arr, 0, n - 1, &count);
        printf("Total = %d\n", count);

        printf("b) ");
        int used[10] = {0};
        int tempArr[m];
        count = 0;
        permutacoes_tamanho_m(arr, n, m, &count, tempArr, 0, used);
        printf("Total = %d\n", count);

        printf("c) ");
        count = 0;
        combinacoes(arr, n, m, 0, tempArr, 0, &count);
        printf("Total = %d\n", count);

        printf("d) ");
        count = 0;
        combinacoes_com_repeticao(arr, n, q, 0, tempArr, 0, &count);
        printf("Total = %d\n", count);

        printf("Digite (1) para informar outro conjunto de numeros ou digite (2) para sair: ");
        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);
        if (choice == 2) break;
    }

    return 0;
}
