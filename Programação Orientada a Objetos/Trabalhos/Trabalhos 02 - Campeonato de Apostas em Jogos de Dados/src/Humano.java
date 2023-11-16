import java.util.Scanner;

public final class Humano extends Jogador implements JogarComoHumano{
    public Humano(String nome){
        super(nome);
    }

    public int escolherJogo(){
        int jogo = 0;
        Scanner teclado = new Scanner(System.in);

        System.out.println("Para qual jogo deseja apostar? Jogo de Azar (1) ou Jogo General (2)? ");
        String nomeJogo = teclado.nextLine();
        this.setNomeJogo(nomeJogo);

        return jogo;
    }

    public int escolherJogada(JogoGeneral jogo){
        int jogada = 0;

        return jogada;
    }
}
