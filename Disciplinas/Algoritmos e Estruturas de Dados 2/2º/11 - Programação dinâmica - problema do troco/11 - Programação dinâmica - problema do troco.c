#include <stdio.h>
#include <stdlib.h>

int contarFormasTroco(int troco, int n_moedas, int moedas[]) {
    int *dp = (int *)calloc(troco + 1, sizeof(int));
    
    dp[0] = 1;

    for (int i = 0; i < n_moedas; i++) {
        for (int j = moedas[i]; j <= troco; j++) {
            dp[j] += dp[j - moedas[i]];
        }
    }

    int resultado = dp[troco];
    
    free(dp);

    return resultado;
}

int main() {
    int troco_total;
    int n;

    scanf("%d", &troco_total);
    scanf("%d", &n);

    int *conjunto_moedas = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &conjunto_moedas[i]);
    }
    
    int formas = contarFormasTroco(troco_total, n, conjunto_moedas);
    printf("%d\n", formas);
    
    free(conjunto_moedas);

    return 0;
}