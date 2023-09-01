/*b) Em seguida, crie uma classe DieDemo com um metodo principal que 
gere dois objetos Die, jogue-os e exiba a soma dos dois lados 
superiores. */

public class DemoDie {
    public static void main(String[] argumentos){
        Die d1 = new Die();
        Die d2 = new Die(5);

        d1.roll();
        d2.roll();

        int soma = d1.getSideUp() + d2.getSideUp();

        System.out.println("Soma dos dados: "+soma);
    }
}