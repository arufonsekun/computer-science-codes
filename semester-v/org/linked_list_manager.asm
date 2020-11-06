.globl main

.data
	header:         .string "\t+-----------------------------------------------------------------------+\n"
	welcomessage:   .string "\t|   Bem-vindo ao gerenciador de lista encadeada ultimate v1.0.0         |\n"
	insert:         .string "\t|   1- Insere um elemento na lista                                      |\n"
	removebyindex:  .string "\t|   2- Remove um elemento pelo seu índice                               |\n"
	removebyvalue:  .string "\t|   3- Remove um elemento pelo seu valor                                |\n"
	listvalues:     .string "\t|   4- Mostra os valores da lista                                       |\n"
	exit:           .string "\t|   0- Sai do programa e exibe o total de valores inseridos e removidos |\n"
	footer:         .string "\t+-----------------------------------------------------------------------+\n"
	inputcode:      .string "\tPor favor, digite o código da operação: "
	inputnumber:    .string "\tDigite o número a ser inserido: "
	removeindex:    .string "\tDigite o índice do valor a ser removido: "
	removevalue:    .string "\tDigite o valor a ser removido\n"
	exitmessage:    .string "\tNunca é um adeus, espero te-lô satisfeito, não é muito mas é trabalho honesto.\n"
	breakline:      .string "\n"
	tab:   		.string "\t"
	space:          .string " "
	operationcodes: .word 1, 2, 3, 4
	
.text
	main:

		la a2, operationcodes
		lw a3, 0(a2)           # Codigo para inserir
		lw a4, 4(a2)           # Remover por índice
		lw a5, 8(a2)           # Remover por valor
		lw a6, 12(a2)          # Listar
		
		addi s1, sp, 0      # Salvar ponteiro da pilha
		addi s2, zero,0    # Salvar endereço do ultimo elemento inserido
		
		addi s3, zero, 0       # Tamanho da lista
		addi s4, zero, 0       # Quantidade de elemetos adicionados
		addi s5, zero, 0       # Quantidade de elemetos removidos
		
		j print_menu
		j input_code
		
	print_menu:
	
		la a0, header
		li a7, 4              # Código 4 escreve uma string na saída padrão ─ STDOUT
		ecall
		
		la a0, welcomessage
		li a7, 4
		ecall
		
		la a0, insert
		li a7, 4
		ecall
		
		la a0, removebyindex
		li a7, 4
		ecall
		
		la a0, removebyvalue
		li a7, 4
		ecall
		
		la a0, listvalues
		li a7, 4
		ecall
		
		la a0, exit
		li a7, 4
		ecall
		
		la a0, footer
		li a7, 4
		ecall

		
	input_code:
		la a0, inputcode
		li a7, 4
		ecall
		  
		li a7, 5                 # Input an integer
		ecall
		
		addi t1, s2, 0          # Endereço do 1º elemento para percorrer a lista
		add a2, a0, zero
		
		beq a3, a2, input_value
		beq a4, a2, remove_by_index
		beq a5, a2, remove_by_value
		beq a6, a2, list_values
		beqz a2, terminate
		
		
	print_value:
		li a7, 1
		ecall
		
	input_value:
		la a0, inputnumber
		li a7, 4
		ecall
	
		li a7, 5
		ecall
		
		bgt s3, zero, insert_sorted    # Faz o desvio caso o tamanho da lista não for 0 
		sw a0, 0(sp)                   # Coloca o 1° valor na 1ª posição
		sw zero, 4(sp)                 # Zera o endereço para o próximo valor
		addi s2, sp, 0
		j update
		
	update:
		addi sp, sp, -8               # Subtrai 8 do Stack Pointer 		
		addi s3, s3, 1                # Tamanho da lista
		addi s4, s4, 1                # Elementos adicionados
		
		j input_code
		
	insert_sorted:
		
		sw a0, 0(sp)
		sw zero,4(sp)
		addi t0, sp, 0              # Armazena o endereço atual
		addi t2, sp, 4              # Volta para o valor anterior
		sw t0, 0(t2)                # Atualiza o endereço para o próximo valor do valor anterior
		j update
		
	remove_by_index:
		la a0, removeindex
		li a7, 4
		ecall
	
		li a7, 5
		ecall
		
		addi s1, s1, -1            # Decrementa o tamanho da lista
		addi s3, zero, 1           # Incrementa a quantidade de elementos removidos
		
		j input_code
		# Logica para remover
		
	remove_by_value:
		la a0, removevalue
		li a7, 4
		ecall
	
		li a7, 5
		ecall
		
		addi s1, s1, -1  # Decrementa o tamanho da lista
		addi s3, zero, 1 # Incrementa a quantidade de elementos removidos
		
		j input_code

	list_values:
		
		lw a0, 0(t1)
		lw t1, -4(t1)

		li a7, 1
		ecall

		bgt t1, sp, list_values
		j input_code
		

	terminate:
		la a0, exitmessage
		li a7, 4
		ecall
		ebreak
		
