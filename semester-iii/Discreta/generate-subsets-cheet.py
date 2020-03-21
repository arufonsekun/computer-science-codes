import sys
from itertools import chain, combinations

def miau():
    inputName = input("Digite seu nome: ")
    nameNonRepeat = str()

    for c in inputName:
        if c != ' ' and not c in nameNonRepeat:
            nameNonRepeat += c

    nameList = list(nameNonRepeat)

    return (chain.from_iterable(combinations(nameList, n) for n in range(len(nameList)+1)))

if __name__ == '__main__':
    combi = list(miau())
    for e in combi:
        for s in e:
            print(s,end='')
        print()
