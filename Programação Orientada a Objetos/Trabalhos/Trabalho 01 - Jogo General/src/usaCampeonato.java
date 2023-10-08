import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
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
                    File arquivo = new File("campeonato.dat");
                    try {
                        FileOutputStream fout = new FileOutputStream(arquivo);
                        ObjectOutputStream oos = new ObjectOutputStream(fout);
                        oos.writeObject(campeonato);
                        oos.flush();
                        oos.close();
                        fout.close();
                        System.out.println("\nArquivo gravado com sucesso!");
                    } catch (Exception ex) {
                        System.err.println("erro: " + ex.toString());
                    }
                    break;
                }
                // F - Ler os dados do campeonato em arquivo
                case "f": {
                    File arquivo = new File("campeonato.dat");

                    try {
                        FileInputStream fin = new FileInputStream(arquivo);
                        ObjectInputStream oin = new ObjectInputStream(fin);

                        Campeonato campeonatoArq = (Campeonato) oin.readObject();
                        oin.close();
                        fin.close();

                        campeonatoArq.mostrarCartela();
                        
                    } catch (Exception ex) {
                        System.err.println("erro: " + ex.toString());
                    }
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
