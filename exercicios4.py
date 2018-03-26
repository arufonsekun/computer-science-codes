#Exercicio1
def exe1():
	x,y = input("Digite dois numeros: ").split(",")
	if x == y:
		print("Numeros iguais")
	elif x > y:
		print("{0} é o numero maior".format(x))
	elif y > x:
		print("{0} é o maior numero".format(y))

def categoria():
	x = int(input("Qual é sua idade: "))
	categoria = str()
	if x < 5:
		categoria = "Mini"
	elif x >= 5 and x <= 7:
		categoria = "Infantil A"
	elif x >= 8 and x <= 10:
		categoria = "Infantil B"
	elif x >= 11 and x <= 13:
		categoria = "Juvenil A"
	elif x >= 14 and x <= 17:
		categoria = "Juvenil B"
	else:
		categoria = "Adulto"
	print("Sua categoria é {0}".format(categoria))

def exe3():
	n = int(input("Digite um numero: "))
	if n <= 10: print("F1")
	elif n > 10 and n <= 100: print("F2")
	else: print("F3")

def compra():
	nome = input("Para iniciar a compra digite seu nome: ")
	parafuso = int(input("Digite a quantidade de parafusos que o senhor quer comprar: "))
	porcas = int(input("Digite a quantidade de porcas: "))
	arruela = int(input("Digite a quantidade de arruelas: "))
	desconto = (parafuso * 0.10 * 0.2) + (porcas * 0.08 *0.1) + (arruela * 0.03 * 0.3)
	print("O senhor {0} gastou R${1:8.2f} em parafusos, R${2:8.2f} em porcas e R${3:8.2f} em arruelas".format(nome, parafuso * 0.10, porcas * 0.08, arruela * 0.03))
	print("(respectivos valores sem descontos)")
	print("O total de descontos é R${0:8.2f}".format(desconto))
	print("O preço total a pagar é R${0:8.2f}".format((parafuso * 0.10) + (porcas * 0.08) + (arruela * 0.03) - desconto))

def aumento_do_proletariado():
	nome, cat, sal, = input("Digite seu nome, categoria e salario, respectivamente: ").split(",")
	reajuste = int(sal)
	cat = cat.split(" ")[1]
	if cat in 'ACFH':
		reajuste *= 1.1
	elif cat in 'BDEIJT':
		reajuste *= 1.15
	elif cat in 'KR':
		reajuste *= 1.25
	elif cat in 'UVXYWZ':
		reajuste *= 1.5
	else:
		reajuste *= 1.35
	print ("Funcionari@ {0}, categoria {1}, com o reajuste passar a receber o salario de R${2:8.2f}".format(nome, cat,reajuste))

def conta():
	operacao = True
	numero = str()
	saldo = int()
	def criar(numero):
		numero = input("Digite o numero da conta: ")
		return numero
	def retirada(saldo):
		valor = int(input("Digite o valor da retirada: "))
		saldo -= valor
		if saldo < 0:
			print ("Conta estourada")
		return saldo
	def deposito(saldo):
		valor1 = int(input("Digite o valor do deposito: "))
		saldo += valor1
		return saldo
	def extrato(saldo, numero):
		print("O saldo da conta nº{1} é de R${0}".format(saldo, numero))
	while operacao:
		x = input("Digite C para criar conta, R para retirada, D para reposito, E para extrato e S para sair: ")
		if x not in "CRDSE":
			print ("Opração inválida")
		if x == "S":
			operacao = False
		if x == "C":
			numero = criar(numero)
		if x == "R":
			saldo = retirada(saldo)
		if x == "D":
			saldo = deposito(saldo)
		if x == "E":
			extrato(saldo, numero)

def shit7():
	op = input("Digite a opção: ")
	if not op in "234":print("Opção invalida"); shit()
	else:
		num1  = input("Digite o primeiro numero: ")
		num2  = input("Digite o primeiro numero: ")
		num3  = input("Digite o primeiro numero: ")
		if op == '2': print (num1)
		if op == '3': print(num2)
		if op == '4': print(num3)

def media():
	x,y,z = input("Digite as notas: ").split(",")
	x = int(x); y = int(y); z = int(z)
	media = input('Digite o tipo da media, 1: aritmetica ou 2: ponderada(3, 3, 4): ')
	if media == '1': print("A media é {0:3.2f}".format((x+y+z)/3))
	if media == '2': print("A media é {0:3.2f}".format(((x * 3) + (y * 3) + (z * 4))/10))
	if not media in '12': print("Opção para tipo de média invalida")

def soma():
	z,y,x,w = input("Digite quatro numeros: ").split(",")
	lista = list()
	lista.append(int(z));lista.append(int(y))
	lista.append(int(x));lista.append(int(w))
	par = int();odd = int()
	for i in range(0,4):
		if lista[i] % 2 == 0: par += lista[i]
		else: odd += lista[i]
	print("A soma dos nºs pares são {0} e dos impares são {1}".format(par, odd))

def conversor():
	seg = int(input("Digite o valor em segundos: "))
	dia = int(); hrs = int(); minu = int()
	if seg // 86400 >= 1:
		dia = seg // 86400
		seg -= dia * 86400
	if seg // 3600 >= 1:
		hrs = seg // 3600
		seg -= hrs * 3600
	if seg // 60 >= 1:
		minu = seg // 60
		seg -= minu * 60
	print ("Você esperou {0} dias, {1} horas, {2} minutos e {3} segundos".format(dia, hrs, minu, seg))

def desconversor():
	dia, hrs, minu, seg = input("Digite o(s) dia(s) horas. minutos e segundos: ").split(',')
	dia = int(dia); hrs = int(hrs); minu = int(minu); seg = int(seg)
	seg += (dia * 86400) + (hrs * 3600) + (minu * 60)
	print("O correspondente em segundos é ",seg)

def salario():
	sal = int(input("Digite seu salario: "))
	salario = sal
	if sal <= 1903.98:
		sal = 0
	elif sal >= 1903.99 and sal <= 2826.65:
		sal *= 0.075
	elif sal >= 2826.66 and sal <= 3751.05:
		sal *= 0.15
	elif sal >= 3751.06 and sal <= 4664.68:
		sal *= 0.255
	elif sal > 4664.68:
		sal *= 0.275
	salario -= sal
	if salario <= 1903.98:
		pass
	elif salario >= 1903.99 and salario <= 2826.65:
		salario -= 69.20
	elif salario >= 2826.66 and salario <= 3500:
		salario -= 101.20
	print("O valor do imposto sem alíquota é R${0} e o salário líquido é R${1}".format(sal, salario))
#exe1()
#categoria()
#exe3()
#compra()
#aumento_do_proletariado()
#conta()
#shit7()
#media()
#soma()
#conversor()
#desconversor()
salario()
