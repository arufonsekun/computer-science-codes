#Exercicios da lista de revisão 2
#Exercicio 3
def inverte_lista(vector):
    index = len(vector) -1
    inverse = []
    while index >= 0:
        inverse.append(vector[index])
        print(vector[index], end=" ")
        index -= 1
    print()
    return (inverse)

def primos_lista(vector):
    primes = []
    divisor = 1
    times = 0
    for e in vector:
        while divisor <= e:
            if e % divisor == 0:
                times += 1
            divisor += 1
        if times == 2:
            primes.append(e)
        divisor = 1
        times = 0
    print(primes)

x = list(map(int, input().split(' ')))
primos_lista(inverte_lista(x))

#Exercicio 4: ler matriz 4x3
