import random
v = list(int (x) for x in input().split())
n = len(v)
#pivo = random.choice(range(0, n))
pivo = -1
l = 0; r = n-1
turn = 0 #0 means comparison with left and 1 with right
counter = 0
pivos = list()

def escolhePivo(p):
    if p == -1:
        k = random.choice(range(0, n))
        pivos.append(k)
        return k
    else:
        pN = random.choice(range(0, n))
        while pN in pivos:
            pN = random.choice(range(0, n))
        pivos.append(pN)
        return pN

while counter < n:
    pivo = escolhePivo(pivo)
    print(pivo)
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
    l = 0; r = n-1; turn = 0
    counter += 1
