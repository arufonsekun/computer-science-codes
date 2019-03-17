import sys

def generate():
    inputName = input()
    nameNonRepeat = list()
    nameMatrix = list()

    for c in inputName:
        if c != ' ' and not c in nameNonRepeat:
            #print(c)
            nameNonRepeat.append(c)

    lenght = len(nameNonRepeat)

    for c in nameNonRepeat:
        print(c)
        buff = c
        index = nameNonRepeat.index(c) + 1

        for i in range(lenght-1):
            if index == lenght: index = 0
            buff += nameNonRepeat[index]
            print(buff)
            index+=1



if __name__ == '__main__':
    generate()
