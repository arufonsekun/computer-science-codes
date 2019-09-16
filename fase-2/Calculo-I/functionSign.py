def functionSign(begin, end, step):
    out = 0
    while begin <= end:
        out = ((begin**5)/5) - ((begin**4)/2) - (begin**3) + (4*begin**2) - (4*begin) + 1
        print("f({}) = {}".format(begin, out))
        begin+= step
begin = int(input("Begin: "))
end = int(input("End: "))
step = float(input("Step: "))
functionSign(begin, end, step)
