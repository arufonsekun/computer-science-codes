	.globl main
	
	.data
vetor:		 .word -3, 2, -5, 2, 1, -1    

	.text
main: 
	nop
	addi a0, zero, 4
	addi a1, zero, 83
	addi a2, zero, 56	
	jal  maior
	jal  menor

	jal  fibonacci

	la   a0, vetor
	addi a1, zero, 6
	jal  menor_vetor

	la   a0, vetor
	addi a1, zero, 2
	addi a2, zero, 4
	jal swap_vector

	la   a0, vetor
	addi a1, zero, 6
#	call  imprime_vetor

	la   a0, vetor
	addi a1, zero, 6
	jal  ordena
	
	la   a0, vetor
	addi a1, zero, 6
#	call  imprime_vetor	
fim:	j fim

####################################
# recebe 3 valores e retorna o maior 
#   entrada: a0, a1, a2
#   saida: s0
####################################
maior: 
	bgt a0, a1, a0_testar
	bgt a1, a2, a1_maior
a2_maior:	
	add s0, a2, zero
	ret
a1_maior:
	add s0, a1, zero
	ret
a0_maior:
	add s0, a0, zero
	ret
a0_testar:
	bgt a0, a2, a0_maior
	j   a2_maior
	
####################################
# recebe 3 valores e retorna o menor 
#   entrada: a0, a1, a2
#   saida: s0
####################################
menor: 
	ble a0, a1, testar_a0
	ble a1, a2, a1_menor
a2_menor:	
	add s0, a2, zero
	ret
a1_menor:
	add s0, a1, zero
	ret
a0_menor:
	add s0, a0, zero
	ret
testar_a0:
	blt a2, a0, a2_menor
	j a0_menor
	
####################################
# recebe 1 valor N e retorna o N-esimo fibonacci 
#   entrada: a0
#   saida: a0
####################################	
	
fibonacci:
	addi t1, zero, 1 #fib1
	addi t2, zero, 1 #fib2
	addi t3, zero, 3
	bgt  a0, t3, calcula
	add s0, zero, t1
	ret 
calcula: 
	beq  t3, a0, terminou
	add  t4, t1, t2 #soma
	add  t1, zero, t2
	add  t2, zero, t4
	addi t3, t3, 1
	j    calcula
terminou:
	add s0, zero, t4
	ret
	
####################################
# recebe um vetor com  N elementos e 
#    retorna o indice do menor valor 
#   entrada: a0 - posicao inicial do vetor na memória
#	     a1 - tamanho do vetor
#   saida: a0 - menor valor
#	   a1 - indice do menor valor
####################################		
	
menor_vetor:
	addi  t0, zero, 1 	# inicializa contador
	lw    t1, 0 (a0)   	# le posicao 0 do vetor (menor)
	add   t2, zero, zero  	# menor indice = 0
	addi  t3, a0, 4
laco_teste:
	beq   t0, a1, fim_busca
	lw    t4, 0(t3)		# le posicao i
	ble   t1, t4, segue
	add   t2, zero, t0     # novo indice menor
	add   t1, zero, t4     # novo menor valor
segue:	
	addi  t0, t0, 1      # atualiza contador
	addi  t3, t3, 4        # atualiza ponteiro para memoria
	j     laco_teste
fim_busca:
	add a0, zero, t1
	add a1, zero, t2
	ret
		

#a0 - endereco vetor
#a1 - indice 1
#a2 - indice 2		
swap_vector:
	slli a1, a1, 2
	slli a2, a2, 2
	add  t0, a0, a1
	lw   a3, 0(t0)
	add  t1, a0, a2
	lw   a4, 0(t1)
	sw   a3, 0(t1)
	sw   a4, 0(t0)
	ret
		
		
####################################
# recebe um vetor com  N elementos e 
#    retorna o indice do menor valor 
#   entrada: a0 - posicao inicial do vetor na memória
#	     a1 - tamanho do vetor
#   saida: 
####################################	
#void
#selecao (int n, int v[])
#{
#   for (int i = 0; i < n-1; ++i) {
#      int min = i;
#      for (int j = i+1; j < n; ++j)
#         if (v[j] < v[min])  min = j;
#      int x = v[i]; v[i] = v[min]; v[min] = x;
#   }
#}
	
			
ordena:
	add   s6, zero, ra
	add   s0, zero, a0
	add   s1, zero, a1
	add   s4, zero, zero  	# menor indice = 0
segue_ordena:
	beq   s4, s1, fim_ordena	
	jal   menor_vetor
	beq   s4, a1, atualiza_var
        add   a2, zero, zero
 	slli  s5, s4, 2
	add   a0, s0, s5           
	jal   swap_vector
atualiza_var:	
	addi s4, s4, 1
	slli s5, s4, 2
	add  a0, s0, s5
	sub  a1, s1, s4
	j    segue_ordena
fim_ordena:
	add   ra, zero, s6
	ret	
	
