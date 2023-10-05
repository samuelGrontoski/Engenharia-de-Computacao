import java.io.Serializable;
import java.util.Scanner;

public class Campeonato implements Serializable {
    private Jogador[] jogadores;
    private int numJogadores = 0;

    public Campeonato() {
        jogadores = new Jogador[10];
    }

    public void incluirJogador(String nome, String tipoJogador) {
        boolean nomeIgual = false;
        Jogador novoJogador = new Jogador(nome, tipoJogador);

        // Se nao houver nenhum jogador registrado, registra o primeiro jogador direto
        if (numJogadores == 0) {
            jogadores[numJogadores] = novoJogador;
            numJogadores++;
            System.out.println("Jogador incluido com sucesso!");
        } else {
            for (int i = 0; i < numJogadores; i++) {
                String nomeSalvo = jogadores[i].getNome();
                nomeIgual = (nomeSalvo.equals(nome)); // Compara se o nome do jogador nao vai se repetir

                if (nomeIgual == true) {
                    System.out.println("Jogador ja registrado, tente outro nome");
                    break;
                }
                if (nomeIgual == false) {
                    jogadores[numJogadores] = novoJogador;
                    numJogadores++;
                    System.out.println("Jogador incluido com sucesso!");
                    break;
                }
            }
        }
    }

    public void removerJogador(String nome) {
        boolean nomeIgual = false;

        for (int i = 0; i < numJogadores; i++) {
            String nomeSalvo = jogadores[i].getNome();
            nomeIgual = (nomeSalvo.equals(nome));

            if (nomeIgual == true) {
                jogadores[i].excluirJogador();
                numJogadores--;
                System.out.println("Jogador excluido com sucesso!");
                break;
            }
        }

        if (nomeIgual == false) {
            System.out.println("Jogador nao encontrado");
        }
    }

    public void iniciarCampeonato() {
        Scanner teclado = new Scanner(System.in);
        int jogada;

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < numJogadores; j++) {
                // Rola os dados
                System.out.println("Rolando dados para " + jogadores[j].getNome() + "(" + jogadores[j].getTipoJogador() + ")...");
                jogadores[j].jogarDados();
                System.out.println("" + jogadores[j].toString());

                // Se for humano pergunta a jogada
                if (jogadores[j].getTipoJogador().equals("H") == true) {
                    boolean validade;
                    do {
                        // Mostra as jogadas e pergunta para qual jogada quer registrar
                        System.out.println("Para qual jogada deseja marcar: [1 - 13] " + jogadores[j].getNome() + "?");
                        jogadores[j].mostrarJogadasExecutadas();
                        do { // Valida a jogada entre 1 e 13
                            jogada = teclado.nextInt();
                            if (jogada < 1 || jogada > 13) {
                                System.out.println("A jogada nao e valida");
                            }
                        } while ((jogada < 1 || jogada > 13));

                        validade = jogadores[j].escolherJogada(jogada);
                    } while (validade != true);
                }
                // Se for maquina vai direto para as pontuacoes
                if (jogadores[j].getTipoJogador().equals("M") == true){
                    jogadores[j].jogadaMaquina();
                }
            }
        }
        teclado.close();
    }
}
