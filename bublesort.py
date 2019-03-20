n = int(input("Vector size: "))
v = list(int(x) for x in input().split())

for i in range(n-1):
    #x = v[i]
    for j in range(i+1, n):
        if v[i] > v[j]:
            v[i], v[j] = v[j], v[i]
print(v)
