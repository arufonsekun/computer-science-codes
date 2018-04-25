#-*-encoding:utf-8-*-#
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import sys
#Function wich gets the colors of the image
def init(name):
    img = np.array(cv.imread(name))
    cores = []
    quantity = []
    x = 0
    color_tuple = ()
    for line in img:
        for color in line:
            color_tuple = (color[2],color[1],color[0])
            if not color_tuple in cores:
                cores.append(color_tuple)
                quantity.append(0)
            else:
                quantity[cores.index(color_tuple)] += 1
    print "A cor: RGB" , cores[quantity.index(max(quantity))]
    print"Esta presente em: ", max(quantity), " pixels"
    show(cores[quantity.index(max(quantity))], img)
#Function that show the color and the image
def show(x,img):
    color = x[::-1]
    img1 = np.zeros((512,512,3), np.uint8)
    cv.rectangle(img1,(180,190),(300,300),(int(color[0]), int(color[1]), int(color[2])),-1)
    cv.imshow("Imagem original", img)
    cv.imshow("Esta é a cor predominante",img1)
    cv.waitKey(0)

init(sys.argv[1])
