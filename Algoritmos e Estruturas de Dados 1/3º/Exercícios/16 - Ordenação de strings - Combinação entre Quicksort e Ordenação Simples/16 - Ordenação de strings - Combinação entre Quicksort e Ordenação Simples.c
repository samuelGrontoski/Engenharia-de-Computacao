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


void troca(char **vstr, int p1, int p2){
    char *str;

    str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}

void imprimir(char **vstr, int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%s\n", vstr[i]);

}

void ordenar(char **nome, int n, int partimin, int n_cima, int n_baixo){
    int i = n_cima , j = n_baixo, x, y, z;
    char *pivo = nome[(i + j) / 2];

        do{
            while((comparar(nome[i], pivo) < 0))
                i++;

            while((comparar(nome[j], pivo) > 0))
                j--;

            if(i <= j){
                troca(nome, i, j);
                i++;
                j--;
            }
        }while(i <= j);

    if(n_baixo - n_cima > partimin){
        if(j > n_cima)
            ordenar(nome, n, partimin, n_cima, j);
        if(i < n_baixo)
            ordenar(nome, n, partimin, i, n_baixo);
    } 
    else{
        z=1;
            for(x = 0; (x <= n - 1) && z; x++){
                z=0;

            for (y = 0; y <= (n-1) - x - 1; y++)
                if(comparar(nome[y], nome[y + 1]) > 0){
                    troca(nome, y, y + 1);
                    z=1;
                }
           }
     }

}

int main() {
    int i, tam_min, n;

    scanf("%d", &n);

    scanf("%d", &tam_min);
    
    char **nome = (char**) malloc(sizeof(char*) * n);   
    
    for(i = 0; i < n; i++){
        nome[i] = (char*)malloc(sizeof(char) * 45);
        scanf("%s", nome[i]);
    }

    ordenar(nome, n, tam_min, 0, n-1);

    imprimir(nome, n);

    for(i = 0; i < n; i++)
        free(nome[i]);
    
    free(nome);

    return 0;
}