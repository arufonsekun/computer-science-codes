import cv2
import numpy as np

#np.set_printoptions(threshold = np.nan)
img = np.array(cv2.imread("google.jpg"))
blue = img[:,:,0]
green = img[:,:,1]
red = img[:,:,2]
teste = np.array(
 [[0, 253, 255],
  [0 ,253, 255],
  [0 ,253 ,255],

  [0 ,253, 255],
  [0 ,253, 255],
  [0 ,253 ,255]]

)

print (img)
cv2.imshow("Teste",teste)
cv2.imshow("Original",img)
cv2.imshow("Blue",blue)
cv2.waitKey(0)
