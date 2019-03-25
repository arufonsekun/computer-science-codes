class Post{
    private Autor autor;
    private String texto;

    public void setAutor(Autor a){
        this.autor = a;
    }

    public Autor getAutor(){
        return this.autor;
    }

    public void setTexto(String t){
        this.texto = t;
    }

    public String getText(){
        return this.texto;
    }

    public void imprimeResumo(){
        System.out.println("Autor : " + this.autor.getNome());
        System.out.println("Autor cpf: " + this.autor.getId());
        System.out.println("Falou : " + this.texto);
    }

}
