class Compra {
    private String nomeProduto;
    private float preço;
    private int quantidade;

    public Compra(String produto, float preço, int quantidade) {
        this.quantidade = quantidade;
        this.nomeProduto = produto;
        this.preço = preço;
    }
    public void setNomeProduto(String novo) {
        this.nomeProduto = novo;
    }
    public String getNomeProduto() {
        return this.nomeProduto;
    }
    public void setPreço(float preço) {
        this.preço = preço;
    }
    public float getPreço() {
        return this.preço;
    }
    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }
    public int getQuantidade() {
        return this.quantidade;
    }
    // Imprime todas as propriedades da classe
    public void imprimeResumo() {
        System.out.println("Nome : "+this.nomeProduto);
        System.out.println("Quantidade : "+this.quantidade);
        System.out.println("Preço total R$: "+(this.preço) * this.quantidade);
    }
}
