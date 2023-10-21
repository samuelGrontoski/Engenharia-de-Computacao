public class UsaPilhaRevista {
    public static void main(String[] args) {
        PilhaRevista pilha = new PilhaRevista();
        
        Revista r1 = new Revista("Programa1", 1, 2021, 10);
        Revista r2 = new Revista("Programa2", 2, 2022, 10);
        Revista r3 = new Revista("Programa3", 3, 2023, 10);

        pilha.empilhar(r1);
        pilha.empilhar(r2);
        pilha.empilhar(r3);

        System.out.println("Tirando resvita do topo da pilha: " + pilha.desempilhar());
        System.out.println("Tirando resvita do topo da pilha: " + pilha.desempilhar());
        System.out.println("Tirando resvita do topo da pilha: " + pilha.desempilhar());

    }
}
