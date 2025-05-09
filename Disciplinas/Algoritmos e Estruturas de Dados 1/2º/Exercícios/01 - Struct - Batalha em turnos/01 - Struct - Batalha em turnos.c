#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int energia;
    int defesa;
    int forca;
}Personagem;

void batalha(Personagem p[], int rodadas){
    int i, x = 0, y = 1, aux;
    
    //batalha
    for(i = 0; i < rodadas * 2; i++){
        //ataque
        if(p[x].energia > 0){
            if(p[x].forca - p[y].defesa <= 0){
                p[y].energia--;
            }
            if(p[x].forca - p[y].defesa > 0){
                p[y].energia = p[y].energia - (p[x].forca - p[y].defesa);
                if(p[y].energia < 0){
                    p[y].energia = 0;
                    break;
                }
            }
        }
        aux = x;
        x = y;
        y = aux;
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
    int rodadas;
    
    Personagem p[2];
    
    //entrada
    scanf("%s %d %d %d", p[0].nome, &p[0].energia, &p[0].defesa, &p[0].forca);
    scanf("%s %d %d %d", p[1].nome, &p[1].energia, &p[1].defesa, &p[1].forca);
    scanf("%d", &rodadas);
    
    //processos
    batalha(p, rodadas);
    
    //saida
    imprime_resultado(p);
     
    return 0;
}