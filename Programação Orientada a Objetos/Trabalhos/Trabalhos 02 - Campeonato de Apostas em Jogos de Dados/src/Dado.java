import java.io.Serializable;
import java.util.Random;

public class Dado implements Serializable{
    private int sideUp;

    // Construtor
    public Dado(){
        sideUp = 1;
    }

    // Rola o dado
    public void roll(){
        Random x = new Random();
        sideUp = x.nextInt(6) + 1;
    }

    // Obtem e retorna o resultado da rolagem
    public int getSideUp(){
        return sideUp;
    }

    // Atualiza o valor do resultado do dado
    public void atualizaValor(int valor){
        sideUp = valor;
    }

    // Passa o valor rolado para uma string, util para a impressao
    public String toString(){
        String resultado = "" + sideUp;
        return resultado;
    }
}
