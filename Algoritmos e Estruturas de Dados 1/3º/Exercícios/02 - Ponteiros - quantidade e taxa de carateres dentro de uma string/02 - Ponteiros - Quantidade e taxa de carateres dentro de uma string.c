#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void carac_string(char str[100], char c, int *quantidade, float *incidencia){
    int i = 0, aux = 0, tam = 0;

    while (str[i] != '\0')
    {
        if(str[i] == c){
            aux++;
        }
        i++;
        tam++;
    }
    
    *quantidade = aux;
    *incidencia = (float) *quantidade / strlen(str);
}

int main() {

    char str[100];
    char c;
    int quantidade;
    float incidencia;

    scanf("%s", str);
    scanf(" %c", &c);

    carac_string(str, c, &quantidade, &incidencia);

    printf("%d\n", quantidade);
    printf("%.2f\n", incidencia);

    return 0;
}
