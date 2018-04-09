def fibonacci():
    x = int(input("Digite a quantidade de elementos da sequencia: "))
    a = 0
    b = 0
    c = 1
    if x == 1:
        print (a , end = ", ")
    else:
        print(a, end = ' ')
        a+=1
        for el in range(1,x):
            print (a, end = " ")
            a += b
            b = c
            c = a

def tabuleti():
    x = 0
    count = 0
    for el in range(64):
        count += 1
        print (2**el)
        x +=  2**el
    print("Os grãos do tabuleiro são", x)
    print(count)

def multiSum():
    x = int(input('Digite um numero: '))
    y = int(input('Digite outro numero: '))
    soma = 0
    for el in range(0,x):
        print ('Estão sendo soma')
        soma += y
    print('{} X {} = {}'.format(x,y,soma))

def matrix():
    x = int(input("Digite a ordem ad matriz: "))
    for i in range(x):
        for e in range(x):
            if e == i:
                print (1, end=" ")
            else:
                print (0, end=" ")
        print()


def matrix2():
    x = int(input("Digite a ordem ad matriz: "))
    i = 1
    e = 1
    while i < x:
        while e < x:
            print (e, end=" ")
            e += 1
        print()
        i += 1
        e = 1
            
