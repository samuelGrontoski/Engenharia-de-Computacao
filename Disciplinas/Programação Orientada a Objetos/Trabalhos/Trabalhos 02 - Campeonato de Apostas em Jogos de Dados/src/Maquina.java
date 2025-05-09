import java.text.DecimalFormat;
import java.util.Random;

public final class Maquina extends Jogador implements JogarComoMaquina {
    // Construtor (Heranca de Jogador)
    public Maquina(String nome) {
        super(nome);
    }

    // Pergunta e valida quanto o jogador deseja apostar, e atualiza o saldo do
    // jogador (a maquina sempre aposta 20% do saldo total)
    @Override
    public float valorAposta() {
        float valorAposta;

        if (getSaldo() != 0) {
            System.out.println(getNome() + " quanto deseja apostar? Saldo atual: R$"
                    + new DecimalFormat("#0.##").format(getSaldo()));
            valorAposta = (float) getSaldo() * (float) (0.2);
            setSaldo(getSaldo() - valorAposta);
        } else {
            System.out.println("Saldo esta zerado!");
            valorAposta = 0;
        }

        return valorAposta;
    }

    // Pergunta ao jogador para qual jogo deseja apostar (a maquina escolha de forma aleatoria)
    @Override
    public int escolherJogo() {
        int jogo = 1;

        Random x = new Random();
        jogo = x.nextInt(2) + 1;

        return jogo;
    }

    // Inicia o jogo de azar
    @Override
    public void iniciarJogoAzar(float valorAposta, int rodada) {
        Jogador jogadorAtual = new Humano(getNome());
        JogoDados novoJogo = new JogoAzar(valorAposta);
        super.setJogo(novoJogo, rodada);

        boolean resultado = executarJogo(rodada, jogadorAtual);

        if (resultado == true) {
            setSaldo(getSaldo() + (valorAposta * 2));
        }
    };

    // Inicia o jogo general
    @Override
    public void iniciarJogoGeneral(float valorAposta, int rodada) {
        Jogador jogadorAtual = new Maquina(getNome());
        JogoDados novoJogo = new JogoGeneral(valorAposta);
        super.setJogo(novoJogo, rodada);

        boolean resultado = executarJogo(rodada, jogadorAtual);

        if (resultado == true) {
            setSaldo(getSaldo() + (valorAposta * 2));
        }
    }
}
