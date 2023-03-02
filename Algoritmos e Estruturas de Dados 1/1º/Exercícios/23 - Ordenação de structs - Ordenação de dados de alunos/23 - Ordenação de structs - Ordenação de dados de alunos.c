#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;

struct lista{
    Aluno dados[10];
    int qtd;
};

typedef struct lista Lista;

Lista* criar_lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    li->qtd = 0;
    return li;
}

int inserir(Lista* li, Aluno x){
    if(li == NULL){
        return -1;
    }
    li->dados[li->qtd] = x;
    li->qtd++;

    return 1;
}

void bubble(Lista* v, int n){
    int i, j;
    
    Aluno aux;
    
    for(i = n - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(strcmp(v->dados[j].nome, v->dados[j+1].nome) > 0){
                aux = v->dados[j];
                v->dados[j] = v->dados[j+1];
                v->dados[j+1] = aux;
            }
            
            if(strcmp(v->dados[j].nome, v->dados[j + 1].nome) == 0){
                if(v->dados[j].matricula > v->dados[j + 1].matricula){
                    aux = v->dados[j];
                    v->dados[j] = v->dados[j + 1];
                    v->dados[j + 1] = aux;
                }
            }
        }
    }
}

int main() {
    int num, i = 0;
    
    scanf("%d", &num);
    
    Lista *li = criar_lista();
    Aluno x[num];

    for(i = 0; i < num; i++){
        x[i].nome = (char*)malloc(sizeof(char*) * 100);
        x[i].curso = (char*)malloc(sizeof(char*) * 100);
    }

    for(i = 0; i < num; i++){
        scanf("%d", &x[i].matricula);
        scanf("%s", &x[i].nome[0]);
        scanf("%s", &x[i].curso[0]);
        scanf("%f", &x[i].coef);

        inserir(li, x[i]);
    }
    
    bubble(li, num);
    
    for(i = 0; i < num; i++){
        printf("%s ", li->dados[i].nome);
        printf("%d ", li->dados[i].matricula);
        printf("%s ", li->dados[i].curso);
        printf("%.2f ", li->dados[i].coef);
        printf("\n");
    }

    return 0;
}