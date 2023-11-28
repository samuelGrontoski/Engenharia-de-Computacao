import java.io.Serializable;

public abstract class Jogador implements Serializable {
    private String nome;
    private JogoDados[] jogos;
    private int numJogos;
    private float saldo;

    // Construtor
    public Jogador(String nome) {
        this.nome = nome;
        jogos = new JogoDados[10];
        this.numJogos = 0;
        this.saldo = 100;
    }

    // Sobrecarga de construtor
    public Jogador() {
        this.nome = "Random";
        jogos = new JogoDados[10];
        this.numJogos = 0;
        this.saldo = 100;
    }

    // Pergunta e valida quanto o jogador deseja apostar, e atualiza o saldo do
    // jogador
    public abstract float valorAposta();

    // Pergunta ao jogador para qual jogo deseja apostar
    public abstract int escolherJogo();

    // Inicia o jogo de azar
    public abstract void iniciarJogoAzar(float valorAposta, int rodada);

    // Inicia o jogo general
    public abstract void iniciarJogoGeneral(float valorAposta, int rodada);

    // Executa o jogo da referente rodada
    public boolean executarJogo(int rodada, Jogador jogador) {
        boolean resultado = jogos[rodada].executarJogo(jogador);

        return resultado;
    }

    // Imprime os resultados dos jogos
    public void imprimirResultados(int tipoJogo) {
        switch (tipoJogo) {
            // Jogo de Azar
            case 1: {
                System.out.println("- Imprimindo resultados dos Jogos de Azar:");
                for (int i = 0; i < numJogos; i++) {
                    if (jogos[i] instanceof JogoAzar) {
                        System.out.print("\n" + (i+1) + " - ");
                        jogos[i].imprimirResultados();
                    }
                }
                break;
            }
            // Jogo General
            case 2: {
                System.out.println("- Imprimindo resultados dos Jogos General:");
                for (int i = 0; i < numJogos; i++) {
                    if (jogos[i] instanceof JogoGeneral) {
                        System.out.print("\n" + (i+1) + " - ");
                        jogos[i].imprimirResultados();
                    }
                }
                break;
            }
            // Todos os Jogos
            case 3: {
                System.out.println("- Imprimindo resultados de todos os jogos:");
                for (int i = 0; i < numJogos; i++) {
                    System.out.print("\n" + (i+1) + " - ");
                    jogos[i].imprimirResultados();
                }
                break;
            }
        }
    }

    // Estatisticas dos dados de todos os jogos do jogador
    public int estatisticasJogador(int n) {
        int estatisticaN = 0;

        for (int i = 0; i < numJogos; i++) {
            estatisticaN += jogos[i].ocorrenciaDeN(n);
        }

        return estatisticaN;
    }

    // Estatisticas dos dados dos Jogos de Azar
    public int estatisticasAzar(int n) {
        int estatisticaN = 0;

        for (int i = 0; i < numJogos; i++) {
            if (jogos[i] instanceof JogoAzar) {
                estatisticaN += jogos[i].ocorrenciaDeN(n);
            }
        }

        return estatisticaN;
    }

    // Estatisticas dos dados dos Jogos General
    public int estatisticasGeneral(int n) {
        int estatisticaN = 0;

        for (int i = 0; i < numJogos; i++) {
            if (jogos[i] instanceof JogoGeneral) {
                estatisticaN += jogos[i].ocorrenciaDeN(n);
            }
        }

        return estatisticaN;
    }

    // Estatisticas dos dados por jogo
    public void estatisticasJogoN() {
        System.out.println("\n------------------------------\n");
        System.out.println("\nEstatisticas dos jogos de " + getNome() + ":\n");
        for (int i = 0; i < numJogos; i++) {
            int totalRolagens = 0;
            System.out.println((i + 1) + " - " + jogos[i].getNome() + ":");
            for (int j = 0; j < 6; j++) {
                System.out.println("Face " + (j + 1) + ": " + jogos[i].ocorrenciaDeN(j));
                totalRolagens += jogos[i].ocorrenciaDeN(j);
            }
            System.out.println("Total de rolagens: " + totalRolagens + "\n");
        }
    }

    // Retorna o nome do jogador
    public String getNome() {
        return nome;
    }

    // Define o nome do jogador
    public void setNomeJogo(String nomeJogo) {
        jogos[numJogos - 1].setNome(nomeJogo);
    }

    // Retorna determinado jogo
    public JogoDados getJogo(int posicao) {
        return jogos[posicao];
    }

    // Define determinado jogo
    public void setJogo(JogoDados novoJogo, int rodada) {
        jogos[rodada] = novoJogo;
        numJogos++;
    }

    // Retorna o saldo do jogador
    public float getSaldo() {
        return saldo;
    }

    // Define o saldo do jogador
    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    // Exclui o jogador
    public void excluirJogador() {
        this.nome = null;
        this.jogos = null;
        this.numJogos = 0;
        this.saldo = 0;
    }

    // Passa o resultados dos dados jogados pelo jogador para uma string
    public String toString() {
        String resultado = jogos[numJogos - 1].toString();

        return resultado;
    }

    // Reseta os jogos
    public void resetarJogos() {
        for (int i = 0; i < numJogos; i++) {
            jogos[i] = null;
        }
        this.numJogos = 0;
    }
}
