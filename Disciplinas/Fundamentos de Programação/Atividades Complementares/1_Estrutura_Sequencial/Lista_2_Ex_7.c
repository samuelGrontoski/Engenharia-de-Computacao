/*7) Fazer um programa para ler o salário de uma pessoa, o percentual de aumento e o percentual de
descontos. Os descontos incidem sobre o salário com aumento. Calcular o novo salário e mostrá-lo*/

int main (void) {

    float salario, salarioAument, salarioLiqui, percentAument, percentDesc, cents;
    int salarioInt;

    printf ("Informe o valor do salario: R$ ");
    scanf ("%f", &salario);
    printf ("Informe o percentual aumentado (Ex: 10 para 10%): ");
    scanf ("%f", &percentAument);
    printf ("Informe o percentual aumentado (Ex: 5 para 5%): ");
    scanf ("%f", &percentDesc);

    salarioAument = salario + (salario * (percentAument/100));
    salarioLiqui = salarioAument - (salarioAument * (percentDesc/100));

    printf ("Salario aumentado: R$ %.2f\n", salarioAument);
    printf ("Salario liquido: R$ %.2f\n", salarioLiqui);

    salarioInt = (int)salarioLiqui;
    cents = (salarioLiqui - salarioInt) * 100;
    round(cents);

    printf ("O salario liquido eh: %d reais e %.0f centavos.\n", salarioInt, cents);

    return 0;
}
