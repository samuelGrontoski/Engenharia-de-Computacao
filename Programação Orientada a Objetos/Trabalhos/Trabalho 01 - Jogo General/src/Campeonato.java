import java.io.Serializable;

public class Campeonato implements Serializable{
    private Jogador[] jogadores;
    private int numJogadores = 0;

    public Campeonato(){
        jogadores = new Jogador[10];
    }

    public void incluirJogador(String nome, String tipoJogador){
        jogadores[0] = new Jogador(nome, tipoJogador);
        numJogadores++;
    }

    public void removerJogador(String nome){
        boolean nomeIgual = false;

        for (int i = 0; i < numJogadores; i++){
            String nomeSalvo = jogadores[i].getNome();
            nomeIgual = (nomeSalvo.equals(nome));

            if (nomeIgual == true){
                jogadores[i].excluirJogador();
                numJogadores--;
                System.out.println("Jogador excluido com sucesso!");
                break;
            }
        }

        if (nomeIgual == false){
            System.out.println("Jogador nao encontrado");
        }
    }

    public void iniciarCampeonato(){
        if(numJogadores < 2){
            System.out.println("Numero de jogadores insuficiente. Inclua ao menos 2 jogadores para iniciar.")
        } else {
            for(int i = 0; i < 13; i++){
                for(int j = 0; j < numJogadores; j++){
                    jogadores[j].jogarDados();
                    System.out.println(jogadores[j].toString());
                }
            }
        }
    }
}
