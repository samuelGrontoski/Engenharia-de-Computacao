import java.io.Serializable;

public class TestarDados implements Serializable{
    public static void main(String[] args){
        Dado d1 = new Dado();
        Dado d2 = new Dado();

        System.out.println(d1.toString());
        System.out.println(d2.toString());

        d1.roll();
        d2.roll();

        System.out.println(d1.toString());
        System.out.println(d2.toString());
    }
}
