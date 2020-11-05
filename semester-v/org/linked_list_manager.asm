.globl main

.data
	vector:         .word 0
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
	exitmessage:    .string "\tNunca é um adeus, espero te-lô satisfeito, não é muito mas é trabalho honesto.\n"
	breakline:      .string "\n"
	tab:   		.string "\t"
	operationcodes: .word 1, 2, 3, 4
	
.text
	main:
		# la a0, vector
		# addi a1, zero, 0    # a1 armazena o código da operação
		# addi a2, zero, 0    # a2 armazena o tamanho da lista
		                      # Carrega o endereço da 1ª posição da string
				      # referenciada pela label welcomessage

		addi a0, x0, 4
		la a1, operationcodes
		lw a3, 0(a1)           # Codigo para inserir
		lw a4, 4(a1)           # Remover por índice
		lw a5, 8(a1)           # Remover por valor
		lw a6, 16(a1)          # Listar
		jal print_menu
		jal input_code
		
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
		
		add a2, zero, a0
		
		beq a2, a3, insert_value
		beq a2, a4, remove_by_index
		beqz a2, terminate
		
		j input_code
		
	print_value:
		li a7, 1                 # Print an integer
		ecall
		
	insert_value:
		la a0, inputnumber
		li a7, 4
		ecall
	
		li a7, 5                 # Input an integer
		ecall
		
		# Logica para inserir o valor
		
		li a7, 1                 # Print an integer
		ecall
		
	remove_by_index:
		la a0, removeindex
		li a7, 4
		ecall
	
		li a7, 5                 # Input an integer
		ecall
		
		# Logica para remover

	terminate:
		la a0, exitmessage
		li a7, 4
		ecall
		ebreak
		ret	
		
