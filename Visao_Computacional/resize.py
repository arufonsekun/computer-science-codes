import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import PIL

img = PIL.Image.open('uffs.png')
img = img.resize((img.size[0] // 8, img.size[1] // 8), PIL.Image.ANTIALIAS)
img.save('uffs.png')
img = np.array(cv.imread(''))
