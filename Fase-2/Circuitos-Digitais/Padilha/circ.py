def circ(a,b,c,d,e,f,g):
    x = (not(a) and b and not(c)) or (d and e and not(f) and not(g)) or (not(a) and b and not(c)) or (d and not(e) and not(f) and not(g)) or (not(a) and b and not (c))

    print(x or (d and not(e) and f and g) or (not(a) and b and c) or (not(d) and e and not(f) and g) or (not(a) and b and c) or (not(d) and e and f and not(g)))
circ(1,0,1,0,0,0,0)
