n = int(input('n: '))
v = list(int(x) for x in input().split())

s = list()
x = int()
d = int()
for i in range(n):
    x = v[0]
    for j in range(len(v)):
        if x >= v[j]:
            x = v[j]
            d = j
    s.append(x)
    v.pop(d)
    n-=1

print(s)
