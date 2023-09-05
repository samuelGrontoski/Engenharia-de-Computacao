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
    }

    public Rational somar(Rational r2){
        Rational r3 = new Rational();

        r3.denominador = numerador * r2.numerador;
        r3.numerador = ((r3.denominador / denominador) * numerador) + ((r3.denominador / r2.denominador) * r2.numerador);

        return r3;
    }

    public Rational subtrair(Rational r2){
        Rational r3 = new Rational();

        r3.denominador = numerador * r2.numerador;
        r3.numerador = ((r3.denominador / denominador) * numerador) - ((r3.denominador / r2.denominador) * r2.numerador);

        return r3;
    }

    public Rational multiplicar(Rational r2){
        Rational r3 = new Rational();

        r3.numerador = numerador * r2.numerador;
        r3.denominador = denominador * r2.denominador;

        return r3;
    }

    public Rational dividir(Rational r2){
        Rational r3 = new Rational();

        r3.numerador = numerador * r2.denominador;
        r3.denominador = denominador * r2.numerador;

        return r3;
    }

    public void imprimir(Rational r){
        String str = r.numerador + "/" + r.denominador;

        System.out.println(str);
    }
}