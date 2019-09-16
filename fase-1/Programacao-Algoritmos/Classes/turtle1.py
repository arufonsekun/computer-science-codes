import turtle
from tkinter import *
class ObjetoGrafico(object):
    def __init__(self):
        self.pen = turtle.Turtle()
        self.pen.pensize(1)
        self.pen.color("red")
        #self.pen.speed("fasted")
        self.colorbg = "Orange"
        turtle.bgcolor(self.colorbg)
        self.screen = self.pen.getscreen()
        self.verify = False

    def seta(self):
        self.root1 = Tk()
        self.root1.geometry = ("400x120")
        self.root1.withdraw()
        self.root1.configure(background = "aqua")
        texto = Label(self.root1, text = "Digite o tamanho do lado ou o raio: ")
        texto1 = Label(self.root1, text = "Digite a quantidade de lados: ")
        texto2 = Label(self.root1, text = "Digite a cor da forma: ")
        texto.pack(side = TOP)
        texto1.pack(side = TOP)
        texto2.pack(side = TOP)
        self.entrada = Entry(self.root1, bd = 5)
        self.entrada1 = Entry(self.root1, bd = 5)
        self.entrada2 = Entry(self.root1, bd = 5)
        ok = Button(self.root1, text = "Ok", command = self.desenha, width = 2, height = 1, font = "Serif, 14")
        ok.pack(fill = 'both', side = BOTTOM)
        self.entrada.pack(side = TOP)
        self.entrada1.pack(side = TOP)
        self.entrada2.pack(side = TOP)
        self.root1.deiconify()
        self.root1.mainloop()

    def desenha(self):
        x = float(self.entrada.get())
        y = int(self.entrada1.get())
        self.pos = (self.posx,self.posy)
        if self.entrada2.get() == "":
            self.pen.color("red")
        else:
            self.pen.color(self.entrada2.get())
        if y == 0:
            self.pen.begin_fill()
            self.pen.circle(x)
            self.pen.end_fill()
        else:
            c = 360.0/float(y)
            self.pen.begin_fill()
            for e in range(y):
                self.pen.forward(x)
                self.pen.right(c)
            self.pen.end_fill()

    def limpar(self):
        turtle.resetscreen()
        self.pen.color("Red")
        self.pen.pensize(1)
        self.pen.speed("fasted")
        turtle.bgcolor(self.colorbg)
        self.posx = 0
        self.posy = 0

    def mover(self,posx,posy):
        self.posx = posx
        self.posy = posy
        if self.verify == False:
            self.verify = True
            self.pen.penup()
            self.pen.goto(self.posx,self.posy)
            self.pen.pendown()
            self.win()
        else:
            self.pen.penup()
            self.pen.goto(self.posx,self.posy)
            self.pen.pendown()

    def desfazer(self):
        x = float(self.entrada.get())
        y = int(self.entrada1.get())
        self.pen.color('orange')
        self.pen.goto(self.pos)
        if y == 0:
            self.pen.begin_fill()
            self.pen.circle(x)
            self.pen.end_fill()
        else:
            c = 360.0/float(y)
            self.pen.begin_fill()
            for e in range(y):
                self.pen.forward(x)
                self.pen.right(c)
            self.pen.end_fill()
        self.pen.color(self.entrada2.get())

    def captura_click(self):
        self.screen.onclick(self.mover)
        turtle.mainloop()


class Desenha(ObjetoGrafico):

    def win(self):
        self.root = Tk()
        self.root.geometry("400x120")
        self.root.withdraw()
        self.root.configure(background = "green")
        self.a = Button(self.root, text = "Desenhar forma", command = self.seta, width = 2, height = 1, font = "Serif, 14")
        self.b = Button(self.root, text = "Limpar", command = self.limpar, width = 2, height = 1, font = "Serif, 14")
        self.c = Button(self.root, text = "Desfazer ultima forma", command = self.desfazer, width = 2, height = 1, font = "Serif, 14")
        self.a.pack(fill = 'both')
        self.c.pack(fill = 'both')
        self.b.pack(fill = 'both')
        self.root.deiconify()
        self.root.mainloop()

obj = Desenha()
obj.captura_click()
