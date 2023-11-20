import java.util.Scanner;

public final class Humano extends Jogador implements JogarComoHumano {
    public Humano(String nome) {
        super(nome);
    }

    @Override
    public int escolherJogo() {
        Scanner teclado = new Scanner(System.in);
        int jogo;

        do {
            System.out.println(
                    this.getNome() + ", para qual jogo deseja apostar? Jogo de Azar (1) ou Jogo General (2)? ");
            jogo = teclado.nextInt();
            teclado.nextLine();
            if (jogo != 1 && jogo != 2) {
                System.out.println("Este jogo nao e valido");
            }
        } while (jogo != 1 && jogo != 2);

        return jogo;
    }

    @Override
    public int escolherJogada() {
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
            if (validade != true) {
                System.out.println("A jogada nao e valida");
            }
        } while (validade != true);

        return jogada;
    }

    // Pergunta e valida quanto o jogador deseja apostar, e atualiza o saldo do jogador
    @Override
    public float valorAposta() {
        Scanner teclado = new Scanner(System.in);
        float valorAposta = 0;

        System.out.println("Quanto deseja apostar? Saldo atual: " + getSaldo());
        do {
            valorAposta = teclado.nextFloat();

            if (valorAposta > getSaldo()) {
                System.out.println("Valor de aposta e maior que o saldo atual!\n");
            }
            if (valorAposta <= 0) {
                System.out.println("Valor de aposta invalido!\n");
            } else {
                setSaldo(getSaldo() - valorAposta);
            }
        } while (valorAposta > getSaldo() || valorAposta <= 0);

        return valorAposta;
    }

    @Override
    public void iniciarJogoAzar(float valorAposta, int rodada) {
        
    };

    @Override
    public void iniciarJogoGeneral(float valorAposta, int jogada) {
        JogoDados novoJogo = new JogoGeneral();
    }
}
