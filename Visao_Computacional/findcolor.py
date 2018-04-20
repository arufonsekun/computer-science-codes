#-*-encoding:utf-8-*-#
import cv2 as cv
import numpy as np
#Function wich gets the colors of the image
def init():
    #img = np.array(cv.imread('mar.jpg'))
    #img = np.array(cv.imread('camelo.jpeg'))
    img = np.array(cv.imread('ceu.jpeg'))

    #print(img[0])
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
init()
