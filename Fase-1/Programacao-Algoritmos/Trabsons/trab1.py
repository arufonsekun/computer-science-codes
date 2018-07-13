# Nome: Junior Vitor Ramisch; Email: junior.ramisch@gmail.com
#Função pagamento: realiza o calculo de juros, descontos e o preço das parcelas conforme o preço do produto e o nº de parcelas
def pagamento():
    valor = float(input("Digite o valor do produto: "))#Recebendo o valor do produto em string e convertendo pra float
    parcelas = int(input("Digite a quantidade de parcelas: "))#Recebendo a quantidade de parcelar em string e convertendo para inteiro
    saida = "O preço final é R$ {0:.2f}, parcelado em {1} vez(es) de R$ {2:3.2f}"#Cria a string para o modelo da saida
    if parcelas == 1 and valor < 200:
        valor *= 1 # Preço constante se o numero de parcelas é um e se o preço for menor que 200
        saida = saida.format(valor, parcelas, valor)# Formata a saida conforme o valor, as casas decimais necessárias e o valor das parcelas

    elif parcelas == 1 and valor >= 200 and valor <= 400:
        valor -= valor * 0.1 # Desconto de 10% se o user for pagar em 1 vez e preço de sua compra ficar entre R$200 à R$400
        saida = saida.format(valor, parcelas, valor)

    elif parcelas == 1 and valor > 400:
        valor -= valor * 0.2 # Desconto de 20% se o user for pagar em 1 vez e preço de sua compra for maior que R$400
        saida = saida.format(valor, parcelas, valor)

    elif parcelas == 2 or parcelas == 3:
        valor *= 1 # Preço constante se o numero de parcelas for 2 ou 3
        saida = saida.format(valor, parcelas, valor / parcelas)

    elif parcelas == 4 and valor <= 1000:
        valor += valor * 0.1 # Aumento de 10% se o numero de parcelas for 4 e o preço da compra for menor ou igual à R$1000
        saida = saida.format(valor, parcelas, valor / parcelas)

    elif parcelas == 4 and valor > 1000:
        valor += valor * 0.2 # Aumento de 20% se o pagamento for feito em 4 vezes e o valor for maior que R$1000
        saida = saida.format(valor, parcelas, valor / parcelas)

    elif parcelas >= 5:
        valor += valor * 0.3 # Aumento de 30% se o pagamento for feito em 5 ou mais parcelas
        saida = saida.format(valor, parcelas, valor / parcelas)
    print (saida)#Mostra na tela

pagamento()#Chamada da função
