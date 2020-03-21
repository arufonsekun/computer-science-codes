class Main {

    public static void main(String[] args) {
    /*
        Exercicios 1 e 2
        Elemento a = new Elemento();
        Elemento b = new Elemento();
        Combativel c = new Cavaleiro();
        Combativel d = new Arqueiro();
        Combativel e = new Bombeiro();

        a.serial = 20;
        a.nivel = 1;
        int[] s = a.serializa();
        b.deserializa(s);

        Cavaleiro f = (Cavaleiro) c;
        f.cavalga();

        System.out.println("Nivel: "+b.nivel+" Serial: "+b.serial);
        System.out.println("Cavaleiro: "+b.podeCombater(c));
        System.out.println("Arqueiro: "+b.podeCombater(d));
        System.out.println("Bombeiro: "+b.podeCombater(e));

        Aplicacao a = new Aplicacao();

        Entidade[] e = new Entidade[5];

        e[0] = new Cavaleiro();
        e[1] = new Arqueiro();
        e[2] = new Bombeiro();
        e[3] = new Trabalhador();
        e[4] = new Construcao();

        int i = 1;
        for (Entidade ent : e) {
            ent.x = e[i-1].y + 17;
            ent.y = e[i-1].x + 11;
            i++;
        }

        a.processa(e, 15, 40);

        i = 0;
        for (Entidade ent : e) {
            System.out.println(ent +" x: "+ ent.x+ " y: "+ent.y);
        }
    */

    /*Exercicio 6
        Linha a, b, c, d, e;
        a = new Linha(); a.id = 1; a.tempo = 10; a.prioridade = 11;
        b = new Linha(); b.id = 2; b.tempo = 20; b.prioridade = 22;
        c = new Linha(); c.id = 1; c.tempo = 30; c.prioridade = 33;
        e = (Linha) b.clona();
        System.out.println( a.igual(b) ); // Imprime false
        System.out.println( a.igual(c) ); // Imprime true
        System.out.println( e.igual(a) ); // Imprime false
        System.out.println( e.igual(b) ); // Imprime true
        System.out.println( e == b ); // Imprime false
        System.out.println( e.id + " " + e.tempo); // Imprime 2 20
    */

    /*Exercicio 7
        Num n[] = new Num[3];
        Avo a[] = new Avo[3];
        n[0] = new Filho(); a[0] = new Filho();
        n[1] = new Pai(); a[1] = new Pai();
        n[2] = new Parente(); a[2] = new Parente();
        System.out.println("n num = " + (n[0].num() + n[1].num() + n[2].num()));
        System.out.println("a num = " + (a[0].num() + a[1].num() + a[2].num()));
        System.out.println("a outro= " + (a[0].outro() + a[1].outro() + a[2].outro()));
    */

	/*Exercicio 8*/

	Inimigo[] ini = new Inimigo[10];
	/* Upcasting */
	ini[0] = new Batedor();
	ini[1] = new Armeiro();
	ini[2] = new BatedorRapido();
	ini[3] = new Batedor();
	ini[4] = new Armeiro();
	ini[5] = new BatedorRapido();
	ini[6] = new Batedor();
	ini[7] = new Armeiro();
	ini[8] = new BatedorRapido();
	ini[9] = new BatedorRapido();

	Inimigo base = new BatedorRapido();

	for (Inimigo i : ini) {
		if (i instanceof BatedorRapido && base instanceof BatedorRapido) {
			/* Downcasting */
			BatedorRapido br = (BatedorRapido) i;
			br.reporta();
			br.olhadinha();
		}
		else if (i instanceof Batedor && base instanceof Batedor) {
			Batedor b = (Batedor) i;
			b.reporta();
		}

		 else {
			 Armeiro a = (Armeiro) i;
			 a.engatilha();
		 }
		 i.ataca();
	     i.defende();
	     i.voa();
	     i.pousa();
	     i.corre();
	     i.pula();
	     i.nada();
	     i.mergulha();
	}


    /*Exercicio 9

    BatedorRapido br = new BatedorRapido();
    Ferreiro f = new Ferreiro();
    Prefeito p = new Prefeito();
    Inimigo i; NPC npc; Batedor b; Corredor c; Nadador n;

    i = br;
    c = f;

    if (i instanceof BatedorRapido) {
        System.out.println("Miau");
        b = i;
    }

    npc = i;
    c = p;
    n = new Inimigo();
    Armeiro a = (Armeiro) n;

    }
	*/
	}
}
