/* 1) A contribuição para o INSS é calculada da seguinte forma:
a) Para o salário bruto de até três salários mínimos, o desconto do INSS será de 8%.
b) Para o salário bruto acima de três salários mínimos, o desconto do INSS será de 10%. Para as
contribuições maiores que o salário mínimo, considerar a importância de um salário mínimo.
Elaborar um programa que receba como entrada o valor do salário mínimo e o valor do salário bruto, calcule o
INSS e o salário líquido restante e informe-os. */

#include <stdio.h>

int main (void) {

    float salarioMinimo, salarioBruto, salarioLiquido, inss;

    printf ("\n-Salario minimo: ");
    scanf ("%f", &salarioMinimo);
    printf ("-Salario bruto: ");
    scanf ("%f", &salarioBruto);

    if (salarioBruto <= salarioMinimo * 3) {

        inss = salarioBruto * 0.08;
        salarioLiquido = salarioBruto - inss;

        printf ("\n-INSS = %.2f * 8%% = %.2f", salarioBruto, inss);
        printf ("\nValor do salario liquido = %.2f - %.2f = %.2f", salarioBruto, inss, salarioLiquido);
    } else
    if (salarioBruto > salarioMinimo * 3) {

        inss = salarioBruto * 0.1;
        salarioLiquido = salarioBruto - inss;

        printf ("\n-INSS = %.2f * 10%% = %.2f", salarioBruto, inss);
        printf ("\nValor do salario liquido = %.2f - %.2f = %.2f", salarioBruto, inss, salarioLiquido);
    }
    return 0;
}