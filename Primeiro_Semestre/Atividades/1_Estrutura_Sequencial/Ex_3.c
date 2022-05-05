
int main (void) {

    float peso, altura, imc;

    printf ("Informe o seu peso (em kg): ");
    scanf ("%f", &peso);
    printf ("Informe a sua altura (em metros): ");
    scanf ("%f", &altura);

    imc = peso / (altura * altura);

    printf ("Seu IMC eh: %.2f", imc);

    return 0;
}
