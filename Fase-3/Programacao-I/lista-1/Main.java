import java.util.Scanner;
class Main{
    public static void main(String[] args){
        //BlurayDisc c;
        // BlurayDisc h ;
        // h = new BlurayDisc("Teste", 1);
        // String st = "teste";
        // float num;
        //c.dados[10] = "i";
        //h.setIdentificação(st, num);


        /*Exercicio 2*/
        //Compra p = new Compra("Desodorante", 13.50f, 4);
        //p.imprimeResumo();

        /*Exercicio 3*/

        /*Exercicio 4*/

        /*Exercicio 5*/
        Scanner s = new Scanner(System.in);
        Autor a = new Autor();
        Post p = new Post();

        String nome = s.nextLine();
        int id = s.nextInt();
        a.setNome(nome);
        a.setId(id);

        String texto = s.nextLine();
        p.setAutor(a);
        p.setTexto(texto);

        p.imprimeResumo();
    }
}
