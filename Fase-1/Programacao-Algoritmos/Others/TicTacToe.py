# -*- coding: cp1252 -*-
import os
import subprocess as sp
rodando = True
x = [ [[' '],[' '],[' ']],
        [[' '],[' '],[' ']],
        [[' '],[' '],[' ']] ]
y = [ [[ 1 ],[ 2 ],[ 3 ]],
       [ [ 4 ],[ 5 ],[ 6 ]],
        [[ 7 ],[ 8 ],[ 9 ]] ]
count = 0
nume = 0
def mostra_tabuleiro(x,y):
       cont = 0
       print "                                ", "Tic Tac Toe"
       print "                                    ","Deluxe"
       while cont < 3 :
              print "                                            "
              print "           ",x[cont],"        ",y[cont]
              print "                                             "
              print "                                              "
              print '\n'
              cont+=1
def jogada_x():
       mostra_tabuleiro(x,y)
       pos = input("Digite a posicao que deseja player X: ")
       if pos == 1:
              if x[0][0] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "                                                                     "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[0][0] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
              
       if pos == 2:
              if x[0][1] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "                                                                    "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[0][1] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 3:
              if x[0][2] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","jogada Invalida: posicao ja ocupada"
                     print "         "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[0][2] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 4:
              if x[1][0] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "        "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[1][0] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 5:
              if x[1][1] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "    "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[1][1] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 6:
              if x[1][2] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "    "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[1][2] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 7:
              if x[2][0] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "     "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[2][0] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 8:
              if x[2][1] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "    "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[2][1] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos == 9:
              if x[2][2] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "  "
                     jogada_x()
                     pos = 1
                     sp.call('clear',shell = True)
              else:
                     pos = 1
                     x[2][2] = ["X"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if pos != 1 and pos != 2 and pos != 3 and pos != 4 and pos != 5 and pos != 6 and pos != 7 and pos != 8 and pos != 9:
              sp.call('clear',shell = True)
              print "                         "
              print  "  =>  ","Jogada Invalida: posicao nao correspondente"
              print "      "
              jogada_x()

def jogada_O():
       mostra_tabuleiro(x,y)
       num = input("Digite a posicao que deseja player O: ")
       if num == 1:
              if x[0][0] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "        "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[0][0] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 2:
              if x[0][1] != [" "]:
                     sp.call('clear',shell = True)
                     print "                         "
                     print  "  ==>  ","Jogada Invalida: posicao ja ocupada"
                     print "     "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[0][1] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 3:
              if x[0][2] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "        "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[0][2] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 4:
              if x[1][0] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "      "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[1][0] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 5:
              if x[1][1] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "     "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[1][1] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 6:
              if x[1][2] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "     "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[1][2] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 7:
              if x[2][0] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "    "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[2][0] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 8:
              if x[2][1] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "   "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[2][1] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num == 9:
              if x[2][2] != [" "]:
                     sp.call('clear',shell = True)
                     print "                          "
                     print "==>","Jogada Invalida: posicao ja ocupada"
                     print "    "
                     jogada_O()
                     num = 1
                     sp.call('clear',shell = True)
              else:
                     x[2][2] = ["O"]
                     sp.call('clear',shell = True)
                     return mostra_tabuleiro(x,y)
       if num != 1 and num != 2 and num != 3 and num != 4 and num != 5 and num != 6 and num != 7 and num != 8 and num != 9:              
              sp.call('clear',shell = True)
              print "                         "
              print  "  =>  ","jogada invalida:  posicao nao correspondente"
              print "                                                                                 "
              jogada_O()

    
while rodando:
       jogada_O()
       nume+=1
       if x[0][0] == ['O'] and x[0][1] == ['O'] and x[0][2] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[1][0] == ['O'] and x[1][1] == ['O'] and x[1][2] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[2][0] == ['O'] and x[2][1] == ['O'] and x[2][2] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][2] == ['O'] and x[1][2] == ['O'] and x[2][2] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][1] == ['O'] and x[1][1] == ['O'] and x[2][1] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][0] == ['O'] and x[1][0] == ['O'] and x[2][0] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][0] == ['O'] and x[1][1] == ['O'] and x[2][2] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][2] == ['O'] and x[1][1] == ['O'] and x[2][0] == ['O']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player O"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if nume == 9:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                                 ", "Deu velha"
              print " "
              print "                                 ","O","     ","O"
              print "                                     0         "
              print"                               ","_____________"
              print "                      "
              print "          "
              mostra_tabuleiro(x,y)
              break
       sp.call('clear',shell = True)
       jogada_x()
       nume+=1
       if x[0][0] == ['X'] and x[0][1] == ['X'] and x[0][2] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[1][0] == ['X'] and x[1][1] == ['X'] and x[1][2] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[2][0] == ['X'] and x[2][1] == ['X'] and x[2][2] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][2] == ['X'] and x[1][2] == ['X'] and x[2][2] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][1] == ['X'] and x[1][1] == ['X'] and x[2][1] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][0] == ['X'] and x[1][0] == ['X'] and x[2][0] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][0] == ['X'] and x[1][1] == ['X'] and x[2][2] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if x[0][2] == ['X'] and x[1][1] == ['X'] and x[2][0] == ['X']:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                   ", "Congratulations the winner it's player X"
              print "                      "
              mostra_tabuleiro(x,y)
              break
       if nume == 9:
              sp.call('clear',shell = True)
              print "      "
              print "     "
              print"                                  ", "Deu velha"
              print "   "
              print "                                 ","O","     ","O"
              print "                                      0         "
              print"                               ","_____________"
              print "                      "
              print " "
              mostra_tabuleiro(x,y)
              break
       sp.call('clear',shell = True)

