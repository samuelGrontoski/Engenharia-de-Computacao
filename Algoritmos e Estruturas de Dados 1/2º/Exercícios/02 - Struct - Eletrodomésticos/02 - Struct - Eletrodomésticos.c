#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int potencia;
    float tempo_ativo;
    float consumo_T;
    float consumo_R;
}Eletro;

void consumo_Ind(Eletro eletro[], int N,int dias){
    int i;
    
    for(i = 0; i < N; i++){
        eletro[i].consumo_T = eletro[i].potencia * eletro[i].tempo_ativo * dias;
    }
}

int consumo_Total(Eletro eletro[], int N){
    int i, cons_Total = 0;
    
    for(i = 0; i < N; i++){
        cons_Total = cons_Total + eletro[i].consumo_T;
    }
    return cons_Total;
}

void consumo_Rel(Eletro eletro[], int consumo_total, int N){
    int i;
    
    for(i = 0; i < N; i++){
        eletro[i].consumo_R = (eletro[i].consumo_T/consumo_total) * 100;
    }
}

int main() {
    int i, N, dias, cons_Total = 0;
    
    //entrada
    scanf("%d", &N);
    
    Eletro eletro[N];
    
    for(i = 0; i < N; i++){
        scanf("%s %d %f", eletro[i].nome, &eletro[i].potencia, &eletro[i].tempo_ativo);
    }
    
    scanf("%d", &dias);
    
    //processos
    consumo_Ind(eletro, N, dias);
    cons_Total = consumo_Total(eletro, N);
    consumo_Rel(eletro, cons_Total, N);
    
    
    //impressao
    printf("%d\n", cons_Total);
    
    for(i = 0; i < N; i++){
        printf("%s %.1f\n", eletro[i].nome, eletro[i].consumo_R);
    }
    
    return 0;
}
