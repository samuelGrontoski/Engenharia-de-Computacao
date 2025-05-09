public class UsaFilaCliente {
    public static void main(String[] args) {
        FilaCliente fila = new FilaCliente();
        Cliente c1 = new Cliente("Galadriel", "Feminino");
        Cliente c2 = new Cliente("Gandalf", "Masculino");
        Cliente c3 = new Cliente("Balrog", "Masculino");
        Cliente c4 = new Cliente("Arwen", "Feminino");
        int i = 1;

        fila.enfileirar(c4);
        fila.enfileirar(c3);
        fila.enfileirar(c1);
        fila.enfileirar(c2);

        System.out.println("Imprimindo a ordem em que os atendimentos foram feitos: ");
        while (!fila.vazia()) {
            System.out.println("Cliente " + i + ": " + fila.desenfileirar());
            i++;
        }
    }
}
