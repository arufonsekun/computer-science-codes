class Data2{
    public int day;
    public int month;
    public int test;

    public Data2(int d, int m){
        this.day   = d;
        this.month = m;
    }

    public void print(){
        System.out.println(day+" "+  month);
    }

    public double average(){
      double average = (this.day + this.month)/2;
      return average;
    }

    public void set(int b){
      this.test = b;
    }
}
