class Main {
    public static void main(String[] args){
        Math a = new Math();
        try {
            System.out.println(a.multiplica(-5, 4));
            System.out.println(a.multiplica(-5, 4));
        } catch(MyException e) {
            System.out.println(e);
        }
    }
}
