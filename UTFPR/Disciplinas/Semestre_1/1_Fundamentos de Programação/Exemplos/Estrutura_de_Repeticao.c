#include <stdio.h>

int main(void) {

    int i, produto=1;

    for(i=1; i <= 10; i++)
    {
        if(i%2 == 0)
        {
        printf("%d\n", i);
        produto = produto * i;
        }
    }

    printf("\nO produto dos numeros pares eh: %d\n", produto);

    return 0;
}
