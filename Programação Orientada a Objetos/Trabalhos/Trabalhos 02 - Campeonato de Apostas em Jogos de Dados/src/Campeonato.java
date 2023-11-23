import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Scanner;
import java.text.DecimalFormat;

public class Campeonato implements Serializable {
    private Jogador[] jogadores;
    private int numJogadores;

    // Construtor
    public Campeonato() {
        jogadores = new Jogador[10];
        this.numJogadores = 0;
    }

    // Inclui um novo jogador a lista de jogadores
    public void incluirJogador() {

        if (numJogadores != 10) {
            Scanner teclado = new Scanner(System.in);
            boolean nomeIgual = false;

            System.out.println("Informe o nome do jogador: ");
            String nome = teclado.nextLine();
            String tipoJogador = "Sem valor";
            do {
                System.out.println("Tipo do Jogador [H - humano ou M - maquina]: ");
                tipoJogador = teclado.nextLine();
            } while ((tipoJogador.equals("H") == false) && (tipoJogador.equals("M") == false));

            Jogador novoJogador = null;
            if (tipoJogador.equals("H")) {
                novoJogador = new Humano(nome);
            }
            if (tipoJogador.equals("M")) {
                novoJogador = new Maquina(nome);
            }

            // Se nao houver nenhum jogador registrado, registra o primeiro jogador direto
            if (numJogadores == 0) {
                jogadores[numJogadores] = novoJogador;
                numJogadores++;
                System.out.println("\nJogador " + nome + " incluido com sucesso!");
            } else {
                for (int i = 0; i < numJogadores; i++) {
                    String nomeSalvo = jogadores[i].getNome();
                    nomeIgual = (nomeSalvo.equals(nome)); // Compara se o nome do jogador nao vai se repetir

                    if (nomeIgual == true) {
                        System.out.println("\nJogador " + nome + " ja registrado, tente outro nome.");
                        break;
                    }
                    if (nomeIgual == false) {
                        jogadores[numJogadores] = novoJogador;
                        numJogadores++;
                        System.out.println("\nJogador " + nome + " incluido com sucesso!");
                        break;
                    }
                }
            }
        } else {
            System.out.println("Limite de jogadores alcancado!");
        }
    }

    // Remove um novo jogador a lista de jogadores
    public void removerJogador() {
        if (numJogadores == 0) {
            System.out.println("Nenhum jogador cadastrado");
        } else {
            Scanner teclado = new Scanner(System.in);
            boolean nomeIgual = false;

            System.out.println("--- Jogadores cadastrados ---");
            for (int i = 1; i <= numJogadores; i++) {
                System.out.println(i + "- " + jogadores[i - 1].getNome());
            }

            System.out.println("Informe o nome do jogador que deseja excluir: ");
            String nome = teclado.nextLine();

            for (int i = 0; i < numJogadores; i++) {
                String nomeSalvo = jogadores[i].getNome();
                nomeIgual = (nomeSalvo.equals(nome));

                if (nomeIgual == true) {
                    jogadores[i].excluirJogador();
                    for (int j = i; j < numJogadores; j++) {
                        jogadores[j] = jogadores[j + 1];
                    }
                    numJogadores--;
                    System.out.println("\nJogador excluido com sucesso!");
                    break;
                }
            }

            if (nomeIgual == false) {
                System.out.println("\nJogador nao encontrado");
            }
        }
    }

    // Inicia o campeonato
    public void iniciarCampeonato() {
        if (numJogadores == 0) {
            System.out.println("Nenhum jogador registrado, nao foi possivel iniciar o campeonato.");
        } else {
            for (int i = 0; i < 10; i++) {
                System.out.println("Iniciando a rodada numero " + (i + 1) + "!\n");

                for (int j = 0; j < numJogadores; j++) {
                    float valorAposta = jogadores[j].valorAposta();
                    if (valorAposta != 0) {
                        int jogo = jogadores[j].escolherJogo();
                        if (jogo == 1) {
                            System.out.println("Apostando R$" + new DecimalFormat("#0.##").format(valorAposta) + " no Jogo de Azar!\n");
                            jogadores[j].iniciarJogoAzar(valorAposta, i);
                        }
                        if (jogo == 2) {
                            System.out.println("Apostando R$" + new DecimalFormat("#0.##").format(valorAposta) + " no Jogo General!\n");
                            jogadores[j].iniciarJogoGeneral(valorAposta, i);
                        }
                    } else {
                        System.out.println("Nao e possivel realizar a rodada para " + jogadores[j].getNome());
                    }
                }
            }
        }
    }

    public void imprimirSaldos() {

    }

    public void imprimirResultados() {

    }

    public void imprimirEstatisticas() {

    }

    public void gravarEmArquivo() {
        File arquivo = new File("jogadores.dat");
        try {
            FileOutputStream fout = new FileOutputStream(arquivo);
            ObjectOutputStream oos = new ObjectOutputStream(fout);
            oos.writeObject(jogadores);
            oos.flush();
            oos.close();
            fout.close();
            System.out.println("\nArquivo gravado com sucesso!");
        } catch (Exception ex) {
            System.err.println("erro: " + ex.toString());
        }
    }

    public void lerDoArquivo() {
        File arquivo = new File("jogadores.dat");

        try {
            FileInputStream fin = new FileInputStream(arquivo);
            ObjectInputStream oin = new ObjectInputStream(fin);

            Jogador[] jogadoresArq = (Jogador[]) oin.readObject();
            oin.close();
            fin.close();

            jogadores = jogadoresArq;

            numJogadores = 0;
            for (Jogador jog : jogadores) {
                if (jog != null)
                    numJogadores++;
            }

            System.out.println("Arquivo lido com sucesso!");

        } catch (Exception ex) {
            System.err.println("erro: " + ex.toString());
        }
    }
}
