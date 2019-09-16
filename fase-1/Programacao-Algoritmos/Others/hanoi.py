from time import sleep

class Disco:

    def __init__(self, tamanho):
        self.tamanho = tamanho

    def __repr__(self):
        return str(self.tamanho)



class Pino:
    def __init__(self, n_discos=0):
        if n_discos > 0:
            self.discos = [Disco(t) for t in range(1, n_discos+1)]
        else:
            self.discos = []
        self.discos.reverse()
        #discos = ex:[6,5,4,3,2,1]

    def getMenorDisco(self):
        return self.discos[-1] if len(self.discos) > 0 else None

    def appendDisco(self, disco):
        self.discos.append(disco)

    def popDisco(self):
        return self.discos.pop()

    def podeReceberDisco(self, disco):
        menor = self.getMenorDisco()
        if menor is None or disco.tamanho < menor.tamanho:
            return True
        return False

class Jogo:

    def __init__(self, n_discos):
        self.n_discos = n_discos
        self.pinos = [Pino(n_discos), Pino(), Pino()]

    def printTab(self):
        print("")
        for d in reversed(range(self.n_discos)):
            print("\t{0}\t{1}\t{2}".format(
                "-" if len(self.pinos[0].discos)-1 < d else self.pinos[0].discos[d],
                "-" if len(self.pinos[1].discos)-1 < d else self.pinos[1].discos[d],
                "-" if len(self.pinos[2].discos)-1 < d else self.pinos[2].discos[d]
                ))
        print("\t" + "*"*17 + "\nPinos \t1\t2\t3\n")

    def mover(self, pino1, pino2):
        self.pinos[pino2].appendDisco(self.pinos[pino1].popDisco())

    def houveVitoria(self):
        if len(self.pinos[1].discos) == self.n_discos or\
           len(self.pinos[2].discos) == self.n_discos:
            return True
        return False

def jogar():
    while True:
        n_discos = int(input("Número de discos(3 - 8): "))
        if 3 <= n_discos <= 8:
            break
        print("\nNúmero de discos inválido.\n")

    jogo = Jogo(n_discos)

    mov = 0

    while True:

        jogo.printTab()

        while True:
            pino1 = int(input("Mover do pino: "))
            pino2 = int(input("Para o pino: "))
            if 1 <= pino1 <= 3 and 1 <= pino2 <= 3 and pino1 != pino2:
                pino1 -= 1
                pino2 -= 1
                menor_disco = jogo.pinos[pino1].getMenorDisco()
                if menor_disco:
                    pode_receber = jogo.pinos[pino2].podeReceberDisco(menor_disco)
                    if pode_receber:
                        jogo.mover(pino1, pino2)
                        break
            print("\nJogada inválida.\n")

        mov += 1

        if jogo.houveVitoria():
            jogo.printTab()
            print("\nParabéns, você venceu!")
            print("Número de movimentos: {}\n".format(mov))
            break

print("\nBem vindo ao Torre de Hanói!\n")

jogar()

while True:
    de_novo = input("Quer jogar de novo? (Enter para sair) ")
    if de_novo == "" or de_novo.isspace(): break
    jogar()

print("\nObrigado por jogar Torre de Hanói!")
sleep(1)
exit()
