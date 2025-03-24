#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int resto_divisao(int a, int b){
    if (b == 0){
        return 0;
    }
    if (a < b){
        return a;
    }
    else{
        return resto_divisao(a - b, b);
    }
}

int main() {
    int n, i, resto;
    
    scanf("%d", &n);
    
    int a[n], b[n];
    
    for(i = 0; i < n; i++){
        scanf("%d %d", &a[i], &b[i]);
    }
    
    for(i = 0; i < n; i++){
        resto = resto_divisao(a[i], b[i]);
        printf("%d\n", resto);
    }
     
    return 0;
}
