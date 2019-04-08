class Evento{
	private int id;
	private Data encontros[];

	public void Evento(){
	}

	public void setId(int i){
		this.id = i;
	}
	public int getId(){
		return this.id;
	}

	public void setEncontro(){
		this.encontros = new Data[20];
		for (int i = 0; i < encontros.length; i++){
			this.encontros[i] = new Data();
		}
	}
	public Data getEncontro(int n){
		return this.encontros[n];
	}
}
