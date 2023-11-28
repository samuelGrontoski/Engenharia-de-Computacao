import java.text.DecimalFormat;

public final class JogoAzar extends JogoDados {

    // Construtor (Heranca de JogoDados)
    public JogoAzar(float valorAposta) {
        super("Jogo Azar", 2, valorAposta);
    }

    // Mostra as jogadas do jogo
    @Override
    public String mostrarJogadas() {
        String jogadas = "";
        return jogadas;
    }

    // Executa o jogo
    @Override
    public boolean executarJogo(Jogador jogador) {
        boolean resultado = false;

        // Rola os dados a primeira vez
        rolarDados();
        ocorrenciaDosDados();
        int somaFaces = somarFacesSorteadas();
        System.out.println("Lancamento 1:");
        System.out.println(getValorDado(0) + " e " + getValorDado(1) + " = " + somaFaces);

        // Se o resultado da soma dos dados for 7 ou 11, o jogador ganha
        if (somaFaces == 7 || somaFaces == 11) {
            resultado = true;
            System.out.println("\n------------------------------\n");
            System.out.println(
                    jogador.getNome() + " ganhou R$" + new DecimalFormat("#0.##").format(getValorAposta()) + "!");
            setResultado("Ganhou");
        }
        // Se o resultado da soma dos dados for 2, 3 ou 12 , o jogador perde
        if (somaFaces == 2 || somaFaces == 3 || somaFaces == 12) {
            resultado = false;
            System.out.println("\n------------------------------\n");
            System.out.println(
                    jogador.getNome() + " perdeu R$" + new DecimalFormat("#0.##").format(getValorAposta()) + "!");
            setResultado("Perdeu");
        } else { // Caso nenhum dos casos seja cumprido, inicia o ciclo para achar o valor obtido
                 // da soma
            int valorBuscado = somaFaces;
            System.out.println("Numero a ser buscado: " + valorBuscado);
            int novaSoma;
            int lancamentoAtual = 2;
            // Inicia o loop para achar o mesmo valor novamente, ou perder
            do {
                novaSoma = 0;
                rolarDados();
                ocorrenciaDosDados();
                novaSoma = somarFacesSorteadas();
                System.out.println("Lancamento " + lancamentoAtual + ":");
                System.out.println(getValorDado(0) + " e " + getValorDado(1) + " = " + novaSoma);
                // Se o resultado da nova soma for igual a anterior, o jogador ganha
                if (novaSoma == valorBuscado) {
                    resultado = true;
                    System.out.println("\n------------------------------\n");
                    System.out.println(jogador.getNome() + " ganhou R$"
                            + new DecimalFormat("#0.##").format(getValorAposta()) + "!");
                    setResultado("Ganhou");
                    break;
                }
                // Se o resultado da nova soma dos dados for 2, 3 ou 12 , o jogador perde
                if (novaSoma == 2 || novaSoma == 3 || novaSoma == 12) {
                    resultado = false;
                    System.out.println("\n------------------------------\n");
                    System.out.println(jogador.getNome() + " perdeu R$"
                            + new DecimalFormat("#0.##").format(getValorAposta()) + "!");
                    setResultado("Perdeu");
                    break;
                }
                lancamentoAtual++;
            } while (valorBuscado != novaSoma);
        }

        return resultado;
    }

    // Imprime os resultados do jogo
    @Override
    public void imprimirResultados() {
        System.out
                .println(getNome() + ":\n\t-- Valor apostado: R$" + new DecimalFormat("#0.##").format(getValorAposta())
                        + "\n\t-- Resultado: " + getResultado());
    }
}
