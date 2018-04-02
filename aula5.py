def mediaNotas():
    count = 1
    while count <= 10:
        n1 = int(input("Digite sua nota 1: "))
        n2 = int(input("Digite sua nota 2: "))
        media = (n1 + n2)/2
        if (media >= 6): print ("Aprovado")
        else: print ("Reprovado")
        count += 1
def senha():
    senha = "python"
    x = input("Digite a password: ")
    while x != senha:
        if x != senha:
            print("Errou")
        x = input("Digite a password: ")

    print ("Acerto")

def soma():
    soma = 0
    count = 1
    while count <= 100:
        soma += 1 / count
        count += 1
    print (soma)
#Exercício 1
def paresImpares():
    num = int(input("Digite um numero: "))
    par = 0
    odd = 0
    while num != 0:
        if num % 2 == 0:par += num
        else: odd += num
        num = int(input("Digite um numero: "))
    print ("A soma dos pares é {0} e impares é {1}".format(par, odd))
#Exercício 2
def antecessor_sucessor():
    num = int()
    count = 0
    while count < 10:
        num = int(input("Digite um numero:"))
        print("O antecessor é {0} e o sucessor é {1}".format(num - 1, num + 1))
        count += 1
#Exercício 3
def reinventar_a_roda():
  n1 = int(input("Digite o divisor: "))
  n2 = int(input("Digite o divisor: "))
  count = int()
  num = n1
  while num >= n2:
    num -= n2
    count += 1
  print ("{0} / {1} = {2}, o resto é {3}".format(n1, n2, count, num))

#Exercicio 4
def soma():
  count = 0
  soma = int()
  while count <= 10:
    soma += count
    count += 1
  print("A soma é {0}".format(soma))
soma()

#Exercicio 5
def salario():
  menor = 9999999999
  maior = 0
  media = 0
  count = 0
  nomes = []
  salarios = []
  while count <= 5:
    x = input("Digite seu nome: ")
    y = int(input("Digite seu salario: "))
    media += y
    nomes.append(x)
    salarios.append(y)
    count += 1
    if y > maior:
      maior = y
    if y < menor:
      menor = y
  print("A media dos salarios é",media/5)
  print("O maior salario é {0} e pertence à {1}".format(maior, nomes[salarios.index(maior)]))
  print("O menor salario é {1} pertence à {0}".format(nomes[salarios.index(menor)], menor))

#Exercicio 6
def fatorial():
  x = int(input("Digite um numero: "))
  fat = int(1)
  while x > 0:
    fat *= x
    x -= 1
  print("O fatorial é",fat)

#Exercicio 7
def tabuada():
  x = int(input("Digite um numero: "))
  count = 1
  while count <= 10:
    print("{0} X {1} = {2}".format(x, count, x*count))
    count += 1

#Exercicio 8
def fibonacci():
  termo = int(input("Digite o a posição do termo: "))
  primeiro = 0
  proximo = 1
  valor = 1
  count = 1
  if termo == 0:
      print(primeiro)
  else:
    count += 1
    print(primeiro)
    while count <= termo:
        print (valor)
        valor += primeiro
        primeiro = proximo
        proximo = valor
        count += 1

#Exercicio 11
def primo():
  x = int(input("Digite um numero: "))
  count = 1
  divInt = 0
  while count <= x:
    if x % count == 0:
      divInt += 1
    else:
      pass
    count += 1
  if divInt == 2:print("É primo")
  else:print("Não é primo")

def greetings():
    while 1:
        print("1- Boas vindas a CC \n 2- Primeiro programa \n 3- Condições ")
        print("4- Repetições \n 0- Sair do programa")
        x = input("Digite sua entrada: ")
        if x == '1': print ("Seja bem-vindo ao curso de Ciência da Computação")
        if x == '2': print ("Alô Mundo em Python")
        if x == '3': print ("IF, ELIF, ELSE")
        if x == '4': print ("WHILE, FOR")
        if x == '0': exit()
        else: print("Entrada inválida")

#fatorial()
#salario()
#reinventar_a_roda()
#senha()
#mediaNotas()
#soma()
#paresImpares()
greetings()
