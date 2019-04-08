class Variavel{
	public static int i = 0;
	private String nome;
	private double valor;

	public void Variavel(){
		Variavel.i++;
	}

	public void setNome(String n){
		this.nome = n;
	}
	public String getNome(){
		return this.nome;
	}

	public void setValor(double v){
		this.valor = v;
	}
	public double getValor(){
		return this.valor;
	}
}
