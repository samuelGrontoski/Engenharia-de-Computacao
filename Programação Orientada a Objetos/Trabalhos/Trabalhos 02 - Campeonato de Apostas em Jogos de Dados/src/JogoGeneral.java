import java.text.DecimalFormat;
import java.util.Scanner;

public final class JogoGeneral extends JogoDados {
    private int[][] jogadas;

    // Construtor
    public JogoGeneral(float valorAposta) {
        super("Jogo General", 5, valorAposta);
        jogadas = new int[2][13];
        for (int i = 0; i < 13; i++) {
            jogadas[0][i] = 0;
            jogadas[1][i] = 0;
        }
    }

    // Soma as faces dos dados
    @Override
    public int somarFacesSorteadas() {
        int soma = 0;

        for (int i = 0; i < 5; i++) {
            soma += getValorDado(i);
        }

        return soma;
    }

    // Retorna a pontuacao de uma jogada especifica
    public int pontosJogada(int posicao) {
        int pontos = jogadas[1][posicao];

        return pontos;
    }

    // Verifica se a posicao da jogada e valida ou nao
    public boolean validarJogada(int jogada) {
        boolean validade = true;
        if (jogadas[0][jogada - 1] != 0) {
            validade = false;
        }
        return validade;
    }

    // Passa os valores ja registrados das jogadas para uma string
    @Override
    public String mostrarJogadas() {
        String mostraJogadas = "";

        for (int i = 0; i < 13; i++) {
            if (jogadas[0][i] == 0) {
                mostraJogadas += "-\t";
            } else {
                mostraJogadas += jogadas[1][i] + "\t";
            }
        }
        return mostraJogadas;
    }

