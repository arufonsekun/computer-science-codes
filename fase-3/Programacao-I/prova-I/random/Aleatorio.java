import java.util.Random;

class Aleatorio {
    private Random rand;

    public Aleatorio() {
        this.rand = new Random();
    }

    public void getInt(int min, int max) {
        System.out.println(this.rand.nextInt((max - min) + 1) + min);
    }
}
