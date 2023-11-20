import java.io.Serializable;

public abstract class Jogador implements Serializable {
    private String nome;
    private JogoDados[] jogos;
    private int numJogos;
    private float saldo;

    // Construtor
    public Jogador(String nome) {
        this.nome = nome;
        this.numJogos = 0;
        this.saldo = 100;
    }

    // Joga os dados para o jogador especifico
    public void jogarDados() {
        jogos[numJogos].rolarDados();
    }

    // Passa o resultados dos dados jogados pelo jogador para uma string
    public String toString() {
        String resultado = jogos.toString();

        return resultado;
    }

    // Valida a jogada
    public boolean validarJogada(int jogada) {
        boolean validade = jogos[numJogos].validarJogada(jogada);

        if(validade == false) {
            System.out.println("Esta jogada ja foi escolhida");
        }
        if(validade == true) {
            System.out.println("Jogada registrada\n");
        }
        return validade;
    }

    public abstract int escolherJogo();

    public abstract int escolherJogada();

    public abstract float valorAposta();

    public abstract void iniciarJogoAzar(float valorAposta, int rodada);

    public abstract void iniciarJogoGeneral(float valorAposta, int jogada);

    // Mostra as jogadas executadas
    public void mostrarJogadasExecutadas() {
        System.out.println("1\t2\t3\t4\t5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
        System.out.println(jogoG.jogadaString());
    }

    // Obtem e retorna o valor da jogada especifica
    public int valorJogada(int posicao){
        int pontos = jogos[posicao].pontosJogada;

        return pontos;
    }

    // Obtem e retorna o nome do jogador
    public String getNome() {
        return nome;
    }

    public void setNomeJogo(String nomeJogo){
        jogos[numJogos].setNome(nomeJogo);
    }

    public JogoDados getJogo(int posicao) {
        return jogos[posicao];
    }

    public void setJogo(JogoDados novoJogo) {
        jogos[numJogos] = novoJogo;
        numJogos++;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    // Exclui o jogador
    public void excluirJogador() {
        this.nome = null;
        this.jogos = null;
        this.numJogos = 0;
        this.saldo = 0;
    }

    // Reinicia oas jogos do jogador toda vez que um campeonato e iniciado
    public void reiniciaJogo() {
        this.jogos = null;
    }
}
