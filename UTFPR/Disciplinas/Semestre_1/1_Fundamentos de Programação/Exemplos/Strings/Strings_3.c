#include <stdio.h>

int main(void)
{
    char string[50], minuscula[50], maiuscula[50], opcao;
    int i = 0;

    do
    {
        printf("Informe uma string: ");
        setbuf(stdin, NULL);
        gets(string);

        while (string[i] != '\0')
        {
            if (string[i] >= 65 && string[i] <= 90)
            {
                maiuscula[i] = string[i];
                minuscula[i] = string[i] + 32;
            }
            else if (string[i] >= 97 && string[i] <= 122)
            {
                minuscula[i] = string[i];
                maiuscula[i] = string[i] - 32;
            }
            else
            {
                maiuscula[i] = string[i];
                minuscula[i] = string[i];
            }

            i++;
        }

        maiuscula[i] = '\0';
        minuscula[i] = '\0';

        printf("String: %s\n", string);
        printf("String maiuscula: %s\n", maiuscula);
        printf("String minuscula: %s\n", minuscula);

        printf("\nDeseja repetiro programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}