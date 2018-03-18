import numpy as np
import cv2
import matplotlib.pyplot as plt
img = np.zeros((1000,1000,3), np.uint8)
def atom(img,cv2):
    angle = 0
    while angle <= 180:
        img = cv2.ellipse(img,(256,256),(130,40),angle,0,360,(0,150,255),4)
        angle += 45
    cv2.circle(img,(256,256), 30, (255,0,0), -1)

def cisne(img,cv2):
    #cv2.line(img,(0,0), (511,511),(255,0,0),5)
    #img = cv2.rectangle(img,(384,0),(510,70),(0,255,0),-3)
    head1 = np.array([[556,490],[637,401],[721,490]], np.int32)
    head2 =np.array([[664,398],[743,398],[748,490]], np.int32)
    neck = np.array([[718,509],[640,511],[575,600],[664,600]], np.int32)
    body1 = np.array([[575,617],[667,617],[667,704],[575,704]], np.int32)
    body2 = np.array([[575,725],[667,725],[670,815]], np.int32)
    tail1 = np.array([[689,660],[689,809],[830,806]], np.int32)
    tail2 = np.array([[686,630],[797,741],[926,630]], np.int32)
    cv2.polylines(img,[head1,head2,neck,body1,body2, tail1, tail2],True,(0,255,255),6)
atom(img,cv2)
cisne(img,cv2)
plt.imshow(img)
plt.show()
