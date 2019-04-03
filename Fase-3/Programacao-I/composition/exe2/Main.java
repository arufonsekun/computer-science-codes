class Main{
	public static void main(String[] args){
		Pessoa p = new Pessoa();
		Data d = new Data();
		d.setDia(20);
		d.setMes(6);
		p.setId(1811100034);
		p.setBirth(d);

		System.out.println(p.getId());
		System.out.println(p.getBirth().getDia());
		System.out.println(p.getBirth().getMes());
	}
}
