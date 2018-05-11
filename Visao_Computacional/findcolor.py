import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import sys
from PIL import Image
#Function wich gets the colors of the image
def init(name):
    size = resize(name)
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
                quantity.append(1)
            else:
                quantity[cores.index(color_tuple)] += 1
    #print("A cor: RGB" , cores[quantity.index(max(quantity))])
    #print("Esta presente em: ", max(quantity), " pixels")
    color1 = cores[quantity.index(max(quantity))]
    frequency = (max(quantity) * 100) / size
    show(color1, img, frequency)

#Function that shows the color and the image
def show(color1, img, frequency):
    color1 = color1[::-1]
    img1 = np.zeros((180,180,3), np.uint8)
    cv.rectangle(img1,(0,0),(180,180),(int(color1[0]), int(color1[1]), int(color1[2])),-1)
    cv.putText(img1, "{0:.2f}%".format(frequency), (45, 90), cv.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2, cv.LINE_AA)
    cv.imshow("Imagem original", img)
    cv.imshow("Esta eh a cor predominante",img1)
    cv.waitKey(0)

#Function wich resizes the Image
def resize(img_name):
    img = Image.open(img_name)
    width, height = img.size
    if width > height:
        rate = width / height
        img = img.resize((int(150 * rate), 150), Image.ANTIALIAS)
    else:
        rate = height / width
        img = img.resize((150, int(150 * rate)), Image.ANTIALIAS)
    img.save(img_name)
    return width * height
resize(sys.argv[1])
init(sys.argv[1])
