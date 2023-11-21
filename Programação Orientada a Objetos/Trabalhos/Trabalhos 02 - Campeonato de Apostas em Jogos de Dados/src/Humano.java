import java.util.Scanner;

public final class Humano extends Jogador implements JogarComoHumano {
    public Humano(String nome) {
        super(nome);
    }

    // Pergunta e valida quanto o jogador deseja apostar, e atualiza o saldo do
    // jogador
    @Override
    public float valorAposta() {
        Scanner teclado = new Scanner(System.in);
        float valorAposta;

        if (getSaldo() != 0) {
            System.out.println("Quanto deseja apostar? Saldo atual: " + getSaldo());
            do {
                valorAposta = teclado.nextFloat();
                teclado.nextLine();

                if (valorAposta > getSaldo()) {
                    System.out.println("Valor de aposta e maior que o saldo atual!\n");
                }
                if (valorAposta <= 0) {
                    System.out.println("Valor de aposta invalido!\n");
                }
            } while (valorAposta > getSaldo() || valorAposta <= 0);
            setSaldo(getSaldo() - valorAposta);
            if (getSaldo() < 0) {
                setSaldo(0);
            }
        } else {
            System.out.println("Saldo esta zerado!");
            valorAposta = 0;
        }

        return valorAposta;
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
        int jogada;

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

    @Override
    public void iniciarJogoAzar(float valorAposta, int rodada) {
        JogoDados novoJogo = new JogoAzar(valorAposta);
        setJogo(novoJogo, rodada);

        boolean resultado = executarJogo(rodada);

        if (resultado == true) {
            setSaldo(getSaldo() + (valorAposta * 2));
        }
    };

    @Override
    public void iniciarJogoGeneral(float valorAposta, int rodada) {
        JogoDados novoJogo = new JogoGeneral(valorAposta);
        setJogo(novoJogo, rodada);

        boolean resultado = executarJogo(rodada);
    }
}
