
int main (void) {

    int segundos;
    float minutos, horas, dias;

    printf ("Informe o tempo em segundos: ");
    scanf ("%d", &segundos);

    minutos = segundos / 60;
    horas = segundos / 3600;
    dias = segundos / 86400;

    printf ("O tempo em minutos eh: %.1f\n", minutos);
    printf ("O tempo em horas eh: %.1f\n", horas);
    printf ("O tempo em dias eh: %.1f\n", dias);

    return 0;
}
