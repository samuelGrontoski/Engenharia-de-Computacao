import java.io.Serializable;

public abstract class JogoDados implements Serializable, Estatistica {
    private int nDados;
    private String nomeJogo;
    private Dado[] dados;

    public JogoDados(String nomeJogo, int nDados) {
        this.nomeJogo = nomeJogo;
        this.nDados = nDados;
        dados = new Dado[nDados];
        for (int i = 0; i < nDados; i++) {
            dados[i] = new Dado();
        }
    }

    // Rola os dados
    public Dado rolarDados() {
        for (int i = 0; i < nDados; i++){
            dados[i].roll();
        }
        return dados[nDados];
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
    public abstract int somarFacesSorteadas(Dado[] dados);

    // Validar jogada
    public abstract boolean validarJogada(int jogada);

    public int getnDados() {
        return nDados;
    }

    public void setnDados(int nDados) {
        this.nDados = nDados;
    }

    public String getNome() {
        return nomeJogo;
    }

    public void setNome(String nomeJogo) {
        this.nomeJogo = nomeJogo;
    }

    public int getValorDado(int i) {
        return dados[i].getSideUp();
    }

    public void setValorDado(int valor, int i) {
        this.dados[i].atualizaValor(valor);
    }

    // Passa os valores rodados para uma string
    public String toString() {
        String resultado = "Valores obtidos: ";
        for (int i = 0; i < nDados; i++) {
            resultado += "" + dados[i];
            if (i != 4)
                resultado += "-";
        }
        return resultado;
    }
}
