import math
class Numero(object):
    def __init__(self):
         self.x = int(input("Digite um numero: "))
    def quadrado(self):
        print("o quadrado eh ",self.x ** 2)
    def raiz(self):
        print("A raiz eh ",math.sqrt(self.x))
