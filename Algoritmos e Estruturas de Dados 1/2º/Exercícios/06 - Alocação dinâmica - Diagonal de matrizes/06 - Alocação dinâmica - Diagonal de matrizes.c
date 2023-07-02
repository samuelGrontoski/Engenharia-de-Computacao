#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void v_diagonal(int N, int matriz[][N]){
    int i, *diagonal[N];
    
    *diagonal = (int*) malloc(N * (sizeof(int)));
    
    for(i = 0; i < N; i++){
        diagonal[i] = matriz[i][i];
    }
    
    for(i = 0; i < N; i++){
        printf("%d ", diagonal[i]);
    }
}

int main() {
    int N, i, j;
    
    scanf("%d", &N);
    
    int matriz[N][N];
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    v_diagonal(N, matriz);
        
    return 0;
}
