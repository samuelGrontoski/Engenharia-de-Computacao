public interface JogarComoHumano {
    float valorAposta();
    int escolherJogo();
    void iniciarJogoAzar(float valorAposta, int rodada);
    void iniciarJogoGeneral(float valorAposta, int rodada);
}
