public class Animal {
    private String nome;
    private String tipo;

    public Animal (String nome, String tipo) {
        this.nome = nome;
        this.tipo = tipo;
    }

    public String toString() {
        return "Nome: " + nome + "\nTipo: " + tipo + "\n";
    }
}
