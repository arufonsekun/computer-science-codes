import csv
"""
    Primeiro exercicio da lista de Estruturas
    O objetivo do algoritmo é ler 5 datas e retornar a
    mais velha e a mais nova
"""
class Data:
    ano = 0
    mes = str()
    dia = str()

def ler_datas():
    datas = []
    for i in range(5):
        data = Data()
        data.dia = input("Digite o dia: ")
        data.mes = input("Digite o mes: ")
        data.ano = int(input("Digite o ano: "))
        datas.append(data)
    return datas

def menor(datas):
    maior = Data()
    for el in range(0,len(datas)):
        if datas[el].ano > maior.ano:
            maior = datas[el]
        if datas[el].ano == maior.ano and datas[el].mes > maior.mes:
            maior = datas[el]
        if datas[el].ano == maior.ano and datas[el].mes == maior.mes:
            if datas[el].dia > maior.dia:
                maior = datas[el]
    menor = maior
    for ele in range(0,len(datas)):
        if datas[ele].ano < menor.ano:
            menor = datas[ele]
    return (menor, maior)
#datas = ler_datas()
#x,y = menor(datas)
#print('A menor data é {}/{}/{} e a maior é {}/{}/{}'.format(x.dia, x.mes,x.ano,y.dia, y.mes, y.ano))

"""
    Exercicio 2 ler informações de 3 bancas receber um indice
    e mostrar as informações da banca referente aquele indice
"""
class Band(object):
    nome = str()
    estilo = str()
    integ = int()
def ler_banda():
    bandas = []
    for el in range(5):
        band = Band()
        band.nome = input("Digite o nome da banda: ")
        band.estilo = input("Digite o estilo da banda: ")
        band.integ = int(input("Digite o nº de integrantes: "))
        bandas.append(band)
    return bandas
def mostra_banda(bandas):
    index = int(input("Digite o indice da banda: "))
    print("Nome: {}".format(bandas[index-1].nome))
    print("Estilo: {}".format(bandas[index-1].estilo))
    print("Integrantes: {}".format(bandas[index-1].integ))
#mostra_banda(ler_banda())

"""
    Exercicio 3 ler matrícula e notas de cinco alunos e
    mostrar a media de cada um e a matícula
"""
class Academico(object):
    matricula = str()
    nota1 = int()
    nota2 = int()

def lerAlunos():
    alunos = list()
    for el in range(5):
        aluno = Academico()
        aluno.matricula = input("Digite sua matrícula: ")
        aluno.nota1 = int(input("Digite sua 1º nota: "))
        aluno.nota2 = int(input("Digite sua 2º nota: "))
        alunos.append(aluno)
    return alunos

def calculaMedia(alunos):
    for el in range(0, len(alunos)):
        print ("Media do aluno {} é {:.2f}".format(alunos[el].matricula, ((alunos[el].nota1 + alunos[el].nota2)/2) ))
#calculaMedia(lerAlunos())

"""
    Exercicio 4: achar o estádio com maior capacidade e maior publico record
"""
class Estadio():
    nome = str()
    capacidade = int()
    publico = int()

def maior_capacidade(estadios):
    estadio = 0
    for el in estadios:
        try:
            if el.capacidade > estadio.capacidade:
                estadio = el
        except AttributeError:
            estadio = el
    return estadio

def maior_publico(estadios):
    estadio = 0
    for el in estadios:
        try:
            if el.publico > estadio.publico:
                estadio = el
        except AttributeError:
            estadio = el
    return estadio

def ler_estadio():
    estadios = []
    for e in range(3):
        est = Estadio()
        est.nome = input("Nome do estádio: ")
        est.capacidade = int(input("Digite a capacidade do estadio: "))
        est.publico = int(input("Digite o público recorde: "))
        estadios.append(est)
#print("Estádio com maior capacidade: {}".format(maior_capacidade(estadios).nome))
#print("Estádio com maior publico recorde: {}".format(maior_publico(estadios).nome))

"""
Exercicio 5: Pegar o código base e implementar 3 funções - ler_aluno, imprime_turma, calcula_media
"""

def le_aluno():
    aluno = Aluno()
    aluno.matricula = input("Digite a sua matricula: ")
    notas = input("Digite suas tres notas separadas por espaço: ").split(' ')
    aluno.n1 = float(notas[0])
    aluno.n2 = float(notas[1])
    aluno.n3 = float(notas[2])
    return aluno


def imprime_turma(turma):
    for el in turma:
        print("Matricula: {}, n1 = {}, n2 = {}, n3 = {} ".format(el.matricula, el.n1, el.n2, el.n3))


def calcula_media_aluno(aluno):
    media = (aluno.n1 + aluno.n2 + aluno.n3) / 3
    return media

class Aluno():
    matricula = str()
    n1 = float()
    n2 = float()
    n3 = float()

def main():
    turma = []
    for i in range(5):
        turma.append(le_aluno())#  Funcao que devo impleentar

    imprime_turma(turma)#  Funcao que devo impleentar
    print()
    for i in range(5):
        media = calcula_media_aluno(turma[i])#  Funcao que devo impleentar
        print("Aluno: {} - Media: {:.1f}".format(turma[i].matricula, media))


"""
Exercicio 6: criar uma estrtura nomePessoa ler o nome e mostra ele invertido
"""

class Pessoa():
    nome = str()
    sobrenome = str()

def ler_pessoa():
    pess = Pessoa()
    pess.nome = input("Digite seu nome: ")
    pess.sobrenome = input("Digite seu sobrenome: ")
    print(pess.nome)
    print(pess.sobrenome)
    for i in range(len(pess.nome)-1, -1,-1):
        print(pess.nome[i], end='')
    print()
    for i in range(len(pess.sobrenome)-1, -1,-1):
        print(pess.sobrenome[i],end='')
#ler_pessoa()


"""
Exercicio 7: ler o arquivo vendas.csv e setar os valores para uma estrutura venda e depois mostrar, bem inutil mesmo
"""

class Vendas():
    codCliente = str()
    codProduto = str()
    valor = float()


def estruturar():
    vendas = open('sales.csv', 'r')
    values = csv.reader(vendas)
    lista_vendas = []
    for el in values:
        objeto_venda = Vendas()
        objeto_venda.codCliente = el[0]
        objeto_venda.codProduto = el[1]
        objeto_venda.valor = float(el[2])
        lista_vendas.append(objeto_venda)

    for e in lista_vendas:
        print("Cod. Cliente: {}".format(e.codCliente))
        print("Cod. produto: {}".format(e.codProduto))
        print("Valor da compra: {}".format(e.valor))
        print()
estruturar()