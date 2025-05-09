import java.util.Random;

public class UsaAnimal {
    public static void main(String[] args) {

        for (int i = 0; i < 10; i++) {
            int num;
            Random x = new Random();
            num = x.nextInt(10) + 1;

            switch (num) {
                case 1: {
                    Mamiferos Urso = new Mamiferos("Urso", "ruuu");
                    System.out.println(Urso);
                    break;
                }
                case 2: {
                    Peixes Tilapia = new Peixes("Tilapia", "splash(batendo na agua)");
                    System.out.println(Tilapia);
                    break;
                }
                case 3: {
                    Aves Galinha = new Aves("Galinha", "cocoroco");
                    System.out.print(Galinha);
                    break;
                }
                case 4: {
                    Mamiferos Cachorro = new Mamiferos("Cachorro", "auau");
                    System.out.print(Cachorro);
                    break;
                }
                case 5: {
                    Mamiferos Gato = new Mamiferos("Gato", "miau");
                    System.out.print(Gato);
                    break;
                }
                case 6: {
                    Peixes Bagre = new Peixes("Bagre", "splash(batendo na agua)");
                    System.out.print(Bagre);
                    break;
                }
                case 7: {
                    Aves Falcao = new Aves("Falcao", "croac croac");
                    System.out.print(Falcao);
                    break;
                }
                case 8: {
                    Aves Coruja = new Aves("Coruja", "uuh uuh");
                    System.out.print(Coruja);
                    break;
                }
                case 9: {
                    Aves Cisne = new Aves("Cisne", "ahn ahn ahn");
                    System.out.print(Cisne);
                    break;
                }
                case 10: {
                    Aves Pato = new Aves("Pato", "quá quá");
                    System.out.print(Pato);
                    break;
                }

                default:
                    break;
            }
        }
    }
}