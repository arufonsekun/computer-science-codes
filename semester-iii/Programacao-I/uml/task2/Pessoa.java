class Pessoa{
	private int id;
	private String nome;
	private Data nascimeno;

	public Pessoa(){
	}

	public Pessoa(int i, String n){
		this.id = i;
		this.nome = n;
	}

	public void setId(int i){
		this.id = i;
	}
	public int getId(){
		return this.id;
	}

	public void setNome(String n){
		this.nome = n;
	}
	public String getNome(){
		return this.nome;
	}

}
