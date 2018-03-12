import math
def mediaFinal(np, nt):
    print("Sua media eh", int(np)*0.7 + int(nt)*0.3)
#mediaFinal(input("Digite sua nota da prova: "), input("Digite sua nota do trab: "))

def segundoGrau():
    a = int(input('a: '))
    b = int(input('b: '))
    c = int(input('c: '))
    try:
        delta =  (b ** 2) - (4 * a * c)
        raiz1 = ((-1 * b) + math.sqrt(delta)) / (2 * a)
        raiz2  = (-1 * b - math.sqrt(delta)) / (2 * a)
        print("As raizaes sao",raiz1, raiz2)
    except ValueError:
        print ("A raiz eh negativa: ",delta)
segundoGrau()
