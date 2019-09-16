class Main{
	public static void main(String[] args){
		Dicionario aurelio = new Dicionario();
		Variavel v = new Variavel();
		v.setNome("Miaau");
		v.setValor(2.545);

		aurelio.setVariavel(v);

		Variavel query = aurelio.search("Miaau");

		if (query == null){
			System.out.println("N achei merda nenhuma");
		}
		else{
			System.out.println("Var name: "+query.getNome() + " "+" value: "+query.getValor());
		}

	}
}
