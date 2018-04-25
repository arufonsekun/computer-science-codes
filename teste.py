def primo():
    x = 2
    primos = 0
    nprimos = 0
    while x > 1:
        x = int(input("Digite ujm numero: "));
        eh = eh_neh(x)
        if (eh): primos += 1
        else: nprimos += 1
    print("Primos são",primos)
    print("Não primos",nprimos)

def eh_neh(x):
    count = 1
    for el in range(1,x):
        if x % el == 0:count += 1
        if count > 2:
            return False
    if count == 2: return True

def ricci():
    x = int(input("Digite um numero: "))
    y = int(input("Digite um numero: "))
    count = int(input("Digite o numero de termos: "))
    nexto = y + x
    while count >= 1:
        nexto = x + y
        print (nexto, end = ' ')
        x = y
        y = nexto
        count -= 1

def growing():
    xico = 1.5
    ze = 1.18
    cu = 0
    while ze < xico:
        xico =+ xico + 0.02
        ze =+ ze + 0.04
        cu += 1
    print(cu, 'Anos')
        
    
