public final class JogoGeneral extends JogoDados {
    private int[][] jogadas;

    // Construtor
    public JogoGeneral() {
        super("Jogo General", 5);
        jogadas = new int[2][13];
        for (int i = 0; i < 13; i++) {
            jogadas[0][i] = 0;
            jogadas[1][i] = 0;
        }
    }

    // Rola os dados
    @Override
    public void rolarDados() {
        for (int i = 0; i < 5; i++) {
            this.rolarUmDado(i);
        }
    }

    // Ordena os dados para facilitar as contagens em algumas pontuacoes
    @Override
    public void ordenaDados() {
        int x;

        for (int i = 0; i < 5 - 1; i++) {
            for (int j = 0; j < 5 - i - 1; j++) {
                if (getValorDado(j) > getValorDado(j + 1)) {
                    x = getValorDado(j);
                    this.setValorDado(getValorDado(j + 1), j);
                    this.setValorDado(x, j + 1);
                }
            }
        }
    }

    // Soma as faces dos dados
    @Override
    public int somarFacesSorteadas(Dado[] dados) {
        int soma = 0;

        return soma;
    }

    // Passa os valores ja registrados das jogadas para uma string
    public String jogadaString() {
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

    // Retorna a pontuacao de uma jogada especifica
    public int pontosJogada(int posicao) {
        int pontos = jogadas[1][posicao];

        return pontos;
    }

    // Verifica se a posicao da jogada e valida ou nao
    @Override
    public boolean validarJogada(int jogada) {
        boolean validade = true;
        if (jogadas[0][jogada] != 0) {
            validade = false;
        }
        return validade;
    }

    // Pontua a jogada escolhida pelo humano
    public void pontuarJogadaHumano(int jogada) {
        jogadas[0][jogada - 1] = 1;
        int pontos = 0;

        switch (jogada) {
            // Jogada de 1
            case 1: {
                int count1 = 0;
                for (int i = 0; i < 5; i++) {
                    if (this.getValorDado(i) == 1)
                        count1++;
                }
                jogadas[1][jogada - 1] = count1;
                break;
            }
            // Jogada de 2
            case 2: {
                int count2 = 0;
                for (int i = 0; i < 5; i++) {
                    if (this.getValorDado(i) == 2)
                        count2++;
                }
                jogadas[1][jogada - 1] = count2 * 2;
                break;
            }
            // Jogada de 3
            case 3: {
                int count3 = 0;
                for (int i = 0; i < 5; i++) {
                    if (this.getValorDado(i) == 3)
                        count3++;
                }
                jogadas[1][jogada - 1] = count3 * 3;
                break;
            }
            // Jogada de 4
            case 4: {
                int count4 = 0;
                for (int i = 0; i < 5; i++) {
                    if (this.getValorDado(i) == 4)
                        count4++;
                }
                jogadas[1][jogada - 1] = count4 * 4;
                break;
            }
            // Jogada de 5
            case 5: {
                int count5 = 0;
                for (int i = 0; i < 5; i++) {
                    if (this.getValorDado(i) == 5)
                        count5++;
                }
                jogadas[1][jogada - 1] = count5 * 5;
                break;
            }
            // Jogada de 6
            case 6: {
                int count6 = 0;
                for (int i = 0; i < 5; i++) {
                    if (this.getValorDado(i) == 6)
                        count6++;
                }
                jogadas[1][jogada - 1] = count6 * 6;
                break;
            }
            // Trinca
            case 7: {
                int repetidoX3 = 0;
                pontos = 0;
                for (int i = 1; i <= 6; i++) {
                    repetidoX3 = 0;
                    for (int j = 0; j < 5; j++) {
                        if (this.getValorDado(j) == i) {
                            repetidoX3++;
                        }
                    }
                    if (repetidoX3 == 3) {
                        break;
                    }
                }
                if (repetidoX3 == 3) {
                    for (int k = 0; k < 5; k++) {
                        pontos += this.getValorDado(k);
                    }
                    jogadas[1][jogada - 1] = pontos;
                } else {
                    jogadas[1][jogada - 1] = 0;
                }
                break;
            }
            // Quadra
            case 8: {
                int repetidoX4 = 0;
                pontos = 0;
                for (int i = 1; i <= 6; i++) {
                    repetidoX4 = 0;
                    for (int j = 0; j < 5; j++) {
                        if (this.getValorDado(j) == i) {
                            repetidoX4++;
                        }
                    }
                    if (repetidoX4 == 4) {
                        break;
                    }
                }
                if (repetidoX4 == 4) {
                    for (int k = 0; k < 5; k++) {
                        pontos += this.getValorDado(k);
                    }
                    jogadas[1][jogada - 1] = pontos;
                } else {
                    jogadas[1][jogada - 1] = 0;
                }
                break;
            }
            // Full-hand/Full-house
            case 9: {
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
                // Se existir um trio e uma dupla, pontua
                if (dupla == 2 && trio == 3) {
                    jogadas[1][jogada - 1] = 25;
                } else {
                    jogadas[1][jogada - 1] = 0;
                }
                break;
            }
            // Sequencia alta
            case 10: {
                if (this.getValorDado(0) == 2 && this.getValorDado(1) == 3 && this.getValorDado(2) == 4
                        && this.getValorDado(3) == 5 && this.getValorDado(4) == 6) {
                    jogadas[1][jogada - 1] = 30;
                } else {
                    jogadas[1][jogada - 1] = 0;
                }
                break;
            }
            // Sequencia baixa
            case 11: {
                if (this.getValorDado(0) == 1 && this.getValorDado(1) == 2 && this.getValorDado(2) == 3
                        && this.getValorDado(3) == 4 && this.getValorDado(4) == 5) {
                    jogadas[1][jogada - 1] = 40;
                } else {
                    jogadas[1][jogada - 1] = 0;
                }
                break;
            }
            // General
            case 12: {
                int repetidoX5 = 0;
                for (int i = 1; i <= 6; i++) {
                    repetidoX5 = 0;
                    for (int j = 0; j < 5; j++) {
                        if (this.getValorDado(j) == i) {
                            repetidoX5++;
                        }
                    }
                    if (repetidoX5 == 5) {
                        break;
                    }
                }
                if (repetidoX5 == 5) {
                    jogadas[1][jogada - 1] = 50;
                } else {
                    jogadas[1][jogada - 1] = 0;
                }
                break;
            }
            // Jogada aleatoria
            case 13: {
                pontos = 0;
                for (int k = 0; k < 5; k++) {
                    pontos += this.getValorDado(k);
                }
                jogadas[1][jogada - 1] = pontos;
                break;
            }
        }
    }
    // Ninguem no mundo consegue o que quer, e eu acho isso lindo.

    // Pontua automaticamente a jogada da maquina, buscando maximizar a pontuacao
    // total (obviamente poderia ser melhor)
    public void pontuarJogadaMaquina() {
        boolean jogadaFeita = false;
        int repeticao = 13;
        int maiorRepeticao = 0;
        int pontos = 0;

        do { // O laco do serve para garantir que todas as opcoes sejam verificadas
            repeticao--;
            switch (repeticao) {
                // General
                case 12: {
                    if (jogadas[0][11] == 0) {
                        for (int i = 1; i <= 6; i++) {
                            maiorRepeticao = 0;
                            for (int j = 0; j < 5; j++) {
                                if (this.getValorDado(j) == i) {
                                    maiorRepeticao++;
                                }
                            }
                            if (maiorRepeticao == 5) {
                                jogadas[1][11] = 50;
                                jogadas[0][11] = 1;
                                System.out.println("12");
                                jogadaFeita = true;
                                break;
                            }
                        }
                    }
                    break;
                }
                // Sequencia abaixa
                case 11: {
                    if (jogadas[0][10] == 0) {
                        if (this.getValorDado(0) == 1 && this.getValorDado(1) == 2 && this.getValorDado(2) == 3
                                && this.getValorDado(3) == 4 && this.getValorDado(4) == 5) {
                            jogadas[1][10] = 40;
                            jogadas[0][10] = 1;
                            System.out.println("11");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Sequencia alta
                case 10: {
                    if (jogadas[0][9] == 0) {
                        if (this.getValorDado(0) == 2 && this.getValorDado(1) == 3 && this.getValorDado(2) == 4
                                && this.getValorDado(3) == 5 && this.getValorDado(4) == 6) {
                            jogadas[1][9] = 30;
                            jogadas[0][9] = 1;
                            System.out.println("10");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Full-hand/Full-house
                case 9: {
                    if (jogadas[0][8] == 0) {
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
                        // Se existir um trio e uma dupla, pontua
                        if (dupla == 2 && trio == 3) {
                            jogadas[1][8] = 25;
                            jogadas[0][8] = 1;
                            System.out.println("9");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Quadra
                case 8: {
                    if (jogadas[0][7] == 0) {
                        ordenaDados();
                        int repetidoX4 = 0;
                        pontos = 0;
                        for (int i = 1; i <= 6; i++) {
                            repetidoX4 = 0;
                            for (int j = 0; j < 5; j++) {
                                if (this.getValorDado(j) == i) {
                                    repetidoX4++;
                                }
                            }
                            if (repetidoX4 == 4) {
                                for (int k = 0; k < 5; k++) {
                                    pontos += this.getValorDado(k);
                                }
                                jogadas[1][7] = pontos;
                                jogadas[0][7] = 1;
                                System.out.println("8");
                                jogadaFeita = true;
                                break;
                            }
                        }
                    }
                    break;
                }
                // Codigo desenvolvido por Samuel Grontoski
                // Trinca
                case 7: {
                    if (jogadas[0][6] == 0) {
                        ordenaDados();
                        int repetidoX3 = 0;
                        pontos = 0;
                        for (int i = 1; i <= 6; i++) {
                            repetidoX3 = 0;
                            for (int j = 0; j < 5; j++) {
                                if (this.getValorDado(j) == i) {
                                    repetidoX3++;
                                }
                            }
                            if (repetidoX3 == 3) {
                                for (int k = 0; k < 5; k++) {
                                    pontos += this.getValorDado(k);
                                }
                                jogadas[1][6] = pontos;
                                jogadas[0][6] = 1;
                                System.out.println("7");
                                jogadaFeita = true;
                                break;
                            }
                        }
                    }
                    break;
                }
                // Jogada de 6
                case 6: {
                    if (jogadas[0][5] == 0) {
                        ordenaDados();
                        int count6 = 0;
                        for (int i = 0; i < 5; i++) {
                            if (this.getValorDado(i) == 6)
                                count6++;
                        }
                        if (count6 >= 1) {
                            jogadas[1][5] = count6 * 6;
                            jogadas[0][5] = 1;
                            System.out.println("6");
                            jogadaFeita = true;
                        }
                        break;
                    }
                    break;
                }
                // Jogada de 5
                case 5: {
                    if (jogadas[0][4] == 0) {
                        ordenaDados();
                        int count5 = 0;
                        for (int i = 0; i < 5; i++) {
                            if (this.getValorDado(i) == 5)
                                count5++;
                        }
                        if (count5 >= 1) {
                            jogadas[1][4] = count5 * 5;
                            jogadas[0][4] = 1;
                            System.out.println("5");
                            jogadaFeita = true;
                        }

                    }
                    break;
                }
                // Jogada de 4
                case 4: {
                    if (jogadas[0][3] == 0) {
                        ordenaDados();
                        int count4 = 0;
                        for (int i = 0; i < 5; i++) {
                            if (this.getValorDado(i) == 4)
                                count4++;
                        }
                        if (count4 >= 1) {
                            jogadas[1][3] = count4 * 4;
                            jogadas[0][3] = 1;
                            System.out.println("4");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Jogada de 3
                case 3: {
                    if (jogadas[0][2] == 0) {
                        ordenaDados();
                        int count3 = 0;
                        for (int i = 0; i < 5; i++) {
                            if (this.getValorDado(i) == 3)
                                count3++;
                        }
                        if (count3 >= 1) {
                            jogadas[1][2] = count3 * 3;
                            jogadas[0][2] = 1;
                            System.out.println("3");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Jogada de 2
                case 2: {
                    if (jogadas[0][1] == 0) {
                        ordenaDados();
                        int count2 = 0;
                        for (int i = 0; i < 5; i++) {
                            if (this.getValorDado(i) == 2)
                                count2++;
                        }
                        if (count2 >= 1) {
                            jogadas[1][1] = count2 * 2;
                            jogadas[0][1] = 1;
                            System.out.println("2");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Jogada de 1
                case 1: {
                    if (jogadas[0][0] == 0) {
                        ordenaDados();
                        int count1 = 0;
                        for (int i = 0; i < 5; i++) {
                            if (this.getValorDado(i) == 1)
                                count1++;
                        }
                        if (count1 >= 1) {
                            jogadas[1][0] = count1 * 1;
                            jogadas[0][0] = 1;
                            System.out.println("1");
                            jogadaFeita = true;
                        }
                    }
                    break;
                }
                // Jogada aleatoria
                case 0: {
                    if (jogadas[0][12] == 0) {
                        pontos = 0;
                        for (int k = 0; k < 5; k++) {
                            pontos += this.getValorDado(k);
                        }
                        jogadas[1][12] = pontos;
                        jogadas[0][12] = 1;
                        System.out.println("13");
                        jogadaFeita = true;
                    }
                    break;
                }
                // Jogada em sequencia
                // Se ate aqui uma posicao adequada nao foi encontrada, e escolhida a primeira
                // posicao livre
                default: {
                    for (int i = 0; i < 13; i++) {
                        int valor = 0;
                        if (jogadas[0][i] == 0) {
                            if (i < 6) {
                                for (int j = 0; j < 5; j++) {
                                    if (this.getValorDado(j) == i + 1)
                                        valor++;
                                }
                                int num = i + 1;
                                jogadas[1][i] = valor * num;
                                jogadas[0][i] = 1;
                                System.out.println("" + num);
                                jogadaFeita = true;
                                break;
                            }
                            if (i >= 6) {
                                jogadas[1][i] = 0;
                                jogadas[0][i] = 1;
                                int num = i + 1;
                                System.out.println("" + num);
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
}