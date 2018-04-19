#https://www.urionlinejudge.com.br/judge/en/login
import numpy as np
import cv2
import matplotlib.pyplot as plt
import math
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
    cv2.polylines(img,[head1,head2,neck,body1,body2, tail1, tail2],True,(0,255,255),4)
    ##The follow line fill de polygon
    cv2.fillPoly(img, [head1,head2,neck,body1,body2, tail1, tail2], (0,255,255), lineType=8, shift=0)

def logo(img, cv2):
    r1 = 70
    r2 = 30
    ang = 60
    d = 170
    h = int(d/2*math.sqrt(3))
    dot_red = (256,128)
    dot_green = (dot_red[0]-d//2, dot_red[1]+h)
    dot_blue = (dot_red[0]+d//2, dot_red[1]+h)
    tan = float(dot_red[0]-dot_green[0])/(dot_green[1]-dot_red[0])
    ang = math.atan(tan)/math.pi*180
    red = (0, 0, 255)
    green = (0, 255, 0)
    blue = (255, 0, 0)
    black = (0, 0, 0)
    full = -1
    triangle_red = np.array([[258,127],[212,189],[293,189]], np.int32)
    cv2.circle(img, dot_red, r1, blue, full)
    cv2.circle(img, dot_green, r1, green, full)
    cv2.circle(img, dot_blue, r1, red, full)
    cv2.circle(img, dot_red, r2, black, full)
    cv2.circle(img, dot_green, r2, black, full)
    cv2.circle(img, dot_blue, r2, black, full)
    cv2.ellipse(img, dot_red, (r1, r1), 0, 130, 55, black, full)
    cv2.ellipse(img, dot_green, (r1, r1), 0, 295, 360, black, full)
    cv2.ellipse(img, dot_blue, (r1, r1), 0, 240, 305, black, full)
    cv2.putText(img, "OpenCV", (69,409), 5, 4,(255,0,0),2,cv2.LINE_AA)


atom(img,cv2)
cisne(img,cv2)
#logo(img, cv2)
plt.imshow(img)
plt.show()
