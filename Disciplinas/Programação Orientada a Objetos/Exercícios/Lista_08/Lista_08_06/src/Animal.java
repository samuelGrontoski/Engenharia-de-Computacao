public class Animal {
    private String nome;
    private String tipo;
    private String som;

    public Animal (String nome, String tipo, String som) {
        this.nome = nome;
        this.tipo = tipo;
        this.som = som;
    }

    public String toString() {
        return "Nome: " + nome + "\nTipo: " + tipo + "\nSom: " + som + "\n";
    }
}