import math
def search(vR, b, e, n):
    if e==b:
        if n > vR[e]: return e+1
        else: return e
    mid = b + (e-b)//2;
    if vR[mid] == n: return mid
    elif vR[mid] > n: return search(vR, b, mid-1, n)
    else: return search(vR, mid+1, e, n)

raios = list()
r, t = map(int, input().split(' '))
p = 0
for i in range(r):
    rVal = int(input())
    raios.append(rVal)

for i in range(t):
    x, y = map(int, input().split(' '))
    d = math.sqrt(x**2 + y**2)
    p += r - search(raios, 0, r-1, d)
    #print("Distance = {}".format(d))
    #print("Index = {}".format(p))
print(p)
#print(recursiveBinarySearch(aList,455, 0, len(aList)))
