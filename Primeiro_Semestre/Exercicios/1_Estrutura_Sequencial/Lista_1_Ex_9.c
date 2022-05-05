#include <math.h>

int main (void) {

    float kmPercorridos, capacidadeTanque, consumoMedio, consumoTrajeto, abastecimentos, combustivelRestante;

    printf ("Informe a distancia (em km) percorrida entre as cidades: ");
    scanf ("%f", &kmPercorridos);
    printf ("Informe a capacidade maxima do tanque de combustivel do veiculo: ");
    scanf ("%f", &capacidadeTanque);
    printf ("Informe o consumo medio (em km por litro) do veiculo: ");
    scanf ("%f", &consumoMedio);

    consumoTrajeto = kmPercorridos / consumoMedio;
    abastecimentos = kmPercorridos / (capacidadeTanque * consumoMedio); //testar esse calculo usando if e while
    combustivelRestante = (capacidadeTanque * ceil(abastecimentos)) - consumoTrajeto;

    printf ("\nForam necessarios %.1f litros de combustivel para percorrer o trajeto.\n", consumoTrajeto);
    printf ("Foi necessario abastecer o veiculo %.0f vezes.\n", ceil(abastecimentos));
    printf ("Restou no tanque de combustivel %.1f litros.\n", combustivelRestante);

    return 0;
}
