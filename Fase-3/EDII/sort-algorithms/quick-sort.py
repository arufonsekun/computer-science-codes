import random
v = list(int (x) for x in input().split())
n = len(v)
#pivo = random.choice(range(0, n))
pivo = int(input("Digite a posição do pivo: "))
l = 0; r = n-1
turn = 0 #0 means comparison with left and 1 with right
while l != r:
    if not turn:
        if pivo == l: turn = 1
        if v[pivo] < v[l]:
            v[l], v[pivo] = v[pivo], v[l]
            pivo = l
            turn = 1
        l+=1
    if turn:
        if pivo == r: turn = 0
        if v[pivo] > v[r]:
            v[r], v[pivo] = v[pivo], v[r]
            pivo = r
            turn = 0
        r-=1
    print(v)

