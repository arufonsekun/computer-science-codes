class Main{
<<<<<<< HEAD
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
    public static void main(String[] args){
        Retangle r = new Retangle();
        r.setHeight(3.14);
        r.setBase(5.6);
        r.setAge(12);

        System.out.println("Altura "+r.getHeight());
        System.out.println("Base "+r.getBase());
        System.out.println("Idade "+r.getAge());
    }
}
