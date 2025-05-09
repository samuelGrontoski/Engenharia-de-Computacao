public class UsaDataHora {
    public static void main(String[] args) {
        DataHora hoje = new DataHora((byte)3, (byte) 2, (byte) 1, (byte) 10, (byte) 5, (short) 2023);
        DataHora ontem = new DataHora((byte)1, (byte) 2, (byte) 3, (byte) 9, (byte) 5, (short) 2023);
        DataHora amanha = new DataHora((byte)4, (byte) 5, (byte) 6, (byte) 11, (byte) 5, (short) 2023);
        DataHora qualquer = new DataHora((byte)3, (byte) 2, (byte) 1, (byte) 10, (byte) 5, (short) 2023);

        System.out.println("Hoje - " + hoje.toString());
        System.out.println("Ontem - " + ontem.toString());
        System.out.println("Amanha - " + amanha.toString());
        System.out.println("Qualquer - " + qualquer.toString());

        System.out.println("A data e hora de hoje e igual a de ontem? " + ontem.eIgual(hoje));
        System.out.println("A data e hora de hoje e igual a de uma data qualquer? " + hoje.eIgual(qualquer));
        System.out.println("A data e hora de ontem e igual a de amanha? " + ontem.eIgual(amanha));
    }
}
