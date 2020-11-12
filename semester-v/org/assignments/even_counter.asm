.globl main

.data
	integers: .word 1, 3, 5, 2, 9, 11
	
.text
	main:
		la a0, integers
		addi a1, zero, 6
		addi a2, zero, 0
		addi a3, zero, 0
		j count_even
	
	
	count_even: 
		beq a1, a2, end # se o contador e o tamanho do vetor são iguais finaliza
		
		lw a4, 0(a0)    # louda o número do vetor
		
		addi a0, a0, 4  # atualiza o ponteiro do vetor (avança 4 bytes)
		
		addi a2, a2, 1  # incrementa o contador
		
		andi a5, a4, 1  # testa se o numero é par
		
		beqz a5, count  # caos a5 == 0 significa que a representação binária n acabou em 1
		j count_even
		
	count:
		addi a3, a3, 1
		j count_even
		
			
	end:
		add s0, a3, zero # coloca o valor de saída no registrador s0

	