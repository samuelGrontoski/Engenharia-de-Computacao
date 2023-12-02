#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int somatorio(int v[], int n) {
    if (n < 1)
        return 0;
    else
        return v[n - 1] + somatorio(v, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int v[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    printf("%d", somatorio(v, n));
    
    return 0;
}
