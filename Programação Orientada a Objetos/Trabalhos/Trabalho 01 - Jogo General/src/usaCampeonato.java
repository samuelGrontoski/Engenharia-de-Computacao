import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class usaCampeonato {
    public static void main(String[] args){
        Campeonato campeonato = new Campeonato();

        Scanner teclado = new Scanner(System.in);
        String opcao = "Sem valor";

        do {
            switch (opcao){
                // A - Incluir jogador
                case "A": {
                    teclado.nextLine();
                    System.out.println("Nome do jogador: ");
                    String nome = teclado.nextLine();
                    do {
                        System.out.println("Tipo do Jogador [H - humano ou M - maquina]: ");
                        String tipoJogador = teclado.nextLine();
                    } while ((tipoJogador != "H") || (tipoJogador != "M"));
                }
                // B - Excluir jogador (pelo nome)
                case "B": {

                }
                // C - Executar rodada
                case "C": {

                }
                // D - Mostrar a cartela de resultados [da ultima rodada realizada
                case "D": {

                }
                // E - Gravar os dados do campeonato em arquivo
                case "E": {

                }
                // F - Ler os dados do campeonato em arquivo
                case "F": {

                }
                // G - Sair da aplicacao
                case "G": {
                    System.out.println("Obrigado por jogar!");
                }

            } 

            
        } while (opcao.equals("G") == false);
        
        teclado.close();
    }
}
