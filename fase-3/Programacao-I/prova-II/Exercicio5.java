interface Pausavel {
    public void pausa();
    public void continua();
}

interface Comparavel {
    public boolean igual(Comparavel c);
}

interface Clonavel {
    public Clonavel clona();
}

class App implements Pausavel, Comparavel, Clonavel {
    public void roda() { }
    public void destroi() { }
    public void continua() { }
    public void pausa() { }
    public boolean igual(Comparavel c) { return false;}
    public Clonavel clona() { return new App();}
}

class Processo implements Pausavel {
    public void fork() { }
    public void continua() { }
    public void pausa() { }
}

class Gui extends App { public void mostra(){ } }
class Hud extends Gui { public void atualiza(){ } }
class Mouse extends Gui { public void posiciona(){ } }
class Compacta extends App { public void recebe(){ } }
class Copia extends Compacta { public void copia(){ } }
class Thread extends Processo { public boolean acao(){ return true; } }

class Disco implements Pausavel, Comparavel, Clonavel {
    public void continua() { }
    public void pausa() { }
    public boolean igual(Comparavel c) { return false;}
    public Clonavel clona() { return new Disco(); }
}

class GerenciarApp {
    public Processo init(Clonavel a) {
        //Clonavel[] v = new Clonavel[3];
        Pausavel p = a;
        return new Thread();
    }
}
