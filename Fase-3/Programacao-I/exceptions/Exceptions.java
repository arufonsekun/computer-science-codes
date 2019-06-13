class EGeral extends Exception {}
class EMovimento extends EGeral {}
class ERecurso extends EGeral {}
class ECaminho extends EMovimento {}

class Main {
    public static void main(String[] args) {
        try {
            int j = -2;
            try {
                analisa(j);
            }

            catch(ERecurso a) { System.out.println("Recurso!"); }
			catch(EMovimento a) { System.out.println("Move!"); }
            catch(ECaminho a) { System.out.println("Caminho!"); }
            catch(EGeral a) { System.out.println("Geral!"); }
            finally { j = 9; }
            analisa(j);
        }
        catch(ECaminho a) { System.out.println("Caminho!"); }
        catch(EMovimento a) { System.out.println("Move!"); }
        catch(ERecurso a) { System.out.println("Recurso!"); }
        catch(Exception a) { System.out.println("Excecao!"); }
    }

    static void analisa(int i) throws EGeral {
        if(i < 0) { throw new ECaminho(); }
        if(i == 0) { throw new ERecurso(); }
        if(i == 9) { throw new EGeral(); }
    }
}
