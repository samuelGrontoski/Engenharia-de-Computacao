/* 5) Apresentar os n primeiros números pares e divisíveis por 3 informados pelo usuário (validar para que n
seja diferente de 0). Se o usuário informar um número negativo transformá-lo em positivo (sem usar funções
prontas) antes de utilizar.
Por exemplo, se o usuário informar 4, o programa deverá mostrar os quatro primeiros números pares que são
divisíveis por três: 0, 6, 12 e 18. */

#include <stdio.h>

int main (void)
{
    int num, count, i, par;
    char opcao;

    do
    {
        count = 0;
        par = 6;

        do
        {
            printf ("\nQuantos numeros pares deseja informar? ");
            scanf ("%d", &num);

            if (num == 0)
            {
                printf ("\nInforme um valor diferente de 0\n");
            }
            if (num < 0)
            {
                num = num * (-1);
            }
        } while (num == 0);
        
        do
        {
            for (i = 0; i < num; i++)
            {
                if (par % 3 == 0)
                {
                    printf ("%d\t", par);
                    count++;
                }
                par = par + 2;
            }
        } while (count < num);
        
        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');
    
    return 0;
}