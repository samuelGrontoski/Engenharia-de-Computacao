/* 9) Construa um programa que leia um conjunto de dados contendo altura (que deve ser maior que 0) e sexo
(que deve ser masculino ou feminino) de um grupo de pessoas. Quando fornecida uma altura igual a 0, é
encerrada a entrada de dados. O programa deve calcular e fornecer:

a) A maior e a menor altura do grupo.
b) A média de altura das mulheres.
c) A média de altura dos homens.
d) O número de homens e o percentual que eles representam no grupo.
e) O número de mulheres e o percentual que elas representam no grupo

*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    float altura, maiorAltura, menorAltura, mediaMulheres = 0, mediaHomens = 0;
    int mulheres = 0, homens = 0, total;
    char sexo;

    do
    {
        printf("\nInforme a altura: ");
        scanf("%f", &altura);

        if (altura < 0)
        {
            printf("\nValor inválido\n");
        }
        if (altura == 0)
        {
            break;
        }
        else
        {
            do
            {
                printf("\nInforme o sexo (F ou M): ");
                setbuf(stdin, NULL);
                scanf("%c", &sexo);

                if (sexo != 'F' && sexo != 'f' && sexo != 'M' && sexo != 'm')
                {
                    printf("\nValor inválido\n");
                }
            } while (sexo != 'F' && sexo != 'f' && sexo != 'M' && sexo != 'm');

            if (sexo == 'F' || sexo == 'f')
            {
                mulheres++;
                mediaMulheres = mediaMulheres + altura;
            }
            if (sexo == 'M' || sexo == 'm')
            {
                homens++;
                mediaHomens = mediaHomens + altura;
            }

            maiorAltura = altura;
            menorAltura = altura;

            if (altura > maiorAltura)
            {
                maiorAltura = altura;
            }
            if (altura < menorAltura)
            {
                menorAltura = altura;
            }
        }

    } while (altura < 0 || altura > 0);

    total = mulheres + homens;

    printf("\n================\n");

    printf("A maior altura do grupo é: %.2f\n", maiorAltura);
    printf("A menor altura do grupo é: %.2f\n", menorAltura);

    printf("\n==== MULHERES ====\n");
    printf("Quantidade: %d\n", mulheres);
    printf("Média de altura: %.2f\n", mediaMulheres / mulheres);
    printf("Percentual: %.2f%%\n", ((float)mulheres * 100) / total);

    printf("\n==== HOMENS ====\n");
    printf("Quantidade: %d\n", homens);
    printf("Média de altura: %.2f\n", mediaHomens / homens);
    printf("Percentual: %.2f%%\n", ((float)homens * 100) / total);

    return 0;
}