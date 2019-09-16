class Math {
    public int soma(int a, int b) throws MyException{
        if (a < 0 || b < 0){
            throw new MyException();
        }
        return a + b;
    }
    public int subtrai(int a, int b) throws MyException{
        if (a < 0 || b < 0){
            throw new MyException();
        }
        return a - b;
    }
    public int multiplica(int a, int b) throws MyException{
        if (a < 0 || b < 0){
            throw new MyException();
        }
        return a * b;
    }
    public double divide(int a, int b) throws MyException{
        if (a < 0 || b < 0){
            throw new MyException();
        }
        return a / b;
    }
}
