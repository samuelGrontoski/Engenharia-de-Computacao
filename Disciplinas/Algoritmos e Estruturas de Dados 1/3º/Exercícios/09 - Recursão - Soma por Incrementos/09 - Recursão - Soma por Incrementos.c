#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma_rec(int a, int b) {
    if(b == 1)
        return a + 1;
    else
        return 1 + soma_rec(a, b-1);
}

int main() {
    int n, a, b;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", soma_rec(a, b));
    }

    return 0;
}
