import pygame as pg
import time
class Game(object):
    #Initializa de Surface
    def __init__(self):
        pg.init()
        self.init_surface = Initial_Surface()
        self.init_surface.screen()

    def __main__(self):
        x = 0
        while True:
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    exit()#Exit de Game
            self.init_surface.move()
            self.init_surface.screen.blit(self.init_surface.bar, (self.init_surface.xbar, 385))
            self.init_surface.screen.blit(self.init_surface.bar1, (self.init_surface.xbar1, 385))
            self.init_surface.display.update()

class Initial_Surface():
    #Initialize de module and others atributes
    def __init__(self):
        self.display = pg.display
        self.dimentions = (768,489)
        self.xbar = 0
        self.xbar1 = 769

    def screen(self):
        self.display.set_mode(self.dimentions, 0)#initialize the screen
        self.display.set_caption("Flappy Bird")
        self.icon = pg.image.load("Images/ico.png").convert_alpha()
        self.display.set_icon(self.icon)
        self.background = pg.image.load("Images/initial_surface.jpg").convert()
        self.bar = pg.image.load("Images/bar.png").convert_alpha()
        self.bar1 = pg.image.load("Images/bar.png").convert_alpha()
        self.screen = pg.display.get_surface()#get the surface
        self.screen.blit(self.background, (0,0))#put de default image
        self.screen.blit(self.bar, (self.xbar, 385))#put bar
        self.screen.blit(self.bar1, (self.xbar1, 385))#put bar1

    def move(self):
        time.sleep(0.003)
        if self.xbar == -768:
            self.xbar  = 760
        if self.xbar1 == -768:
            self.xbar1 = 760
        else:
            self.xbar -= 1
            self.xbar1 -= 1

game = Game()
game.__main__()
