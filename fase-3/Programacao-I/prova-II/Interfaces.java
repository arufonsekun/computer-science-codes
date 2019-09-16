abstract class Entidade {
    public int x, y;
    //public abstract void posiciona(int x, int y);
}

interface Movel {
    public void moveX(int q);
    public void moveY(int q);
}

interface Atualizavel {
    public void atualiza();
}

interface Serializavel {
    public int[] serializa();
    public void deserializa(int[] q);
}

interface Combativel {
    public boolean podeCombater(Combativel c);
}
