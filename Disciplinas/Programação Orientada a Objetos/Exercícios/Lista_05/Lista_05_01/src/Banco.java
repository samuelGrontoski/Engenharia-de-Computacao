public class Banco {
    public static void main(String[] a){

        ContaBancaria2[] myBank = new ContaBancaria2[10];

        myBank[0] = new ContaBancaria2("Chaves", 800);
        myBank[3] = new ContaBancaria2("Chiquinha", 1200);
        myBank[7] = new ContaBancaria2("Kiko", 1700);

        double total = total(myBank);

        System.out.println("Capital do banco:" + total);
    }

    public static double total(ContaBancaria2[] x){
        double s = 0;

        for(ContaBancaria2 p : x){
            if(p != null){
                s += p.getSaldo();
            }
        }
        return s;
    }
}
