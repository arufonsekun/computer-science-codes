class Elemento extends Entidade implements Serializavel, Combativel {

    public int serial, nivel;

    public void posiciona(int x, int y) {

    }

    public int[] serializa() {
        int[] serialized = new int[2];
        serialized[0] = this.serial;
        serialized[1] = this.nivel;

        return serialized;
    }

    public void deserializa(int[] v) {

        this.serial = v[0];
        this.nivel = v[1];

    }

    public boolean podeCombater(Combativel c) {
        if (c instanceof Arqueiro || c instanceof Cavaleiro) {
            return true;
        } else {
            return false;
        }
    }

}
