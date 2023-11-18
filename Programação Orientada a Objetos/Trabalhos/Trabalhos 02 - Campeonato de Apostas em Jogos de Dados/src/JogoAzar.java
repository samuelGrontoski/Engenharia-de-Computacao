public final class JogoAzar extends JogoDados{
    private float valorAposta;

    public JogoAzar() {
        super("Jogo Azar", 2);
    }

    // Rola os dados
    @Override
    public void rolarDados() {
        for (int i = 0; i < 2; i++) {
            this.rolarUmDado(i);
        }
    }

    // Ordena os dados para facilitar as contagens em algumas pontuacoes
    @Override
    public void ordenaDados() {
        int x;

        for (int i = 0; i < 2 - 1; i++) {
            for (int j = 0; j < 2 - i - 1; j++) {
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
    public int somarFacesSorteadas(Dado[] dados){
        int soma = 0;

        return soma;
    }

    // Valida se a jogada e validad ou nao
    @Override
    public boolean validarJogada(int jogada) {
        boolean validade = false;

        return validade;
    }
} 
