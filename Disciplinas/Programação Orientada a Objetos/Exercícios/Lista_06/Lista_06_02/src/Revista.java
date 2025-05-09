public class Revista {
    private String nome;
    private int numEd;
    private int mesPubli;
    private int anoPubli;

    public Revista (String nome, int numEd, int anoPubli, int mesPubli){
        this.nome = nome;
        this.numEd = numEd;
        this.anoPubli=anoPubli;
        this.mesPubli=mesPubli;
    }

    public String toString(){
        return "Revista: " + nome + " - Edicao: " + numEd + " - Publicado em: " + mesPubli + "/" + anoPubli;
    }
}
