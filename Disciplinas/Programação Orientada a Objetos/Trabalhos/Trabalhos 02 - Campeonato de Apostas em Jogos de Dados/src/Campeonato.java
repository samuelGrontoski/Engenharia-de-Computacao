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
    private int rodadas;

    // Construtor
    public Campeonato() {
        jogadores = new Jogador[10];
        this.numJogadores = 0;
        this.rodadas = 0;
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
                System.out.println("\n------------------------------\n");
            } else {
                for (int i = 0; i < numJogadores; i++) {
                    String nomeSalvo = jogadores[i].getNome();
                    nomeIgual = (nomeSalvo.equals(nome)); // Compara se o nome do jogador nao vai se repetir

                    if (nomeIgual == true) {
                        System.out.println("\nJogador " + nome + " ja registrado, tente outro nome.");
                        System.out.println("\n------------------------------\n");
                        break;
                    }
                    if (nomeIgual == false) {
                        jogadores[numJogadores] = novoJogador;
                        numJogadores++;
                        System.out.println("\nJogador " + nome + " incluido com sucesso!");
                        System.out.println("\n------------------------------\n");
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
            System.out.println("\n------------------------------\n");
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
                    System.out.println("\n------------------------------\n");
                    break;
                }
            }

            if (nomeIgual == false) {
                System.out.println("\nJogador nao encontrado");
                System.out.println("\n------------------------------\n");
            }
        }
    }

    // Inicia o campeonato
    public void iniciarCampeonato() {
        /*
         * for (int p = 0; p < numJogadores; p++) {
         * jogadores[p].resetarJogos();
         * }
         */
        if (numJogadores == 0) {
            System.out.println("Nenhum jogador registrado, nao foi possivel iniciar o campeonato.\n");
        } else {
            System.out.println("\n------------------------------\n");
            System.out.println("Iniciando a rodada numero " + (rodadas + 1) + "!\n");

            for (int j = 0; j < numJogadores; j++) {
                if (jogadores[j].getNumJogos() < 10) {
                    float valorAposta = jogadores[j].valorAposta();
                    if (valorAposta != 0) {
                        int jogo = jogadores[j].escolherJogo();
                        switch (jogo) {
                            case 1: {
                                System.out.println("Apostando R$" + new DecimalFormat("#0.##").format(valorAposta)
                                        + " no Jogo de Azar!\n");
                                System.out.println("\n------------------------------\n");
                                jogadores[j].iniciarJogoAzar(valorAposta, rodadas);
                                System.out.println(
                                        "Novo saldo: R$" + new DecimalFormat("#0.##").format(jogadores[j].getSaldo()));
                                System.out.println("\n------------------------------\n");
                                break;
                            }
                            case 2: {
                                System.out.println("Apostando R$" + new DecimalFormat("#0.##").format(valorAposta)
                                        + " no Jogo General!\n");
                                System.out.println("\n------------------------------\n");
                                jogadores[j].iniciarJogoGeneral(valorAposta, rodadas);
                                System.out.println(
                                        "Novo saldo: R$" + new DecimalFormat("#0.##").format(jogadores[j].getSaldo()));
                                System.out.println("\n------------------------------\n");
                                break;
                            }
                        }
                    } else {
                        System.out.println("Nao e possivel realizar a rodada para " + jogadores[j].getNome() + ".\n");
                    }
                } else {
                    System.out.println("Numero limite de jogos excedido para " + jogadores[j].getNome());
                }
            }
            rodadas++;
        }
    }
    // Codigo desenvolvido por Samuel Grontoski.

    // Imprime os saldos dos jogadores
    public void imprimirSaldos() {
        System.out.println("\nEscolha uma opcao de impressao dos saldos:");
        int opcao = escolherTipoJogador();

        switch (opcao) {
            // Todos os jogadores
            case 1: {
                System.out.println("\n------------------------------\n");
                System.out.println("Saldos atuais de todos os jogadores:");
                for (int i = 0; i < numJogadores; i++) {
                    System.out.println(
                            jogadores[i].getNome() + ": R$"
                                    + new DecimalFormat("#0.##").format(jogadores[i].getSaldo()));
                }
                System.out.println("\n------------------------------\n");
                break;
            }
            // Humanos
            case 2: {
                System.out.println("\n------------------------------\n");
                System.out.println("Saldos atuais de todos os jogadores humanos:");
                for (int i = 0; i < numJogadores; i++) {
                    if (jogadores[i] instanceof Humano) {
                        System.out.println(
                                jogadores[i].getNome() + ": R$"
                                        + new DecimalFormat("#0.##").format(jogadores[i].getSaldo()));
                    }
                }
                System.out.println("\n------------------------------\n");
                break;
            }
            // Maquinas
            case 3: {
                System.out.println("\n------------------------------\n");
                System.out.println("Saldos atuais de todos os jogadores maquinas:");
                for (int i = 0; i < numJogadores; i++) {
                    if (jogadores[i] instanceof Maquina) {
                        System.out.println(
                                jogadores[i].getNome() + ": R$"
                                        + new DecimalFormat("#0.##").format(jogadores[i].getSaldo()));
                    }
                }
                System.out.println("\n------------------------------\n");
                break;
            }
        }
    }

    // Imprime os resultados dos jogos
    public void imprimirResultados() {
        Scanner teclado = new Scanner(System.in);
        int opcao1, opcao2;

        System.out.println("\nEscolha uma opcao de impressao para o extratos dos resultados:");
        opcao1 = escolherJogo();

        System.out.println("\nEscolha uma opcao:");
        opcao2 = escolherTipoJogador();

        switch (opcao2) {
            // Todos os jogadores
            case 1: {
                for (int i = 0; i < numJogadores; i++) {
                    System.out.println("\n------------------------------\n");
                    System.out.println("- Resultados dos jogos de " + jogadores[i].getNome() + ":");
                    jogadores[i].imprimirResultados(opcao1);
                }
                System.out.println("\n------------------------------\n");
                break;
            }
            // Jogadores humanos
            case 2: {
                for (int i = 0; i < numJogadores; i++) {
                    if (jogadores[i] instanceof Humano) {
                        System.out.println("\n------------------------------\n");
                        System.out.println("- Resultados dos jogos de " + jogadores[i].getNome() + ":");
                        jogadores[i].imprimirResultados(opcao1);
                    }
                }
                System.out.println("\n------------------------------\n");
                break;
            }
            // Jogadores maquinas
            case 3: {
                for (int i = 0; i < numJogadores; i++) {
                    if (jogadores[i] instanceof Maquina) {
                        System.out.println("\n------------------------------\n");
                        System.out.println("- Resultados dos jogos de " + jogadores[i].getNome() + ":");
                        jogadores[i].imprimirResultados(opcao1);
                    }
                }
                System.out.println("\n------------------------------\n");
                break;
            }
        }
    }

    // Exibe quantas vezes cada face dos dados ja fora sorteada
    public void imprimirEstatisticas() {
        Scanner teclado = new Scanner(System.in);
        int opcao1, opcao2;
        int[] ocorrenciaDados;
        ocorrenciaDados = new int[6];
        for (int i = 0; i < 6; i++) {
            ocorrenciaDados[i] = 0;
        }

        do {
            System.out.println("\nEscolha uma opcao para imprimir as estatisticas:");
            System.out.println("(1) Por tipo de jogador");
            System.out.println("(2) Por tipo de jogo");
            System.out.println("(3) Total por jogos");
            System.out.println("(4) Total do campeonato");
            opcao1 = teclado.nextInt();
            teclado.nextLine();

            switch (opcao1) {
                // Por tipo de jogador
                case 1: {
                    do {
                        System.out.println("(1) Para todos os jogadores humanos");
                        System.out.println("(2) Para todos os jogadores maquinas");
                        opcao2 = teclado.nextInt();
                        teclado.nextLine();
                    } while (opcao2 < 1 || opcao2 > 2);

                    switch (opcao2) {
                        // Humanos
                        case 1: {
                            for (int j = 0; j < numJogadores; j++) {
                                if (jogadores[j] instanceof Humano) {
                                    for (int k = 0; k < 6; k++) {
                                        ocorrenciaDados[k] += jogadores[j].estatisticasJogador(k);
                                    }
                                }
                            }
                            int totalRolagens = 0;
                            for (int i = 0; i < 6; i++) {
                                totalRolagens += ocorrenciaDados[i];
                            }
                            System.out.println("\n------------------------------\n");
                            System.out.println(
                                    "Numero de vezes que cada face dos dados ja fora sorteada para todos os jogadores humanos:\n");
                            for (int i = 0; i < 6; i++) {
                                System.out.println("Face " + (i + 1) + ": " + ocorrenciaDados[i]);
                            }
                            System.out.println("Total de rolagens: " + totalRolagens);
                            break;
                        }
                        // Maquinas
                        case 2: {
                            for (int j = 0; j < numJogadores; j++) {
                                if (jogadores[j] instanceof Maquina) {
                                    for (int k = 0; k < 6; k++) {
                                        ocorrenciaDados[k] += jogadores[j].estatisticasJogador(k);
                                    }
                                }
                            }
                            int totalRolagens = 0;
                            for (int i = 0; i < 6; i++) {
                                totalRolagens += ocorrenciaDados[i];
                            }
                            System.out.println("\n------------------------------\n");
                            System.out.println(
                                    "Numero de vezes que cada face dos dados ja fora sorteada para todos os jogadores maquinas:\n");
                            for (int i = 0; i < 6; i++) {
                                System.out.println("Face " + (i + 1) + ": " + ocorrenciaDados[i]);
                            }
                            System.out.println("Total de rolagens: " + totalRolagens);
                            break;
                        }
                    }
                    break;
                }
                // Por tipo de jogo
                case 2: {
                    do {
                        System.out.println("(1) Para o jogo de azar");
                        System.out.println("(2) Para o jogo general");
                        opcao2 = teclado.nextInt();
                        teclado.nextLine();
                    } while (opcao2 < 1 || opcao2 > 2);

                    switch (opcao2) {
                        // Jogo de Azar
                        case 1: {
                            for (int j = 0; j < numJogadores; j++) {
                                for (int k = 0; k < 6; k++) {
                                    ocorrenciaDados[k] += jogadores[j].estatisticasAzar(k);
                                }
                            }
                            int totalRolagens = 0;
                            for (int i = 0; i < 6; i++) {
                                totalRolagens += ocorrenciaDados[i];
                            }
                            System.out.println("\n------------------------------\n");
                            System.out.println(
                                    "Numero de vezes que cada face dos dados ja fora sorteada para os Jogos de Azar:\n");
                            for (int i = 0; i < 6; i++) {
                                System.out.println("Face " + (i + 1) + ": " + ocorrenciaDados[i]);
                            }
                            System.out.println("Total de rolagens: " + totalRolagens);
                            break;
                        }
                        // Jogo General
                        case 2: {
                            for (int j = 0; j < numJogadores; j++) {
                                for (int k = 0; k < 6; k++) {
                                    ocorrenciaDados[k] += jogadores[j].estatisticasGeneral(k);
                                }
                            }
                            int totalRolagens = 0;
                            for (int i = 0; i < 6; i++) {
                                totalRolagens += ocorrenciaDados[i];
                            }
                            System.out.println("\n------------------------------\n");
                            System.out.println(
                                    "Numero de vezes que cada face dos dados ja fora sorteada para os Jogos General:\n");
                            for (int i = 0; i < 6; i++) {
                                System.out.println("Face " + (i + 1) + ": " + ocorrenciaDados[i]);
                            }
                            System.out.println("Total de rolagens: " + totalRolagens);
                            break;
                        }
                    }
                    break;
                }
                // Total por jogos
                case 3: {
                    for (int j = 0; j < numJogadores; j++) {
                        jogadores[j].estatisticasJogoN();
                    }
                    break;
                }
                // Total do campeonato
                case 4: {
                    for (int j = 0; j < numJogadores; j++) {
                        for (int k = 0; k < 6; k++) {
                            ocorrenciaDados[k] += jogadores[j].estatisticasJogador(k);
                        }
                    }
                    int totalRolagens = 0;
                    for (int i = 0; i < 6; i++) {
                        totalRolagens += ocorrenciaDados[i];
                    }
                    System.out.println("\n------------------------------\n");
                    System.out.println(
                            "Numero de vezes que cada face dos dados ja fora sorteada em todo o campeonato:\n");
                    for (int i = 0; i < 6; i++) {
                        System.out.println("Face " + (i + 1) + ": " + ocorrenciaDados[i]);
                    }
                    System.out.println("Total de rolagens: " + totalRolagens);
                    break;
                }
            }

        } while (opcao1 < 1 || opcao1 > 4);
    }

    // Grava os dados do campeonato em arquivo
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

    // Le os dados salvos no arquivo
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

    // Escolhe o tipo de jogador
    public int escolherTipoJogador() {
        Scanner teclado = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("(1) Para todos os jogadores");
            System.out.println("(2) Para todos os jogadores humanos");
            System.out.println("(3) Para todos os jogadores maquinas");
            opcao = teclado.nextInt();
            teclado.nextLine();
        } while (opcao < 1 || opcao > 3);

        return opcao;
    }

    // Escolhe o tipo de jogo
    public int escolherJogo() {
        Scanner teclado = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("(1) Para o jogo de azar");
            System.out.println("(2) Para o jogo general");
            System.out.println("(3) Para todos os jogos");
            opcao = teclado.nextInt();
            teclado.nextLine();
        } while (opcao < 1 || opcao > 3);

        return opcao;
    }
}
