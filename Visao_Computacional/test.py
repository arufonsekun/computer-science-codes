import numpy as np
import cv2 as cv 
import matplotlib.pyplot as plt

image = np.array(cv.imread("garrafa.jpg"))

plt.subplot(221)
plt.imshow(image)
plt.axis("off")

plt.show()
