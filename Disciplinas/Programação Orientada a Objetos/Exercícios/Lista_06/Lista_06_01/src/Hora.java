public class Hora {
    private byte hora;
    private byte minuto;
    private byte segundo;

    public Hora(byte hora, byte minuto, byte segundo) {
        this.hora = hora;
        this.minuto = minuto;
        this.segundo = segundo;
    }

    public boolean eIgual(Hora estaHora) {
        boolean igual;

        if(this.hora == estaHora.hora && this.minuto == estaHora.minuto && this.segundo == estaHora.segundo) {
            igual = true;
        } else {
            igual = false;
        }
        return igual;
    }

    public String toString() {
        return this.hora + "h " + this.minuto + "min " + this.segundo + "s";
    }
}
