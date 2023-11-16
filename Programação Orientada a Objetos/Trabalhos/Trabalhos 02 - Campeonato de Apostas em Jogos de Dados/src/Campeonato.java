import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Scanner;

public class Campeonato implements Serializable {
    private Jogador[] jogadores;
    private int numJogadores = 0;

    // Construtor
    public Campeonato() {
        jogadores = new Jogador[10];
    }

    // Inclui um novo jogador a lista de jogadores
    public void incluirJogador() {
        Scanner teclado = new Scanner(System.in);
        boolean nomeIgual = false;

        System.out.println("Nome do jogador: ");
        String nome = teclado.nextLine();
        String tipoJogador = "Sem valor";
        do {
            System.out.println("Tipo do Jogador [H - humano ou M - maquina]: ");
            tipoJogador = teclado.nextLine();
        } while ((tipoJogador.equals("H") == false) && (tipoJogador.equals("M") == false));

        Jogador novoJogador = new Jogador(nome);

        // Se nao houver nenhum jogador registrado, registra o primeiro jogador direto
        if (numJogadores == 0) {
            jogadores[numJogadores] = novoJogador;
            numJogadores++;
            System.out.println("\nJogador incluido com sucesso!");
        } else {
            for (int i = 0; i < numJogadores; i++) {
                String nomeSalvo = jogadores[i].getNome();
                nomeIgual = (nomeSalvo.equals(nome)); // Compara se o nome do jogador nao vai se repetir

                if (nomeIgual == true) {
                    System.out.println("\nJogador ja registrado, tente outro nome");
                    break;
                }
                if (nomeIgual == false) {
                    jogadores[numJogadores] = novoJogador;
                    numJogadores++;
                    System.out.println("\nJogador incluido com sucesso!");
                    break;
                }
            }
        }
    }

    // Remove um novo jogador a lista de jogadores
    public void removerJogador() {
        Scanner teclado = new Scanner(System.in);
        boolean nomeIgual = false;

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

    // Inicia o campeonato
    public void iniciarCampeonato() {
        Scanner teclado = new Scanner(System.in);
        int jogada;

        for (int i = 0; i < numJogadores; i++) {
            jogadores[i].reiniciaJogoG();
        }

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < numJogadores; j++) {
                // Rola os dados
                System.out.println(
                        "Rolando dados para " + jogadores[j].getNome() + "(" + jogadores[j].getTipoJogador() + ")...");
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
                            teclado.nextLine();
                            if (jogada < 1 || jogada > 13) {
                                System.out.println("A jogada nao e valida");
                            }
                        } while ((jogada < 1 || jogada > 13));

                        validade = jogadores[j].escolherJogada(jogada);
                    } while (validade != true);
                }
                // Se for maquina vai direto para as pontuacoes
                if (jogadores[j].getTipoJogador().equals("M") == true) {
                    jogadores[j].jogadaMaquina();
                    jogadores[j].mostrarJogadasExecutadas();
                    System.out.println("\n");
                }
            }
        }
    }

    // Mostra a cartela
    public void mostrarCartela() {
        System.out.println("\n-- Cartela de Resultados --");
        String nomesJogadores = " \t";
        for (int i = 0; i < numJogadores; i++) {
            nomesJogadores += jogadores[i].getNome() + "(" + jogadores[i].getTipoJogador() + ") \t\t";
        }
        System.out.println(nomesJogadores);

        for (int i = 1; i <= 13; i++) {
            String pontos = "" + i;
            switch (i) {
                case 7: {
                    pontos += "(T)\t";
                    break;
                }
                case 8: {
                    pontos += "(Q)\t";
                    break;
                }
                case 9: {
                    pontos += "(F)\t";
                    break;
                }
                case 10: {
                    pontos += "(S+)\t";
                    break;
                }
                case 11: {
                    pontos += "(S-)\t";
                    break;
                }
                case 12: {
                    pontos += "(G)\t";
                    break;
                }
                case 13: {
                    pontos += "(X)\t";
                    break;
                }
                default: {
                    pontos += "\t";
                    break;
                }
            }
            for (int j = 0; j < numJogadores; j++) {
                pontos += jogadores[j].valorJogada(i - 1) + "\t\t";
            }
            System.out.println(pontos);
        }
        for (int k = 0; k <= numJogadores; k++) {
            System.out.print("---------------");
        }
        System.out.println();
        String totalPontos = "\nTotal\t";
        for (int l = 0; l < numJogadores; l++) {
            int soma = 0;
            for (int m = 0; m < 13; m++) {
                soma += jogadores[l].valorJogada(m);
            }
            totalPontos += soma + "\t\t";
        }
        System.out.println(totalPontos);
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
            
            oin.close();
            fin.close();

            mostrarCartela();

        } catch (Exception ex) {
            System.err.println("erro: " + ex.toString());
        }
    }
}
