def maior_impar():
    x,y,z = input("Digite 3 numeros: ").split(",")
    x = int(x); y = int(y); z = int(z)
    impar = False
    maior = -9999
    if x % 2 == 0 and y % 2 == 0 and z % 2 == 0:
        impar = False
    else:
        impar = True
    if not impar:
        print("Nenhum numero impar foi informado")
    if x > maior and x % 2 != 0:
        maior = x
    if y > maior and y % 2 != 0:
        maior = y
    if z > maior and z % 2 != 0:
        maior = z
    print ("O numero {0} eh o maior impar".format(maior))

def maior():
    x,y = input("Digite dois numeros: ").split(",")
    x = int(x); y = int(y)
    if x > y: print ("{0} é maior".format(x))
    else: print ("{0}  é maior".format(y))

def shit():
    x,y,z = input("Digite 3 numeros: ").split(",")
    x = int(x); y = int(y); z = int(z)
    if (x + y) > z: print ("A soma de {0} e {1} é maior que {2}".format(x,y,z))
    else: print ("A soma não maior")

def fibonacci(x):
    primeiro = 0
    proximo = 1
    valor = 1
    if x == 0:
        print(primeiro)
    else:
        print(primeiro)
        while valor <= x:
            print (valor)
            valor += primeiro
            primeiro = proximo
            proximo = valor

def shit2():
    x,y = input("Digite dois numeros").split(",")
    x = int(x); y = int(y)
    if x == y: print ("São iguais")
    elif x > y: print ("{0} é maior que {1}".format(x,y))
    else: print("{0} é maior que {1}".format(y,x))
