interface Num {
    public int num();
}

abstract class Avo implements Num {
    public int num() { return 1; }
    abstract public int outro();
}

class Pai extends Avo {
    public int num() { return 2; }
    public int outro() {return -2;}
}

class Filho extends Pai {
    public int num() {return 3;}
    public int outro() {return -3;}
}

class Parente extends Avo {
    public int outro() {return -4;}
}
