public class Agenda {
    private Pessoa[] agenda;

    public Agenda() {
        agenda = new Pessoa[50];
    }

    int posicao = 0;

    public void incluir_pessoa(String nome, String cpf) {
        boolean nomeIgual = false;
        boolean cpfIgual = false;
        Pessoa nova = new Pessoa(nome, cpf);

        if (posicao == 0) {
            agenda[posicao] = nova;
            posicao++;
            System.out.println("Pessoa cadastrada com sucesso!");
        } else {
            for (int i = 0; i < posicao; i++) {
                String nomeSalvo = agenda[i].getNome();
                String cpfSalvo = agenda[i].getCPF();
                nomeIgual = (nomeSalvo.equals(nome));
                cpfIgual = (cpfSalvo.equals(cpf));

                if (nomeIgual == true && cpfIgual == true) {
                    System.out.println("Pessoa ja cadastrada, tente outro nome");
                    break;
                }
            }

            if (nomeIgual == false || cpfIgual == false) {
                agenda[posicao] = nova;
                posicao++;
                System.out.println("Pessoa cadastrada com sucesso!");
            }
        }
    }

    public void excluir_pessoa(String nome) {
        boolean nomeIgual = false;

        for (int i = 0; i < posicao; i++) {
            String nomeSalvo = agenda[i].getNome();
            nomeIgual = (nomeSalvo.equals(nome));

            if (nomeIgual == true) {
                agenda[i].excluirPessoa();
                System.out.println("Pessoa excluida com sucesso!");
                break;
            }
        }

        if (nomeIgual == false) {
            System.out.println("Pessoa nao encontrada");
        }
    }
}
