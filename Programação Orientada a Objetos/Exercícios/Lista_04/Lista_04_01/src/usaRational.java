public class usaRational {
    public static void main(String[] argumentos){
        Rational r1 = new Rational(2, 4);
        Rational r2 = new Rational(3, 2);
        Rational r3 = new Rational();

        r1.imprimir();
        r2.imprimir();

        //somar
        r3 = r1.somar(r2);
        r3.imprimir();

        //subtrair
        r3 = r1.subtrair(r2);
        r3.imprimir();

        //multiplicar
        r3 = r1.multiplicar(r2);
        r3.imprimir();

        //dividir
        r3 = r1.dividir(r2);
        r3.imprimir();

        //imprimir ponto flutuante
        r1.imprimirFloat(3);

    }
}
