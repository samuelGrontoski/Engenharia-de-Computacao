import java.io.Serializable;

public class JogoGeneral implements Serializable{
    private Dado[] dados = new Dado[5];
    private int[] jogadas = new int[13];

    public JogoGeneral(){
        dados = null;
        for(int i = 0; i < 13; i++)
            jogadas[i] = 0;
    }

    public void rolarDados(){
        for(int i = 0; i < 5; i++){
            dados[i].roll();
        }
    }

    public String toString(){
        String resultado = "Valores obtidos: ";
        for(int i =0; i < 5; i++){
            resultado += dados[i].getSideUp() + "-";
        }
        return resultado;
    }

    // mexer nisso aqui
    public boolean validarJogada(int posicao){
        boolean valido = true;
        if(jogadas[posicao] != 0){
            valido = false;
        }
        return valido;
    }
}
