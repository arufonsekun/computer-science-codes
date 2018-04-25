# -*- coding: cp1252 -*-
import os
import subprocess as sp
def translate():
      continua = True
      while continua:
            numero = input("Digite 1 para traduzir de numero para binario ou 2 de binario para numero: ")
            if numero == 1:
                  x = input("Digite o numero a ser transformado em binario:  ")
                  lista = []
                  lista2 = []
                  if x == x:
                        divisao = x/2
                        resto = x%2
                        lista.append(resto)
                        x+=1
                        while divisao>0:
                              resto = divisao%2
                              lista.append(resto)
                              divisao = divisao/2
                        cont = (len(lista)-1)
                        while cont>=0:
                              lista2.append(lista[cont])
                              cont-=1
                        print "Seu numero em binario e: ",'\n'
                        for el in lista2:
                              print el,
                        print '\n'
                        y =raw_input("Se deseja reiniciar o programa escreva y senao escreva n: ")
                        if y == 'n':
                              continua = False
                        else:
                              continua = True
            else:
                  if numero == 2:
                        x = raw_input("Digite seu numero em binario : ")
                        num = ' '
                        cont = len(x)-1
                        while cont>=0:
                            num += x[cont]
                            cont-=1
                        soma = 0
                        cont1 = 0
                        for el in num:
                            if el =='0':
                                cont1 +=1
                            else:
                                if el == '1':
                                    soma+= 2**cont1
                                    cont1+=1
                        print "Seu numero eh",soma,'\n'
                        y =raw_input("Se deseja reiniciar o programa escreva y senao escreva n: ")
                        if y == 'n':
                              continua = False
                        else:
                              continua = True
translate()            
     

