public final class Maquina extends Jogador implements JogarComoMaquina{
    public Maquina(String nome){
        super(nome);
    }

    public void aplicarEstrategia(){
        System.out.print("Jogada escolhida por " + getNome() + "(M) [1 - 13]: ");
    };

    @Override
    public void pontuandoGeneral(int jogada) {
        JogoDados novoJogo = new JogoGeneral();
    }
}
