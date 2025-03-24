#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int nivel;
    float energia;
    int forca, defesa;
} Personagem;

void imprimir_P(Personagem p){
    printf("%s %d %.2f %d %d\n", p.nome, p.nivel, p.energia, p.forca, p.defesa);
}

Personagem criar_P(char nome[], int nivel, float energia, int forca, int defesa){
    Personagem p;

    strcpy(p.nome, nome);
    p.nivel = nivel;
    p.energia = energia;
    p.forca = forca;
    p.defesa = defesa;

    return p;
}

int main () {

    /*char nome[6][30];
    int nivel [6];
    float energia[6];
    int forca[6], defesa[6];

    strcpy(nome[0], "Vegeta");
    nivel[0] = 50;
    energia[0] = 100.1;
    forca[0] = 500;
    defesa[0] = 100;

    strcpy(nome[0], "Goku");
    nivel[1] = 40;
    energia[1] = 90.1;
    forca[1] = 400;
    defesa[1] = 90;*/

    /*
    Personagem p1 = {"Vegeta", 50, 100.1, 500, 100};
    Personagem p2;
    Personagem p3;

    p2.defesa = 200;
    strcpy(p2.nome, "Goku");
    p2.energia = 100.1;
    p2.forca = 400;
    p2.nivel = 50;

    p3 = p2;

    strcpy(p3.nome, "Gohan");

    printf("%s\n", p3.nome);
    printf("%d\n", p3.nivel);
    printf("%f\n", p3.energia);
    printf("%d\n", p3.forca);
    printf("%d\n", p3.defesa);
    */
   Personagem p;
   Personagem vp[6];
   int i;

   for (i = 0; i < 6; i++){
        vp[i] = criar_P("Pedro", i, (float) i * 50, i * 100, i * 2);
        /*strcpy(vp[i].nome, "Pedro");
        vp[i].nivel = i;
        vp[i].energia = (float) i * 50;
        vp[i].forca = i * 100;
        vp[i].defesa = i * 2;*/
   }

   for (i = 0; i < 6; i++)
   {
        imprimir_P(vp[i]);
   }
   

    return 0;
}