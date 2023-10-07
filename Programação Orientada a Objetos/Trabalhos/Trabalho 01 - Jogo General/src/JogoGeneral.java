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
        for (int i = 0; i < 13; i++){
            jogadas[0][i] = 0;
            jogadas[1][i] = 0;
        }
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
        }

        return mostraJogadas;
    }

    // Retorna a pontuacao de uma jogada especifica
    public int pontosJogada(int posicao){
        int pontos = jogadas[1][posicao];

        return pontos;
    }

    // Verifica se a posicao da jogada e valida ou nao
    public boolean validarJogada(int jogada){
        boolean validade = true;
        if(jogadas[0][jogada] != 0){
            validade = false;
        }
        return validade;
    }

    // Ordena os dados para facilitar as contagens na pontuacao
    public void ordenaDados(){
        int x;
    
        for (int i = 0; i < 5 - 1; i++){
            for (int j = 0; j < 5 - i - 1; j++)
                if (dados[j].getSideUp() > dados[j + 1].getSideUp()){
                    x = dados[j].getSideUp();
                    dados[j].atualizaValor(dados[j + 1].getSideUp());
                    dados[j + 1].atualizaValor(x);
                }
        }
    }

    // Pontua a jogada do humano
    public void pontuarJogadaHumano(int jogada){
        jogadas[0][jogada - 1] = 1;
        int pontos = 0;

        switch (jogada){
            // Jogada de 1
            case 1 : {
                int count1 = 0;
                for (int i = 0; i < 5; i++){
                    if (dados[i].getSideUp() == 1)
                        count1++;
                }
                jogadas[1][jogada-1] = count1;
                break;
            }
            // Jogada de 2
            case 2 : {
                int count2 = 0;
                for (int i = 0; i < 5; i++){
                    if (dados[i].getSideUp() == 2)
                        count2++;
                }
                jogadas[1][jogada-1] = count2 * 2;
                break;
            }
            // Jogada de 3
            case 3 : {
                int count3 = 0;
                for (int i = 0; i < 5; i++){
                    if (dados[i].getSideUp() == 3)
                        count3++;
                }
                jogadas[1][jogada-1] = count3 * 3;
                break;
            }
            // Jogada de 4
            case 4 : {
                int count4 = 0;
                for (int i = 0; i < 5; i++){
                    if (dados[i].getSideUp() == 4)
                        count4++;
                }
                jogadas[1][jogada-1] = count4 * 4;
                break;
            }
            // Jogada de 5
            case 5 : {
                int count5 = 0;
                for (int i = 0; i < 5; i++){
                    if (dados[i].getSideUp() == 5)
                        count5++;
                }
                jogadas[1][jogada-1] = count5 * 5;
                break;
            }
            // Jogada de 6
            case 6 : {
                int count6 = 0;
                for (int i = 0; i < 5; i++){
                    if (dados[i].getSideUp() == 6)
                        count6++;
                }
                jogadas[1][jogada-1] = count6 * 6;
                break;
            }
            // Trinca
            case 7 : {
                int repetidoX3 = 0;
                for (int i = 1; i <= 6; i++){
                    repetidoX3 = 0;
                    for (int j = 0; j < 5; j++){
                        if (dados[j].getSideUp() == i){
                            repetidoX3++;
                        }
                    }
                    if (repetidoX3 == 3){
                        break;
                    }
                }
                if (repetidoX3 == 3){
                    for (int k = 0; k < 5; k++){
                        pontos += dados[k].getSideUp();
                    }
                    jogadas[1][jogada-1] = pontos;
                } else {
                    jogadas[1][jogada-1] = 0;
                }
                break;
            }
            // Quadra
            case 8 : {
                int repetidoX4 = 0;
                for (int i = 1; i <= 6; i++){
                    repetidoX4 = 0;
                    for (int j = 0; j < 5; j++){
                        if (dados[j].getSideUp() == i){
                            repetidoX4++;
                        }
                    }
                    if (repetidoX4 == 4){
                        break;
                    }
                }
                if (repetidoX4 == 4){
                    for (int k = 0; k < 5; k++){
                        pontos += dados[k].getSideUp();
                    }
                    jogadas[1][jogada-1] = pontos;
                } else {
                    jogadas[1][jogada-1] = 0;
                }
                break;
            }
            // Full-hand/Full-house
            case 9 : {
                
            }
            case 10 : {
                
            }
            case 11 : {
                
            }
            case 12 : {
                
            }
            case 13 : {
                
            }
        }
    }

    // Pontua a jogada da maquina
    public void pontuarJogadaMaquina(){

    }
}
