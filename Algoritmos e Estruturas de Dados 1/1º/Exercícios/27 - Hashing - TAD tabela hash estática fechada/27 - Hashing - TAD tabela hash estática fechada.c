#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct HashT HashT;

struct HashT{
    unsigned int tam;
    int *buckets;
};

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hash1(int k, float c, int B){
    float aux;

    aux = k * c;
    aux = aux - (int)aux;

    return (int)(aux * B);
}

static int hash2(int k, int B){
    return 1 + k % (B - 1);
}

static int rehash(int h1, int h2, int B, int i, float c){
    return (h1 + i * h2) % B;
}

int inserir(int key, HashT *t, float c){
    int x, h1, h2, i = 1, rh;

    if ((t != NULL) && (key > 0)){
        x = hash1(key, c, t->tam);

        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            printf("%d\n",x);
            return 1;

        }else{
            i = 1; 
            rh = x; 
            h1 = hash1(key, c, t->tam);
            h2 = hash2(key, t->tam);

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = rehash(h1, h2, t->tam, i, c);
                i++;
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = key;

                printf("%d\n",rh);

                return 1;
            }
        }
    }
    return 0;
}

int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);
        free(t);

        return 1;
    }
    return 0;
}

int main() {  
    int n, aux, i, item;
    float c;

    scanf("%f %d %d", &c, &n, &aux);

    HashT *t = criar(n);

    for(i = 0; i < aux; i++){
        scanf("%d",&item);

        inserir(item, t, c);
    }

    liberar(t);

    return 0;
}