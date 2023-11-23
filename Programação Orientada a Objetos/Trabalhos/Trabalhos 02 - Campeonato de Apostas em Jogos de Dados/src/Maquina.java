import java.util.Random;

public final class Maquina extends Jogador implements JogarComoMaquina{
    public Maquina(String nome){
        super(nome);
    }

    @Override
    public float valorAposta() {
        float valorAposta;

        if (getSaldo() != 0) {
            valorAposta = (float)getSaldo() * (float)(0.2);
            setSaldo(getSaldo() - valorAposta);
        } else {
            System.out.println("Saldo esta zerado!");
            valorAposta = 0;
        }

        return valorAposta;
    }

    @Override
    public int escolherJogo() {
        int jogo = 1;

        Random x = new Random();
        jogo = x.nextInt(1) + 1;

        return jogo;
    }

    @Override
    public int escolherJogada() {
        int jogada = 0;

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
        
    }
}
