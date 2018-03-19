import math
    c = 8
class Numero(object):
    def __init__(self):
         self.x = int(input("Digite um numero: "))
    def quadrado(self):
        print("o quadrado eh ",self.x ** 2)
    def raiz(self):
        print("A raiz eh ",math.sqrt(self.x))

def exercicio():
    a = 3
    b = 4
    c = 8
    print (c > a*b and c <= 8)
    print (a != c or b >= 5)
    print (a == 3 or b < 2 and c == 8)
    print (a < b and not b <= 4 or c == a + b)
    print (a < c and b > a and c != b)

exercicio()
