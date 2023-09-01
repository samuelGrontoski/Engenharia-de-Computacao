public class usaComplexo {

    public static void main(String[] argumentos){
        Complexo c1 = new Complexo();
        Complexo c2 = new Complexo(2, 2);

        c1.inicializaNumero(2, 3);

        c1.imprimeNumero();
        c2.imprimeNumero();

        boolean iguais = c1.elgual(c2);
        if(iguais == true){
            System.out.println("Sao iguais");
        }
        else{
           System.out.println("Nao sao iguais"); 
        }

        c1.soma(c2);
        c1.imprimeNumero();

        c1.subtrai(c2);
        c1.imprimeNumero();

        c1.multiplica(c2);
        c1.imprimeNumero();

        c1.divide(c2);
        c1.imprimeNumero();
    }

    
}
