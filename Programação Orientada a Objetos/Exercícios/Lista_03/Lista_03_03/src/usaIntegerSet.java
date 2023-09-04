public class usaIntegerSet {
    
    public static void main(String[] argumentos){
        IntegerSet c1 = new IntegerSet();
        IntegerSet c2 = new IntegerSet();

        c1.insertElement(10);
        c1.insertElement(23);
        c1.insertElement(1);
        c2.insertElement(10);
        c2.insertElement(23);
        c2.insertElement(1);

        System.out.println(c1.toSetString());
        System.out.println(c2.toSetString());

        IntegerSet c3 = c1.union(c2);
        System.out.println(c3.toSetString());

        IntegerSet c4 = c1.intersection(c2);
        System.out.println(c4.toSetString());

        c2.deleteElement(1);

        boolean iguais = c1.isEqualTo(c2);

        if(iguais == true){
            System.out.println("Sao iguais");
        }
        else{
           System.out.println("Nao sao iguais"); 
        }
    }
}
