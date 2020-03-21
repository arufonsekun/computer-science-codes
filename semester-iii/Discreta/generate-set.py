import sys

def generate():
    inputName = input()
    nameNonRepeat = list()

    for c in inputName:
        if c != ' ' and not c in nameNonRepeat:
            #print(c)
            nameNonRepeat.append(c)

    length = len(nameNonRepeat)

    for c in nameNonRepeat:
        print(c)
        buff1 = c
        index1 = nameNonRepeat.index(c)+1

        for i in nameNonRepeat[index1:length]:
            buff1 += i
            print(buff1)
            index2 = nameNonRepeat.index(i) +1
            buff3 = buff1

            for j in nameNonRepeat[index2:length]:
                print(buff3+j)

if __name__ == '__main__':
    generate()
