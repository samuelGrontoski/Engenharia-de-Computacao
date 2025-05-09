#define MAX_EXP 20
typedef struct{
    int cons; // constanteint 
    expo; // expoente
}Elemento;// Estrutura para uma lista estática

typedef struct{
    Elemento item[MAX_EXP];
    int tam; // tamanho da lista
}Lista;

Lista*criar_lista();
int lista_cheia(Lista*l);
int buscar(Lista*l, int expo);

int pot(int a, unsigned int b){
    int i, res = 1;
    if(b > 0)
        for (i = 1; i <= b; i++)
            res *= a;
    
    return res;
}

int polinomio(Lista *l, int x){
    int i, res = 0;

    if (l !+ NULL){
        for (i = 0; i < l->tam; i++)
            res += l->item[i].cons * pot(x, l->item[i].expo);
    }
    return res;
}