public class usaArrayDePontos2D {
    public static void main(String[] args){
        ArrayDePontos2D pontos2d = new ArrayDePontos2D(10);

        pontos2d.modifica(0, new Ponto2D(-1, -3));
        pontos2d.modifica(2, new Ponto2D(0, 0));
        pontos2d.modifica(6, new Ponto2D(13, 17));

        System.out.println(pontos2d);

    }
}