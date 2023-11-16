import java.util.Scanner;

public final class Humano extends Jogador implements JogarComoHumano {
    public Humano(String nome) {
        super(nome);
    }

    public int escolherJogo() {
        Scanner teclado = new Scanner(System.in);
        int jogo;

        do {
            System.out.println("Para qual jogo deseja apostar? Jogo de Azar (1) ou Jogo General (2)? ");
            jogo = teclado.nextInt();
            teclado.nextLine();
            if (jogo < 1 || jogo > 2) {
                System.out.println("O jogo nao e valido");
            }
        } while (jogo < 1 || jogo > 2);

        return jogo;
    }

    public int escolherJogada(JogoGeneral jogo) {
        Scanner teclado = new Scanner(System.in);
        int jogada = 0;

        boolean validade;
        do {
            do {
                System.out.println("Para qual jogada deseja marcar: [1 - 13] " + this.getNome() + "?");
                jogada = teclado.nextInt();
                teclado.nextLine();
                if (jogada < 1 || jogada > 13) {
                    System.out.println("A jogada nao e valida");
                }

            } while (jogada < 1 || jogada > 13);

            validade = this.validarJogada(jogada);
        } while (validade != true);

        return jogada;
    }

    @Override
    public void pontuandoGeneral(int jogada) {
        JogoDados novoJogo = new JogoGeneral();
    }
}
