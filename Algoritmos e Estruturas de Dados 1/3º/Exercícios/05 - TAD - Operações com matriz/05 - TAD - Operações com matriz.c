#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int **arr;
    int l;
    int c;
}Matriz;

Matriz * iniciar(int l, int c){
    int i;
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    
    mat->l = l;
    mat->c = c;
    mat->arr = (int **)malloc(sizeof(int *) * l);

    for(i = 0; i < l; i++){
        mat->arr[i] = (int *)malloc(sizeof(int) * c);
    }

    return mat;
};

void alterar(Matriz *m, int x, int i, int j){
    m->arr[i][j] = x;
};

int *obter_linha(Matriz *m, int i){
    int *v = (int *)malloc(sizeof(int) * m->c);

    for(int j =0; j < m->c; j++){
        v[j] = m->arr[i][j];
    }

    return v;
};


int *obter_coluna(Matriz *m, int i){
    int *v = (int *)malloc(sizeof(int) * m->l);

    for(int j = 0; j < m->l; j++){
        v[j] = m->arr[j][i];
    }

    return v;
};

Matriz *obter_submat(Matriz *m, int li, int ci, int lf, int cf){
    int ls = lf - li + 1;
    int cs = lf - li + 1;
    int r = 0, s = 0;

    Matriz *submat = iniciar(ls, cs);

    for(int i = li; i <= lf; i++){
        for(int j = ci; j <= cf; j++){
            submat->arr[r][s] = m->arr[i][j];
            s++;
        }
        r++;
        s = 0;
    }

    return submat;
};

void imprime_vetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
};

void imprime_matriz(Matriz *m){
    for(int i = 0; i < m->l; i++){
        for(int j = 0; j < m->c; j++){
            printf("%d ", m->arr[i][j]);
        }
        printf("\n");
    }
};

int main() {
    int l, c, pl, pc, li, ci, lf, cf;

    // le a quantidade de linhas e colunas da matriz
    scanf("%d %d", &l, &c);
    while (l < 0 || c < 0)
    {
        printf("Valores Invalidos\n");
        scanf("%d %d", &l, &c);
    }

    Matriz *m = iniciar(l, c);

    // le a matriz
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &m->arr[i][j]);
        }
    }

    // entrada para posicao de linha e coluna da matriz
    scanf("%d %d", &pl, &pc);
    while ((pl < 0 || pc < 0) || (pl >= l || pc >= c))
    {   
        printf("Valores invalidos\n");
        scanf("%d %d", &pl, &pc);
    }

    // entrada para submatriz
    scanf("%d %d %d %d", &li, &ci, &lf, &cf);
    while (li < 0 || ci < 0 || lf < 0 || cf < 0 || li >= l || ci >= c || lf >= l || cf >= c)
    {   
        printf("Valores invalidos\n");
        scanf("%d %d %d %d", &li, &ci, &lf, &cf);
    }

    // obtem e imprime determinada linha da matriz
    int *vl = obter_linha(m, pl);
    
    imprime_vetor(vl, c);
    printf("\n");

    // obtem e imprime determinada coluna da matriz
    int *vc = obter_coluna(m, pc);
    
    imprime_vetor(vc, l);
    printf("\n");

    // obtem e imprime determinada submatriz da matriz
    Matriz *submat = obter_submat(m, li, ci, lf, cf);
    
    imprime_matriz(submat);

    return 0;
}
