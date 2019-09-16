class Autor{
    private String nome;
    private int id;
    
    public void Autor(String n, int i){
        this.setId(i);
        this.setNome(n);
    }

    private void setId(int id){
        this.id = id;
    }

    private void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return this.nome;
    }

    public int getId(){
        return this.id;
    }
}
