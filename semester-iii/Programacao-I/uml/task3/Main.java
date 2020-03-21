class Main{
	public static void main(String[] args){
		Evento ae = new Evento();
		ae.setId(109);
		ae.setEncontro();
		System.out.println(ae.getId());
		for (int i  = 0; i < 32; i++){
			System.out.println(ae.getEncontro(i).dia);
		}
	}
}
