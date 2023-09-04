#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quicksort(float *v, int esq, int dir){
    int i = esq, j = dir;
    float pivo = v[(i + j) / 2], aux;
    
    do{
        while (v[i] < pivo)
            i++;
        while (v[j] > pivo)
            j--;
        
        if (i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while (i <= j);
        
    if (esq < j)
        quicksort(v, esq, j);
    
    if (dir > i)
        quicksort(v, i, dir);
}

int main() {
    int i, n;
    float *v;
    scanf("%d", &n);
    
    v = malloc(sizeof(float) * n);
    
    for (i = 0; i < n; i++)
        scanf("%f", &v[i]);
    
    quicksort(v, 0, n - 1);
    
    for (i = 0; i < n; i++)
        printf("%.1f ", v[i]);
    
    free(v);
    
    return 0;
}
