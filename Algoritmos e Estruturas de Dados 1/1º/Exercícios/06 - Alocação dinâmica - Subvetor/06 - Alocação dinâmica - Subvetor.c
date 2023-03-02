#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void subvetor(int *a, int inicio, int fim, int tamanho){

    int i;

    if(tamanho <= fim)
        printf("subvetor inexistente");
    else
        for(i=inicio; i<=fim; i++){
            printf("%d ", a[i]);
        }

}

int main() {

    int n, i, *a, inicio, fim;

    scanf("%d", &n);

    a = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d %d", &inicio, &fim);

    subvetor(a, inicio, fim, n);

    free(a);

    return 0;
}
