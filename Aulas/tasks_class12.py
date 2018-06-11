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
    Exercicio  ler matrícula e notas de cinso alunos e
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
calculaMedia(lerAlunos())
