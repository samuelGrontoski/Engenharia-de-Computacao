import java.io.Serializable;

public class Pessoa implements Serializable {
    private String nome;
    private String cpf;

    public Pessoa(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }

    public String getNome(){
        return nome;
    }

    public String getCPF(){
        return cpf;
    }

    public void excluirPessoa(){
        this.nome = "####";
        this.cpf = "####";
    }

    public String toString() {
        String resultado = "Nome: " + nome + "\nCPF: " + cpf + "\n";
        return resultado;
    }
}
