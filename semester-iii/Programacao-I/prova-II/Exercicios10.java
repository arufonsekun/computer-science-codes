interface Rastreador {

}

interface Rastreador2 {

}

class Animal implements Rastreador, Rastreador2{
	private int b;
}

class Main {
	public static void main(String[] args) {
		Rastreador b = new Animal();
		System.out.println(b instanceof Rastreador2);
	}
}
