order = int(input("Digite a ordem da matrix: "))
matriz = []
row = []
for el in range(order**2):
    element = int(input("Digite os elementos: "))
    row.append(element)
    if len(row) == order:
        matriz.append(row)
        row = []
def imprime_matriz(matriz):
    for i in range(len(matriz)):
        for j in range(len(matriz)):
            print(matriz[i][j], end=" ")
        print('\n')
imprime_matriz(matriz)
