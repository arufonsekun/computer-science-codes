class Dicionario{
	private Variavel v[];

	public Dicionario(){
		v = new Variavel[32];
	}

	public Variavel search(String n){
		for (Variavel c : v){
			if (c == null) return c;
			else if ((c.getNome()).equals(n)){
				return c;
			}
		}
		return null;
	}

	public void setVariavel(Variavel var){
		this.v[Variavel.i] = var;
	}
	public Variavel[] getVariavel(){
		return this.v;
	}
}
