
/*
 * Lembre:
 *  - A classe que implementa uma interface precisa obrigatoriamente
 *    sobrescrever os métodos definidos pela interface.
 *  -
 */

class Unidade extends Entidade implements Movel, Atualizavel {

    public void atacar() { }
    public float distanciaBase() { return 0;}
    public boolean estahMorta(){
        return false;
    }
    public void posiciona(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public void moveX(int q) {
        this.x = q;
    }
    public void moveY(int q) {
        this.y = q;
    }
    public void atualiza() { }

}

class Construcao extends Entidade implements Atualizavel {

    public void produzir() { }
    public void posiciona(int x, int y) { }
    public void atualiza() { }

}

class Infantaria extends Unidade implements Combativel {
    public void caminha() { }
    public boolean podeCombater(Combativel c) { return false; }
}

class Trabalhador extends Unidade {

    public void executaTarefa() { }

}

class Arqueiro extends Infantaria {

    public void atiraFlecha() { }

}

class Cavaleiro extends Infantaria {

    public void cavalga() { System.out.println("Cavalgando..."); }

}

class Bombeiro extends Infantaria {

    public void explode() { }

}

class Ferraria extends Construcao {

    public void carrega() { }

}

class Quartel extends Construcao {

    public void treina() { }

}

class Aplicacao {

    public void processa(Entidade[] e, int dx, int dy) {

        for (Entidade ent : e) {

            if (ent instanceof Construcao) {
                Construcao con = (Construcao) ent;
                con.produzir();
                con.atualiza();

            } else if (ent instanceof Unidade) {
                Unidade uni = (Unidade) ent;
                if (uni.estahMorta()) {
                    uni.posiciona(0, 0);
                } else {
                    uni.moveX(dx);
                    uni.moveY(dy);
                }
                uni.atualiza();
            }
        }

    }

}
