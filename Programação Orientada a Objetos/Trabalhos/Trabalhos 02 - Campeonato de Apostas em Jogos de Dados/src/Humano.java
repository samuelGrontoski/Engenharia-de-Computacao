import java.text.DecimalFormat;
import java.util.Scanner;

public final class Humano extends Jogador implements JogarComoHumano {
    // Construtor (Heranca de Jogador)
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
            System.out.println(getNome() + " quanto deseja apostar? Saldo atual: R$"
                    + new DecimalFormat("#0.##").format(getSaldo()));
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

    // Pergunta ao jogador para qual jogo deseja apostar
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

    // Inicia o jogo de azar
    @Override
    public void iniciarJogoAzar(float valorAposta, int rodada) {
        Jogador jogadorAtual = new Humano(getNome());
        JogoDados novoJogo = new JogoAzar(valorAposta);
        setJogo(novoJogo, rodada);

        boolean resultado = executarJogo(rodada, jogadorAtual);

        if (resultado == true) {
            setSaldo(getSaldo() + (valorAposta * 2));
        }
    };

    // Inicia o jogo general
    @Override
    public void iniciarJogoGeneral(float valorAposta, int rodada) {
        Jogador jogadorAtual = new Humano(getNome());
        JogoDados novoJogo = new JogoGeneral(valorAposta);
        setJogo(novoJogo, rodada);

        boolean resultado = executarJogo(rodada, jogadorAtual);

        if (resultado == true) {
            setSaldo(getSaldo() + (valorAposta * 2));
        }
    }
}
