public class Rational {
    private int numerador;
    private int denominador;

    public Rational(){
        numerador = 0;
        denominador = 0;
    }

    public Rational(int n, int d){
        numerador = n;
        denominador = d;

        if (denominador > 1){
            for (int i = 1; i <= denominador; i++){
                if (numerador % i == 0 && denominador % i == 0){
                    numerador = numerador / i;
                    denominador = denominador / i;
                }
            }
        }
    }

    public Rational somar(Rational r2){
        int n, d;

        d = denominador * r2.denominador;
        n = ((d / denominador) * numerador) + ((d / r2.denominador) * r2.numerador);

        Rational r3 = new Rational(n, d);

        return r3;
    }

    public Rational subtrair(Rational r2){
        int n, d;

        d = denominador * r2.denominador;
        n = ((d / denominador) * numerador) - ((d / r2.denominador) * r2.numerador);

        Rational r3 = new Rational(n, d);

        return r3;
    }

    public Rational multiplicar(Rational r2){
        int n, d;

        n = numerador * r2.numerador;
        d = denominador * r2.denominador;

        Rational r3 = new Rational(n, d);

        return r3;
    }

    public Rational dividir(Rational r2){
        int n, d;

        n = numerador * r2.denominador;
        d = denominador * r2.numerador;

        Rational r3 = new Rational(n, d);

        return r3;
    }

    public void imprimir(){
        String str = numerador + "/" + denominador;

        System.out.println(str);
    }

    public void imprimirFloat(int n){
        float flutuante;

        flutuante = (float)numerador / (float)denominador;

        System.out.printf("%." + n + "f", flutuante);
    }
}