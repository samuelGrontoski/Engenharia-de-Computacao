#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}

int comparar(char s1[], char s2[]){
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}

void merge(char **v, int esq, int meio, int dir){
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    char **L = (char**) malloc(sizeof(char*) * n1);
    char **R = (char**) malloc(sizeof(char*) * n2);

    for (i = 0; i < n1; i++)
        L[i] = v[esq + i];

    for (j = 0; j < n2; j++)
        R[j] = v[meio + j + 1];

    i = 0;
    j = 0;

    for (k = esq; k <= dir; k++)
        if ((i < n1) && ((j >= n2) || comparar(L[i], R[j]) <= 0)){
            v[k] = L[i];
            i++;
        }else if ((j < n2) || (i >= n1)){
            v[k] = R[j];
            j++;
        }
}

void mergesort(char **v, int esq, int dir){
    int meio;

    if (esq < dir){
        meio = (esq + dir) / 2;
        mergesort(v, esq, meio);
        mergesort(v, meio + 1, dir);
        merge(v, esq, meio, dir);
    }
}

int main() {
    int i, n;
    char **v;
    
    scanf("%d", &n);
    
    v = (char**) malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++){
        v[i] = (char*) malloc(sizeof(char) * 50);
        scanf("%s", v[i]);
    }    
    
    mergesort(v, 0, n - 1);
    
    for (i = 0; i < n; i++){
        printf("%s\n", v[i]);
        free(v[i]);
    }
    
    free(v);
    
    return 0;
}


