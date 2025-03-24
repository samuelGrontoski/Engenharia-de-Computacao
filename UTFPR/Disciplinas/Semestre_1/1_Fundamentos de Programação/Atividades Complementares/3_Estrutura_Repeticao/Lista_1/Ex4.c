/*4) Fazer um programa que faça o levantamento dos candidatos que se inscreveram para vagas em uma
empresa. Considerando que para cada candidato, a empresa tenha obtido as seguintes informações:
- Idade
- Nacionalidade (B - Brasileiro ou E - Estrangeiro)
- Possui curso superior (S - Sim ou N - Não)
Determinar:
a) A quantidade de brasileiros.
b) A quantidade de estrangeiros.
c) A idade média dos brasileiros sem curso superior.
d) A menor idade entre os estrangeiros com curso superior.
Estabelecer uma condição para finalizar a entrada de dados do programa. Por exemplo, igual a 0 ou idade
negativa. Se a idade for igual a 0 ou negativa, não ler as informações de nacionalidade e se possui curso
superior, e sair do programa.
*/

#include <stdio.h>

int main (void)
{

    int idade, brasileiros=0, estrangeiros=0, comSup=0, semSup=0, brSemSup=0, somaIdadeBR=0, estComSup=0, menor;
    float mediaIdadeBR;
    char nacionalidade, r, cursoSup;

    do
    {
        printf ("Informe a idade: ");
        scanf ("%d", &idade);

        if (idade > 0)
        {
            // validação
            do
            {
                printf ("Informe a nacionalidade (B - Brasileiro ou E - Estrangeiro): ");
                setbuf (stdin, NULL);
                scanf ("%c", &nacionalidade);

                if (nacionalidade != 'B' && nacionalidade !='b' && nacionalidade !='E' && nacionalidade !='e')
                {
                    printf ("Entrada invalida\n");
                }
            }
            while (nacionalidade != 'B' && nacionalidade !='b' && nacionalidade !='E' && nacionalidade !='e');

            do
            {
                printf ("Possui curso superior (S - Sim ou N - Nao): ");
                setbuf (stdin, NULL);
                scanf ("%c", &cursoSup);

                if (cursoSup != 'S' && cursoSup != 's' && cursoSup != 'N' && cursoSup != 'n')
                {
                    printf ("Entrada invalida\n");
                }
            }
            while (cursoSup != 'S' && cursoSup != 's' && cursoSup != 'N' && cursoSup != 'n');


            // contagem
            if (nacionalidade == 'B' || nacionalidade == 'b')
            {
                brasileiros++;
                if (cursoSup == 'N' || cursoSup == 'n')
                {
                    somaIdadeBR = somaIdadeBR + idade;
                    brSemSup++;
                }
            }
            else
            {
                estrangeiros++;
                if (cursoSup == 'S' || cursoSup == 's')
                {
                    estComSup++;
                    if (estComSup == 1)
                    {
                        menor = idade;
                    }
                    else
                    {
                        if (idade < menor)
                        {
                            menor = idade;
                        }
                    }
                }
            }
        }
    }
    while (idade > 0);

    printf ("\nQuantidade de brasileiros: %d\n", brasileiros);
    printf ("Quantidade de estrangeiros: %d\n", estrangeiros);

    if (brSemSup > 0)
    {
        mediaIdadeBR = somaIdadeBR / brSemSup;
        printf ("A idade media dos brasileiros sem curso superior eh: %.1f\n", mediaIdadeBR);
    }
    else
    {
        printf ("Não existe nenhum brasileiro sem curso superior");
    }

    if (estComSup > 0)
    {
        printf ("A menor idade de estrangeiros com curso superior eh: %d\n", menor);
    }
    else
    {
        printf ("Não existe nenhum estrangeiro com curso superior");
    }

    return 0;
}
