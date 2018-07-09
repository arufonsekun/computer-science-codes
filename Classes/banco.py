def conta():
    operacao = 1
    while operacao != '0':
        x = input("Digite o numero da conta: ")
        saldo = float(input("Digite o saldo atual: "))
        operacao = input("Type: D -> para deposito ou R -> para retirada: ")
        valor = float(input("Digite o valor da operação: "))
        if operacao not in "RD":print ("Operação invalida")
        else:
            if operacao == 'R': saldo -= valor
            else: saldo += valor
        if saldo < 0: print ("Conta estourada")
        print("O saldo da conta {} é {:.2f}".format(x, saldo))
if __name__ == '__main__':
    conta()
