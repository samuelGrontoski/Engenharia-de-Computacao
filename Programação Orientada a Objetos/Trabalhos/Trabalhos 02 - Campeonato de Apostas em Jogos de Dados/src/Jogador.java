import java.io.Serializable;

public abstract class Jogador implements Serializable {
    private String nome;
    private JogoDados[] jogos;
    private float saldo;

    // Construtor
    public Jogador(String nome) {
        this.nome = nome;
        this.saldo = 100;
    }

    // Joga os dados para o jogador especifico
    public void jogarDados(int i) {
        jogos[i].rolarDados();
    }

    // Passa o resultados dos dados jogados pelo jogador para uma string
    public String toString() {
        String resultado = jogos.toString();

        return resultado;
    }

    // Escolhe a jogada e verifica se ela e valida
    public boolean escolherJogada(int jogada) {
        boolean validade = jogoG.validarJogada(jogada - 1);

        // Se a jogada ainda nao foi escolhida, chama a metodo que pontua
        if (validade == false) {
            System.out.println("Esta jogada ja foi escolhida");
        }
        if (validade == true) {
            jogoG.pontuarJogadaHumano(jogada);
            System.out.println("Jogada registrada\n");
            validade = true;
        }

        return validade;
    }

    // Faz a jogada automatica da maquina
    public void jogadaMaquina(){
        System.out.print("Jogada escolhida por " + getNome() + "(" + getTipoJogador() + ") [1 - 13]: ");
        jogoG.pontuarJogadaMaquina();
    }

    // Mostra as jogadas executadas
    public void mostrarJogadasExecutadas() {
        System.out.println("1\t2\t3\t4\t5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
        System.out.println(jogoG.jogadaString());
    }

    // Obtem e retorna o valor da jogada especifica
    public int valorJogada(int posicao){
        int pontos = jogoG.pontosJogada(posicao);

        return pontos;
    }

    // Obtem e retorna o nome do jogador
    public String getNome() {
        return nome;
    }

    public void setNomeJogo(String nomeJogo, int i){
        jogos[i].setNome(nomeJogo);
    }

    // Exclui o jogador
    public void excluirJogador() {
        this.nome = null;
        this.jogos = null;
        this.saldo = 0;
    }

    // Reinicia o jogo general do jogador toda vez que um campeonato e iniciado
    public void reiniciaJogoG() {
        this.jogoG = new JogoGeneral();
    }
}
