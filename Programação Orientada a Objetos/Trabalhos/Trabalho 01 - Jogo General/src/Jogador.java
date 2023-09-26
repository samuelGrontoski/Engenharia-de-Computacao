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
    public void escolherJogada() {
        Scanner teclado = new Scanner(System.in);
        int jogada;
        boolean validade = false;

        // Se for uma maquina, vai direto para a parte de pontuacao
        if (tipoJogador.equals("H") == true) {
            // Laco do while valida se o jogador esta entrando com um numero entre 1 e 13
            do {
                System.out.println("Para qual jogada deseja marcar: [1 - 13] " + nome + "?");
                mostrarJogadasExecutadas();
                jogada = teclado.nextInt();

                if (jogada < 1 || jogada > 13) {
                    System.out.println("A jogada nao e valida"); // Da um alerta de que o numero nao esta entre 1 e 13
                } else {
                    validade = jogoG.validarJogada(jogada); // chama a validacao da jogada se estiver entre 1 e 13

                    // Se a jogada ainda nao foi escolhida, chama a metodo que pontua
                    if (validade == true) {
                        jogoG.pontuarJogadaHumano(jogada);
                        System.out.println("Jogada registrada");
                    } else {
                        System.out.println("Esta jogada ja foi escolhida");
                    }
                }

            } while ((jogada < 1 || jogada > 13) && validade != true);
        }
        if (tipoJogador.equals("M") == true) {
            jogoG.pontuarJogadaMaquina();
            System.out.println("Jogada registrada");
        }

        teclado.close();
    }

    // Mostra as jogadas executadas
    public void mostrarJogadasExecutadas(){
        System.out.println("1 2 3 4 5 6 7(T) 8(Q) 9(F) 10(S+) 11(S-) 12(G) 13(X)");
        System.out.println(jogoG.jogadaString());
    }

    public String getNome(){
        return nome;
    }

    public String getTipoJogador(){
        return tipoJogador;
    }

    public void excluirJogador(){
        this.nome = null;
        this.tipoJogador = null;
        this.jogoG = null;
    }
}
