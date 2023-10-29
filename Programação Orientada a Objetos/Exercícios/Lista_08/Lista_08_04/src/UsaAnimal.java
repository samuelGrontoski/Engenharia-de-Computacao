public class UsaAnimal {
    public static void main(String[] args){
        Mamiferos Urso = new Mamiferos("Urso", "Rugido: ruuu");
        Peixes Tilapia = new Peixes("Tilapia", "Barulho? splash(batendo na agua)");
        Aves Galinha = new Aves("Galinha", "Cacarejo: cocoroco");

        System.out.println(Urso);
        System.out.println(Tilapia);
        System.out.print(Galinha);
    }
}