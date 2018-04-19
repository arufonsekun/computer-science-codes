# -*- coding: cp1252 -*-
import pygame,sys
from pygame.locals import *
pygame.init()
class damas:
  def __init__(self,wid,hei):
    self.indice = []
    self.pos_vazia = ()
    self.pos_ocupada = 0
    self.wid = wid
    self.hei = hei
    self.jogada_branca = True
    self.fonte = pygame.font.SysFont("None",50)
    self.window = pygame.display.set_mode((self.wid,self.hei))
    self.tabuleiro_name = 'tabuleiro.png'
    self.peca1_name = 'peca1.png'
    self.peca2_name = 'peca2.png'
    self.dama = 'dama.png'
    self.dama2 = 'dama2.png'
    self.pos = ()
    self.vence_marron = False
    self.vence_branco = False
    self.list_dama = []
    self.po1 = (0,0)
    self.po2 = (135,75)
    self.po3 = (251,75)
    self.po4 = (367,75)
    self.po5 = (483,75)
    self.po6 = (73,135)
    self.po7 = (189,135)
    self.po8 = (305,135)
    self.po9 = (421,135)
    self.po10 = (135,195)
    self.po11 = (251,195)
    self.po12 = (367,195)
    self.po13 = (483,195)
    self.po14 = (73,363)
    self.po15 = (189,363)
    self.po16 = (305,363)
    self.po17 = (421,363)
    self.po18 = (130,423)
    self.po19 = (246,423)
    self.po20 = (362,423)
    self.po21 = (478,423)
    self.po22 = (73,483)
    self.po23 = (189,483)
    self.po24 = (305,483)
    self.po25 = (421,483)
    self.background = pygame.image.load(self.tabuleiro_name).convert()
    self.peca1 = pygame.image.load(self.peca1_name).convert()
    self.peca2 = pygame.image.load(self.peca1_name).convert()
    self.peca3 = pygame.image.load(self.peca1_name).convert()
    self.peca4 = pygame.image.load(self.peca1_name).convert()
    self.peca5 = pygame.image.load(self.peca1_name).convert()
    self.peca6 = pygame.image.load(self.peca1_name).convert()
    self.peca7 = pygame.image.load(self.peca1_name).convert()
    self.peca8 = pygame.image.load(self.peca1_name).convert()
    self.peca9 = pygame.image.load(self.peca1_name).convert()
    self.peca10 = pygame.image.load(self.peca1_name).convert()
    self.peca11 = pygame.image.load(self.peca1_name).convert()
    self.peca12 = pygame.image.load(self.peca1_name).convert()
    self.branco1 = pygame.image.load(self.peca2_name).convert()
    self.branco2 = pygame.image.load(self.peca2_name).convert()
    self.branco3 = pygame.image.load(self.peca2_name).convert()
    self.branco4 = pygame.image.load(self.peca2_name).convert()
    self.branco5 = pygame.image.load(self.peca2_name).convert()
    self.branco6 = pygame.image.load(self.peca2_name).convert()
    self.branco7 = pygame.image.load(self.peca2_name).convert()
    self.branco8 = pygame.image.load(self.peca2_name).convert()
    self.branco9 = pygame.image.load(self.peca2_name).convert()
    self.branco10 = pygame.image.load(self.peca2_name).convert()
    self.branco11 = pygame.image.load(self.peca2_name).convert()
    self.branco12 = pygame.image.load(self.peca2_name).convert()
    self.tabuleiro = [[[],[self.peca1],[],[self.peca2],[],[self.peca3],[],[self.peca4]],
                       [[self.peca5],[],[self.peca6],[],[self.peca7],[],[self.peca8],[]],
                       [[],[self.peca9],[],[self.peca10],[],[self.peca11],[],[self.peca12]],
                       [[],[],[],[],[],[],[],[]],
                       [[],[],[],[],[],[],[],[]],
                       [[self.branco1],[],[self.branco2],[],[self.branco3],[],[self.branco4],[]],
                       [[],[self.branco5],[],[self.branco6],[],[self.branco7],[],[self.branco8]],
                       [[self.branco9],[],[self.branco10],[],[self.branco11],[],[self.branco12],[]]]
    self.branco = ([self.branco1],[self.branco2],[self.branco3],[self.branco4],
                   [self.branco5],[self.branco6],[self.branco7],[self.branco8],
                  [self.branco9],[self.branco10],[self.branco11],[self.branco12]
                  )
    self.peca = ([self.peca1],[self.peca2],[self.peca3],[self.peca4],[self.peca5],
                 [self.peca6],[self.peca7],[self.peca8],[self.peca9],[self.peca10],
                 [self.peca11],[self.peca12])
    self.blita = [[self.background],[self.peca1],[self.peca2],[self.peca3],[self.peca4],[self.peca5],
                  [self.peca6],[self.peca7],[self.peca8],[self.peca9],[self.peca10],
                  [self.peca11],[self.peca12],[self.branco1],[self.branco2],[self.branco3],
                  [self.branco4],[self.branco5],[self.branco6],[self.branco7],[self.branco8],
                  [self.branco9],[self.branco10],[self.branco11],[self.branco12]]
    
  def Pegar_posicao_ocupada(self):
    if (self.pos[0] >= 126 and self.pos[0]< 182) and (self.pos[1] >= 182 and self.pos[1] < 240): #pos 6b
      if self.tabuleiro[2][1] != []:
        self.pos_ocupada = self.tabuleiro[2][1]
        self.indice = [2,1]
      else:
        self.pos_vazia = (135,195)
    if (self.pos[0] >= 125 and self.pos[0] <= 182) and (self.pos[1] >= 68 and self.pos[1] <= 124): # pos 5a
      if self.tabuleiro[0][1] != []:
        self.pos_ocupada = self.tabuleiro[0][1]
        self.indice = [0,1]
      else:
        self.pos_vazia = (135,78)
    if (self.pos[0] >= 241 and self.pos[0] <= 298) and (self.pos[1] >= 67 and self.pos[1] <= 124): #pos 8d 
      if self.tabuleiro[0][3] != []:
        self.pos_ocupada = self.tabuleiro[0][3]
        self.indice = [0,3]
      else:
        self.pos_vazia = (251,78)
      #print "voce clicou na posicao 8d"
    if (self.pos[0] >= 358 and self.pos[0] <= 415) and (self.pos[1] >= 68 and self.pos[1] <= 124):
      if self.tabuleiro[0][5] != []:
        self.pos_ocupada = self.tabuleiro[0][5]
        self.indice = [0,5]
      else:
        self.pos_vazia = (367,75)
      #print "Voce clicou na posicao 8f"
    if (self.pos[0] >= 474 and self.pos[0] <= 531) and (self.pos[1] >= 68 and self.pos[1] <= 124):
      if self.tabuleiro[0][7] != []:
        self.pos_ocupada = self.tabuleiro[0][7]
        self.indice = [0,7]
      else:
        self.pos_vazia = (484,78)
      #print "Voce clicou na posicao 8h"
    if (self.pos[0] >= 67 and self.pos[0] <= 124) and (self.pos[1] >= 125 and self.pos[1] <= 182):
      if self.tabuleiro[1][0] != []:
        self.pos_ocupada = self.tabuleiro[1][0]
        self.indice = [1,0]
      else:
        self.pos_vazia = (77,135)
      #print "Voce clicou na posicao 7a"
    if (self.pos[0] >= 183 and self.pos[0] <= 240) and (self.pos[1] >= 126 and self.pos[1] <= 182):
      if self.tabuleiro[1][2] != []:
        self.pos_ocupada = self.tabuleiro[1][2]
        self.indice = [1,2]
      else:
        self.pos_vazia = (193,135)
      #print "vc clico na pos 7c"
    if (self.pos[0] >= 300 and self.pos[0] <= 356) and (self.pos[1] >= 125 and self.pos[1] <= 182):
      if self.tabuleiro[1][4] != []:
        self.pos_ocupada = self.tabuleiro[1][4]
        self.indice = [1,4]
      else:
        self.pos_vazia = (310,135)
      #print "posicao 7e"
    if (self.pos[0] >= 415 and self.pos[0] <= 472) and (self.pos[1] >= 125 and self.pos[1] <= 182):
      if self.tabuleiro[1][6] != []:
        self.pos_ocupada = self.tabuleiro[1][6]
        self.indice = [1,6]
      else:
        self.pos_vazia = (425,135)
      #print "Voce clico na pos 7g"
    if (self.pos[0] >= 241 and self.pos[0] <= 298) and (self.pos[1] >= 183 and self.pos[1] <= 240):
      if self.tabuleiro[2][3] != []:
        self.pos_ocupada = self.tabuleiro[2][3]
        self.indice = [2,3]
      else:
        self.pos_vazia = (251,195)
    if (self.pos[0] >= 358 and self.pos[0] <= 415) and (self.pos[1] >= 184 and self.pos[1] <= 240):
      if self.tabuleiro[2][5] != []:
        self.pos_ocupada = self.tabuleiro[2][5]
        self.indice = [2,5]
      else:
        self.pos_vazia = (368,194)
      #print "Voce clicou na pos 6f"
    if (self.pos[0] >= 475 and self.pos[0] <= 531) and (self.pos[1] >= 183 and self.pos[1] <= 240):
      if self.tabuleiro[2][7] != []:
        self.pos_ocupada = self.tabuleiro[2][7]
        self.indice = [2,7]
      else:
        self.pos_vazia = (485,194)
      #print "vc clico na pos 6h"
    if (self.pos[0] >= 67 and self.pos[0] <= 124) and (self.pos[1] >= 241 and self.pos[1] <= 298):
        if self.tabuleiro[3][0] != []:
          self.pos_ocupada = self.tabuleiro[3][0]
          self.indice = [3,0]
        else:
          self.pos_vazia = (73,255)
    if (self.pos[0] >= 183 and self.pos[0] <= 243) and (self.pos[1] >= 240 and self.pos[1] <= 298):
      if self.tabuleiro[3][2] != []:
        self.pos_ocupada = self.tabuleiro[3][2]
        self.indice = [3,2]
      else:
        self.pos_vazia = (193,250)
    if (self.pos[0] >= 300 and self.pos[0] <= 356) and (self.pos[1] >= 242 and self.pos[1] <= 299):
      if self.tabuleiro[3][4] != []:
        self.pos_ocupada = self.tabuleiro[3][4]
        self.indice = [3,4]
      else:
        self.pos_vazia = (310,250)
    if (self.pos[0] >= 416 and self.pos[0] <= 473) and (self.pos[1] >= 241 and self.pos[1] <= 298):
      if self.tabuleiro[3][6] != []:
        self.pos_ocupada = self.tabuleiro[3][6]
        self.indice = [3,6]
      else:
        self.pos_vazia = (426,250)
      #print "voce clicou na pos 5g"
    if (self.pos[0] >= 124 and self.pos[0] <= 182) and (self.pos[1] >= 300 and self.pos[1] <= 356):
      if self.tabuleiro[4][1] != []:
        self.pos_ocupada = self.tabuleiro[4][1]
        self.indice = [4,1]
      else:
        self.pos_vazia = (134,310)
      #print "Voce clicou na pos 4B"
    if (self.pos[0] >= 242 and self.pos[0] <= 300) and (self.pos[1] >= 300 and self.pos[1] <= 356):
         if self.tabuleiro[4][3] != []:
            self.pos_ocupada = self.tabuleiro[4][3]
            self.indice = [4,3]
         else:
           self.pos_vazia = (252,310)
      #print "Voce clicou na posicao D4"
    if (self.pos[0] >= 358 and self.pos[0] <= 415) and (self.pos[1] >= 300 and self.pos[1] <= 357):
      if self.tabuleiro[4][5] != []:
        self.pos_ocupada = self.tabuleiro[4][5]
        self.indice = [4,5]
      else:
        self.pos_vazia = (368,310)
      #print "voce clico na posicao 4f"
    if (self.pos[0] >= 474 and self.pos[0] <= 531) and (self.pos[1] >= 300 and self.pos[1] <= 355):
      if self.tabuleiro[4][7] != []:
        self.pos_ocupada = self.tabuleiro[4][7]
        self.indice = [4,7]
      else:
        self.pos_vazia = (484,310)
    if (self.pos[0] >= 67 and self.pos[0] <= 125) and (self.pos[1] >= 360 and self.pos[1] <= 414):
      if self.tabuleiro[5][0] != []:
        self.pos_ocupada = self.tabuleiro[5][0]
        self.indice = [5,0]
      else:
        self.pos_vazia = (77,370)
      #print "posicao A3"
    if (self.pos[0] >= 182 and self.pos[0] <= 240) and (self.pos[1] >= 359 and self.pos[1] <= 415):
      if self.tabuleiro[5][2] != []:
        self.pos_ocupada = self.tabuleiro[5][2]
        self.indice = [5,2]
      else:
        self.pos_vazia = (192,370)
      #print "posicao 3C"
    if (self.pos[0] >= 300 and self.pos[0] <= 360) and (self.pos[1] >= 358 and self.pos[1] <= 415):
      if self.tabuleiro[5][4] != []:
        self.pos_ocupada = self.tabuleiro[5][4]
        self.indice = [5,4]
      else:
        self.pos_vazia = (310,368)
      #print "Posicao 3E"
    if (self.pos[0] >= 415 and self.pos[0] <= 473) and (self.pos[1] >= 360 and self.pos[1] <= 415):
      if self.tabuleiro[5][6] != []:
        self.pos_ocupada = self.tabuleiro[5][6]
        self.indice = [5,6]
      else:
        self.pos_vazia = (425,370)
      #print "Posicao 3G"
    if (self.pos[0] >= 126 and self.pos[0] <= 182 ) and (self.pos[1] >= 417 and self.pos[1] <= 472):
      if self.tabuleiro[6][1] != []:
        self.pos_ocupada = self.tabuleiro[6][1]
        self.indice = [6,1]
      else:
        self.pos_vazia = (136,427)
      #print "posicao 2B"
    if (self.pos[0] >= 241 and self.pos[0] <= 298) and (self.pos[1] >= 417 and self.pos[1] <= 472):
      if self.tabuleiro[6][3] != []:
        self.pos_ocupada = self.tabuleiro[6][3]
        self.indice = [6,3]
      else:
        self.pos_vazia = (251,427)
      #print "posicao 2D"
    if (self.pos[0] >= 358 and self.pos[0] <= 415) and (self.pos[1] >= 416 and self.pos[1] <= 473):
      if self.tabuleiro[6][5] != []:
        self.pos_ocupada = self.tabuleiro[6][5]
        self.indice = [6,5]
      else:
        self.pos_vazia = (368,427)
      #print "Posicao 2F"
    if (self.pos[0] >= 474 and self.pos[0] <= 530) and (self.pos[1] >= 416 and self.pos[1] <= 473):
      if self.tabuleiro[6][7] != []:
        self.pos_ocupada = self.tabuleiro[6][7]
        self.indice = [6,7]
      else:
        self.pos_vazia = (484,427)
      #print "Posicao 2H"
    if (self.pos[0] >= 68 and self.pos[0] <= 124) and (self.pos[1] >= 475 and self.pos[1] <= 531):
      if self.tabuleiro[7][0] != []:
        self.pos_ocupada = self.tabuleiro[7][0]
        self.indice = [7,0]
      else:
        self.pos_vazia = (78,485)
        #pos 1a
    if (self.pos[0] >= 184 and self.pos[0] <= 240) and (self.pos[1] >= 475 and self.pos[1] <= 530):
      if self.tabuleiro[7][2] != []:
        self.pos_ocupada = self.tabuleiro[7][2]
        self.indice = [7,2]
      else:
        self.pos_vazia = (194,485)
      #print "posicao 1C"
    if (self.pos[0] >= 300 and self.pos[0] <= 357) and (self.pos[1] >= 475 and self.pos[1] <= 530):
      if self.tabuleiro[7][4] != []:
        self.pos_ocupada = self.tabuleiro[7][4]
        self.indice = [7,4]
      else:
        self.pos_vazia = (310,485)
      #print "posicao 1E"
    if (self.pos[0] >= 416 and self.pos[0] <= 473) and (self.pos[1] >= 475 and self.pos[1] <= 531):
      if self.tabuleiro[7][6] != []:
        self.pos_ocupada = self.tabuleiro[7][6]
        self.indice = [7,6]
      else:
        self.pos_vazia = (426,485)
      #print "posicao 1G"
  def __main__(self):
    self.rodando = True
    while self.rodando:
      for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
          self.rodando = False
        if evento.type == pygame.MOUSEBUTTONUP:
            self.pos = pygame.mouse.get_pos()
            dama.Pegar_posicao_ocupada()
      dama.vencedor()
      dama.Valida()
      dama.move()
      dama.atualiza()
      pygame.display.update()
      
      
  def troca_dama(self):        
    if self.pos_ocupada == [self.peca1]:
      self.blita.remove([self.peca1])
      self.peca1 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca1]
      self.blita.append([self.peca1])
      self.list_dama.append([self.peca1])
    if self.pos_ocupada == [self.peca2]:
      self.blita.remove([self.peca2])
      self.peca2 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca2]
      self.blita.append([self.peca2])
      self.list_dama.append([self.peca2])
    if self.pos_ocupada == [self.peca3]:
      self.blita.remove([self.peca3])
      self.peca3 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca3]
      self.blita.append([self.peca3])
      self.list_dama.append([self.peca3])
    if self.pos_ocupada == [self.peca4]:
      self.blita.remove([self.peca4])
      self.peca4 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca4]
      self.blita.append([self.peca4])
      self.list_dama.append([self.peca4])
    if self.pos_ocupada == [self.peca5]:
      self.blita.remove([self.peca5])
      self.peca5 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca5]
      self.blita.append([self.peca5])
      self.list_dama.append([self.peca5])
    if self.pos_ocupada == [self.peca6]:
      self.blita.remove([self.peca6])
      self.peca6 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca6]
      self.blita.append([self.peca6])
      self.list_dama.append([self.peca6])
    if self.pos_ocupada == [self.peca7]:
      self.blita.remove([self.peca7])
      self.peca7 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca7]
      self.blita.append([self.peca7])
      self.list_dama.append([self.peca7])
    if self.pos_ocupada == [self.peca8]:
      self.blita.remove([self.peca8])
      self.peca8 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca8]
      self.blita.append([self.peca8])
      self.list_dama.append([self.peca8])
    if self.pos_ocupada == [self.peca9]:
      self.blita.remove([self.peca9])
      self.peca9 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca9]
      self.blita.append([self.peca9])
      self.list_dama.append([self.peca9])
    if self.pos_ocupada == [self.peca10]:
      self.blita.remove([self.peca10])
      self.peca10 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca10]
      self.blita.append([self.peca10])
      self.list_dama.append([self.peca10])
    if self.pos_ocupada == [self.peca11]:
      self.blita.remove([self.peca11])
      self.peca11 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca11]
      self.blita.append([self.peca11])
      self.list_dama.append([self.peca11])
    if self.pos_ocupada == [self.peca12]:
      self.blita.remove([self.peca12])
      self.peca12 = pygame.image.load(self.dama).convert()
      self.pos_ocupada = [self.peca12]
      self.blita.append([self.peca12])
      self.list_dama.append([self.peca12])
    if self.pos_ocupada == [self.branco1]:
      self.blita.remove([self.branco1])
      self.branco1 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco1])
      self.pos_ocupada = [self.branco1]
      self.blita.append([self.branco1])
    if self.pos_ocupada == [self.branco2]:
      self.blita.remove([self.branco2])
      self.branco2 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco2])
      self.pos_ocupada = [self.branco2]
      self.blita.append([self.branco2])
    if self.pos_ocupada == [self.branco3]:
      self.blita.remove([self.branco3])
      self.branco3 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco3])
      self.pos_ocupada = [self.branco3]
      self.blita.append([self.branco3])
    if self.pos_ocupada == [self.branco4]:
      self.blita.remove([self.branco4])
      self.branco4 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco4])
      self.pos_ocupada = [self.branco4]
      self.blita.append([self.branco4])
    if self.pos_ocupada == [self.branco5]:
      self.blita.remove([self.branco5])
      self.branco5 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco5])
      self.pos_ocupada = [self.branco5]
      self.blita.append([self.branco5])
    if self.pos_ocupada == [self.branco6]:
      self.blita.remove([self.branco6])
      self.branco6 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco6])
      self.pos_ocupada = [self.branco6]
      self.blita.append([self.branco6])
    if self.pos_ocupada == [self.branco7]:
      self.blita.remove([self.branco7])
      self.branco7 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco7])
      self.pos_ocupada = [self.branco7]
      self.blita.append([self.branco7])
    if self.pos_ocupada == [self.branco8]:
      self.blita.remove([self.branco8])
      self.branco8 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco8])
      self.pos_ocupada = [self.branco8]
      self.blita.append([self.branco8])
    if self.pos_ocupada == [self.branco9]:
      self.blita.remove([self.branco9])
      self.branco9 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco9])
      self.pos_ocupada = [self.branco9]
      self.blita.append([self.branco9])
    if self.pos_ocupada == [self.branco10]:
      self.blita.remove([self.branco10])
      self.branco10 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco10])
      self.pos_ocupada = [self.branco10]
      self.blita.append([self.branco10])
    if self.pos_ocupada == [self.branco11]:
      self.blita.remove([self.branco11])
      self.branco11 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco11])
      self.pos_ocupada = [self.branco11]
      self.blita.append([self.branco11])
    if self.pos_ocupada == [self.branco12]:
      self.blita.remove([self.branco12])
      self.branco12 = pygame.image.load(self.dama2).convert()
      self.list_dama.append([self.branco12])
      self.pos_ocupada = [self.branco12]
      self.blita.append([self.branco12])
    self.branco = ([self.branco1],[self.branco2],[self.branco3],[self.branco4],
                   [self.branco5],[self.branco6],[self.branco7],[self.branco8],
                  [self.branco9],[self.branco10],[self.branco11],[self.branco12]
                  )
    self.peca = ([self.peca1],[self.peca2],[self.peca3],[self.peca4],[self.peca5],
                 [self.peca6],[self.peca7],[self.peca8],[self.peca9],[self.peca10],
                 [self.peca11],[self.peca12])
                 
  def atualiza(self):
    if [self.background] in self.blita:
      self.window.blit(self.background,self.po1)
    if [self.peca1] in self.blita:
      self.window.blit(self.peca1,self.po2)
    if [self.peca2] in self.blita:
      self.window.blit(self.peca2,self.po3)
    if [self.peca3] in self.blita:
      self.window.blit(self.peca3,self.po4)
    if [self.peca4] in self.blita:
      self.window.blit(self.peca4,self.po5)
    if [self.peca5] in self.blita:
      self.window.blit(self.peca5,self.po6)
    if [self.peca6] in self.blita:
      self.window.blit(self.peca6,self.po7)
    if [self.peca7] in self.blita:
      self.window.blit(self.peca7,self.po8)
    if [self.peca8] in self.blita:
      self.window.blit(self.peca8,self.po9)
    if [self.peca9] in self.blita:
      self.window.blit(self.peca9,self.po10)
    if [self.peca10] in self.blita:
      self.window.blit(self.peca10,self.po11)
    if [self.peca11] in self.blita:
      self.window.blit(self.peca11,self.po12)
    if [self.peca12] in self.blita:
      self.window.blit(self.peca12,self.po13)
    if [self.branco1] in self.blita:
      self.window.blit(self.branco1,self.po14)
    if [self.branco2] in self.blita:
      self.window.blit(self.branco2,self.po15)
    if [self.branco3] in self.blita:
      self.window.blit(self.branco3,self.po16)
    if [self.branco4] in self.blita:
      self.window.blit(self.branco4,self.po17)
    if [self.branco5] in self.blita:
      self.window.blit(self.branco5,self.po18)
    if [self.branco6] in self.blita:
      self.window.blit(self.branco6,self.po19)
    if [self.branco7] in self.blita:
      self.window.blit(self.branco7,self.po20)
    if [self.branco8] in self.blita:
      self.window.blit(self.branco8,self.po21)
    if [self.branco9] in self.blita:
      self.window.blit(self.branco9,self.po22)
    if [self.branco10] in self.blita:
      self.window.blit(self.branco10,self.po23)
    if [self.branco11] in self.blita:
      self.window.blit(self.branco11,self.po24)
    if [self.branco12] in self.blita:
      self.window.blit(self.branco12,self.po25)
    if self.vence_marron == True:
      self.mensagem = self.fonte.render("O ganhador é o jogador marron",0,((255,255,0)))
      self.window.blit(self.mensagem,(90,5))
    if self.vence_branco == True:
      self.mensagem = self.fonte.render("O ganhador é o jogador branco",0,((255,255,0)))
      self.window.blit(self.mensagem,(90,5))
      
  def vencedor(self):
    if[self.branco1] not in self.blita and [self.branco2] not in self.blita and [self.branco3] not in self.blita and [self.branco4] not in self.blita and [self.branco5] not in self.blita and [self.branco6] not in self.blita and [self.branco7] not in self.blita and [self.branco8] not in self.blita and [self.branco9] not in self.blita and [self.branco10] not in self.blita and [self.branco11] not in self.blita and [self.branco12] not in self.blita:
      self.vence_marron = True
    if [self.peca1] not in self.blita and [self.peca2] not in self.blita and [self.peca3] not in self.blita and [self.peca4] not in self.blita and [self.peca5] not in self.blita and [self.peca6] not in self.blita and [self.peca7] not in self.blita and [self.peca8] not in self.blita and [self.peca9] not in self.blita and [self.peca10] not in self.blita and [self.peca11] not in self.blita and [self.peca12] not in self.blita:
      self.vence_branco = True
      
  def Valida(self):
    if self.pos_ocupada in self.list_dama:
      dama.movimento_dama()
      if self.pos_ocupada in self.branco and self.jogada_branca == True:
        self.jogada_branca = False
      if self.pos_ocupada in self.peca and self.jogada_branca == False:
        self.jogada_branca = True
    elif self.pos_ocupada in self.branco and self.jogada_branca == True:#ohnb9uiafhnub n
      if self.indice == [5,0] and (self.pos_vazia == (134,310) or self.pos_vazia == (193,250)):
        self.jogada_branca = False
        if self.pos_vazia == (134,310):
          self.tabuleiro[5][0] = []
          self.tabuleiro[4][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,250) and (self.tabuleiro[4][1] in self.peca) and (self.tabuleiro[3][2] == []):
          self.tabuleiro[5][0] = []
          self.blita.remove(self.tabuleiro[4][1])
          self.tabuleiro[3][2] = self.pos_ocupada
          self.tabuleiro[4][1] = []
          self.jogada = True
      elif self.indice == [6,1] and (self.pos_vazia == (77,370) or self.pos_vazia == (192,370) or self.pos_vazia == (252,310)):
        self.jogada_branca = False
        if self.pos_vazia == (77,370):
          self.tabuleiro[6][1] = []
          self.tabuleiro[5][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (192,370):
          self.tabuleiro[6][1] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True 
        if self.pos_vazia == (252,310) and self.tabuleiro[5][2] in self.peca and self.tabuleiro[4][3] == []:
          self.tabuleiro[6][1] = []
          self.blita.remove(self.tabuleiro[5][2])
          self.tabuleiro[4][3] = self.pos_ocupada
          self.tabuleiro[5][2] = []
          self.jogada = True
      elif self.indice == [6,3] and (self.pos_vazia == (192,370) or self.pos_vazia == (310,368) or self.pos_vazia == (134,310) or self.pos_vazia == (368,310)):
        self.jogada_branca = False
        if self.pos_vazia == (192,370):
          self.tabuleiro[6][3] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,368):
          self.tabuleiro[6][3] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (134,310) and self.tabuleiro[5][2] in self.peca and self.tabuleiro[4][1] == []:
          self.tabuleiro[6][3] = []
          self.blita.remove(self.tabuleiro[5][2])
          self.tabuleiro[5][2] = []
          self.tabuleiro[4][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,310) and self.tabuleiro[5][4] in self.peca and self.tabuleiro[4][5] == []:
          self.tabuleiro[6][3] = []
          self.blita.remove(self.tabuleiro[5][4])
          self.tabuleiro[5][4] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,1] and (self.pos_vazia == (193,250) or self.pos_vazia == (73,255) or self.pos_vazia == (251,195)):
        self.jogada_branca = False
        if self.pos_vazia == (193,250):
          self.tabuleiro[4][1] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (73,255):
          self.tabuleiro[4][1] = []
          self.tabuleiro[3][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,195) and self.tabuleiro[3][2] in self.peca and self.tabuleiro[2][3] == []:
          self.tabuleiro[4][1] = []
          self.blita.remove(self.tabuleiro[3][2])
          self.tabuleiro[3][2] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,2] and (self.pos_vazia == (134,310) or self.pos_vazia == (252,310) or self.pos_vazia == (73,255) or self.pos_vazia == (310,250)):
        self.jogada_branca = False
        if self.pos_vazia == (134,310):
          self.tabuleiro[5][2] = []
          self.tabuleiro[4][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (252,310):
          self.tabuleiro[5][2] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (73,255) and self.tabuleiro[4][1] in self.peca and self.tabuleiro[3][0] == []:
          self.tabuleiro[5][2] = []
          self.blita.remove(self.tabuleiro[4][1])
          self.tabuleiro[4][1] = []
          self.tabuleiro[3][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,250) and self.tabuleiro[4][3] in self.peca and self.tabuleiro[3][4] ==[]:
          self.tabuleiro[5][2] = []
          self.blita.remove(self.tabuleiro[4][3])
          self.tabuleiro[4][3] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,4] and (self.pos_vazia == (252,310) or self.pos_vazia == (368,310) or self.pos_vazia == (193,250) or self.pos_vazia == (426,250)):
        self.jogada_branca = False
        if self.pos_vazia == (252,310):
          self.tabuleiro[5][4] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,310):
          self.tabuleiro[5][4] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,250) and self.tabuleiro[4][3] in self.peca and self.tabuleiro[3][2] == []:
          self.tabuleiro[5][4] = []
          self.blita.remove(self.tabuleiro[4][3])
          self.tabuleiro[4][3] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (426,250) and self.tabuleiro[4][5] in self.peca and self.tabuleiro[3][6] == []:
          self.tabuleiro[5][4] = []
          self.blita.remove(self.tabuleiro[4][5])
          self.tabuleiro[4][5] = []
          self.tabuleiro[3][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,6] and (self.pos_vazia == (368,310) or self.pos_vazia == (484,310) or self.pos_vazia == (310,250)):
        self.jogada_branca = False
        if self.pos_vazia == (368,310):
          self.tabuleiro[5][6] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,310):
          self.tabuleiro[5][6] = []
          self.tabuleiro[4][7] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,250) and self.tabuleiro[4][5] in self.peca and self.tabuleiro[3][4] == []:
          self.tabuleiro[5][6] = []
          self.blita.remove(self.tabuleiro[4][5])
          self.tabuleiro[4][5] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,3] and (self.pos_vazia == (193,250) or self.pos_vazia == (310,250) or self.pos_vazia == (135,195) or self.pos_vazia == (368,194)):
        self.jogada_branca = False
        if self.pos_vazia == (193,250):
          self.tabuleiro[4][3] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,250):
          self.tabuleiro[4][3] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (135,195) and self.tabuleiro[3][2] in self.peca and self.tabuleiro[2][1] == []:
          self.tabuleiro[4][3] = []
          self.blita.remove(self.tabuleiro[3][2])
          self.tabuleiro[3][2] = []
          self.tabuleiro[2][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,194) and self.tabuleiro[3][4] in self.peca and self.tabuleiro[2][5] == []:
          self.tabuleiro[4][3] = []
          self.blita.remove(self.tabuleiro[3][4])
          self.tabuleiro[3][4] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,5] and (self.pos_vazia == (310,250) or self.pos_vazia == (426,250) or self.pos_vazia == (251,195) or self.pos_vazia == (485,194)):
        self.jogada_branca = False
        if self.pos_vazia == (310,250):
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
          self.tabuleiro[4][5] = []
        if self.pos_vazia == (426,250):
          self.tabuleiro[3][6] = self.pos_ocupada
          self.jogada = True
          self.tabuleiro[4][5] = []
        if self.pos_vazia == (251,195) and self.tabuleiro[3][4] in self.peca and self.tabuleiro[2][3] == []:
          self.tabuleiro[4][5] = []
          self.blita.remove(self.tabuleiro[3][4])
          self.tabuleiro[3][4] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (485,194) and self.tabuleiro[3][6] in self.peca and self.tabuleiro[2][7] == []:
          self.tabuleiro[4][5] = []
          self.blita.remove(self.tabuleiro[3][6])
          self.tabuleiro[3][6] = []
          self.tabuleiro[2][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,7] and (self.pos_vazia == (426,250) or self.pos_vazia == (368,194)):
        self.jogada_branca = False
        if self.pos_vazia == (426,250):
          self.tabuleiro[4][7] = []
          self.tabuleiro[3][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,194) and self.tabuleiro[3][6] in self.peca and self.tabuleiro[2][5] == []:
          self.tabuleiro[4][7] = []
          self.blita.remove(self.tabuleiro[3][6])
          self.tabuleiro[3][6] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,0] and (self.pos_vazia == (135,195) or self.pos_vazia == (193,135)):
        self.jogada_branca = False
        if self.pos_vazia == (135,195):
          self.tabuleiro[3][0] = []
          self.tabuleiro[2][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,135) and self.tabuleiro[2][1] in self.peca and self.tabuleiro[1][2] == []:
          self.tabuleiro[3][0] = []
          self.blita.remove(self.tabuleiro[2][1])
          self.tabuleiro[2][1] = []
          self.tabuleiro[1][2] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,2] and (self.pos_vazia == (135,195) or self.pos_vazia == (251,195) or self.pos_vazia == (77,135) or self.pos_vazia == (310,135)):
        self.jogada_branca = False
        if self.pos_vazia == (135,195):
          self.tabuleiro[3][2] = []
          self.tabuleiro[2][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,195):
          self.tabuleiro[3][2] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (77,135) and self.tabuleiro[2][1] in self.peca and self.tabuleiro[1][0] == []:
          self.tabuleiro[3][2] = []
          self.blita.remove(self.tabuleiro[2][1])
          self.tabuleiro[2][1] = []
          self.tabuleiro[1][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,135) and self.tabuleiro[2][3] in self.peca and self.tabuleiro[1][4] == []:
          self.tabuleiro[3][2] = []
          self.blita.remove(self.tabuleiro[2][3])
          self.tabuleiro[2][3] = []
          self.tabuleiro[1][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,4] and (self.pos_vazia == (251,195) or self.pos_vazia == (368,194) or self.pos_vazia == (193,135) or self.pos_vazia == (425,135)):
        self.jogada_branca = False
        if self.pos_vazia == (251,195):
          self.tabuleiro[3][4] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia  == (368,194):
          self.tabuleiro[3][4] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,135) and self.tabuleiro[2][3] in self.peca and self.tabuleiro[1][2] == []:
          self.tabuleiro[3][4] = []
          self.blita.remove(self.tabuleiro[2][3])
          self.tabuleiro[2][3] = []
          self.tabuleiro[1][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (425,135) and self.tabuleiro[2][5] in self.peca and self.tabuleiro[1][6] == []:
          self.tabuleiro[3][4] = []
          self.blita.remove(self.tabuleiro[2][5])
          self.tabuleiro[2][5] = []
          self.tabuleiro[1][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,6] and (self.pos_vazia == (368,194) or self.pos_vazia == (485,194) or self.pos_vazia == (310,135)):
        self.jogada_branca = False
        if self.pos_vazia == (368,194):
          self.tabuleiro[3][6] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (485,194):
          self.tabuleiro[3][6] = []
          self.tabuleiro[2][7] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,135) and self.tabuleiro[2][5] in self.peca and self.tabuleiro[1][4] == []:
          self.tabuleiro[3][6] = []
          self.blita.remove(self.tabuleiro[2][5])
          self.tabuleiro[2][5] = []
          self.tabuleiro[1][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [6,5] and (self.pos_vazia == (310,368) or self.pos_vazia == (425,370) or self.pos_vazia == (252,310) or self.pos_vazia == (484,310)):
        self.jogada_branca = False
        if self.pos_vazia == (310,368):
          self.tabuleiro[6][5] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
          self.tabuleiro[6][5] = []
        if self.pos_vazia == (425,370):
          self.tabuleiro[6][5] = []
          self.tabuleiro[5][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (252,310) and self.tabuleiro[5][4] in self.peca:
          self.tabuleiro[6][5] = []
          self.blita.remove(self.tabuleiro[5][4])
          self.tabuleiro[5][4] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,310) and self.tabuleiro[5][6] in self.peca:
          self.tabuleiro[6][5] = []
          self.blita.remove(self.tabuleiro[5][6])
          self.tabuleiro[5][6] = []
          self.tabuleiro[4][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [6,7] and (self.pos_vazia == (425,370) or self.pos_vazia == (368,310)):
        self.jogada_branca = False
        if self.pos_vazia == (425,370):
          self.tabuleiro[6][7] = []
          self.tabuleiro[5][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,310) and self.tabuleiro[5][6] in self.peca and self.tabuleiro[4][5] == []:
          self.tabuleiro[6][7] = []
          self.blita.remove(self.tabuleiro[5][6])
          self.tabuleiro[5][6] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [7,0] and (self.pos_vazia == (136,427) or self.pos_vazia == (192,370)):
        self.jogada_branca = False
        if self.pos_vazia == (136,427):
          self.tabuleiro[7][0] = []
          self.tabuleiro[6][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (192,370) and self.tabuleiro[6][1] in self.peca and self.tabuleiro[5][2] == []:
          self.tabuleiro[7][0] = []
          self.blita.remove(self.tabuleiro[6][1])
          self.tabuleiro[6][1] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [7,2] and (self.pos_vazia == (136,427) or self.pos_vazia == (251,427) or self.pos_vazia == (77,370) or self.pos_vazia == (310,368)):
        self.jogada_branca = False
        if self.pos_vazia == (136,427):
          self.tabuleiro[7][2] = []
          self.tabuleiro[6][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,427):
          self.tabuleiro[7][2] = []
          self.tabuleiro[6][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (77,370) and self.tabuleiro[6][1] in self.peca and self.tabuleiro[5][0] == []:
          self.tabuleiro[7][2] = []
          self.blita.remove(self.tabuleiro[6][1])
          self.tabuleiro[6][1] = []
          self.tabuleiro[5][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,368) and self.tabuleiro[6][3] in self.peca and self.tabuleiro[5][4] == []:
          self.tabuleiro[7][2] = []
          self.blita.remove(self.tabuleiro[6][3])
          self.tabuleiro[6][3] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [7,4] and (self.pos_vazia == (251,427) or self.pos_vazia == (368,427) or self.pos_vazia == (192,370) or self.pos_vazia == (425,370)):
        self.jogada_branca = False
        if self.pos_vazia == (251,427):
          self.tabuleiro[7][4] = []
          self.tabuleiro[6][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,427):
          self.tabuleiro[7][4] = []
          self.tabuleiro[6][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (192,370) and self.tabuleiro[6][3] in self.peca and self.tabuleiro[5][2] == []:
          self.tabuleiro[7][4] = []
          self.blita.remove(self.tabuleiro[6][3])
          self.tabuleiro[6][3] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (425,370) and self.tabuleiro[6][5] in self.peca and self.tabuleiro[5][6] == []:
          self.tabuleiro[7][4] = []
          self.blita.remove(self.tabuleiro[6][5])
          self.tabuleiro[6][5] = []
          self.tabuleiro[5][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [7,6] and (self.pos_vazia == (368,427) or self.pos_vazia == (484,427) or self.pos_vazia == (310,368)):
        self.jogada_branca = False
        if self.pos_vazia == (368,427):
          self.tabuleiro[7][6] = []
          self.tabuleiro[6][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,427):
          self.tabuleiro[7][6] = []
          self.tabuleiro[6][7] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,368) and self.tabuleiro[6][5] in self.peca and self.tabuleiro[5][4] == []:
          self.tabuleiro[7][6] = []
          self.blita.remove(self.tabuleiro[6][5])
          self.tabuleiro[6][5] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,0] and self.pos_vazia == (135,78):
        self.jogada_branca = False
        dama.troca_dama()
        self.tabuleiro[1][0] = []
        self.tabuleiro[0][1] = self.pos_ocupada
        self.jogada = True
      elif self.indice == [1,2] and (self.pos_vazia == (135,78) or self.pos_vazia == (251,78)):
        self.jogada_branca = False
        self.tabuleiro[1][2] = []
        if self.pos_vazia == (135,78):
          dama.troca_dama()
          self.tabuleiro[0][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,78):
          dama.troca_dama()
          self.tabuleiro[0][3] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,4] and (self.pos_vazia == (251,78) or self.pos_vazia == (367,75)):
        self.jogada_branca = False
        self.tabuleiro[1][4] = []
        if self.pos_vazia == (251,78):
          dama.troca_dama()
          self.tabuleiro[0][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (367,75):
          dama.troca_dama()
          self.tabuleiro[0][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,6] and (self.pos_vazia == (367,75) or self.pos_vazia == (484,78)):
        self.jogada_branca = False
        self.tabuleiro[1][6] = []
        if self.pos_vazia == (367,75):
          dama.troca_dama()
          self.tabuleiro[0][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,78):
          dama.troca_dama()
          self.tabuleiro[0][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,1] and (self.pos_vazia == (77,135) or self.pos_vazia == (193,135) or self.pos_vazia == (251,78)):
        self.jogada_branca = False
        if self.pos_vazia == (77,135):
          self.tabuleiro[2][1] = []
          self.tabuleiro[1][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,135):
          self.tabuleiro[2][1] = []
          self.tabuleiro[1][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,78) and self.tabuleiro[1][2] in self.peca and self.tabuleiro[0][3] == []:
          dama.troca_dama()
          self.tabuleiro[2][1] = []
          self.blita.remove(self.tabuleiro[1][2])
          self.tabuleiro[1][2] = []
          self.tabuleiro[0][3] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,3] and (self.pos_vazia == (193,135) or self.pos_vazia == (310,135) or self.pos_vazia == (135,78) or self.pos_vazia == (367,75)):
        self.jogada_branca = False
        if self.pos_vazia == (193,135):
          self.tabuleiro[2][3] = []
          self.tabuleiro[1][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,135):
          self.tabuleiro[2][3] = []
          self.tabuleiro[1][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (135,78) and self.tabuleiro[1][2] in self.peca and self.tabuleiro[0][1] == []:
          dama.troca_dama()
          self.tabuleiro[2][3] = []
          self.blita.remove(self.tabuleiro[1][2])
          self.tabuleiro[1][2] = []
          self.tabuleiro[0][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (367,75) and self.tabuleiro[1][4] in self.peca and self.tabuleiro[0][5] == []:
          self.jogada_branca = False
          dama.troca_dama()
          self.tabuleiro[2][3] = []
          self.blita.remove(self.tabuleiro[1][4])
          self.tabuleiro[1][4] = []
          self.tabuleiro[0][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,5] and (self.pos_vazia == (310,135) or self.pos_vazia == (425,135) or self.pos_vazia == (251,78) or self.pos_vazia == (484,78)):
        self.jogada_branca = False
        if self.pos_vazia == (310,135):
          self.tabuleiro[2][5] = []
          self.tabuleiro[1][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (425,135):
          self.tabuleiro[2][5] = []
          self.tabuleiro[1][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,78) and self.tabuleiro[1][4] in self.peca and self.tabuleiro[0][3] == []:
          dama.troca_dama()
          self.tabuleiro[2][5] = []
          self.blita.remove(self.tabuleiro[1][4])
          self.tabuleiro[1][4] = []
          self.tabuleiro[0][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,78) and self.tabuleiro[1][6] in self.peca and self.tabuleiro[0][7] == []:
          dama.troca_dama()
          self.tabuleiro[2][5] = []
          self.blita.remove(self.tabuleiro[1][6])
          self.tabuleiro[1][6] = []
          self.tabuleiro[0][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,7] and (self.pos_vazia == (425,135) or self.pos_vazia == (367,75)):
        self.jogada_branca = False
        if self.pos_vazia == (425,135):
          self.tabuleiro[2][7] = []
          self.tabuleiro[1][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (367,75) and self.tabuleiro[1][6] in self.peca and self.tabuleiro[0][5] == []:
          dama.troca_dama()
          self.tabuleiro[2][7] = []
          self.blita.remove(self.tabuleiro[1][6])
          self.tabuleiro[1][6] = []
          self.tabuleiro[0][5] = self.pos_ocupada
          self.jogada = True
    elif self.pos_ocupada in self.peca and  self.jogada_branca == False: # obnwtjehnyrhn ytk,meyujmyjui,tuhjmmukmweyhtrgbnh
      if self.indice == [2,1] and (self.pos_vazia == (73,255) or self.pos_vazia == (193,250) or self.pos_vazia == (252,310)):
        self.jogada_branca = True
        if self.pos_vazia == (73,255):
          self.tabuleiro[2][1] = []
          self.tabuleiro[3][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,250):
          self.tabuleiro[2][1] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (252,310) and self.tabuleiro[3][2] in self.branco and self.tabuleiro[4][3] == []:
          self.tabuleiro[2][1] = []
          self.blita.remove(self.tabuleiro[3][2])
          self.tabuleiro[3][2] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,3] and (self.pos_vazia == (193,250) or self.pos_vazia == (310,250) or self.pos_vazia == (134,310) or self.pos_vazia == (368,310)):
        self.jogada_branca = True
        if self.pos_vazia == (193,250):
          self.tabuleiro[2][3] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,250):
          self.tabuleiro[2][3] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (134,310) and self.tabuleiro[3][2] in self.branco and self.tabuleiro[4][1] == []:
          self.tabuleiro[2][3] = []
          self.blita.remove(self.tabuleiro[3][2])
          self.tabuleiro[3][2] = []
          self.tabuleiro[4][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,310) and self.tabuleiro[3][4] in self.branco and self.tabuleiro[4][5] == []:
          self.tabuleiro[2][3] = []
          self.blita.remove(self.tabuleiro[3][4])
          self.tabuleiro[3][4] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,5] and (self.pos_vazia == (310,250) or self.pos_vazia == (426,250) or self.pos_vazia == (252,310) or self.pos_vazia == (484,310)):
        self.jogada_branca = True
        if self.pos_vazia == (310,250):
          self.tabuleiro[2][5] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (426,250):
          self.tabuleiro[2][5] = []
          self.tabuleiro[3][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (252,310) and self.tabuleiro[3][4] in self.branco and self.tabuleiro[4][3] == []:
          self.tabuleiro[2][5] = []
          self.blita.remove(self.tabuleiro[3][4])
          self.tabuleiro[3][4] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,310) and self.tabuleiro[3][6] in self.branco and self.tabuleiro[4][7] == []:
          self.tabuleiro[2][5] = []
          self.blita.remove(self.tabuleiro[3][6])
          self.tabuleiro[3][6] = []
          self.tabuleiro[4][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [2,7] and (self.pos_vazia == (426,250) or self.pos_vazia == (368,310)):
        self.jogada_branca = True
        if self.pos_vazia == (426,250):
          self.tabuleiro[2][7] = []
          self.tabuleiro[3][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,310) and self.tabuleiro[3][6] in self.branco and self.tabuleiro[4][5] == []:
          self.tabuleiro[2][7] = []
          self.blita.remove(self.tabuleiro[3][6])
          self.tabuleiro[3][6] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,0] and (self.pos_vazia == (134,310) or self.pos_vazia == (192,370)):
        self.jogada_branca = True
        if self.pos_vazia == (134,310):
          self.tabuleiro[3][0] = []
          self.tabuleiro[4][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (192,370) and self.tabuleiro[4][1] in self.branco and self.tabuleiro[5][2] == []:
          self.tabuleiro[3][0] = []
          self.blita.remove(self.tabuleiro[4][1])
          self.tabuleiro[4][1] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,2] and (self.pos_vazia == (134,310) or self.pos_vazia == (252,310) or self.pos_vazia == (77,370) or self.pos_vazia == (310,368)):
        self.jogada_branca = True
        if self.pos_vazia == (134,310):
          self.tabuleiro[3][2] = []
          self.tabuleiro[4][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (252,310):
          self.tabuleiro[3][2] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (77,370) and self.tabuleiro[4][1] in self.branco and self.tabuleiro[5][0] == []:
          self.tabuleiro[3][2] = []
          self.blita.remove(self.tabuleiro[4][1])
          self.tabuleiro[4][1] = []
          self.tabuleiro[5][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,368) and self.tabuleiro[4][3] in self.branco and self.tabuleiro[5][4] == []:
          self.tabuleiro[3][2] = []
          self.blita.remove(self.tabuleiro[4][3])
          self.tabuleiro[4][3] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,4] and (self.pos_vazia == (252,310) or self.pos_vazia == (368,310) or self.pos_vazia == (192,370) or self.pos_vazia == (425,370)):
        self.jogada_branca = True
        if self.pos_vazia == (252,310):
          self.tabuleiro[3][4] = []
          self.tabuleiro[4][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,310):
          self.tabuleiro[3][4] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia ==(192,370) and self.tabuleiro[4][3] in self.branco and self.tabuleiro[5][2] == []:
          self.tabuleiro[3][4] = []
          self.blita.remove(self.tabuleiro[4][3])
          self.tabuleiro[4][3] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (425,370) and self.tabuleiro[4][5] in self.branco and self.tabuleiro[5][6] == []:
          self.tabuleiro[3][4] = []
          self.blita.remove(self.tabuleiro[4][5])
          self.tabuleiro[4][5] = []
          self.tabuleiro[5][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [3,6] and (self.pos_vazia == (368,310) or self.pos_vazia == (484,310) or self.pos_vazia == (310,368)):
        self.jogada_branca = True
        if self.pos_vazia == (368,310):
          self.tabuleiro[3][6] = []
          self.tabuleiro[4][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,310):
          self.tabuleiro[3][6] = []
          self.tabuleiro[4][7] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,368) and self.tabuleiro[4][5] in self.branco and self.tabuleiro[5][4] == []:
          self.tabuleiro[3][6] = []
          self.blita.remove(self.tabuleiro[4][5])
          self.tabuleiro[4][5] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,1] and (self.pos_vazia == (77,370) or self.pos_vazia == (192,370) or self.pos_vazia == (251,427)):
        self.jogada_branca = True
        if self.pos_vazia == (77,370):
          self.tabuleiro[4][1] = []
          self.tabuleiro[5][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (192,370):
          self.tabuleiro[4][1] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,427) and self.tabuleiro[5][2] in self.branco and self.tabuleiro[6][3] == []:
          self.tabuleiro[4][1] = []
          self.blita.remove(self.tabuleiro[5][2])
          self.tabuleiro[5][2] = []
          self.tabuleiro[6][3] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,3] and (self.pos_vazia == (192,370) or self.pos_vazia == (310,368) or self.pos_vazia == (136,427) or self.pos_vazia == (368,427)):
        self.jogada_branca = True
        if self.pos_vazia == (192,370):
          self.tabuleiro[4][3] = []
          self.tabuleiro[5][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,368):
          self.tabuleiro[4][3] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (136,427) and self.tabuleiro[5][2] in self.branco and self.tabuleiro[6][1] == []:
          self.tabuleiro[4][3] = []
          self.blita.remove(self.tabuleiro[5][2])
          self.tabuleiro[5][2] = []
          self.tabuleiro[6][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,427) and self.tabuleiro[5][4] in self.branco and self.tabuleiro[6][5] == []:
          self.tabuleiro[4][3] = []
          self.blita.remove(self.tabuleiro[5][4])
          self.tabuleiro[5][4] = []
          self.tabuleiro[6][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,5] and (self.pos_vazia == (310,368) or self.pos_vazia == (425,370) or self.pos_vazia == (251,427) or self.pos_vazia == (484,427)):
        self.jogada_branca = True
        if self.pos_vazia == (310,368):
          self.tabuleiro[4][5] = []
          self.tabuleiro[5][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (425,370):
          self.tabuleiro[4][5] = []
          self.tabuleiro[5][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,427) and self.tabuleiro[5][4] in self.branco and self.tabuleiro[6][3] == []:
          self.tabuleiro[4][5] = []
          self.blita.remove(self.tabuleiro[5][4])
          self.tabuleiro[5][4] = []
          self.tabuleiro[6][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,427) and self.tabuleiro[5][6] in self.branco and self.tabuleiro[6][7] == []:
          self.tabuleiro[4][5] = []
          self.blita.remove(self.tabuleiro[5][6])
          self.tabuleiro[5][6] = []
          self.tabuleiro[6][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [4,7] and (self.pos_vazia == (425,370) or self.pos_vazia == (368,427)):
        self.jogada_branca = True
        if self.pos_vazia == (425,370):
          self.tabuleiro[4][7] = []
          self.tabuleiro[5][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,427) and self.tabuleiro[5][6] in self.branco and self.tabuleiro[6][5] == []:
          self.tabuleiro[4][7] = []
          self.blita.remove(self.tabuleiro[5][6])
          self.tabuleiro[5][6] = []
          self.tabuleiro[6][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,0] and (self.pos_vazia == (136,427) or self.pos_vazia == (194,485)):
        self.jogada_branca = True
        if self.pos_vazia == (136,427):
          self.tabuleiro[5][0] = []
          self.tabuleiro[6][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (194,485) and self.tabuleiro[6][1] in self.branco and self.tabuleiro[7][2] == []:
          dama.troca_dama()
          self.tabuleiro[5][0] = []
          self.blita.remove(self.tabuleiro[6][1])
          self.tabuleiro[6][1] = []
          self.tabuleiro[7][2] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,2] and (self.pos_vazia == (136,427) or self.pos_vazia == (251,427) or self.pos_vazia == (78,485) or self.pos_vazia == (310,485)):
        self.jogada_branca = True
        if self.pos_vazia == (136,427):
          self.tabuleiro[5][2] = []
          self.tabuleiro[6][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,427):
          self.tabuleiro[5][2] = []
          self.tabuleiro[6][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (78,485) and self.tabuleiro[6][1] in self.branco and self.tabuleiro[7][0] == []:
          dama.troca_dama()
          self.tabuleiro[5][2] = []
          self.blita.remove(self.tabuleiro[6][1])
          self.tabuleiro[6][1] = []
          self.tabuleiro[7][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,485) and self.tabuleiro[6][3] in self.branco and self.tabuleiro[7][4] == []:
          dama.troca_dama()
          self.tabuleiro[5][2] = []
          self.blita.remove(self.tabuleiro[6][3])
          self.tabuleiro[6][3] = []
          self.tabuleiro[7][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,4] and (self.pos_vazia == (251,427) or self.pos_vazia == (368,427) or self.pos_vazia == (194,485) or self.pos_vazia == (426,485)):
        self.jogada_branca = True
        if self.pos_vazia == (251,427):
          self.tabuleiro[5][4] = []
          self.tabuleiro[6][3] = self.pos_ocupada
          self.jogada = True    
        if self.pos_vazia == (368,427):
          self.tabuleiro[5][4] = []
          self.tabuleiro[6][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (194,485) and self.tabuleiro[6][3] in self.branco and self.tabuleiro[7][2] == []:
          dama.troca_dama()
          self.tabuleiro[5][4] = []
          self.blita.remove(self.tabuleiro[6][3])
          self.tabuleiro[6][3] = []
          self.tabuleiro[7][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (426,485) and self.tabuleiro[6][5] in self.branco and self.tabuleiro[7][6] == []:
          dama.troca_dama()
          self.tabuleiro[5][4] = []
          self.blita.remove(self.tabuleiro[6][5])
          self.tabuleiro[6][5] = []
          self.tabuleiro[7][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [5,6] and (self.pos_vazia == (368,427) or self.pos_vazia == (484,427) or self.pos_vazia == (310,485)):
        self.jogada_branca = True
        if self.pos_vazia == (368,427):
          self.tabuleiro[5][6] = []
          self.tabuleiro[6][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (484,427):
          self.tabuleiro[5][6] = []
          self.tabuleiro[6][7] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,485) and self.tabuleiro[6][5] in self.branco and self.tabuleiro[7][4] == []:
          dama.troca_dama()
          self.tabuleiro[5][6] = []
          self.blita.remove(self.tabuleiro[6][5])
          self.tabuleiro[6][5] = []
          self.tabuleiro[7][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [6,1] and (self.pos_vazia == (78,485) or self.pos_vazia == (194,485)):
        self.jogada_branca = True
        self.tabuleiro[6][1] = []
        if self.pos_vazia == (78,485):
          dama.troca_dama()
          self.tabuleiro[7][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (194,485):
          dama.troca_dama()
          self.tabuleiro[7][2] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [6,3] and (self.pos_vazia == (194,485) or self.pos_vazia == (310,485)):
        self.jogada_branca = True
        self.tabuleiro[6][3] = []
        if self.pos_vazia == (194,485):
          dama.troca_dama()
          self.tabuleiro[7][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,485):
          dama.troca_dama()
          self.tabuleiro[7][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [6,5] and (self.pos_vazia == (310,485) or self.pos_vazia == (426,485)):
        self.jogada_branca = True
        self.tabuleiro[6][5] = []
        if self.pos_vazia == (310,485):
          dama.troca_dama()
          self.tabuleiro[7][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (426,485):
          dama.troca_dama()
          self.tabuleiro[7][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [6,7] and self.pos_vazia == (426,485):
        self.jogada_branca = True
        dama.troca_dama()
        self.tabuleiro[6][7] = []
        self.tabuleiro[7][6] = self.pos_ocupada
        self.jogada = True
      elif self.indice == [0,1] and (self.pos_vazia == (77,135) or self.pos_vazia == (193,135) or self.pos_vazia == (251,195)):
        self.jogada_branca = True
        if self.pos_vazia == (77,135):
          self.tabuleiro[0][1] = []
          self.tabuleiro[1][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,135):
          self.tabuleiro[0][1] = []
          self.tabuleiro[1][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,195) and self.tabuleiro[1][2] in self.branco and self.tabuleiro[2][3] == []:
          self.tabuleiro[0][1] = []
          self.blita.remove(self.tabuleiro[1][2])
          self.tabuleiro[1][2] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [0,3] and (self.pos_vazia == (193,135) or self.pos_vazia == (310,135) or self.pos_vazia == (135,195) or self.pos_vazia == (368,194)):
        self.jogada_branca = True
        if self.pos_vazia == (193,135):
          self.tabuleiro[0][3] = []
          self.tabuleiro[1][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,135):
          self.tabuleiro[0][3] = []
          self.tabuleiro[1][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (135,195) and self.tabuleiro[1][2] in self.branco and self.tabuleiro[2][1] == []:
          self.tabuleiro[0][3] = []
          self.blita.remove(self.tabuleiro[1][2])
          self.tabuleiro[1][2] = []
          self.tabuleiro[2][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,194) and self.tabuleiro[1][4] in self.branco and self.tabuleiro[2][5] == []:
          self.tabuleiro[0][3] = []
          self.blita.remove(self.tabuleiro[1][4])
          self.tabuleiro[1][4] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [0,5] and (self.pos_vazia == (310,135) or self.pos_vazia == (425,135) or self.pos_vazia == (251,195) or self.pos_vazia == (485,194)):
        self.jogada_branca = True
        if self.pos_vazia == (310,135):
          self.tabuleiro[0][5] = []
          self.tabuleiro[1][4] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (425,135):
          self.tabuleiro[0][5] = []
          self.tabuleiro[1][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,195) and self.tabuleiro[1][4] in self.branco and self.tabuleiro[2][3] == []:
          self.tabuleiro[0][5] = []
          self.blita.remove(self.tabuleiro[1][4])
          self.tabuleiro[1][4] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (485,194) and self.tabuleiro[1][6] in self.branco and self.tabuleiro[2][7] == []:
          self.tabuleiro[0][5] = []
          self.blita.remove(self.tabuleiro[1][6])
          self.tabuleiro[1][6] = []
          self.tabuleiro[2][7] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [0,7] and (self.pos_vazia == (425,135) or self.pos_vazia == (368,194)):
        self.jogada_branca = True
        if self.pos_vazia == (425,135):
          self.tabuleiro[0][7] = []
          self.tabuleiro[1][6] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,194) and self.tabuleiro[1][6] in self.branco and self.tabuleiro[2][5] == []:
          self.tabuleiro[0][7] = []
          self.blita.remove(self.tabuleiro[1][6])
          self.tabuleiro[1][6] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,0] and (self.pos_vazia == (135,195) or self.pos_vazia == (193,250)):
        self.jogada_branca = True
        if self.pos_vazia == (135,195):
          self.tabuleiro[1][0] = []
          self.tabuleiro[2][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,250) and self.tabuleiro[2][1] in self.branco and self.tabuleiro[3][2] == []:
          self.tabuleiro[1][0] = []
          self.blita.remove(self.tabuleiro[2][1])
          self.tabuleiro[2][1] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,2] and (self.pos_vazia == (135,195) or self.pos_vazia == (251,195) or self.pos_vazia == (73,255) or self.pos_vazia == (310,250)):
        self.jogada_branca = True
        if self.pos_vazia == (135,195):
          self.tabuleiro[1][2] = []
          self.tabuleiro[2][1] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (251,195):
          self.tabuleiro[1][2] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (73,255) and self.tabuleiro[2][1] in self.branco and self.tabuleiro[3][0] == []:
          self.tabuleiro[1][2] = []
          self.blita.remove(self.tabuleiro[2][1])
          self.tabuleiro[2][1] = []
          self.tabuleiro[3][0] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,250) and self.tabuleiro[2][3] in self.branco and self.tabuleiro[3][4] == []:
          self.tabuleiro[1][2] = []
          self.blita.remove(self.tabuleiro[2][3])
          self.tabuleiro[2][3] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,4] and (self.pos_vazia == (251,195) or self.pos_vazia == (368,194) or self.pos_vazia == (193,250) or self.pos_vazia == (426,250)):
        self.jogada_branca = True
        if self.pos_vazia == (251,195):
          self.tabuleiro[1][4] = []
          self.tabuleiro[2][3] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (368,194):
          self.tabuleiro[1][4] = []
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (193,250) and self.tabuleiro[2][3] in self.branco and self.tabuleiro[3][2] == []:
          self.tabuleiro[1][4] = []
          self.blita.remove(self.tabuleiro[2][3])
          self.tabuleiro[2][3] = []
          self.tabuleiro[3][2] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (426,250) and self.tabuleiro[2][5] in self.branco and self.tabuleiro[3][6] == []:
          self.tabuleiro[1][4] = []
          self.blita.remove(self.tabuleiro[2][5])
          self.tabuleiro[2][5] = []
          self.tabuleiro[3][6] = self.pos_ocupada
          self.jogada = True
      elif self.indice == [1,6] and (self.pos_vazia == (368,194) or self.pos_vazia == (485,194) or self.pos_vazia == (310,250)):
        self.jogada_branca = True
        if self.pos_vazia == (368,194):
          self.tabuleiro[1][6] = []                           
          self.tabuleiro[2][5] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (485,194):
          self.tabuleiro[1][6] = []          
          self.tabuleiro[2][7] = self.pos_ocupada
          self.jogada = True
        if self.pos_vazia == (310,250) and self.tabuleiro[2][5] in self.branco and self.tabuleiro[3][4] == []:
          self.tabuleiro[1][6] = []
          self.blita.remove(self.tabuleiro[2][5])
          self.tabuleiro[2][5] = []
          self.tabuleiro[3][4] = self.pos_ocupada
          self.jogada = True
    else:
      self.jogada = False
      self.pos_vazia = ()
    
           
   
  def move(self):
    if self.jogada == True:
      if self.pos_ocupada == [self.peca1] and self.pos_vazia != ():
        self.po2 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca2] and self.pos_vazia != ():
        self.po3 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca3] and self.pos_vazia != ():
        self.po4 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca4] and self.pos_vazia != ():
        self.po5 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca5] and self.pos_vazia != ():
        self.po6 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca6] and self.pos_vazia != ():
        self.po7 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca7] and self.pos_vazia != ():
        self.po8 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca8] and self.pos_vazia != ():
        self.po9 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca9] and self.pos_vazia != ():
        self.po10 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca10] and self.pos_vazia != ():
        self.po11 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca11]  and self.pos_vazia != ():
        self.po12 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.peca12] and self.pos_vazia != ():
        self.po13 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco1] and self.pos_vazia != ():
        self.po14 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco2] and self.pos_vazia != ():
        self.po15 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco3] and self.pos_vazia != ():
        self.po16 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco4] and self.pos_vazia != ():
        self.po17 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco5] and self.pos_vazia != ():
        self.po18 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco6] and self.pos_vazia != ():
        self.po19 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco7] and self.pos_vazia != ():
        self.po20 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco8] and self.pos_vazia != ():
        self.po21 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco9] and self.pos_vazia != ():
        self.po22 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco10] and self.pos_vazia != ():
        self.po23 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco11] and self.pos_vazia != ():
        self.po24 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
      if self.pos_ocupada == [self.branco12] and self.pos_vazia != ():
        self.po25 = self.pos_vazia
        self.pos_ocupada = 0
        self.pos_vazia = ()
        
  def movimento_dama(self):
    if self.indice == [5,0] and (self.pos_vazia == (134,310) or self.pos_vazia == (193,250)):
      if self.pos_vazia == (134,310):
        self.tabuleiro[5][0] = []
        self.tabuleiro[4][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,250) and (self.tabuleiro[4][1] in self.peca and self.tabuleiro[5][0] in self.branco or self.tabuleiro[4][1] in self.branco and self.tabuleiro[5][0] in self.peca) and self.tabuleiro[3][2] == []:
        self.tabuleiro[5][0] = []
        self.blita.remove(self.tabuleiro[4][1])
        self.tabuleiro[3][2] = self.pos_ocupada
        self.tabuleiro[4][1] = []
        self.jogada = True
    elif self.indice == [6,1] and (self.pos_vazia == (77,370) or self.pos_vazia == (192,370) or self.pos_vazia == (252,310)):
      if self.pos_vazia == (77,370):
        self.tabuleiro[6][1] = []
        self.tabuleiro[5][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (192,370):
        self.tabuleiro[6][1] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (252,310) and (self.tabuleiro[6][1] in self.peca and self.tabuleiro[5][2] in self.branco or self.tabuleiro[6][1] in self.branco and self.tabuleiro[5][2] in self.peca) and self.tabuleiro[4][3] == []:
        self.tabuleiro[6][1] = []
        self.blita.remove(self.tabuleiro[5][2])
        self.tabuleiro[4][3] = self.pos_ocupada
        self.tabuleiro[5][2] = []
        self.jogada = True
    elif self.indice == [6,3] and (self.pos_vazia == (192,370) or self.pos_vazia == (310,368) or self.pos_vazia == (134,310) or self.pos_vazia == (368,310)):
      if self.pos_vazia == (192,370):
        self.tabuleiro[6][3] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,368):
        self.tabuleiro[6][3] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (134,310) and ((self.tabuleiro[6][3] in self.peca and (self.tabuleiro[5][2] in self.branco or self.tabuleiro[5][4] in self.branco)) or (self.tabuleiro[6][3] in self.branco and (self.tabuleiro[5][2] in self.peca or self.tabuleiro[5][4] in self.peca))) and self.tabuleiro[4][1] == []:
        self.tabuleiro[6][3] = []
        self.blita.remove(self.tabuleiro[5][2])
        self.tabuleiro[5][2] = []
        self.tabuleiro[4][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,310) and ((self.tabuleiro[6][3] in self.branco and (self.tabuleiro[5][2] in self.peca or self.tabuleiro[5][4] in self.peca)) or (self.tabuleiro[6][3] in self.peca and (self.tabuleiro[5][2] in self.branco or self.tabuleiro[5][4] in self.branco))) and self.tabuleiro[4][5] == []:                                         
        self.tabuleiro[6][3] = []
        self.blita.remove(self.tabuleiro[5][4])
        self.tabuleiro[5][4] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,1] and (self.pos_vazia == (193,250) or self.pos_vazia == (73,255) or self.pos_vazia == (251,195)):
      if self.pos_vazia == (193,250):
        self.tabuleiro[4][1] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (73,255):
        self.tabuleiro[4][1] = []
        self.tabuleiro[3][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,195) and ((self.tabuleiro[4][1] in self.peca and self.tabuleiro[3][2] in self.branco) or (self.tabuleiro[4][1] in self.branco and self.tabuleiro[3][2] in self.peca)) and self.tabuleiro[2][3] == []:
        self.tabuleiro[4][1] = []
        self.blita.remove(self.tabuleiro[3][2])
        self.tabuleiro[3][2] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,2] and (self.pos_vazia == (134,310) or self.pos_vazia == (252,310) or self.pos_vazia == (73,255) or self.pos_vazia == (310,250)):
      if self.pos_vazia == (134,310):
        self.tabuleiro[5][2] = []
        self.tabuleiro[4][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (252,310):
        self.tabuleiro[5][2] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (73,255) and (self.tabuleiro[5][2] in self.peca and (self.tabuleiro[4][1] in self.branco or self.tabuleiro[4][3] in self.branco) or self.tabuleiro[5][2] in self.branco and (self.tabuleiro[4][1] in self.peca or self.tabuleiro[4][3] in self.peca)) and self.tabuleiro[3][0] == []:
        self.tabuleiro[5][2] = []
        self.blita.remove(self.tabuleiro[4][1])
        self.tabuleiro[4][1] = []
        self.tabuleiro[3][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,250) and (self.tabuleiro[5][2] in self.peca and (self.tabuleiro[4][1] in self.branco or self.tabuleiro[4][3] in self.branco) or self.tabuleiro[5][2] in self.branco and (self.tabuleiro[4][1] in self.peca or self.tabuleiro[4][3] in self.peca)) and self.tabuleiro[3][4] == []:
        self.tabuleiro[5][2] = []
        self.blita.remove(self.tabuleiro[4][3])
        self.tabuleiro[4][3] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,4] and (self.pos_vazia == (252,310) or self.pos_vazia == (368,310) or self.pos_vazia == (193,250) or self.pos_vazia == (426,250)):
      if self.pos_vazia == (252,310):
        self.tabuleiro[5][4] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,310):
        self.tabuleiro[5][4] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,250) and (self.tabuleiro[5][4] in self.peca and (self.tabuleiro[4][3] in self.branco) or self.tabuleiro[5][4] in self.branco and (self.tabuleiro[4][3] in self.peca)) and self.tabuleiro[3][2] == []:
        self.tabuleiro[5][4] = []
        self.blita.remove(self.tabuleiro[4][3])
        self.tabuleiro[4][3] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (426,250) and (self.tabuleiro[5][4] in self.peca and (self.tabuleiro[4][5] in self.branco) or self.tabuleiro[5][4] in self.branco and (self.tabuleiro[4][5] in self.peca)) and self.tabuleiro[3][6] == []:
        self.tabuleiro[5][4] = []
        self.blita.remove(self.tabuleiro[4][5])
        self.tabuleiro[4][5] = []
        self.tabuleiro[3][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,6] and (self.pos_vazia == (368,310) or self.pos_vazia == (484,310) or self.pos_vazia == (310,250)):
      if self.pos_vazia == (368,310):
        self.tabuleiro[5][6] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,310):
        self.tabuleiro[5][6] = []
        self.tabuleiro[4][7] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,250) and (self.tabuleiro[5][6] in self.peca and (self.tabuleiro[4][5] in self.branco) or self.tabuleiro[5][6] in self.branco and (self.tabuleiro[4][5] in self.peca)) and self.tabuleiro[3][4] == []:
        self.tabuleiro[5][6] = []
        self.blita.remove(self.tabuleiro[4][5])
        self.tabuleiro[4][5] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,3] and (self.pos_vazia == (193,250) or self.pos_vazia == (310,250) or self.pos_vazia == (135,195) or self.pos_vazia == (368,194)):
      if self.pos_vazia == (193,250):
        self.tabuleiro[4][3] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,250):
        self.tabuleiro[4][3] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (135,195) and (self.tabuleiro[4][3] in self.peca and (self.tabuleiro[3][2] in self.branco) or self.tabuleiro[4][3] in self.branco and (self.tabuleiro[3][2] in self.peca)) and self.tabuleiro[2][1] == []:
        self.tabuleiro[4][3] = []
        self.blita.remove(self.tabuleiro[3][2])
        self.tabuleiro[3][2] = []
        self.tabuleiro[2][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,194) and (self.tabuleiro[4][3] in self.peca and (self.tabuleiro[3][4] in self.branco) or self.tabuleiro[4][3] in self.branco and (self.tabuleiro[3][4] in self.peca)) and self.tabuleiro[2][5] == []:
        self.tabuleiro[4][3] = []
        self.blita.remove(self.tabuleiro[3][4])
        self.tabuleiro[3][4] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,5] and (self.pos_vazia == (310,250) or self.pos_vazia == (426,250) or self.pos_vazia == (251,195) or self.pos_vazia == (485,194)):
      if self.pos_vazia == (310,250):
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
        self.tabuleiro[4][5] = []
      if self.pos_vazia == (426,250):
        self.tabuleiro[3][6] = self.pos_ocupada
        self.jogada = True
        self.tabuleiro[4][5] = []
      if self.pos_vazia == (251,195) and (self.tabuleiro[4][5] in self.peca and (self.tabuleiro[3][4] in self.branco) or self.tabuleiro[4][5] in self.branco and (self.tabuleiro[3][4] in self.peca)) and self.tabuleiro[2][3] == []:
        self.tabuleiro[4][5] = []
        self.blita.remove(self.tabuleiro[3][4])
        self.tabuleiro[3][4] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (485,194) and (self.tabuleiro[4][5] in self.peca and (self.tabuleiro[3][6] in self.branco) or self.tabuleiro[4][5] in self.branco and (self.tabuleiro[3][6] in self.peca)) and self.tabuleiro[2][7] == []:
        self.tabuleiro[4][5] = []
        self.blita.remove(self.tabuleiro[3][6])
        self.tabuleiro[3][6] = []
        self.tabuleiro[2][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,7] and (self.pos_vazia == (426,250) or self.pos_vazia == (368,194)):
      if self.pos_vazia == (426,250):
        self.tabuleiro[4][7] = []
        self.tabuleiro[3][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,194) and (self.tabuleiro[4][7] in self.peca and (self.tabuleiro[3][6] in self.branco) or self.tabuleiro[4][7] in self.branco and (self.tabuleiro[3][6] in self.peca)) and self.tabuleiro[2][5] == []:
        self.tabuleiro[4][7] = []
        self.blita.remove(self.tabuleiro[3][6])
        self.tabuleiro[3][6] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,0] and (self.pos_vazia == (135,195) or self.pos_vazia == (193,135)):
      if self.pos_vazia == (135,195):
        self.tabuleiro[3][0] = []
        self.tabuleiro[2][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,135) and (self.tabuleiro[3][0] in self.peca and (self.tabuleiro[2][1] in self.branco) or self.tabuleiro[3][0] in self.branco and (self.tabuleiro[2][1] in self.peca)) and self.tabuleiro[1][2] == []:
        self.tabuleiro[3][0] = []
        self.blita.remove(self.tabuleiro[2][1])
        self.tabuleiro[2][1] = []
        self.tabuleiro[1][2] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,2] and (self.pos_vazia == (135,195) or self.pos_vazia == (251,195) or self.pos_vazia == (77,135) or self.pos_vazia == (310,135)):
      if self.pos_vazia == (135,195):
        self.tabuleiro[3][2] = []
        self.tabuleiro[2][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,195):
        self.tabuleiro[3][2] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (77,135) and (self.tabuleiro[3][2] in self.peca and (self.tabuleiro[2][1] in self.branco) or self.tabuleiro[3][2] in self.branco and (self.tabuleiro[2][1] in self.peca)) and self.tabuleiro[1][0] == []:
        self.tabuleiro[3][2] = []
        self.blita.remove(self.tabuleiro[2][1])
        self.tabuleiro[2][1] = []
        self.tabuleiro[1][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,135) and (self.tabuleiro[3][2] in self.peca and (self.tabuleiro[2][3] in self.branco) or self.tabuleiro[3][2] in self.branco and (self.tabuleiro[2][3] in self.peca)) and self.tabuleiro[1][4] == []:
        self.tabuleiro[3][2] = []
        self.blita.remove(self.tabuleiro[2][3])
        self.tabuleiro[2][3] = []
        self.tabuleiro[1][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,4] and (self.pos_vazia == (251,195) or self.pos_vazia == (368,194) or self.pos_vazia == (193,135) or self.pos_vazia == (425,135)):
      if self.pos_vazia == (251,195):
        self.tabuleiro[3][4] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia  == (368,194):
        self.tabuleiro[3][4] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,135) and (self.tabuleiro[3][4] in self.peca and (self.tabuleiro[2][3] in self.branco) or self.tabuleiro[3][4] in self.branco and (self.tabuleiro[2][3] in self.peca)) and self.tabuleiro[1][2] == []:
        self.tabuleiro[3][4] = []
        self.blita.remove(self.tabuleiro[2][3])
        self.tabuleiro[2][3] = []
        self.tabuleiro[1][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (425,135) and (self.tabuleiro[3][4] in self.peca and (self.tabuleiro[2][5] in self.branco) or self.tabuleiro[3][4] in self.branco and (self.tabuleiro[2][5] in self.peca)) and self.tabuleiro[1][6] == []:
        self.tabuleiro[3][4] = []
        self.blita.remove(self.tabuleiro[2][5])
        self.tabuleiro[2][5] = []
        self.tabuleiro[1][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,6] and (self.pos_vazia == (368,194) or self.pos_vazia == (485,194) or self.pos_vazia == (310,135)):
      if self.pos_vazia == (368,194):
        self.tabuleiro[3][6] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (485,194):
        self.tabuleiro[3][6] = []
        self.tabuleiro[2][7] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,135) and (self.tabuleiro[3][6] in self.peca and (self.tabuleiro[2][5] in self.branco) or self.tabuleiro[3][6] in self.branco and (self.tabuleiro[2][5] in self.peca)) and self.tabuleiro[1][4] == []:
        self.tabuleiro[3][6] = []
        self.blita.remove(self.tabuleiro[2][5])
        self.tabuleiro[2][5] = []
        self.tabuleiro[1][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [6,5] and (self.pos_vazia == (310,368) or self.pos_vazia == (425,370) or self.pos_vazia == (252,310) or self.pos_vazia == (484,310)):
      if self.pos_vazia == (310,368):
        self.tabuleiro[6][5] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
        self.tabuleiro[6][5] = []
      if self.pos_vazia == (425,370):
        self.tabuleiro[6][5] = []
        self.tabuleiro[5][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (252,310) and (self.tabuleiro[6][5] in self.peca and (self.tabuleiro[5][4] in self.branco) or self.tabuleiro[6][5] in self.branco and (self.tabuleiro[5][4] in self.peca)) and self.tabuleiro[4][3] == []:
        self.tabuleiro[6][5] = []
        self.blita.remove(self.tabuleiro[5][4])
        self.tabuleiro[5][4] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,310) and (self.tabuleiro[6][5] in self.peca and (self.tabuleiro[5][6] in self.branco) or self.tabuleiro[6][5] in self.branco and (self.tabuleiro[5][6] in self.peca)) and self.tabuleiro[4][7] == []:
        self.tabuleiro[6][5] = []
        self.blita.remove(self.tabuleiro[5][6])
        self.tabuleiro[5][6] = []
        self.tabuleiro[4][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [6,7] and (self.pos_vazia == (425,370) or self.pos_vazia == (368,310)):
      if self.pos_vazia == (425,370):
        self.tabuleiro[6][7] = []
        self.tabuleiro[5][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,310) and (self.tabuleiro[6][7] in self.peca and (self.tabuleiro[5][6] in self.branco) or self.tabuleiro[6][7] in self.branco and (self.tabuleiro[5][6] in self.peca)) and self.tabuleiro[4][5] == []:
        self.tabuleiro[6][7] = []
        self.blita.remove(self.tabuleiro[5][6])
        self.tabuleiro[5][6] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [7,0] and (self.pos_vazia == (136,427) or self.pos_vazia == (192,370)):
      if self.pos_vazia == (136,427):
        self.tabuleiro[7][0] = []
        self.tabuleiro[6][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (192,370) and (self.tabuleiro[7][0] in self.peca and (self.tabuleiro[6][1] in self.branco) or self.tabuleiro[7][0] in self.branco and (self.tabuleiro[6][1] in self.peca)) and self.tabuleiro[5][2] == []:
        self.tabuleiro[7][0] = []
        self.blita.remove(self.tabuleiro[6][1])
        self.tabuleiro[6][1] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [7,2] and (self.pos_vazia == (136,427) or self.pos_vazia == (251,427) or self.pos_vazia == (77,370) or self.pos_vazia == (310,368)):
      if self.pos_vazia == (136,427):
        self.tabuleiro[7][2] = []
        self.tabuleiro[6][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,427):
        self.tabuleiro[7][2] = []
        self.tabuleiro[6][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (77,370) and (self.tabuleiro[7][2] in self.peca and (self.tabuleiro[6][1] in self.branco) or self.tabuleiro[7][2] in self.branco and (self.tabuleiro[6][1] in self.peca)) and self.tabuleiro[5][0] == []:
        self.tabuleiro[7][2] = []
        self.blita.remove(self.tabuleiro[6][1])
        self.tabuleiro[6][1] = []
        self.tabuleiro[5][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,368) and (self.tabuleiro[7][2] in self.peca and (self.tabuleiro[6][3] in self.branco) or self.tabuleiro[7][2] in self.branco and (self.tabuleiro[6][3] in self.peca)) and self.tabuleiro[5][4] == []:
        self.tabuleiro[7][2] = []
        self.blita.remove(self.tabuleiro[6][3])
        self.tabuleiro[6][3] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [7,4] and (self.pos_vazia == (251,427) or self.pos_vazia == (368,427) or self.pos_vazia == (192,370) or self.pos_vazia == (425,370)):
      if self.pos_vazia == (251,427):
        self.tabuleiro[7][4] = []
        self.tabuleiro[6][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,427):
        self.tabuleiro[7][4] = []
        self.tabuleiro[6][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (192,370) and (self.tabuleiro[7][4] in self.peca and (self.tabuleiro[6][3] in self.branco) or self.tabuleiro[7][4] in self.branco and (self.tabuleiro[6][3] in self.peca)) and self.tabuleiro[5][2] == []:
        self.tabuleiro[7][4] = []
        self.blita.remove(self.tabuleiro[6][3])
        self.tabuleiro[6][3] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (425,370) and (self.tabuleiro[7][4] in self.peca and (self.tabuleiro[6][5] in self.branco) or self.tabuleiro[7][4] in self.branco and (self.tabuleiro[6][5] in self.peca)) and self.tabuleiro[5][6] == []:
        self.tabuleiro[7][4] = []
        self.blita.remove(self.tabuleiro[6][5])
        self.tabuleiro[6][5] = []
        self.tabuleiro[5][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [7,6] and (self.pos_vazia == (368,427) or self.pos_vazia == (484,427) or self.pos_vazia == (310,368)):
      if self.pos_vazia == (368,427):
        self.tabuleiro[7][6] = []
        self.tabuleiro[6][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,427):
        self.tabuleiro[7][6] = []
        self.tabuleiro[6][7] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,368) and (self.tabuleiro[7][6] in self.peca and (self.tabuleiro[6][5] in self.branco) or self.tabuleiro[7][6] in self.branco and (self.tabuleiro[6][5] in self.peca)) and self.tabuleiro[5][4] == []:
        self.tabuleiro[7][6] = []
        self.blita.remove(self.tabuleiro[6][5])
        self.tabuleiro[6][5] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,0] and self.pos_vazia == (135,78):
      self.tabuleiro[1][0] = []
      self.tabuleiro[0][1] = self.pos_ocupada
      self.jogada = True
    elif self.indice == [1,2] and (self.pos_vazia == (135,78) or self.pos_vazia == (251,78)):
      self.tabuleiro[1][2] = []
      if self.pos_vazia == (135,78):
        self.tabuleiro[0][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,78):
        self.tabuleiro[0][3] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,4] and (self.pos_vazia == (251,78) or self.pos_vazia == (367,75)):
      self.tabuleiro[1][4] = []
      if self.pos_vazia == (251,78):
        self.tabuleiro[0][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (367,75):
        self.tabuleiro[0][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,6] and (self.pos_vazia == (367,75) or self.pos_vazia == (484,78)):
      self.tabuleiro[1][6] = []
      if self.pos_vazia == (367,75):
        self.tabuleiro[0][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,78):
        self.tabuleiro[0][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,1] and (self.pos_vazia == (77,135) or self.pos_vazia == (193,135) or self.pos_vazia == (251,78)):
      if self.pos_vazia == (77,135):
        self.tabuleiro[2][1] = []
        self.tabuleiro[1][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,135):
        self.tabuleiro[2][1] = []
        self.tabuleiro[1][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,78) and (self.tabuleiro[2][1] in self.peca and (self.tabuleiro[1][2] in self.branco) or self.tabuleiro[2][1] in self.branco and (self.tabuleiro[1][2] in self.peca)) and self.tabuleiro[0][3] == []:
        self.tabuleiro[2][1] = []
        self.blita.remove(self.tabuleiro[1][2])
        self.tabuleiro[1][2] = []
        self.tabuleiro[0][3] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,3] and (self.pos_vazia == (193,135) or self.pos_vazia == (310,135) or self.pos_vazia == (135,78) or self.pos_vazia == (367,75)):
      if self.pos_vazia == (193,135):
        self.tabuleiro[2][3] = []
        self.tabuleiro[1][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,135):
        self.tabuleiro[2][3] = []
        self.tabuleiro[1][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (135,78) and (self.tabuleiro[2][3] in self.peca and (self.tabuleiro[1][2] in self.branco) or self.tabuleiro[2][3] in self.branco and (self.tabuleiro[1][2] in self.peca)) and self.tabuleiro[0][1] == []:
        self.tabuleiro[2][3] = []
        self.blita.remove(self.tabuleiro[1][2])
        self.tabuleiro[1][2] = []
        self.tabuleiro[0][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (367,75) and (self.tabuleiro[2][3] in self.peca and (self.tabuleiro[1][4] in self.branco) or self.tabuleiro[2][3] in self.branco and (self.tabuleiro[1][4] in self.peca)) and self.tabuleiro[0][5] == []:
        self.tabuleiro[2][3] = []
        self.blita.remove(self.tabuleiro[1][4])
        self.tabuleiro[1][4] = []
        self.tabuleiro[0][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,5] and (self.pos_vazia == (310,135) or self.pos_vazia == (425,135) or self.pos_vazia == (251,78) or self.pos_vazia == (484,78)):
      if self.pos_vazia == (310,135):
        self.tabuleiro[2][5] = []
        self.tabuleiro[1][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (425,135):
        self.tabuleiro[2][5] = []
        self.tabuleiro[1][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,78) and (self.tabuleiro[2][5] in self.peca and (self.tabuleiro[1][4] in self.branco) or self.tabuleiro[2][5] in self.branco and (self.tabuleiro[1][4] in self.peca)) and self.tabuleiro[0][3] == []:
        self.tabuleiro[2][5] = []
        self.blita.remove(self.tabuleiro[1][4])
        self.tabuleiro[1][4] = []
        self.tabuleiro[0][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,78) and (self.tabuleiro[2][5] in self.peca and (self.tabuleiro[1][6] in self.branco) or self.tabuleiro[2][5] in self.branco and (self.tabuleiro[1][6] in self.peca)) and self.tabuleiro[0][7] == []:
        self.tabuleiro[2][5] = []
        self.blita.remove(self.tabuleiro[1][6])
        self.tabuleiro[1][6] = []
        self.tabuleiro[0][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,7] and (self.pos_vazia == (425,135) or self.pos_vazia == (367,75)):
      if self.pos_vazia == (425,135):
        self.tabuleiro[2][7] = []
        self.tabuleiro[1][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (367,75) and (self.tabuleiro[2][7] in self.peca and (self.tabuleiro[1][6] in self.branco) or self.tabuleiro[2][7] in self.branco and (self.tabuleiro[1][6] in self.peca)) and self.tabuleiro[0][5] == []:
        self.tabuleiro[2][7] = []
        self.blita.remove(self.tabuleiro[1][6])
        self.tabuleiro[1][6] = []
        self.tabuleiro[0][5] = self.pos_ocupada
        self.jogada = True
    #capturar para casas maiores
    elif self.indice == [2,1] and (self.pos_vazia == (73,255) or self.pos_vazia == (193,250) or self.pos_vazia == (252,310)):
      if self.pos_vazia == (73,255):
        self.tabuleiro[2][1] = []
        self.tabuleiro[3][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,250):
        self.tabuleiro[2][1] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (252,310) and (self.tabuleiro[2][1] in self.peca and (self.tabuleiro[3][2] in self.branco) or self.tabuleiro[2][1] in self.branco and (self.tabuleiro[3][2] in self.peca)) and self.tabuleiro[4][3] == []:
        self.tabuleiro[2][1] = []
        self.blita.remove(self.tabuleiro[3][2])
        self.tabuleiro[3][2] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,3] and (self.pos_vazia == (193,250) or self.pos_vazia == (310,250) or self.pos_vazia == (134,310) or self.pos_vazia == (368,310)):
      if self.pos_vazia == (193,250):
        self.tabuleiro[2][3] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,250):
        self.tabuleiro[2][3] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (134,310) and (self.tabuleiro[2][3] in self.peca and (self.tabuleiro[3][2] in self.branco) or self.tabuleiro[2][3] in self.branco and (self.tabuleiro[3][2] in self.peca)) and self.tabuleiro[4][1] == []:
        self.tabuleiro[2][3] = []
        self.blita.remove(self.tabuleiro[3][2])
        self.tabuleiro[3][2] = []
        self.tabuleiro[4][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,310) and (self.tabuleiro[2][3] in self.peca and (self.tabuleiro[3][4] in self.branco) or self.tabuleiro[2][3] in self.branco and (self.tabuleiro[3][4] in self.peca)) and self.tabuleiro[4][5] == []:
        self.tabuleiro[2][3] = []
        self.blita.remove(self.tabuleiro[3][4])
        self.tabuleiro[3][4] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,5] and (self.pos_vazia == (310,250) or self.pos_vazia == (426,250) or self.pos_vazia == (252,310) or self.pos_vazia == (484,310)):
      if self.pos_vazia == (310,250):
        self.tabuleiro[2][5] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (426,250):
        self.tabuleiro[2][5] = []
        self.tabuleiro[3][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (252,310) and (self.tabuleiro[2][5] in self.peca and (self.tabuleiro[3][4] in self.branco) or self.tabuleiro[2][5] in self.branco and (self.tabuleiro[3][4] in self.peca)) and self.tabuleiro[4][3] == []:
        self.tabuleiro[2][5] = []
        self.blita.remove(self.tabuleiro[3][4])
        self.tabuleiro[3][4] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,310) and (self.tabuleiro[2][5] in self.peca and (self.tabuleiro[3][6] in self.branco) or self.tabuleiro[2][5] in self.branco and (self.tabuleiro[3][6] in self.peca)) and self.tabuleiro[4][7] == []:
        self.tabuleiro[2][5] = []
        self.blita.remove(self.tabuleiro[3][6])
        self.tabuleiro[3][6] = []
        self.tabuleiro[4][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [2,7] and (self.pos_vazia == (426,250) or self.pos_vazia == (368,310)):
      if self.pos_vazia == (426,250):
        self.tabuleiro[2][7] = []
        self.tabuleiro[3][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,310) and (self.tabuleiro[2][7] in self.peca and (self.tabuleiro[3][6] in self.branco) or self.tabuleiro[2][7] in self.branco and (self.tabuleiro[3][6] in self.peca)) and self.tabuleiro[4][5] == []:
        self.tabuleiro[2][7] = []
        self.blita.remove(self.tabuleiro[3][6])
        self.tabuleiro[3][6] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,0] and (self.pos_vazia == (134,310) or self.pos_vazia == (192,370)):
      if self.pos_vazia == (134,310):
        self.tabuleiro[3][0] = []
        self.tabuleiro[4][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (192,370) and (self.tabuleiro[3][0] in self.peca and (self.tabuleiro[4][1] in self.branco) or self.tabuleiro[3][0] in self.branco and (self.tabuleiro[4][1] in self.peca)) and self.tabuleiro[5][2] == []:
        self.tabuleiro[3][0] = []
        self.blita.remove(self.tabuleiro[4][1])
        self.tabuleiro[4][1] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,2] and (self.pos_vazia == (134,310) or self.pos_vazia == (252,310) or self.pos_vazia == (77,370) or self.pos_vazia == (310,368)):
      if self.pos_vazia == (134,310):
        self.tabuleiro[3][2] = []
        self.tabuleiro[4][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (252,310):
        self.tabuleiro[3][2] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (77,370) and (self.tabuleiro[3][2] in self.peca and (self.tabuleiro[4][1] in self.branco) or self.tabuleiro[3][2] in self.branco and (self.tabuleiro[4][1] in self.peca)) and self.tabuleiro[5][0] == []:
        self.tabuleiro[3][2] = []
        self.blita.remove(self.tabuleiro[4][1])
        self.tabuleiro[4][1] = []
        self.tabuleiro[5][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,368) and (self.tabuleiro[3][2] in self.peca and (self.tabuleiro[4][3] in self.branco) or self.tabuleiro[3][2] in self.branco and (self.tabuleiro[4][3] in self.peca)) and self.tabuleiro[5][4] == []:
        self.tabuleiro[3][2] = []
        self.blita.remove(self.tabuleiro[4][3])
        self.tabuleiro[4][3] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,4] and (self.pos_vazia == (252,310) or self.pos_vazia == (368,310) or self.pos_vazia == (192,370) or self.pos_vazia == (425,370)):
      if self.pos_vazia == (252,310):
        self.tabuleiro[3][4] = []
        self.tabuleiro[4][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,310):
        self.tabuleiro[3][4] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia ==(192,370) and (self.tabuleiro[3][4] in self.peca and (self.tabuleiro[4][3] in self.branco) or self.tabuleiro[3][4] in self.branco and (self.tabuleiro[4][3] in self.peca)) and self.tabuleiro[5][2] == []:
        self.tabuleiro[3][4] = []
        self.blita.remove(self.tabuleiro[4][3])
        self.tabuleiro[4][3] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (425,370) and (self.tabuleiro[3][4] in self.peca and (self.tabuleiro[4][5] in self.branco) or self.tabuleiro[3][4] in self.branco and (self.tabuleiro[4][5] in self.peca)) and self.tabuleiro[5][6] == []:
        self.tabuleiro[3][4] = []
        self.blita.remove(self.tabuleiro[4][5])
        self.tabuleiro[4][5] = []
        self.tabuleiro[5][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [3,6] and (self.pos_vazia == (368,310) or self.pos_vazia == (484,310) or self.pos_vazia == (310,368)):
      if self.pos_vazia == (368,310):
        self.tabuleiro[3][6] = []
        self.tabuleiro[4][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,310):
        self.tabuleiro[3][6] = []
        self.tabuleiro[4][7] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,368) and (self.tabuleiro[3][6] in self.peca and (self.tabuleiro[4][5] in self.branco) or self.tabuleiro[3][6] in self.branco and (self.tabuleiro[4][5] in self.peca)) and self.tabuleiro[5][4] == []:
        self.tabuleiro[3][6] = []
        self.blita.remove(self.tabuleiro[4][5])
        self.tabuleiro[4][5] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,1] and (self.pos_vazia == (77,370) or self.pos_vazia == (192,370) or self.pos_vazia == (251,427)):
      if self.pos_vazia == (77,370):
        self.tabuleiro[4][1] = []
        self.tabuleiro[5][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (192,370):
        self.tabuleiro[4][1] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,427) and (self.tabuleiro[4][1] in self.peca and (self.tabuleiro[5][2] in self.branco) or self.tabuleiro[4][1] in self.branco and (self.tabuleiro[5][2] in self.peca)) and self.tabuleiro[6][3] == []:
        self.tabuleiro[4][1] = []
        self.blita.remove(self.tabuleiro[5][2])
        self.tabuleiro[5][2] = []
        self.tabuleiro[6][3] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,3] and (self.pos_vazia == (192,370) or self.pos_vazia == (310,368) or self.pos_vazia == (136,427) or self.pos_vazia == (368,427)):
      if self.pos_vazia == (192,370):
        self.tabuleiro[4][3] = []
        self.tabuleiro[5][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,368):
        self.tabuleiro[4][3] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (136,427) and (self.tabuleiro[4][3] in self.peca and (self.tabuleiro[5][2] in self.branco) or self.tabuleiro[4][3] in self.branco and (self.tabuleiro[5][2] in self.peca)) and self.tabuleiro[6][1] == []:
        self.tabuleiro[4][3] = []
        self.blita.remove(self.tabuleiro[5][2])
        self.tabuleiro[5][2] = []
        self.tabuleiro[6][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,427) and (self.tabuleiro[4][3] in self.peca and (self.tabuleiro[5][4] in self.branco) or self.tabuleiro[4][3] in self.branco and (self.tabuleiro[5][4] in self.peca)) and self.tabuleiro[6][5] == []:
        self.tabuleiro[4][3] = []
        self.blita.remove(self.tabuleiro[5][4])
        self.tabuleiro[5][4] = []
        self.tabuleiro[6][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,5] and (self.pos_vazia == (310,368) or self.pos_vazia == (425,370) or self.pos_vazia == (251,427) or self.pos_vazia == (484,427)):
      if self.pos_vazia == (310,368):
        self.tabuleiro[4][5] = []
        self.tabuleiro[5][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (425,370):
        self.tabuleiro[4][5] = []
        self.tabuleiro[5][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,427) and (self.tabuleiro[4][5] in self.peca and (self.tabuleiro[5][4] in self.branco) or self.tabuleiro[4][5] in self.branco and (self.tabuleiro[5][4] in self.peca)) and self.tabuleiro[6][3] == []:
        self.tabuleiro[4][5] = []
        self.blita.remove(self.tabuleiro[5][4])
        self.tabuleiro[5][4] = []
        self.tabuleiro[6][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,427) and (self.tabuleiro[4][5] in self.peca and (self.tabuleiro[5][6] in self.branco) or self.tabuleiro[4][5] in self.branco and (self.tabuleiro[5][6] in self.peca)) and self.tabuleiro[6][7] == []:
        self.tabuleiro[4][5] = []
        self.blita.remove(self.tabuleiro[5][6])
        self.tabuleiro[5][6] = []
        self.tabuleiro[6][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [4,7] and (self.pos_vazia == (425,370) or self.pos_vazia == (368,427)):
      if self.pos_vazia == (425,370):
        self.tabuleiro[4][7] = []
        self.tabuleiro[5][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,427) and (self.tabuleiro[4][7] in self.peca and (self.tabuleiro[5][6] in self.branco) or self.tabuleiro[4][7] in self.branco and (self.tabuleiro[5][6] in self.peca)) and self.tabuleiro[6][5] == []:
        self.tabuleiro[4][7] = []
        self.blita.remove(self.tabuleiro[5][6])
        self.tabuleiro[5][6] = []
        self.tabuleiro[6][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,0] and (self.pos_vazia == (136,427) or self.pos_vazia == (194,485)):
      if self.pos_vazia == (136,427):
        self.tabuleiro[5][0] = []
        self.tabuleiro[6][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (194,485) and (self.tabuleiro[5][0] in self.peca and (self.tabuleiro[6][1] in self.branco) or self.tabuleiro[5][0] in self.branco and (self.tabuleiro[6][1] in self.peca)) and self.tabuleiro[7][2] == []:
        self.tabuleiro[5][0] = []
        self.blita.remove(self.tabuleiro[6][1])
        self.tabuleiro[6][1] = []
        self.tabuleiro[7][2] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,2] and (self.pos_vazia == (136,427) or self.pos_vazia == (251,427) or self.pos_vazia == (78,485) or self.pos_vazia == (310,485)):
      if self.pos_vazia == (136,427):
        self.tabuleiro[5][2] = []
        self.tabuleiro[6][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,427):
        self.tabuleiro[5][2] = []
        self.tabuleiro[6][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (78,485) and (self.tabuleiro[5][2] in self.peca and (self.tabuleiro[6][1] in self.branco) or self.tabuleiro[5][2] in self.branco and (self.tabuleiro[6][1] in self.peca)) and self.tabuleiro[7][0] == []:
        self.tabuleiro[5][2] = []
        self.blita.remove(self.tabuleiro[6][1])
        self.tabuleiro[6][1] = []
        self.tabuleiro[7][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,485) and (self.tabuleiro[5][2] in self.peca and (self.tabuleiro[6][3] in self.branco) or self.tabuleiro[5][2] in self.branco and (self.tabuleiro[6][3] in self.peca)) and self.tabuleiro[7][4] == []:
        self.tabuleiro[5][2] = []
        self.blita.remove(self.tabuleiro[6][3])
        self.tabuleiro[6][3] = []
        self.tabuleiro[7][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,4] and (self.pos_vazia == (251,427) or self.pos_vazia == (368,427) or self.pos_vazia == (194,485) or self.pos_vazia == (426,485)):
      if self.pos_vazia == (251,427):
        self.tabuleiro[5][4] = []
        self.tabuleiro[6][3] = self.pos_ocupada
        self.jogada = True    
      if self.pos_vazia == (368,427):
        self.tabuleiro[5][4] = []
        self.tabuleiro[6][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (194,485) and (self.tabuleiro[5][4] in self.peca and (self.tabuleiro[6][3] in self.branco) or self.tabuleiro[5][4] in self.branco and (self.tabuleiro[6][3] in self.peca)) and self.tabuleiro[7][2] == []:
        self.tabuleiro[5][4] = []
        self.blita.remove(self.tabuleiro[6][3])
        self.tabuleiro[6][3] = []
        self.tabuleiro[7][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (426,485) and (self.tabuleiro[5][4] in self.peca and (self.tabuleiro[6][5] in self.branco) or self.tabuleiro[5][4] in self.branco and (self.tabuleiro[6][5] in self.peca)) and self.tabuleiro[7][6] == []:
        self.tabuleiro[5][4] = []
        self.blita.remove(self.tabuleiro[6][5])
        self.tabuleiro[6][5] = []
        self.tabuleiro[7][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [5,6] and (self.pos_vazia == (368,427) or self.pos_vazia == (484,427) or self.pos_vazia == (310,485)):
      if self.pos_vazia == (368,427):
        self.tabuleiro[5][6] = []
        self.tabuleiro[6][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (484,427):
        self.tabuleiro[5][6] = []
        self.tabuleiro[6][7] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,485) and (self.tabuleiro[5][6] in self.peca and (self.tabuleiro[6][5] in self.branco) or self.tabuleiro[5][6] in self.branco and (self.tabuleiro[6][5] in self.peca)) and self.tabuleiro[7][4] == []:
        self.tabuleiro[5][6] = []
        self.blita.remove(self.tabuleiro[6][5])
        self.tabuleiro[6][5] = []
        self.tabuleiro[7][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [6,1] and (self.pos_vazia == (78,485) or self.pos_vazia == (194,485)):
      self.tabuleiro[6][1] = []
      if self.pos_vazia == (78,485):
        self.tabuleiro[7][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (194,485):
        self.tabuleiro[7][2] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [6,3] and (self.pos_vazia == (194,485) or self.pos_vazia == (310,485)):
      self.tabuleiro[6][3] = []
      if self.pos_vazia == (194,485):
        self.tabuleiro[7][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,485):
        self.tabuleiro[7][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [6,5] and (self.pos_vazia == (310,485) or self.pos_vazia == (426,485)):
      self.tabuleiro[6][5] = []
      if self.pos_vazia == (310,485):
        self.tabuleiro[7][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (426,485):
        self.tabuleiro[7][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [6,7] and self.pos_vazia == (426,485):
      self.tabuleiro[6][7] = []
      self.tabuleiro[7][6] = self.pos_ocupada
      self.jogada = True
    elif self.indice == [0,1] and (self.pos_vazia == (77,135) or self.pos_vazia == (193,135) or self.pos_vazia == (251,195)):
      if self.pos_vazia == (77,135):
        self.tabuleiro[0][1] = []
        self.tabuleiro[1][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,135):
        self.tabuleiro[0][1] = []
        self.tabuleiro[1][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,195) and (self.tabuleiro[0][1] in self.peca and (self.tabuleiro[1][2] in self.branco) or self.tabuleiro[0][1] in self.branco and (self.tabuleiro[1][2] in self.peca)) and self.tabuleiro[2][3] == []:
        self.tabuleiro[0][1] = []
        self.blita.remove(self.tabuleiro[1][2])
        self.tabuleiro[1][2] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [0,3] and (self.pos_vazia == (193,135) or self.pos_vazia == (310,135) or self.pos_vazia == (135,195) or self.pos_vazia == (368,194)):
      if self.pos_vazia == (193,135):
        self.tabuleiro[0][3] = []
        self.tabuleiro[1][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,135):
        self.tabuleiro[0][3] = []
        self.tabuleiro[1][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (135,195) and (self.tabuleiro[0][3] in self.peca and (self.tabuleiro[1][2] in self.branco) or self.tabuleiro[0][3] in self.branco and (self.tabuleiro[1][2] in self.peca)) and self.tabuleiro[2][1] == []:
        self.tabuleiro[0][3] = []
        self.blita.remove(self.tabuleiro[1][2])
        self.tabuleiro[1][2] = []
        self.tabuleiro[2][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,194) and (self.tabuleiro[0][3] in self.peca and (self.tabuleiro[1][4] in self.branco) or self.tabuleiro[0][3] in self.branco and (self.tabuleiro[1][4] in self.peca)) and self.tabuleiro[2][5] == []:
        self.tabuleiro[0][3] = []
        self.blita.remove(self.tabuleiro[1][4])
        self.tabuleiro[1][4] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [0,5] and (self.pos_vazia == (310,135) or self.pos_vazia == (425,135) or self.pos_vazia == (251,195) or self.pos_vazia == (485,194)):
      if self.pos_vazia == (310,135):
        self.tabuleiro[0][5] = []
        self.tabuleiro[1][4] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (425,135):
        self.tabuleiro[0][5] = []
        self.tabuleiro[1][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,195) and (self.tabuleiro[0][5] in self.peca and (self.tabuleiro[1][4] in self.branco) or self.tabuleiro[0][5] in self.branco and (self.tabuleiro[1][4] in self.peca)) and self.tabuleiro[2][3] == []:
        self.tabuleiro[0][5] = []
        self.blita.remove(self.tabuleiro[1][4])
        self.tabuleiro[1][4] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (485,194) and (self.tabuleiro[0][5] in self.peca and (self.tabuleiro[1][6] in self.branco) or self.tabuleiro[0][5] in self.branco and (self.tabuleiro[1][6] in self.peca)) and self.tabuleiro[2][7] == []:
        self.tabuleiro[0][5] = []
        self.blita.remove(self.tabuleiro[1][6])
        self.tabuleiro[1][6] = []
        self.tabuleiro[2][7] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [0,7] and (self.pos_vazia == (425,135) or self.pos_vazia == (368,194)):
      if self.pos_vazia == (425,135):
        self.tabuleiro[0][7] = []
        self.tabuleiro[1][6] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,194) and (self.tabuleiro[0][7] in self.peca and (self.tabuleiro[1][6] in self.branco) or self.tabuleiro[0][7] in self.branco and (self.tabuleiro[1][6] in self.peca)) and self.tabuleiro[2][5] == []:
        self.tabuleiro[0][7] = []
        self.blita.remove(self.tabuleiro[1][6])
        self.tabuleiro[1][6] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,0] and (self.pos_vazia == (135,195) or self.pos_vazia == (193,250)):
      if self.pos_vazia == (135,195):
        self.tabuleiro[1][0] = []
        self.tabuleiro[2][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,250) and (self.tabuleiro[1][0] in self.peca and (self.tabuleiro[2][1] in self.branco) or self.tabuleiro[1][0] in self.branco and (self.tabuleiro[2][1] in self.peca)) and self.tabuleiro[3][2] == []:
        self.tabuleiro[1][0] = []
        self.blita.remove(self.tabuleiro[2][1])
        self.tabuleiro[2][1] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,2] and (self.pos_vazia == (135,195) or self.pos_vazia == (251,195) or self.pos_vazia == (73,255) or self.pos_vazia == (310,250)):
      if self.pos_vazia == (135,195):
        self.tabuleiro[1][2] = []
        self.tabuleiro[2][1] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (251,195):
        self.tabuleiro[1][2] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (73,255) and (self.tabuleiro[1][2] in self.peca and (self.tabuleiro[2][1] in self.branco) or self.tabuleiro[1][2] in self.branco and (self.tabuleiro[2][1] in self.peca)) and self.tabuleiro[3][0] == []:
        self.tabuleiro[1][2] = []
        self.blita.remove(self.tabuleiro[2][1])
        self.tabuleiro[2][1] = []
        self.tabuleiro[3][0] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,250) and (self.tabuleiro[1][2] in self.peca and (self.tabuleiro[2][3] in self.branco) or self.tabuleiro[1][2] in self.branco and (self.tabuleiro[2][3] in self.peca)) and self.tabuleiro[3][4] == []:
        self.tabuleiro[1][2] = []
        self.blita.remove(self.tabuleiro[2][3])
        self.tabuleiro[2][3] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,4] and (self.pos_vazia == (251,195) or self.pos_vazia == (368,194) or self.pos_vazia == (193,250) or self.pos_vazia == (426,250)):
      if self.pos_vazia == (251,195):
        self.tabuleiro[1][4] = []
        self.tabuleiro[2][3] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (368,194):
        self.tabuleiro[1][4] = []
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (193,250) and (self.tabuleiro[1][4] in self.peca and (self.tabuleiro[2][3] in self.branco) or self.tabuleiro[1][4] in self.branco and (self.tabuleiro[2][3] in self.peca)) and self.tabuleiro[3][2] == []:
        self.tabuleiro[1][4] = []
        self.blita.remove(self.tabuleiro[2][3])
        self.tabuleiro[2][3] = []
        self.tabuleiro[3][2] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (426,250) and (self.tabuleiro[1][4] in self.peca and (self.tabuleiro[2][5] in self.branco) or self.tabuleiro[1][4] in self.branco and (self.tabuleiro[2][5] in self.peca)) and self.tabuleiro[3][6] == []:
        self.tabuleiro[1][4] = []
        self.blita.remove(self.tabuleiro[2][5])
        self.tabuleiro[2][5] = []
        self.tabuleiro[3][6] = self.pos_ocupada
        self.jogada = True
    elif self.indice == [1,6] and (self.pos_vazia == (368,194) or self.pos_vazia == (485,194) or self.pos_vazia == (310,250)):
      if self.pos_vazia == (368,194):
        self.tabuleiro[1][6] = []                           
        self.tabuleiro[2][5] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (485,194):
        self.tabuleiro[1][6] = []          
        self.tabuleiro[2][7] = self.pos_ocupada
        self.jogada = True
      if self.pos_vazia == (310,250) and (self.tabuleiro[1][6] in self.peca and (self.tabuleiro[2][5] in self.branco) or self.tabuleiro[1][6] in self.branco and (self.tabuleiro[2][5] in self.peca)) and self.tabuleiro[3][4] == []:
        self.tabuleiro[1][6] = []
        self.blita.remove(self.tabuleiro[2][5])
        self.tabuleiro[2][5] = []
        self.tabuleiro[3][4] = self.pos_ocupada
        self.jogada = True

    
dama = damas(600,600)
dama.__main__()
damas.py
