interface Voador {
    public void voa();
    public void pousa();
}
interface Corredor {
    public void corre();
    public void pula();
}
interface Nadador {
    public void nada();
    public void mergulha();
}
class Inimigo implements Voador, Corredor, Nadador {
    public void ataca() {System.out.println("Ataca"); }
    public void defende() { System.out.println("Defende");}
    public void voa() { System.out.println("Voa");}
    public void pousa(){ System.out.println("Pousa");}
    public void corre() { System.out.println("Corre");}
    public void pula() { System.out.println("Pula");}
    public void nada() { System.out.println("Nada");}
    public void mergulha() { System.out.println("Mergulha");}
}

class NPC implements Corredor {
    public int fala() { return 0; }
    public void corre() { System.out.println("Corre");}
    public void pula() { System.out.println("Pula");}
}

class Batedor extends Inimigo {
    public void reporta(){System.out.println("reporta");}
}

class BatedorRapido extends Batedor {
    public void olhadinha(){System.out.println("Olha");}
}

class Armeiro extends Inimigo {
    public void engatilha(){System.out.println("Engatilha");}
}

class Auxiliar extends NPC {
    public void ajuda(){}
}

class Ferreiro extends NPC {
    public void forja(){}
}

class Prefeito implements Corredor, Nadador {

    public void manda() { }
    public void corre() { System.out.println("Corre");}
    public void pula() { System.out.println("Pula");}
    public void nada() { System.out.println("Nada");}
    public void mergulha() {System.out.println("Mergulha"); }

}
