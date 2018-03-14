import math
def mediaFinal(np, nt):
    print("Sua media eh", int(np)*0.7 + int(nt)*0.3)
#mediaFinal(input("Digite sua nota da prova: "), input("Digite sua nota do trab: "))

#Resolve baskara
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
#segundoGrau()

#Exercicio 1 produro de 28 por 43
def soma():
    print ("O produto eh", 28 * 43)

#Exercicio 2
def soma_numeros():
    x = int(input("Digite o 1º numero: "))
    y = int(input("Digite o 2º numero: "))
    print ("A soma eh ", x+y)

#Exercicio 3
def sucessor_antecessor():
    x = int(input("Digite um numero: "))
    print ("Seu antecessor eh", x-1, " e seu sucessor eh ", x+1)

#Exercicio 4
def minutos():
    x = int(input("Digite a hora: "))
    print("Os minutos que se passaram sao ", x*60)

def conversao():
    velocidade = int(input("Digite a velocidade em km/h: "))
    print("A velocidade eh ", velocidade, "km/h e ", (velocidade/3.6), "m/s")

def salario():
    salario = int(input("DIgite seu salario bruto: "))
    salario = salario - (salario*0.1)
    salario = salario - (salario*0.05)
    print ("Seu salario liquido eh R$ %s0 " % salario)

def fatorial(x,fat):
    if x == 1:
        print ("O fatorial eh %i" % fat)
    else:
        fatorial(x - 1, fat * x)

#soma()
#soma_numeros()
#sucessor_antecessor()
#minutos()
#conversao()
#salario()
#fatorial(5,1)
