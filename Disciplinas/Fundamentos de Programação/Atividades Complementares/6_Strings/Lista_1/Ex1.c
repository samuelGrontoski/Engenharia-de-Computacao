#include <stdio.h>

int main(void)
{
    char string[100], opcao;

    do
    {
        printf("Informe uma string: ");
        setbuf(stdin, NULL);
        gets(string);
        printf("\n");

        int i = 0, vetVogais[5] = {0, 0, 0, 0, 0};

        while (string[i] != '\0')
        {
            if (string[i] == 'a' || string[i] == 'A')
            {
                vetVogais[0]++;
            }
            else if (string[i] == 'e' || string[i] == 'E')
            {
                vetVogais[1]++;
            }
            else if (string[i] == 'i' || string[i] == 'I')
            {
                vetVogais[2]++;
            }
            else if (string[i] == 'o' || string[i] == 'O')
            {
                vetVogais[3]++;
            }
            else if (string[i] == 'u' || string[i] == 'U')
            {
                vetVogais[4]++;
            }
            else
            {
            }

            i++;
        }

        printf("VOGAL\tQUANTIDADE\n");
        printf("====================\n");
        printf("A/a\t\t%d \nE/e\t\t%d \nI/i\t\t%d \nO/o\t\t%d \nU/u\t\t%d \n", vetVogais[0], vetVogais[1], vetVogais[2], vetVogais[3], vetVogais[4]);

        printf("\nDeseja repetir o programa(S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
        printf("\n");

    } while (opcao == 's' || opcao == 'S');

    return 0;
}