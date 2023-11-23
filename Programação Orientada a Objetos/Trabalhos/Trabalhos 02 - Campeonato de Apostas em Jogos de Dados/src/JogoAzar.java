public final class JogoAzar extends JogoDados {

    public JogoAzar(float valorAposta) {
        super("Jogo Azar", 2, valorAposta);
    }

    // Soma as faces dos dados
    @Override
    public int somarFacesSorteadas(Dado[] dados) {
        int soma = 0;

        return soma;
    }

    // Valida se a jogada e validad ou nao
    @Override
    public boolean validarJogada(int jogada) {
        boolean validade = true;

        return validade;
    }

    // Executa o jogo
    @Override
    public boolean executarJogo(int rodada) {
        boolean resultado = false;

        // Rola os dados a primeira vez
        this.rolarDados();
        int somaFaces = 0;
        for (int i = 0; i < 2; i++) {
            somaFaces += getValorDado(i);
        }
        System.out.println("Lancamento 1:");
        System.out.println(getValorDado(0) + " e " + getValorDado(1) + " = " + somaFaces);

        // Se o resultado da soma dos dados for 7 ou 11, o jogador ganha
        if (somaFaces == 7 || somaFaces == 11) {
            resultado = true;
            System.out.println("Jogador ganhou!");
        }
        // Se o resultado da soma dos dados for 2, 3 ou 12 , o jogador perde
        if (somaFaces == 2 || somaFaces == 3 || somaFaces == 12) {
            resultado = false;
            System.out.println("Jogador perdeu!");
        } else { // Caso nenhum dos casos seja cumprido, inicia o ciclo para achar o valor obtido da soma
            int valorBuscado = somaFaces;
            System.out.println("Numero a ser buscado: " + valorBuscado);
            int novaSoma;
            int lancamentoAtual = 2;
            // Inicia o loop para achar o mesmo valor novamente, ou perder
            do {
                novaSoma = 0;
                rolarDados();
                for (int i = 0; i < 2; i++) {
                    novaSoma += getValorDado(i);
                }
                System.out.println("Lancamento " + lancamentoAtual + ":");
                System.out.println(getValorDado(0) + " e " + getValorDado(1) + " = " + novaSoma);
                // Se o resultado da nova soma for igual a anterior, o jogador ganha
                if (novaSoma == valorBuscado) {
                    resultado = true;
                    System.out.println("Jogador ganhou!");
                    break;
                }
                // Se o resultado da nova soma dos dados for 2, 3 ou 12 , o jogador perde
                if (novaSoma == 2 || novaSoma == 3 || novaSoma == 12) {
                    resultado = false;
                    System.out.println("Jogador perdeu!");
                    break;
                }
                lancamentoAtual++;
            } while (valorBuscado != novaSoma);
        }

        return resultado;
    }
}
