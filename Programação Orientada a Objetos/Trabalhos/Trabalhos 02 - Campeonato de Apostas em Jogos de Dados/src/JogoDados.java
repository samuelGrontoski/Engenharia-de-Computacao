import java.io.Serializable;

public abstract class JogoDados implements Serializable {
    private int nDados;
    private String nomeJogo;
    private Dado[] dados;

    public JogoDados(int jogo, String nomeJogo) {
        this.nomeJogo = nomeJogo;
        if (jogo == 1) {
            this.nDados = 2;
            dados = new Dado[2];
            for (int i = 0; i < 2; i++) {
                dados[i] = new Dado();
            }
        }
        if (jogo == 2) {
            this.nDados = 5;
            dados = new Dado[5];
            for (int i = 0; i < 5; i++) {
                dados[i] = new Dado();
            }
        }
    }

    public void rolarDados() {
        for (int i = 0; i < nDados; i++) {
            dados[i].roll();
        }
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
