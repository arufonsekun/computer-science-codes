def media():
    lista = [5,6,7,8.8,5,6,7.8,9.8,7]
    soma = int()
    for el in lista:
        soma += el
    print('Media com for= {}'.format(soma/len(lista)))
    index = 0
    soma = 0
    while index < len(lista):
        soma += lista[index]
        index += 1
    print('Media com while= {}'.format(soma/index))

def nomes():
    x = []
    for el in range(5):
        nome = input("Digite um nome: ")
        x.append(nome)
    print(sort(x))
nomes()
