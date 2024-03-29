import java.util.Scanner;

public class usaCampeonato {
    public static void main(String[] args) {
        Campeonato campeonato = new Campeonato();

        Scanner teclado = new Scanner(System.in);
        String opcao = "";

        do {
            // Menu
            System.out.println("\n..::: Menu Jogo General :::..");
            System.out.println("(a) Incluir jogador");
            System.out.println("(b) Remover jogador");
            System.out.println("(c) Executar rodada");
            System.out.println("(d) Mostrar a cartela de resultados [da ultima rodada realizada]");
            System.out.println("(e) Gravar os dados do campeonato em arquivo");
            System.out.println("(f) Ler os dados do campeonato em arquivo");
            System.out.println("(g) Sair da aplicacao");
            System.out.println("Escolha uma opcao: ");
            opcao = teclado.nextLine();

            switch (opcao) {
                // A - Incluir jogador
                case "a": {
                    campeonato.incluirJogador();
                    break;
                }
                // B - Excluir jogador (pelo nome)
                case "b": {
                    campeonato.removerJogador();
                    break;
                }
                // C - Executar rodada
                case "c": {
                    campeonato.iniciarCampeonato();
                    break;
                }
                // D - Mostrar a cartela de resultados [da ultima rodada realizada
                case "d": {
                    campeonato.mostrarCartela();
                    break;
                }
                // E - Gravar os dados do campeonato em arquivo
                case "e": {
                    campeonato.gravarEmArquivo();
                    break;
                }
                // F - Ler os dados do campeonato em arquivo
                case "f": {
                    campeonato.lerDoArquivo();
                    break;
                }
                // G - Sair da aplicacao
                case "g": {
                    System.out.println("\nObrigado por jogar!");
                    System.out.println("\n");
                    break;
                }
                default: {
                    System.out.println("\nOpcao invalida. Tente novamente");
                }
            }
        } while (opcao.equals("g") == false);

        teclado.close();
    }
}
