import java.util.Scanner;
class Main2{

    public static void main(String[] args){
        float n;
        Scanner input = new Scanner(System.in);
        //exeDouble(input);
        //exeData(input);
        // exeString(input);
        //exeBackwards(input);
        Data2 d = new Data2(1,4);

    }

    static public void exeData(Scanner input){
      System.out.println("Digite o dia: ");
      int a = input.nextInt();
      System.out.println("Digite o mes: ");
      int b = input.nextInt();

      Data2 d = new Data2(a, b);
      d.print();
      System.out.println("A media é "+d.average());
    }

    static public void exeDouble(Scanner input){
      String a, b, c ;
      a = input.nextLine();
      b = input.nextLine();
      c = input.nextLine();

      double out = Double.parseDouble(a) + Double.parseDouble(b) + Double.parseDouble(c);

      System.out.println("A media é "+(out/2));
    }

    static public void exeString(Scanner input){
      String a = input.nextLine();
      System.out.println(Character.toString(a.charAt(4))+ Character.toString(a.charAt(5)));
    }

    static public void exeBackwards(Scanner input){
      String miau = input.nextLine();

      for (int i = miau.length() -1; i >= 0; i--){
        System.out.print(miau.charAt(i));
      }
      System.out.println();

    }
}
