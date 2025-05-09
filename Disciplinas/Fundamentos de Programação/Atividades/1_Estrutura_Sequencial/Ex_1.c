#include <math.h>

int main (void) {

    float valorEspetaculo, valorConvite, ingressos, ingressos25Lucro;

    printf ("Informe o valor de custo do espetaculo: R$");
    scanf ("%f", &valorEspetaculo);
    printf ("Informe o valor do convite: R$");
    scanf ("%f", &valorConvite);

    ingressos = valorEspetaculo / valorConvite;
    ingressos25Lucro = (valorEspetaculo + (valorEspetaculo*0.25)) / valorConvite;

    printf ("\nPara cobrir o custo do espetaculo eh necessario vender %.0f ingressos\n", ceil(ingressos));
    printf ("Para cobrir o custo do espetaculo e ter lucro de 25%% eh necessario vender %.0f ingressos\n", ceil(ingressos25Lucro));

    return 0;
}
