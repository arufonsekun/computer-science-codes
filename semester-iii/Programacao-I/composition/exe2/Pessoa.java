class Pessoa{
	private int id;
	private Data birth;

	public Pessoa(){
		this.birth = new Data();
	}

	public void setId(int d){
		this.id = d;
	}
	public int getId(){
		return this.id;
	}
	public void setBirth(Data d){
		this.birth = d;
	}
	public Data getBirth(){
		return this.birth;
	}
}
