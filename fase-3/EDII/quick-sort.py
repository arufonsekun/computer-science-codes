import random
v = list(int (x) for x in input().split())
n = len(v)
#pivo = random.choice(range(0, n))
l = 0; r = n-1

def quickSort(pivo, l , r, turn):
    while l != r:
        if pivo == l: turn = 1
        if pivo == r: turn = 0

        if not turn:#0 means comparison with left and 1 with right
            if v[pivo] < v[l]:
                v[l], v[pivo] = v[pivo], v[l]
                pivo = l
                turn = 1
            else:
                l+=1
        if turn:
            if v[pivo] > v[r]:
                v[r], v[pivo] = v[pivo], v[r]
                pivo = r
                turn = 0
            else:
                r-=1
        print(v)
    pl = int(input("Digite a posição do pivo da esquerda: "))
    pr = int(input("Digite a posição do pivo da direita: "))
    if pl >= 0 and pr >= 0:
        quickSort(pl, 0, pivo-1, 0)
        quickSort(pr, pivo+1, n-1, 0)

pivo = int(input("Digite a posição do pivo: "))
quickSort(pivo, 0, n-1, 0)
