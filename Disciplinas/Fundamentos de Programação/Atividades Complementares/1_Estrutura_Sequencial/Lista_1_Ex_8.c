int main (void) {

    float custoFabrica, percentDistribuidor, percentImposto, custoConsumidor;

    printf ("Informe o custo de fabrica de um automovel: R$ ");
    scanf ("%f", &custoFabrica);
    printf ("Informe a percentagem do distribuidor (0 a 100): ");
    scanf ("%f", &percentDistribuidor);
    printf ("Informe a percentagem de impostos (0 a 100): ");
    scanf ("%f", &percentImposto);

    custoConsumidor = custoFabrica + (custoFabrica*(percentDistribuidor/100)) + (custoFabrica*(percentImposto/100));

    printf ("O custo do veiculo ao consumidor eh: R$ %.2f\n", custoConsumidor);

    return 0;
}
