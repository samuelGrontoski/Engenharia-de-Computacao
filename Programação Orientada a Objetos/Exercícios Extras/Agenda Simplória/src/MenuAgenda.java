import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
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
                // 1 - Incluir pessoa
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
                // 2 - Listar pessoas cadastradas na agenda
                case 2: {
                    System.out.println(agenda);
                    System.out.println("\n");
                    break;
                }
                // 3 - Excluir pessoa (pelo nome)
                case 3: {
                    teclado.nextLine();
                    System.out.print("Informe o nome que deseja apagar: ");
                    String nome = teclado.nextLine();

                    agenda.excluir_pessoa(nome);

                    System.out.println("\n");
                    break;
                }
                // 4 - Gravar a agenda em arquivo
                case 4: {
                    File arquivo = new File("agenda.dat");
                    try {
                        FileOutputStream fout = new FileOutputStream(arquivo);
                        ObjectOutputStream oos = new ObjectOutputStream(fout);
                        oos.writeObject(agenda);
                        oos.flush();
                        oos.close();
                        fout.close();
                        System.out.println("Arquivo gravado com sucesso!\n");
                    } catch (Exception ex) {
                        System.err.println("erro: " + ex.toString());
                    }
                    break;
                }
                // 5 - Ler a agenda do arquivo
                case 5: {
                    File arquivo = new File("agenda.dat");

                    try {
                        FileInputStream fin = new FileInputStream(arquivo);
                        ObjectInputStream oin = new ObjectInputStream(fin);

                        // Lendo os objetos de um arquivo e fazendo a coercao de tipos
                        Agenda agendaArq = (Agenda) oin.readObject();
                        oin.close();
                        fin.close();

                        // Uma forma de diferente do for para percorrer vetores
                        
                        System.out.println(agendaArq.toString());
                        
                    } catch (Exception ex) {
                        System.err.println("erro: " + ex.toString());
                    }
                    break;
                }
                // 6 - Sair do programa
                case 6: {
                    System.out.println("Saindo do programa!");
                }
                // 
            }

        } while (opcao != 6);

        teclado.close();
    }
}
