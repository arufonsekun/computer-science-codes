#!/usr/bin/env python3
#font: ubuntumono
import pygame as pg
import time
import random
class Game(object):
    #Initialize the pygame module and others atributes
    def __init__(self):
        pg.init()
        self.display = pg.display
        self.dimentions = (768,489)
        self.display.set_mode(self.dimentions, 0)
        self.display.set_caption("Flappy Bird")
        self.icon = pg.image.load("Images/ico.png").convert_alpha()
        self.display.set_icon(self.icon)
        self.screen = pg.display.get_surface()#get the surface
        self.begin = False

    #Instantiate the objects that will compose the game
    def composition(self):
        #Create the object which represents the initial game interface
        self.init_surface = Initial_Surface(self.screen)
        self.init_surface.show()

        #Creates the object bird
        self.bird = Bird(self.screen)
        self.bird.show()

        #Create object cloud
        self.cloud1 = Cloud(self.screen, 200, 10)
        self.cloud1.show()

        #Create object cloud with a different image
        self.cloud2 = Cloud(self.screen, 760, 100)
        self.cloud2.show()

    #Esse __main__ não faz parte do objeto jogo
    def __main__(self):
        while True:
            #A surface deve ser a primeira imagem a ser mostrada
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    exit()#Exit de Game
                if event.type == pg.KEYUP:
                    if event.key == pg.K_SPACE:
                        self.begin = True
                        #Aqui eu implemento o passaro caindo ou subindo

            if self.begin == True:
                time.sleep(0.006)
                self.bird.fall()
                self.bird.show()

            if self.begin == False:
                time.sleep(0.006)
                self.bird.moves()
                self.bird.show()
            self.move_game_surface()
    def move_game_surface(self):
        self.init_surface.moves()
        self.init_surface.show()
        
        self.cloud2.moves()
        self.cloud2.show()

        self.cloud1.moves()
        self.cloud1.show()

        self.display.flip()
        self.display.update()

class Initial_Surface():

    def __init__(self, screen):
        self.screen = screen
        self.xbar = 0
        self.xbar1 = 768
        self.background = pg.image.load("Images/initial_surface.jpg").convert()
        self.bar = pg.image.load("Images/bar.png").convert_alpha()
        self.bar1 = pg.image.load("Images/bar.png").convert_alpha()

    def show(self):
        self.screen.blit(self.background, (0,0))#put de default image
        self.screen.blit(self.bar, (self.xbar, 385))#put bar
        self.screen.blit(self.bar1, (self.xbar1, 385))#put bar1

    def moves(self):
        if self.xbar == -766:
            self.xbar  = 768
        if self.xbar1 == -766:
            self.xbar1 = 768
        else:
            self.xbar -= 2
            self.xbar1 -= 2
        #self.bar.scroll(self.xbar, 385)
        #self.bar1.scroll(self.xbar1, 385)

class Bird():
    def __init__(self, screen):
        self.screen = screen
        self.birdx = 130
        self.birdy = 200
        self.fly = 0
        self.bird = pg.image.load("Images/bird.png").convert_alpha()

    def show(self):
        self.screen.blit(self.bird, (self.birdx, self.birdy))#put the bird

    def moves(self):
        time.sleep(0.002)
        if self.fly == 0:
            self.birdy -= 1
        if self.birdy == 190:
            self.fly = 1
        if self.fly == 1:
            self.birdy += 1
        if self.birdy == 230:
            self.fly = 0

    #Faz o bird cair
    def fall(self):
        self.birdy += 1

class Cloud():
    def __init__(self,screen, x, y):
        self.screen = screen
        self.xcloud = x #740
        self.ycloud = y #40
        self.cloud = pg.image.load("Images/cloud.png").convert_alpha()
        self.new_x_position = [200, 350, 900, 800, 1000]

    def show(self):
        self.screen.blit(self.cloud, (self.xcloud, self.ycloud))

    def moves(self):
        if self.xcloud == -205:
            self.xcloud = random.choice(self.new_x_position)
        else:
            self.xcloud -= 1
        #self.cloud.scroll(self.xsun, self.ysun)
game = Game()
game.composition()
game.__main__()
