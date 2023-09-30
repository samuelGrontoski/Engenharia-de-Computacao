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
            // Menu
            System.out.println("..::: Menu Jogo General :::..");
            System.out.println("(a) Incluir jogador");
            System.out.println("(b) Remover jogador");
            System.out.println("(c) Executar rodada");
            System.out.println("(d) Mostrar a cartela de resultados [da última rodada realizada]");
            System.out.println("(e) Gravar os dados do campeonato em arquivo");
            System.out.println("(f) Ler os dados docampeonato em arquivo");
            System.out.println("(g) Sair da aplicacao");
            System.out.println("Escolha uma opcao: ");
            opcao = teclado.nextLine();

            switch (opcao){
                // A - Incluir jogador
                case "a": {
                    System.out.println("Nome do jogador: ");
                    String nome = teclado.nextLine();
                    String tipoJogador = "Sem valor";
                    do {
                        System.out.println("Tipo do Jogador [H - humano ou M - maquina]: ");
                        tipoJogador = teclado.nextLine();
                    } while ((tipoJogador.equals("H") == false) && (tipoJogador.equals("M") == false));

                    campeonato.incluirJogador(nome, tipoJogador);

                    System.out.println("\n");
                    break;
                }
                // B - Excluir jogador (pelo nome)
                case "b": {
                    System.out.println("Informe o nome do jogador que deseja excluir: ");
                    String nome = teclado.nextLine();

                    campeonato.removerJogador(nome);
                    System.out.println("\n");
                    break;
                }
                // C - Executar rodada
                case "c": {

                }
                // D - Mostrar a cartela de resultados [da ultima rodada realizada
                case "d": {

                }
                // E - Gravar os dados do campeonato em arquivo
                case "e": {

                }
                // F - Ler os dados do campeonato em arquivo
                case "f": {

                }
                // G - Sair da aplicacao
                case "g": {
                    System.out.println("Obrigado por jogar!");
                }
                default : {
                    System.out.println("Opcao invalida. Tente novamente");
                }

            } 

            
        } while (opcao.equals("g") == false);
        
        teclado.close();
    }

    static void menu() {

    }
}
