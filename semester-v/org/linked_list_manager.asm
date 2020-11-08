.globl main

.data
	header:           .string "\t+-----------------------------------------------------------------------+\n"
	welcomessage:     .string "\t|   Bem-vindo ao gerenciador de lista encadeada ultimate v1.0.1         |\n"
	insert:           .string "\t|   1- Insere um elemento na lista                                      |\n"
	removebyindex:    .string "\t|   2- Remove um elemento pelo seu índice                               |\n"
	removebyvalue:    .string "\t|   3- Remove um elemento pelo seu valor                                |\n"
	listvalues:       .string "\t|   4- Mostra os valores da lista                                       |\n"
	exit:             .string "\t|   0- Sai do programa e exibe o total de valores inseridos e removidos |\n"
	footer:           .string "\t+-----------------------------------------------------------------------+\n"
	inputcode:        .string "\tPor favor, digite o código da operação: "
	inputnumber:      .string "\tDigite o número a ser inserido: "
	removeindex:      .string "\tDigite o índice do valor a ser removido: "
	removevalue:      .string "\tDigite o valor a ser removido\n"
	exitmessage:      .string "\tNunca é um adeus, espero te-lô satisfeito, não é muito mas é trabalho honesto.\n"
	emptylistmessage: .string "\tNão é possível realizar esta operação, a lista está vazia.\n"
	amountinserted:   .string "\tQuantidade de elementos inseridos: "
	amountremoved :   .string "\tQuantidade de elementos excluídos: "
	length:           .string "\tTamanho da lista:"
	breakline:        .string "\n"
	tab:   		  .string "\t"
	space:            .string " "
	operationcodes:   .word 1, 2, 3, 4
	last: .string "\n\tUltimo elemento: "
	
.text
	main:

		la a2, operationcodes
		lw a3, 0(a2)           # Codigo para inserir
		lw a4, 4(a2)           # Remover por índice
		lw a5, 8(a2)           # Remover por valor
		lw a6, 12(a2)          # Listar
		
		addi s1, sp, 0         # Salva o valor de Stack Pointer
		addi s2, sp,0          # Salva o endereço do 1° elemento da lista
		addi s3, sp, 0       # Salva o endereço do último elemento adicionado
		
		addi s4, zero, 0       # Tamanho da lista
		addi s5, zero, 0       # Quantidade de elemetos adicionados
		addi s6, zero, 0       # Quantidade de elemetos removidos
		
		j print_menu
		
	print_menu:
	
		la a0, header
		li a7, 4               # Código 4 escreve uma string na saída padrão ─ STDOUT
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
		
		j input_code

		
	input_code:		
		la a0, inputcode
		li a7, 4
		ecall
		  
		li a7, 5                      # Input an integer
		ecall
		
		addi t1, s2, 0                # Endereço do 1º elemento para percorrer a lista
		addi t2, zero, 0              # Contador para percorrer a lista

		addi a2, a0, 0
		
		beqz a2, terminate
		beq a3, a2, input_value
		beq a4, a2, remove_by_index
		beq a5, a2, remove_by_value
		beq a6, a2, list_values
		
	input_value:
		la a0, inputnumber
		li a7, 4
		ecall
	
		li a7, 5
		ecall
		
		bgt s4, zero, insert_value     # Faz o desvio caso o tamanho da lista não for 0 
		sw a0, 0(s3)                   # Coloca o 1° valor na 1ª posição
		sw zero, -4(s3)                # Zera o endereço para o próximo valor
		addi t4, s3, 0
		j update_insert_stats
		
	update_insert_stats:
		                               # Salva o endereço do último valor inserido
		
		addi s4, s4, 1                 # Tamanho da lista
		addi s5, s5, 1                 # Elementos adicionados
		
		j input_code
		
	insert_value:
		
		addi sp, sp, -8                # Subtrai 8 do Stack Pointer
		addi s3, sp, 0
		
		sw a0, 0(s3)                  # Armazena o valor inserido no endereço 0
		sw zero, -4(s3)               # Atribui 0 para o endereço do próximo valor
		
		sw s3, -4(t4)                 # Atualiza o endereço para o próximo valor do elemento n-1
		addi t4, s3, 0
		
		j update_insert_stats
		
	remove_by_index:

		beqz s4, empty_list           # Desvia caso a lista for vazia
		
		la a0, removeindex
		li a7, 4
		ecall
		
		li a7, 5
		ecall
		
		addi t3, s4, -1              # t3 = Tamanho da lista -1
		beqz a0, remove_first        # Caso a0 == 0, remove o 1° elemento
		# beq a0, t3, remove_last      # Caso a0 == tamanho_list-1, remove o último elemento
		j remove_middle
	
	
	update_remove_stats: 		
		addi s4, s4, -1              # Tamanho da lista
		addi s6, s6, 1               # Elementos removidos
		j input_code
	
	remove_first:
		lw s2, -4(s2)                # Endereço do próximo elemento
 	
		j update_remove_stats

	# remove_last:
	##	sw zero, -4(t4)               # Coloca zero no endereço do penúltimo elemento
#		addi s3, s3, 8		     # Atualiza o valor do último elemento 
#			
#		j update_remove_stats
	
	remove_middle:
		beq t2, a0, change_pointers
		addi t2, t2, 1               # Incrementa o contador caso o índice não tiver sido encontrado
		addi t3, t1, 0               # Armazena o endereço do valor anterior
		addi t4, t3, 0
		lw t1, -4(t1)                # Acessa o endereço do próximo elemento
		
		j remove_middle	
	
	change_pointers:
	
		lw t0, -4(t1)                # Carrega o endereço do próximo elemento
		sw t0, -4(t3)                # Altera o endereço do elemento anterior ao que será excluído (ver linha 161)
		addi s3, t3, 0
		j update_remove_stats
		
	remove_by_value:
		beqz s4, empty_list          # Faz o desvio caso a lista for vazia 
	
		la a0, removevalue
		li a7, 4
		ecall
	
		li a7, 5
		ecall
		
		addi s1, s1, -1            # Decrementa o tamanho da lista
		addi s4, zero, 1           # Incrementa a quantidade de elementos removidos
		
		j input_code

	empty_list:
		addi s2, sp, 0
		addi s3, sp, 0
		
		la a0, emptylistmessage
		li a7, 4
		ecall
		
		j input_code		

	list_values:
		beqz s4, empty_list          # Desvia caso a lista for vazia
		
		la a0, length
		li a7, 4
		ecall
		
		addi a0, s4, 0
		li a7, 1
		ecall
		
		la a0, breakline
		li a7, 4
		ecall
		
		la a0, tab
		li a7, 4
		ecall

		j continue_listing
		
	continue_listing:
		
		lw a0, 0(t1)
		lw t1, -4(t1)              # Acessa o endereço do próximo elemento

		li a7, 1
		ecall
		
		la a0, space
		li a7, 4
		ecall

		bge t1, sp, continue_listing

		la a0, breakline
		li a7, 4
		ecall
		
		j input_code

	terminate:
		la a0, amountinserted
		li a7, 4
		ecall
		
		addi a0, s5, 0         # Mostra a quantidade de valores removidos
		li a7, 1
		ecall
		
		la a0, breakline
		li a7, 4
		ecall

		la a0, amountremoved
		li a7, 4
		ecall
		
		addi a0, s6, 0         # Mostra a quantidade de valores inseridos
		li a7, 1
		ecall
		
		la a0, breakline
		li a7, 4
		ecall
		
		la a0, exitmessage
		li a7, 4
		ecall
		ebreak
		
