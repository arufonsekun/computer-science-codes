class Linha implements Comparavel, Clonavel {

    public int id;
    public int tempo;
    public int prioridade;

    public boolean igual(Comparavel c) {
        if (c instanceof Linha) {
            Linha l = (Linha) c;
            if (this.id == l.id){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    public Clonavel clona() {
        Linha copia = new Linha();
        copia.id = this.id;
        copia.tempo = this.tempo;
        copia.prioridade = this.prioridade;
        return copia;
    }

}
