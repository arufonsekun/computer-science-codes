import cv2
import numpy as np
import matplotlib.pyplot as plt

bgr_img = cv2.imread('imagens/san_francisco.jpg')
gray_img = cv2.cvtColor(bgr_img, cv2.COLOR_BGR2GRAY)
cv2.imwrite('san_francisco_grayscale.jpg', gray_img)

plt.imshow(gray_img, cmap = plt.get_cmap('gray'))
plt.xticks([]), plt.yticks([])
plt.show()


