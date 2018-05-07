def ordem4():
    vector = []
    y = []
    count = 0
    for el in range(1,17):
        x = int(input("Digite um numero: "))
        y.append(x)
        if el % 4 == 0:
            vector.append(y)
            y = []
    average = 0
    for i in vector:
        for a in i:
            average += a
    print(vector)
    print("Average: {}".format(average/16))
    diagonal(vector)
def diagonal(vector):
    x = 0
    summ = 0
    for el in range(0,len(vector)):
        for i in range(0,len(vector[0])):
            if i == el:
                print(vector[i][el])
                summ += vector[i][el]
    print(summ)

def matriz_5x5():
    matriz = []
    line = []
    for el in range(1,26):
        x = int(input("Digite o elemento da matriz: "))
        line.append(x)
        if el % 5 == 0:
            matriz.append(line)
            line = []
    row4 = 0
    col2 = 0
    all_in = 0
    sumdia = 0
    dia = 4
    for i in range(len(matriz[0])):
        print(matriz[i])
        row4 += matriz[3][i]
        col2 += matriz[i][1]
        all_in += sum(matriz[i])
        sumdia += matriz[i][dia]
        dia -= 1
    print("A soma da linha 4 é",row4)
    print("A soma da coluna 2 é",col2)
    print("A soma da diagonal secundária é",sumdia)
    print("A soma de todos os elementos é", all_in)

def gemeo():
    a = int(input("Digite o primeiro valor: "))
    b = int(input("Digite o segundo valor: "))
    for el in range(a, b+1):
        primo1 = primo(el)
        primo2 = primo(el + 2)
        if primo1 == True and primo2 == True and el + 2 <= b:
            print(el, el+2)
def primo(x):
    div = 0
    cont = 1
    while cont <= x:
        if x % cont == 0:
            div += 1
        cont += 1
    if div == 2:
        return True
    else:
        return False
#matriz_5x5()
