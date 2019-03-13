class Main{
    public static void main(String args[]){
      Data a, b;
      a = new Data();
      b = new Data();

      a.setDia(23);
      a.setMes(3);

      b.setDia(20);
      b.setMes(6);

      System.out.println("Dia: "+a.getDia() + " " + "Mes: "+a.getMes());

      Person m;
      m = new Person();
      m.age = 18;
      m.birth = b;
      m.height = 1.78f;

      System.out.println("Age: "+m.age+ " " + " Birth: "+m.birth.getDia()+" Day: "+m.birth.getMes() + " Height: " + m.height);
    }
}
