/*
1) Elaborar um programa que leia um n�mero que representa uma senha e verifica se a mesma est� correta
ou n�o, comparando-a com 12345 e informa "Acesso autorizado" ou "Acesso negado", conforme o caso.
*/

int main (void) {

    int senha;

    printf ("Informe a senha: ");
    scanf ("%d", &senha);

    if (senha == 12345) {
        printf ("Acesso autorizado\n");
    } else {
        printf ("Acesso negado\n");
    }
return 0;
}
