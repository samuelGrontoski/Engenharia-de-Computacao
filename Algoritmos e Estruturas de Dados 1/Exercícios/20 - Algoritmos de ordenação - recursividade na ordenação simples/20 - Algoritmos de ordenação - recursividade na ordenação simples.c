#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void selectsort2(int v[], int i, int n){
    int j, p, aux;
    
    if (i < n - 1){
        p = i;
    
        for (j = i + 1; j < n; j++)
            if (v[j] < v[p])
                p = j;
        
        if (p != i){
            aux = v[i];
            v[i] = v[p];
            v[p] = aux;
        }
        
        selectsort2(v, i + 1, n);
    }
}

int main() {
    int i, n, *v;
    
    scanf("%d", &n);
    
    v = malloc(sizeof(int) * n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    selectsort2(v, 0, n);
    
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    
    free(v);
    
    
    return 0;
}