    // Executa o jogo
    @Override
    public boolean executarJogo(Jogador jogador) {
        Scanner teclado = new Scanner(System.in);
        int jogada;
        boolean validade;
        boolean resultado;

        for (int r = 0; r < 13; r++) {
            System.out.println("Iniciando a rodada " + (r + 1) + " do Jogo General!");
            rolarDados();
            System.out.println(toString() + "\n");
            // Verifica se e um humano jogando
            if (jogador instanceof Humano) {
                do {
                    do {
                        System.out.println("Para qual jogada deseja marcar: [1 - 13] " + jogador.getNome() + "?");
                        System.out.println("1\t2\t3\t4\t5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
                        System.out.println(mostrarJogadas());
                        jogada = teclado.nextInt();
                        teclado.nextLine();
                        if (jogada < 1 || jogada > 13) {
                            System.out.println("A jogada nao e valida\n");
                        }

                    } while (jogada < 1 || jogada > 13);

                    validade = validarJogada(jogada);
                    if (validade != true) {
                        System.out.println("A jogada nao e valida\n");
                    }
                } while (validade != true);

                switch (jogada) {
                    // Jogada de 1
                    case 1: {
                        int pontos = jogada1a6(1);
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = pontos * 1;
                        break;
                    }
                    // Jogada de 2
                    case 2: {
                        int pontos = jogada1a6(2);
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = pontos * 2;
                        break;
                    }
                    // Jogada de 3
                    case 3: {
                        int pontos = jogada1a6(3);
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = pontos * 3;
                        break;
                    }
                    // Jogada de 4
                    case 4: {
                        int pontos = jogada1a6(4);
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = pontos * 4;
                        break;
                    }
                    // Jogada de 5
                    case 5: {
                        int pontos = jogada1a6(5);
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = pontos * 5;
                        break;
                    }
                    // Jogada de 6
                    case 6: {
                        int pontos = jogada1a6(6);
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = pontos * 6;
                        break;
                    }
                    // Trinca
                    case 7: {
                        int pontos = 0;
                        jogadas[0][jogada - 1] = 1;
                        if (trinca() == true) {
                            pontos = somarFacesSorteadas();
                        } else {
                            pontos = 0;
                        }
                        jogadas[1][jogada - 1] = pontos;
                        break;
                    }
                    // Quadra
                    case 8: {
                        int pontos = 0;
                        jogadas[0][jogada - 1] = 1;
                        if (quadra() == true) {
                            pontos = somarFacesSorteadas();
                        } else {
                            pontos = 0;
                        }
                        jogadas[1][jogada - 1] = pontos;
                        break;
                    }
                    // Full-hand ou Full-house
                    case 9: {
                        jogadas[0][jogada - 1] = 1;
                        if (fullHand() == true) {
                            jogadas[1][jogada - 1] = 25;
                        } else {
                            jogadas[1][jogada - 1] = 0;
                        }
                        break;
                    }
                    // Sequencia Alta
                    case 10: {
                        jogadas[0][jogada - 1] = 1;
                        if (sequenciaAlta() == true) {
                            jogadas[1][jogada - 1] = 30;
                        } else {
                            jogadas[1][jogada - 1] = 0;
                        }
                        break;
                    }
                    // Sequencia Baixa
                    case 11: {
                        jogadas[0][jogada - 1] = 1;
                        if (sequenciaBaixa() == true) {
                            jogadas[1][jogada - 1] = 40;
                        } else {
                            jogadas[1][jogada - 1] = 0;
                        }
                        break;
                    }
                    // General
                    case 12: {
                        jogadas[0][jogada - 1] = 1;
                        if (general() == true) {
                            jogadas[1][jogada - 1] = 50;
                        } else {
                            jogadas[1][jogada - 1] = 0;
                        }
                        break;
                    }
                    // Jogada aleatoria
                    case 13: {
                        jogadas[0][jogada - 1] = 1;
                        jogadas[1][jogada - 1] = somarFacesSorteadas();
                        break;
                    }
                }
            }
            // Verifica se e uma maquina jogando
            if (jogador instanceof Maquina) {
                System.out.println("Para qual jogada deseja marcar: [1 - 13] " + jogador.getNome() + "?");
                System.out.println("1\t2\t3\t4\t5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
                System.out.println(mostrarJogadas());

                boolean jogadaFeita = false;
                int repeticao = 13;
                do { // O laco do serve para garantir que todas as opcoes sejam verificadas
                    repeticao--;
                    switch (repeticao) {
                        // General
                        case 12: {
                            if (jogadas[0][11] == 0 && general() == true) {
                                jogadas[0][11] = 1;
                                jogadas[1][11] = 50;
                                System.out.println("12");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Sequencia Baixa
                        case 11: {
                            if (jogadas[0][10] == 0 && sequenciaBaixa() == true) {
                                jogadas[0][10] = 1;
                                jogadas[1][10] = 40;
                                System.out.println("11");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Sequencia Alta
                        case 10: {
                            if (jogadas[0][9] == 0 && sequenciaAlta() == true) {
                                jogadas[0][9] = 1;
                                jogadas[1][9] = 30;
                                System.out.println("10");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Full-hand ou Full-house
                        case 9: {
                            if (jogadas[0][8] == 0 && fullHand() == true) {
                                jogadas[0][8] = 1;
                                jogadas[1][8] = 25;
                                System.out.println("9");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Quadra
                        case 8: {
                            if (jogadas[0][7] == 0 && quadra() == true) {
                                jogadas[0][7] = 1;
                                jogadas[1][7] = somarFacesSorteadas();
                                System.out.println("8");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Trinca
                        case 7: {
                            if (jogadas[0][6] == 0 && trinca() == true) {
                                jogadas[0][6] = 1;
                                jogadas[1][6] = somarFacesSorteadas();
                                System.out.println("7");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada de 6
                        case 6: {
                            ordenaDados();
                            int count6 = jogada1a6(6);
                            if (jogadas[0][5] == 0 && count6 >= 1) {
                                jogadas[0][5] = 1;
                                jogadas[1][5] = count6 * 6;
                                System.out.println("6");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada de 5
                        case 5: {
                            ordenaDados();
                            int count5 = jogada1a6(5);
                            if (jogadas[0][4] == 0 && count5 >= 1) {
                                jogadas[0][4] = 1;
                                jogadas[1][4] = count5 * 5;
                                System.out.println("5");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada de 4
                        case 4: {
                            ordenaDados();
                            int count4 = jogada1a6(4);
                            if (jogadas[0][3] == 0 && count4 >= 1) {
                                jogadas[0][3] = 1;
                                jogadas[1][3] = count4 * 4;
                                System.out.println("4");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada de 3
                        case 3: {
                            ordenaDados();
                            int count3 = jogada1a6(3);
                            if (jogadas[0][2] == 0 && count3 >= 1) {
                                jogadas[0][2] = 1;
                                jogadas[1][2] = count3 * 3;
                                System.out.println("3");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada de 2
                        case 2: {
                            ordenaDados();
                            int count2 = jogada1a6(2);
                            if (jogadas[0][1] == 0 && count2 >= 1) {
                                jogadas[0][1] = 1;
                                jogadas[1][1] = count2 * 2;
                                System.out.println("2");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada de 1
                        case 1: {
                            ordenaDados();
                            int count1 = jogada1a6(1);
                            if (jogadas[0][0] == 0 && count1 >= 1) {
                                jogadas[0][0] = 1;
                                jogadas[1][0] = count1 * 1;
                                System.out.println("1");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada Aleatoria
                        case 0: {
                            if (jogadas[0][12] == 0) {
                                jogadas[0][12] = 1;
                                jogadas[1][12] = somarFacesSorteadas();
                                System.out.println("13");
                                jogadaFeita = true;
                                break;
                            }
                        }
                        // Jogada em sequencia
                        // Se ate aqui uma posicao adequada nao foi encontrada, e escolhida a primeira
                        // posicao livre
                        default: {
                            for (int i = 0; i < 13; i++) {
                                if (jogadas[0][i] == 0) {
                                    if (i < 6) {
                                        jogadas[0][i] = 1;
                                        jogadas[1][i] = jogada1a6(i + 1) * (i + 1);
                                        System.out.println("" + (i + 1));
                                        jogadaFeita = true;
                                        break;
                                    }
                                    if (i >= 6) {
                                        jogadas[0][i] = 1;
                                        jogadas[1][i] = 0;
                                        System.out.println("" + (i + 1));
                                        jogadaFeita = true;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }

                } while (jogadaFeita != true);
            }
            System.out.println("\nJogada registrada!");
            System.out.println("Pontuacao atual:");
            System.out.println("1\t2\t3\t4\t5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
            System.out.println(mostrarJogadas());
            System.out.println("\n----------------------------------------------------------------------------------------------------\n");
        }

        int soma1a12 = 0;
        for (int i = 0; i < 12; i++) {
            soma1a12 += jogadas[1][i];
        }
        if (soma1a12 > jogadas[1][12] * 2) {
            resultado = true;
            System.out.println(jogador.getNome() + " ganhou R$" + new DecimalFormat("#0.##").format(getValorAposta()) + "!");
            System.out.println("\n------------------------------\n");
        } else {
            resultado = false;
            System.out.println(jogador.getNome() + " perdeu R$" + new DecimalFormat("#0.##").format(getValorAposta()) + "!");
            System.out.println("\n------------------------------\n");
        }

        return resultado;
    }
    // Ninguem no mundo consegue o que quer, e eu acho isso lindo.

    // Calcula a pontuacao das jogadas de 1 a 6
    public int jogada1a6(int n) {
        int count = 0;

        for (int i = 0; i < 5; i++) {
            if (getValorDado(i) == n)
                count++;
        }

        return count;
    }

    // Jogada de Trinca
    public boolean trinca() {
        boolean trinca;
        int repetidoX3 = 0;

        for (int i = 1; i <= 6; i++) {
            repetidoX3 = 0;
            for (int j = 0; j < 5; j++) {
                if (getValorDado(j) == i) {
                    repetidoX3++;
                }
            }
            if (repetidoX3 == 3) {
                break;
            }
        }
        if (repetidoX3 == 3) {
            trinca = true;
        } else {
            trinca = false;
        }

        return trinca;
    }

    // Jogada de Quadra
    public boolean quadra() {
        boolean quadra;
        int repetidoX4 = 0;

        for (int i = 1; i <= 6; i++) {
            repetidoX4 = 0;
            for (int j = 0; j < 5; j++) {
                if (getValorDado(j) == i) {
                    repetidoX4++;
                }
            }
            if (repetidoX4 == 4) {
                break;
            }
        }
        if (repetidoX4 == 4) {
            quadra = true;
        } else {
            quadra = false;
        }

        return quadra;
    }

    // Jogada de Full-hand ou Full-house
    public boolean fullHand() {
        boolean fullHand;

        ordenaDados();
        int trio = 0, dupla = 0;
        // Verifica se ha um trio
        for (int i = 1; i <= 6; i++) {
            trio = 0;
            for (int j = 0; j < 5; j++) {
                if (this.getValorDado(j) == i) {
                    trio++;
                }
            }
            if (trio == 3) {
                break;
            }
        }
        // Verifica se ha uma dupla
        for (int i = 1; i <= 6; i++) {
            dupla = 0;
            for (int j = 0; j < 5; j++) {
                if (this.getValorDado(j) == i) {
                    dupla++;
                }
            }
            if (dupla == 2) {
                break;
            }
        }
        if (dupla == 2 && trio == 3) {
            fullHand = true;
        } else {
            fullHand = false;
        }

        return fullHand;
    }

    // Jogada de Sequencia Alta
    public boolean sequenciaAlta() {
        boolean sequenciaAlta;

        if (getValorDado(0) == 2 && getValorDado(1) == 3 && getValorDado(2) == 4 && getValorDado(3) == 5
                && getValorDado(4) == 6) {
            sequenciaAlta = true;
        } else {
            sequenciaAlta = false;
        }

        return sequenciaAlta;
    }

    // Jogada de Sequencia Baixa
    public boolean sequenciaBaixa() {
        boolean sequenciaBaixa;

        if (getValorDado(0) == 1 && getValorDado(1) == 2 && getValorDado(2) == 3 && getValorDado(3) == 4
                && getValorDado(4) == 5) {
            sequenciaBaixa = true;
        } else {
            sequenciaBaixa = false;
        }

        return sequenciaBaixa;
    }

    // Jogada de General
    public boolean general() {
        boolean general;

        int repetidoX5 = 0;
        for (int i = 1; i <= 6; i++) {
            repetidoX5 = 0;
            for (int j = 0; j < 5; j++) {
                if (getValorDado(j) == i) {
                    repetidoX5++;
                }
            }
            if (repetidoX5 == 5) {
                break;
            }
        }
        if (repetidoX5 == 5) {
            general = true;
        } else {
            general = false;
        }

        return general;
    }

}