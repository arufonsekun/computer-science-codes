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

def paresImpares():
    num = int(input("Digite um numero: "))
    par = 0
    odd = 0
    while num != 0:
        if num % 2 == 0:par += 1
        else: odd += 1
        num = int(input("Digite um numero: "))
    print ("O n° de pares é {0} e impares é {1}".format(par, odd))

#senha()
#mediaNotas()
#soma()
paresImpares()
