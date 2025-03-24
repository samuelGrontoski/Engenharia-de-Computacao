#include <stdio.h>

int main (void)
{
    char opcao, texto[50];
    int i;

    do
    {
        printf("Informe um texto com ate 50 caracteres: ");
        setbuf(stdin,NULL);
        gets(texto);

        printf("\n==== TEXTO NA VERTICAL ====\n");
        
        for (i = 0; i < 50; i++)
        {
            printf("%c", texto[i]);

            if (texto[i] == ' ')
            {
                printf("\n");
            }
            else if (texto[i] == '\0')
            {
                break;
            }
        }
        
        printf("\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin,NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}