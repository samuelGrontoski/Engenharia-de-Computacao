#include <stdio.h>
#include <math.h>

int main () {

// Produtos

    float precofarinha = 8.55;
    float precorefri = 6.22;
    float precoazeite = 23.03;
    float precoarroz = 3.25;

    float farinha, refri, azeite, arroz;

// Unidades

    printf ("Unidades de Farinha de Trigo: \n");
    scanf ("%f", &farinha);

    printf ("Unidades de Refrigerante de Cola 2L: \n");
    scanf ("%f", &refri);

    printf ("Unidades de Azeite de Oliva Extra-Virgem: \n");
    scanf ("%f", &azeite);

    printf ("Unidades de Arroz Branco: \n");
    scanf ("%f", &arroz);

// Valor de cada Produto

    float totalfarinha = farinha * precofarinha;
    float totalrefri = refri * precorefri;
    float totalazeite = azeite * precoazeite;
    float totalarroz = arroz * precoarroz;

// Valor Total e descontos

    float total = totalarroz + totalazeite + totalfarinha + totalrefri;
    float desconto = total * 0.1;
    float totalapagar = total * 0.9;

// Nota fiscal

    printf ("\n\n-------------------------------------------------------------------------------------------------------------------\n");
    printf ("                                         SUPER C - Adora atender bem voce                                          \n");
    printf ("-------------------------------------------------------------------------------------------------------------------\n\n");
    printf ("Produto                           Quantidade(Uni.)               Preco (R$/Uni.)                  Preco total (R$) \n");
    printf ("Farinha de Trigo                      %.0f                           %.2f                                %.2f      \n", farinha, precofarinha, totalfarinha);
    printf ("Refrigerante de Cola 2l               %.0f                           %.2f                                %.2f      \n", refri, precorefri, totalrefri);
    printf ("Azeite de Olive Extra-Virgem          %.0f                           %.2f                               %.2f      \n", azeite, precoazeite, totalazeite);
    printf ("Arroz Branco                          %.0f                           %.2f                                %.2f      \n\n", arroz, precoarroz, totalarroz);
    printf ("TOTAL:          R$%.2f \n", total);
    printf ("Desconto:       R$%.2f \n", desconto);
    printf ("Total a pagar:  R$%.2f \n\n", totalapagar);

    printf ("-------------------------------------------------------------------------------------------------------------------\n");
    printf ("                                         Obrigado por comprar conosco! \n");
    printf ("-------------------------------------------------------------------------------------------------------------------\n");
}
