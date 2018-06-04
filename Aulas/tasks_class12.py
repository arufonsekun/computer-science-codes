class Data:
    ano = 0
    mes = 0
    dia = 0

def ler_datas():
    datas = []
    for i in range(3):
        data = Data()
        data.dia = int(input("Digite o dia: "))
        data.mes = int(input("Digite o mes: "))
        data.ano = int(input("Digite o ano: "))
        datas.append(data)
    return datas

datas = ler_datas()
maior_menor(datas)
