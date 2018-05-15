import cv2

def resizeImg(img, basewidth):
    height, width, channels = img.shape
    scale = width/height
    img = cv2.resize(img, (basewidth, int(basewidth/scale)))
    return img

def escreve(img, texto, cor=(255,0,0)):
    fonte = cv2.FONT_HERSHEY_SIMPLEX
    cv2.putText(img, texto, (10,20), fonte, 0.5, cor, 0, cv2.LINE_AA)
