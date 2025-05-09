public class Data {
    private byte dia;
    private byte mes;
    private short ano;

    public Data(byte dia, byte mes, short ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public boolean eIgual(Data estaData) {
        boolean igual;

        if(this.dia == estaData.dia && this.mes == estaData.mes && this.ano == estaData.ano) {
            igual = true;
        } else {
            igual = false;
        }
        return igual;
    }

    public String toString() {
        return this.dia + "/" + this.mes + "/" + this.ano;
    }
}
