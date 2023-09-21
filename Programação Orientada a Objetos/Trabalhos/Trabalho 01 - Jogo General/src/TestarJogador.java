public class TestarJogador {
    public static void main(String[] args){
        Jogador j1 = new Jogador("Samuel", "H");

        j1.jogarDados();
        System.out.println(j1.toString());

        j1.escolherJogada();
    }
}
