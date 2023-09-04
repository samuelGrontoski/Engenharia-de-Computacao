#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char nome[30];
    int energia;
    int defesa;
    int forca;
    int A1;
    int A2;
    int A3;
}Personagem;

void reduzir_energia(Personagem *p, int dano){
    p->energia = p->energia - dano;
    if(p->energia < 0){
        p->energia = 0;
    }
}

void curar(Personagem *p){
    p->energia = p->energia + 200;
    if(p->energia > 1000){
        p->energia = 1000;
    }
}

void batalha(Personagem p[], int N, int P[], char A[], int G[]){
    int i, dano;
    
    for(i = 0; i < N; i++){
        if(P[i] == 1){
            if(A[i] == 'A'){
                if(G[i] == 1){
                    dano = p[0].forca + p[0].A1 - p[1].defesa;
                    if(dano < 0){
                        dano = 1;
                    }
                }
                if(G[i] == 2){
                    dano = p[0].forca + p[0].A2 - p[1].defesa;
                    if(dano < 0){
                        dano = 1;
                    }
                }
                if(G[i] == 3){
                    dano = p[0].forca + p[0].A3 - p[1].defesa;
                    if(dano < 0){
                        dano = 1;
                    }
                }
                reduzir_energia(&p[1], dano);
            }
            if(A[i] == 'C'){
                curar(&p[0]);
            }
        }
        if(P[i] == 2){
            if(A[i] == 'A'){
                if(G[i] == 1){
                    dano = p[1].forca + p[1].A1 - p[0].defesa;
                    if(dano < 0){
                        dano = 1;
                    }
                }
                if(G[i] == 2){
                    dano = p[1].forca + p[1].A2 - p[0].defesa;
                    if(dano < 0){
                        dano = 1;
                    }
                }
                if(G[i] == 3){
                    dano = p[1].forca + p[1].A3 - p[0].defesa;
                    if(dano < 0){
                        dano = 1;
                    }
                }
                reduzir_energia(&p[0], dano);
            }
            if(A[i] == 'C'){
                curar(&p[1]);
            }
        }
    }
}

void imprime_resultado(Personagem p[]){
    
    printf("%s %d\n", p[0].nome, p[0].energia);
    printf("%s %d\n", p[1].nome, p[1].energia);
    
    if(p[0].energia > p[1].energia)
        printf("%s", p[0].nome);
    if(p[0].energia < p[1].energia)
        printf("%s", p[1].nome);
    if(p[0].energia == p[1].energia)
        printf("empate");
}

int main() {
    int i, N;
    
    Personagem p[2];
    
    //entrada
    scanf("%s %d %d %d %d %d %d", p[0].nome, &p[0].energia, &p[0].defesa, &p[0].forca, &p[0].A1, &p[0].A2, &p[0].A3);
    scanf("%s %d %d %d %d %d %d", p[1].nome, &p[1].energia, &p[1].defesa, &p[1].forca, &p[1].A1, &p[1].A2, &p[1].A3);
    scanf("%d", &N);
    
    int P[N], G[N];
    char A[N];
    
    for(i = 0; i < N; i++){
        scanf("%d %c", &P[i], &A[i]);
        if(A[i] == 'A'){
            scanf("%d", &G[i]);
        }
    }
    
    //processos
    batalha(p, N, P, A, G);
    
    //saida
    imprime_resultado(p);
     
    return 0;
}