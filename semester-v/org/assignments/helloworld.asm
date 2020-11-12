.globl main

.data
	helloworld: .string "\nHello World!!\n"
	
.text 
	# ecall 1 mostra inteiro
	# ecall 4 mostra string
	# ecall 5 lê int
	main:
		
		addi a0, zero, 2
		sw a0, 0(sp)
		
		addi s0, sp, 0     # Salva o endereço do primeiro elemento
		
		addi sp, sp, -4    # Decrementa o endereço de SP 
		
		addi a0, zero, 5
		sw a0, 0(sp)    
		
		addi sp, sp, -4
	
		addi a0, zero, 6
		sw a0, 0(sp)
		
	loop:
		blt s0, sp, terminate
		lw a0, 0(s0)
		
		addi a7, zero, 1
		ecall
		
		addi s0, s0, -4
		
		j loop
		
	terminate:
		ebreak	
		