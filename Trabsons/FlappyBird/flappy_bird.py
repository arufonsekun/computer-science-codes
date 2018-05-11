#!/usr/bin/env python3
import pygame as pg
import time
class Game(object):
    #Initialize the Surface
    def __init__(self):
        pg.init()
        self.display = pg.display
        self.dimentions = (768,489)
        self.display.set_mode(self.dimentions, 0)
        self.display.set_caption("Flappy Bird")
        self.icon = pg.image.load("Images/ico.png").convert_alpha()
        self.display.set_icon(self.icon)
        self.screen = pg.display.get_surface()#get the surface

        #Initialize the begin GUI
        self.init_surface = Initial_Surface(self.screen)
        self.init_surface.show()

        #Creates the object birds
        self.bird = Bird(self.screen)
        self.bird.show()
    def __main__(self):
        x = 0
        while True:
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    exit()#Exit de Game
            self.init_surface.moves()
            self.init_surface.show()
            self.bird.moves()
            self.bird.show()
            self.display.update()

class Initial_Surface():
    #Initialize the pygame module and others atributes
    def __init__(self, screen):
        self.screen = screen
        self.xbar = 0
        self.xbar1 = 769
        self.background = pg.image.load("Images/initial_surface.jpg").convert()
        self.bar = pg.image.load("Images/bar.png").convert_alpha()
        self.bar1 = pg.image.load("Images/bar.png").convert_alpha()

    def show(self):
        self.screen.blit(self.background, (0,0))#put de default image
        self.screen.blit(self.bar, (self.xbar, 385))#put bar
        self.screen.blit(self.bar1, (self.xbar1, 385))#put bar1

    def moves(self):
        time.sleep(0.003)
        if self.xbar == -768:
            self.xbar  = 760
        if self.xbar1 == -768:
            self.xbar1 = 760
        else:
            self.xbar -= 1
            self.xbar1 -= 1
        self.bar.scroll(self.xbar, 385)
        self.bar1.scroll(self.xbar1, 385)

class Bird():
    def __init__(self, screen):
        self.screen = screen
        self.birdx = 330
        self.birdy = 200
        self.bird = pg.image.load("Images/bird.png").convert_alpha()

    def show(self):
        self.screen.blit(self.bird, (self.birdx, self.birdy))#put the bird

    def moves(self):
        self.birdy -= 1
        self.bird.scroll(self.birdx, self.birdy)#put de default image


game = Game()
game.__main__()
