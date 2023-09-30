import java.io.Serializable;

public class JogoGeneral implements Serializable{
    private Dado[] dados;
    private int[][] jogadas;

    // Construtor
    public JogoGeneral(){
        dados = new Dado[5];
        for(int i = 0; i < 5; i++){
            dados[i] = new Dado();
        }
        jogadas = new int[2][13];
    }

    // Rola os 5 dados
    public void rolarDados(){
        for(int i = 0; i < 5; i++){
            dados[i].roll();
        }
    }

    // Passa os valores rodados para uma string
    public String toString(){
        String resultado = "Valores obtidos: ";
        for(int i = 0; i < 5; i++){
            resultado += "" + dados[i];
            if(i != 4)
                resultado += "-";
        }
        return resultado;
    }

    // Passa os valores ja registrados das jogadas para uma string
    public String jogadaString(){
        String mostraJogadas = "";

        for(int i = 0; i < 13; i++){
            if(jogadas[0][i] == 0){
                mostraJogadas += "-\t";
            } else {
                mostraJogadas += jogadas[1][i] + "\t";
            }
            // adcionar os espacos a mais necessarios
            //if(i < )
        }

        return mostraJogadas;
    }

    // Verifica se a posicao da jogada e valida ou nao
    public boolean validarJogada(int jogada){
        boolean validade = true;
        if(jogadas[0][jogada] != 0){
            validade = false;
        }
        return validade;
    }

    // Pontua a jogada do humano
    public void pontuarJogadaHumano(int jogada){
        jogadas[0][jogada] = 1;
    }

    // Pontua a jogada da maquina
    public void pontuarJogadaMaquina(){

    }
}
