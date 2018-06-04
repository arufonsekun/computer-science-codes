class Pessoa(object):
    nome = ""
    idade = 0
    peso = 0
    altura = 0.0

def ler_pessoa():
    pessoas = []
    for el in range(3):
        pes = Pessoa()
        pes.nome = input("Digite seu nome: ")
        pes.idade = int(input("Digite sua idade: "))
        pes.peso = int(input("Digite seu peso: "))
        pes.altura = float(input("Digite sua altura: "))
        pessoas.append(pes)
    achar_velha(pessoas)

def achar_velha(pessoa):
    idade = 0
    obj = None
    for el in pessoa:
        if el.idade > idade:
            obj = el
    print("As informações da pessoa + velha é: ")
    print("Nome", obj.nome)
    print("Idade", obj.idade)
    print("Peso", obj.peso)
    print("Altura", obj.altura)

ler_pessoa()
