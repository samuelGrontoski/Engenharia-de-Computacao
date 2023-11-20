import java.util.Scanner;

public class usaCampeonato {
    public static void main(String[] args) {
        Campeonato campeonato = new Campeonato();

        Scanner teclado = new Scanner(System.in);
        char opcao;

        do {
            // Menu
            System.out.println("\n..::: Menu Campeonato de Apostas em Jogos de Dados :::..");
            System.out.println("(a) Incluir jogador");
            System.out.println("(b) Remover jogador");
            System.out.println("(c) Executar rodadas de apostas");
            System.out.println("(d) Imprimir saldo(s)");
            System.out.println("(e) Imprimir extratos dos resultados");
            System.out.println("(f) Imprimir estatisticas");
            System.out.println("(g) Gravar os dados do campeonato em arquivo");
            System.out.println("(h) Ler os dados do campeonato em arquivo");
            System.out.println("(i) Sair da aplicacao\n");
            System.out.println("Escolha uma opcao: ");
            opcao = teclado.next().charAt(0);

            switch (opcao) {
                // A - Incluir jogador
                case 'a': {
                    campeonato.incluirJogador();
                    break;
                }
                // B - Remover jogador (pelo nome)
                case 'b': {
                    campeonato.removerJogador();
                    break;
                }
                // C - Executar rodadas de apostas
                case 'c': {
                    campeonato.iniciarCampeonato();
                    break;
                }
                // D - Imprimir saldo(s)
                case 'd': {
                    campeonato.imprimirSaldos();
                    break;
                }
                // E - Imprimir extratos dos resultados
                case 'e': {
                    campeonato.imprimirResultados();
                    break;
                }
                // F - Imprimir estatisticas
                case 'f': {
                    campeonato.imprimirEstatisticas();
                    break;
                }
                // G - Gravar os dados do campeonato em arquivo
                case 'g': {
                    campeonato.gravarEmArquivo();
                    break;
                }
                // H - Ler os dados do campeonato em arquivo
                case 'h': {
                    campeonato.lerDoArquivo();
                    break;
                }
                // I - Sair da aplicacao
                case 'i': {
                    System.out.println("\nObrigado por jogar!");
                    System.out.println("\n");
                    break;
                }
                default: {
                    System.out.println("\nOpcao invalida. Tente novamente");
                }
            }
        } while (opcao != 'i');

        teclado.close();
    }
}
