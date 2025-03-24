public class Pessoa1{

 private String nome, cpf;
 private int anoNasc;

 // metodo construtor padrao
 public Pessoa1(){
	nome = ""; cpf = ""; anoNasc = 0;
 }

 // metodo construtor com 1 parametro
 public Pessoa1(String no){
	nome = no; cpf = ""; anoNasc = 0;
 }

  public Pessoa1(String no, int a){
	nome = no; cpf = ""; anoNasc = 0;
 }

   public Pessoa1(String no, String c){
	nome = no; cpf = ""; anoNasc = 0;
 }

 // metodo construtor com 3 parametros
 public Pessoa1(String no, String c, int a){
	nome = no; cpf = c; anoNasc = a;
 }
 
// todos os metodos construtores acima são validos

 public void imprimirDados(){
	 System.out.println("Nome: " + nome);
	 System.out.println("CPF: " + cpf);
	 System.out.println("Ano: " + anoNasc);
	 
 }	  
}// fim da classe
