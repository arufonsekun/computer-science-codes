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

ordem4()
