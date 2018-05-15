import numpy as np
import cv2
from mine import *

imgColorida = cv2.imread("dados1.jpg")
imgColorida = resizeImg(imgColorida, 400)

#Conversão para tons de cinza
img = cv2.cvtColor(imgColorida, cv2.COLOR_BGR2GRAY)

#Suavizar a imagem
suave = cv2.GaussianBlur(img, (7,7), 0)
bordas = cv2.Canny(suave, 200, 350)

#Identificação e contagem de contornos
(lx, objetos, lx) = cv2.findContours(bordas.copy(),
cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

#Escreve texto em cima das imagens analisadas
imgC2 = img.copy()
escreve(img, "Imagem em tons de cinza", 0)
escreve(suave, "Suavizacao com Blur", 0)
escreve(bordas, "Detector de bordas Canny", 255)

cv2.drawContours(imgC2, objetos, -1, (255,255,255), 2)
escreve(imgC2, "Resultado da rolagem: "+str(len(objetos)), 0)

#juntando as imagens para mostra-las em uma janela so

temp = np.vstack([
np.hstack([img, suave]),
np.hstack([bordas, imgC2])
])

cv2.imshow("Resultado", temp)
cv2.waitKey(0)
