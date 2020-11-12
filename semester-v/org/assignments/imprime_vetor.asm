	.globl imprime_vetor
	.data
vetor:		 .word   2, -5, 1, 7, 36, 4, -1, 0	
msg_vetor: 	 .string "Vetor: "
msg_new_line:	 .string "\n"
msg_space:	 .string " "

	.text
	
main:
	la	a0, vetor
	li 	a1, 8
	jal	imprime_vetor
	nop
	ebreak
	

#########################################################
# imprime_vetor
# argumentos: a0 - endereço inicial do vetor
#             a1 - tamanho do vetor
# retorno: ---- (nenhum retorno)
# registradores ocupados: a0 - argumento de entrada (endereço do vetor)
#			       e argumento para o ecall
#			  a1 - argumento de entrada (tamanho do vetor)
#			  a2 - ponteiro para o vetor
# 			  a7 - argumento para o ecall
# comentário: a função NÂO preserva os valores dos 
#	      argumentos passados para a função
#########################################################
	
imprime_vetor:
	add	a2, zero, a0	#transfere valor de a0 para a2

	la	a0, msg_vetor	# coloca endereço inicial da mensagem em a0
	li	a7, 4		# carrega a7 com valor correspondente a impressao de string na chamada de sistema
	ecall			# chamada de sistema (exception call)

laco_imp:	
	beq	a1, zero, fim	# verifica se percorreu todo o vetor. Caso sim, desvia para fim
	lw	a0, 0(a2)	# lê endereço atual do vetor e coloca em a0
	li	a7, 1		# carrega a7 com valor correspondente a impressao de inteiro na chamada de sistema
	ecall			# chamada de sistema (exception call)

	la	a0, msg_space	# coloca endereço inicial da mensagem em a0
	li	a7, 4		# carrega a7 com valor correspondente a impressao de string na chamada de sistema
	ecall			# chamada de sistema (exception call)
	
	addi	a2, a2, 4	# faz a2 apontar para próxima posição do vetor
	addi 	a1, a1, -1 	# decrementa variável de controle (para saber se percorreu todo o vetor)
	j	laco_imp	# desvia para laco
	
fim:
	la	a0, msg_new_line # coloca endereço inicial da mensagem em a0	
	li	a7, 4		 # carrega a7 com valor correspondente a impressao de string na chamada de sistema
	ecall			 # chamada de sistema (exception call)
	ret	
		
######################################################	

