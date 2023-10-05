import java.io.Serializable;
import java.util.Scanner;

public class Jogador implements Serializable {
    private String nome;
    private String tipoJogador;
    private JogoGeneral jogoG;

    // Construtor
    public Jogador(String nome, String tipoJogador) {
        this.nome = nome;
        this.tipoJogador = tipoJogador;
        jogoG = new JogoGeneral();
    }

    // Joga os dados para o jogador especifico
    public void jogarDados() {
        jogoG.rolarDados();
    }

    // Passa o resultados dos dados jogados pelo jogador
    public String toString() {
        String resultado = jogoG.toString();

        return resultado;
    }

    // Escolhe a jogada
    public boolean escolherJogada(int jogada) {
        boolean validade = false;

        // Se a jogada ainda nao foi escolhida, chama a metodo que pontua
        if (jogoG.validarJogada(jogada - 1) == false) {
            System.out.println("Esta jogada ja foi escolhida");
            validade = false;
        }
        if (jogoG.validarJogada(jogada - 1) == true) {
            jogoG.pontuarJogadaHumano(jogada - 1);
            System.out.println("Jogada registrada");
            validade = true;
        }

        return validade;
    }

    public void jogadaMaquina(){
        jogoG.pontuarJogadaMaquina();
            System.out.println("Jogada registrada");
    }

    // Mostra as jogadas executadas
    public void mostrarJogadasExecutadas() {
        System.out.println("1\t2\t3\tt4\tt5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
        System.out.println(jogoG.jogadaString());
    }

    public String getNome() {
        return nome;
    }

    public String getTipoJogador() {
        return tipoJogador;
    }

    public void excluirJogador() {
        this.nome = null;
        this.tipoJogador = null;
        this.jogoG = null;
    }
}
