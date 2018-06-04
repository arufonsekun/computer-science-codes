
#pygame command to collide: pygame.sprite.collide_rect(sprite1, sprite2)
import csv
import sys
def arquivo(nome):
    media = 0
    scores_file = open(nome,'r')
    scores = scores_file.read().splitlines()
    scores_file.close()
    for el in scores:
        media += float(el)
    return (media/len(scores))

def read_csv(nome):
    fiou = open(nome)
    values = csv.reader(fiou)
    num = 0
    media = 0
    for row in values:
        for el in row: media += float(el); num += 1
    print ("A media dos valores do arquivo: {0} é {1:1.2f}".format(nome, media / num))
    fiou.close()

def plot_file(nome):




read_csv(sys.argv[1])
#print("Media {:1.2f}".format(arquivo(sys.argv[1])))
