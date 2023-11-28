import java.io.Serializable;

public abstract class JogoDados implements Serializable, Estatistica {
    private int nDados;
    private String nomeJogo;
    private Dado[] dados;
    private float valorAposta;
    private String resultado;
    private int[] ocorrenciaDados;

    // Construtor
    public JogoDados(String nomeJogo, int nDados, float valorAposta) {
        this.nomeJogo = nomeJogo;
        this.nDados = nDados;
        dados = new Dado[nDados];
        for (int i = 0; i < nDados; i++) {
            dados[i] = new Dado();
        }
        this.valorAposta = valorAposta;
        ocorrenciaDados = new int[6];
        for (int i = 0; i < 6; i++) {
            ocorrenciaDados[i] = 0;
        }
    }

    // Rola os dados
    public void rolarDados() {
        for (int i = 0; i < nDados; i++) {
            dados[i].roll();
        }
    };

    // Ordena os dados para facilitar as contagens em algumas pontuacoes
    public void ordenaDados() {
        int x;

        for (int i = 0; i < nDados - 1; i++) {
            for (int j = 0; j < nDados - i - 1; j++)
                if (dados[j].getSideUp() > dados[j + 1].getSideUp()) {
                    x = dados[j].getSideUp();
                    dados[j].atualizaValor(dados[j + 1].getSideUp());
                    dados[j + 1].atualizaValor(x);
                }
        }
    }

    // Soma as faces dos dados
    public int somarFacesSorteadas() {
        int soma = 0;

        for (int i = 0; i < nDados; i++) {
            soma += getValorDado(i);
        }

        return soma;
    }

    // Metodo que calcula quantas vezes cada face foi sorteada
    public void ocorrenciaDosDados() {
        for (int i = 0; i < nDados; i++) {
            for (int j = 0; j < 6; j++) {
                if (getValorDado(i) == (j + 1)) {
                    ocorrenciaDados[j]++;
                }
            }
        }
    }

    // Retorna quantas vezes determinada face foi sorteada
    public int ocorrenciaDeN(int n) {
        return ocorrenciaDados[n];
    }

    // Mostrar as jogadas do jogo
    public abstract String mostrarJogadas();

    // Executa o jogo
    public abstract boolean executarJogo(Jogador jogador);

    // Imprime os resultados do jogo
    public abstract void imprimirResultados();

    // Retorna o numero de dados
    public int getnDados() {
        return nDados;
    }

    // Define o numero de dados
    public void setnDados(int nDados) {
        this.nDados = nDados;
    }

    // Retorna o numero de dados
    public String getNome() {
        return nomeJogo;
    }

    // Define o numero de dados
    public void setNome(String nomeJogo) {
        this.nomeJogo = nomeJogo;
    }

    // Retorna o valor sorteado em determinado dado
    public int getValorDado(int i) {
        return dados[i].getSideUp();
    }

    // Define o valor de determinado dado
    public void setValorDado(int valor, int i) {
        this.dados[i].atualizaValor(valor);
    }

    // Retorna o valor apostado
    public float getValorAposta() {
        return valorAposta;
    }

    // Define o valor apostado
    public void setValorAposta(float valorAposta) {
        this.valorAposta = valorAposta;
    }

    // Retorna o resultado do jogo
    public String getResultado() {
        return resultado;
    }

    // Define o resultado do jogo
    public void setResultado(String resultado) {
        this.resultado = resultado;
    }

    // Passa os valores rodados para uma string
    public String toString() {
        String resultado = "Valores obtidos: ";
        for (int i = 0; i < nDados; i++) {
            resultado += "" + getValorDado(i);
            if (i != 4)
                resultado += "-";
        }
        return resultado;
    }
}
