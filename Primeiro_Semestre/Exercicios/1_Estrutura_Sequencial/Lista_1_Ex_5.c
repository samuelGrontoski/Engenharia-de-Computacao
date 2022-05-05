/* 5) Calcular o valor do salário líquido de uma pessoa.
Sobre o salário bruto incidem descontos de imposto de renda e de INSS.
*/

int main (void) {
    float salarioBruto, inss, ir, salarioLiquido;

    printf ("Informe o valor do salario bruto: R$");
    scanf ("%f", &salarioBruto);
    printf ("Informe o percentual de INSS: ");
    scanf ("%f", &inss);
    printf ("Informe o percentual de IR: ");
    scanf ("%f", &ir);

    salarioLiquido = salarioBruto - (salarioBruto*(inss/100)) -(salarioBruto*(ir/100));

    printf ("Salario Liquido: R$ %.2f", salarioLiquido);

    return 0;
}
