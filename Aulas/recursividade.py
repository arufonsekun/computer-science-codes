def soma(summ, x):
    if x == 0:
        print(summ)
    else:
        soma(summ+x, x-1)
soma(0,4)
