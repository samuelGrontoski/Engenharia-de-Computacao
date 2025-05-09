public class Complexo {
    private double a, b;

    public Complexo(){
        a = 1;
        b = 1;
    }

    public Complexo(double x, double y){
        a = x;
        b = y;
    }

    public void inicializaNumero(double x, double y){
        a = x;
        b = y;
    }

    public void imprimeNumero(){
        String str = a + " + " + b + "i";

        System.out.println(str);
    }

    public boolean elgual(Complexo c2){
        if(a != c2.a || b != c2.b){
            return false;
        }
        return true;
    }

    public void soma(Complexo c2){
        a = a + c2.a;
        b = b + c2.b;
    }

    public void subtrai(Complexo c2){
        a = a - c2.a;
        b = b - c2.b;
    }

    public void multiplica(Complexo c2){
        a = (a * c2.a) - (b * c2.b);
        b = (a * c2.b) + (b * c2.a); 
    }

    public void divide(Complexo c2){
        a = (((a * c2.a) + (b * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b)));
        b = (((b * c2.a) - (a * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b)));
    }
}