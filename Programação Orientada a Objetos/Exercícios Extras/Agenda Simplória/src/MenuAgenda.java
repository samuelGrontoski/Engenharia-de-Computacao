import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class MenuAgenda {
    public static void main(String[] args) {
        Agenda agenda = new Agenda(50);

        Scanner teclado = new Scanner(System.in);
        int opcao = 0;

        do {
            System.out.println("..:: Menu ::..");
            System.out.println("1 - Incluir pessoa");
            System.out.println("2 - Listar pessoas cadastradas na agenda");
            System.out.println("3 - Excluir pessoa (pelo nome)");
            System.out.println("4 - Gravar a agenda em arquivo");
            System.out.println("5 - Ler a agenda do arquivo");
            System.out.println("6 - Sair do programa");
            System.out.println("Escolha uma opcao: ");
            opcao = teclado.nextInt();

            switch (opcao) {
                case 1: {
                    teclado.nextLine();
                    System.out.print("Nome: ");
                    String nome = teclado.nextLine();
                    System.out.print("CPF: ");
                    String cpf = teclado.nextLine();

                    agenda.incluir_pessoa(nome, cpf);

                    System.out.println("\n");
                    break;
                }
                case 2: {
                    System.out.println(agenda);
                    System.out.println("\n");
                    break;
                }
                case 3: {
                    teclado.nextLine();
                    System.out.print("Informe o nome que deseja apagar: ");
                    String nome = teclado.nextLine();

                    agenda.excluir_pessoa(nome);

                    System.out.println("\n");
                    break;
                }
                case 4: {
                    File arquivo = new File("agenda.dat");
                    try {
                        FileOutputStream fout = new FileOutputStream(arquivo);
                        ObjectOutputStream oos = new ObjectOutputStream(fout);
                        oos.writeObject(agenda);
                        oos.flush();
                        oos.close();
                        fout.close();
                    } catch (Exception ex) {
                        System.err.println("erro: " + ex.toString());
                    }
                    break;
                }

            }

        } while (opcao != 6);

        teclado.close();
    }
}
