# @author Junior Vitor Ramisch 
# email: junior.ramisch@gmail.com
# matrícula: 1811100034

# @author Kellane Lopes Pereira
# email: kellanelopes2000@gmail.com
# matrícula: 1811100020

.globl main

.data
	header:           .string "\t+-----------------------------------------------------------------------+\n"
	welcomessage:     .string "\t|   Bem-vindo ao gerenciador de lista encadeada ultimate v1.0.2         |\n"
	insert:           .string "\t|   1- Insere um elemento na lista                                      |\n"
	removebyindex:    .string "\t|   2- Remove um elemento pelo seu índice                               |\n"
	removebyvalue:    .string "\t|   3- Remove um elemento pelo seu valor                                |\n"
	listvalues:       .string "\t|   4- Mostra os valores da lista                                       |\n"
	exit:             .string "\t|   0- Sai do programa e exibe o total de valores inseridos e removidos |\n"
	footer:           .string "\t+-----------------------------------------------------------------------+\n"
	inputcode:        .string "\tPor favor, digite o código da operação: "
	inputnumber:      .string "\tDigite o número a ser inserido: "
	removeindex:      .string "\tDigite o índice do valor a ser removido: "
	removevalue:      .string "\tDigite o valor a ser removido: "
	exitmessage:      .string "\tNunca é um adeus, espero te-lô satisfeito, não é muito mas é trabalho honesto.\n"
	emptylistmessage: .string "\tNão é possível realizar esta operação, a lista está vazia.\n"
	valuenotfound:    .string "\tValor não encontrado.\n"
	indexnotfound:    .string "\tÍndice não encontrado.\n"
	amountinserted:   .string "\tQuantidade de elementos inseridos: "
	amountremoved :   .string "\tQuantidade de elementos excluídos: "
	length:           .string "\tTamanho da lista: "
	breakline:        .string "\n"
	tab:   		  .string "\t"
	space:            .string " "
	operationcodes:   .word 1, 2, 3, 4
	
.text
	main:
		la a2, operationcodes       # Carrega o vetor dos códigos de operação
		lw a3, 0(a2)                # Código para inserir
		lw a4, 4(a2)                # Remover por índice
		lw a5, 8(a2)                # Remover por valor
		lw a6, 12(a2)               # Listar valores
		
		addi s1, sp, 0              # Salva o endereço do 1° elemento inserido
		addi s2, sp, 0              # Salva o endereço do último elemento da lista,
		                            # na 1ª inserção  o 1º elemento inserido também é o último.
		
		addi s3, zero, 0            # Armazena o tamanho da lista
		addi s4, zero, 0            # Quantidade de elemetos adicionados
		addi s5, zero, 0            # Quantidade de elemetos removidos
		addi s6, zero, 0            # Salva o tamanho da lista -1
		
		j print_menu
		
	print_menu:                         
	
		la a0, header
		li a7, 4             
		ecall		            # Escreve o cabeçalho
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
		ecall		            # Mostra a mensagem que pede o código da operação
		  
		li a7, 5
		ecall		            # Lê o código da operação                        
		
		addi t1, s1, 0              # Reseta o valor de t1 que é o endereço do 1º elemento
					    # para posteriormente percorrer a lista.
		addi t2, zero, 0            # Reseta contador para percorrer a lista no remover por índice e 
					    # remover por valor.
		
		beqz a0, terminate          # Caso a0 == 0 termina o programa
		beq a3, a0, insert_value
		beq a4, a0, remove_by_index
		beq a5, a0, remove_by_value
		beq a6, a0, list_values
	
	insert_value:
		la a0, inputnumber
		li a7, 4
		ecall		               # Mostra a mensagem que pede o valor a ser inserido
	
		li a7, 5
		ecall		               # Lê o valor a ser inserido
		
		bgt s3, zero, insert_sorted    # Faz o desvio caso o tamanho da lista não for 0,
					       # caso contrário insere o 1º elemento 
		
		addi s1, s2, 0                 # Caso trivial: Insere o primeiro valor

		sw a0, 0(s2)                   # Coloca o 1° valor na 1ª posição
		sw zero, -4(s2)                # Zera o endereço para o próximo valor
		
		j update_insert_stats          # Atualiza o tamanho da lista e a quantidade de elementos
		                               # inseridos.

	update_insert_stats:
		
		addi s3, s3, 1                 # Atualiza o tamanho da lista
		addi s6, s3, -1                # Atualiza o tamanho da lista -1
		addi s4, s4, 1                 # Atualiza a quantidade de elementos adicionados
		
		j input_code
	
	insert_sorted:
		
		lw t5, 0(t1)                     # Carrega o valor da 1ª posição
		ble a0, t5, insert_element       # Caso o valor inserido seja menor ou igual que o atual então insere 
		beq t2, s6, push_back            # Se o contador == lista.length-1 então insere no fim
		beq t2, s3, input_code           # Chegou no fim da lista (just in case se loopar infinitamente)
		
		addi t2, t2, 1                   # Contador pra controlar onde está sendo inserido (início, meio ou fim)
		addi t3, t1, 0                   # Guarda o endereço do elemento atual que está sendo comparado para posteriormente
		                                 # usá-lo para ajustar os endereços (na prox iteração t3 será o elemento anterior).
		lw t1, -4(t1)                    # Carrega o endereço do próximo elemento
		
		j insert_sorted
	
	insert_element:
		beqz t2, push_front              # Se o contador for 0 significa que deve ser inserido no início
			
		addi sp, sp, -8                  # Aloca memória na pilha
		sw a0, 0(sp)                     # Armazena o novo valor
		sw t1, -4(sp)                    # Faz o link com o próximo elemento
		
		sw sp, -4(t3)                    # Faz o link entre o elemento anterior com o endereço do novo valor (ver linha 138)
		
		j update_insert_stats
		
	push_front:
		addi sp, sp, -8                  # Alloca espaço na pilha
		sw a0, 0(sp)                     # Armazena o novo valor 
		sw t1, -4(sp)                    # Faz o link com o próximo elemento
		
		addi s1, sp, 0                   # Atualiza o endereço do 1° valor
		
		j update_insert_stats
	
	push_back:
		addi sp, sp, -8                  # Alloca espaço na pilha
		
		sw a0, 0(sp)                     # Armazena o novo valor  
		sw zero, -4(sp)                  # Coloca zero no endereço para o próximo valor   
		
		sw sp, -4(s2)                    # Armazena o endereço do valor inserido no penúltimo elemento (que nessa
		                                 # situação é representado pelo registrador s2).
		addi s2, sp, 0                   # Atualiza o endereço do último valor
		
		j update_insert_stats	
	
	remove_by_index:
		beqz s3, empty_list              # Desvia caso a lista for vazia (s3 == 0)
		
		la a0, removeindex
		li a7, 4
		ecall                            # Pede o indíce que será removido
		
		li a7, 5
		ecall                            # Lê o indice
		
		bge a0, s3, index_not_found      # Desvia caso o índice é >= que o tamanho da lista
		beqz a0, remove_first            # 
		j remove_middle 
	
	index_not_found:
		la a0, indexnotfound
		li a7, 4
		ecall
		
		j input_code
	
	update_remove_stats:
	
		addi s3, s3, -1                 # Decrementa o tamanho da lista
		addi s6, s3, -1                 # Decrementa o tamanho-1
		addi s5, s5, 1                  # Incrementa a quantidade de elementos removidos
		j input_code
	
	remove_first:
		lw s1, -4(s1)                   # Define como 1° elemento o endereço do próximo elemento
 	
		j update_remove_stats
	
	remove_middle:
		beq t2, a0, change_pointers
		addi t2, t2, 1                  # Incrementa o contador caso o índice não tiver sido encontrado
		addi t3, t1, 0                  # Armazena o endereço do valor atual que na proxima iteração será o elemento anterior
		lw t1, -4(t1)                   # Acessa o endereço do próximo elemento
		
		j remove_middle	
	
	
	change_pointers:
						
		lw t0, -4(t1)                    # Carrega o endereço do próximo elemento
		sw t0, -4(t3)                    # Altera o endereço do elemento anterior ao que será excluído (ver linha 161)
				
 		beq t2, s6, update_last_pointer  # Caso o valor removido for o último será preciso atualizar
 						 # o registrador que aponta para o último elemento
		j update_remove_stats
	
	update_last_pointer:
		addi s2, t3, 0
		j update_remove_stats
	
	remove_by_value:
	
		beqz s3, empty_list              # Desvia caso a lista for vazia
			
		la a0, removevalue
		li a7, 4
		ecall                            # Pede o indíce que será removido
		
		li a7, 5
		ecall                            # Lê o índice

		lw t0, 0(t1)
		beq a0, t0, remove_first
		addi t2, zero, 0
		j remove_middle_value 	
		
	remove_middle_value:
		
		beq a0, t0, change_value_pointers
		bge t2, s6, value_not_found      # Se o contador for maior que o tamanho da lista-1 o valor inserido não existe

		addi t2, t2, 1                   # Incrementa o contador caso o valor não tiver sido encontrado
		addi t3, t1, 0                   # Armazena o endereço do valor anterior

		lw t1, -4(t1)
		lw t0, 0(t1)
				
		j remove_middle_value
	
	change_value_pointers:
		lw t0, -4(t1)                   # Carrega o endereço do próximo elemento
		sw t0, -4(t3)                   # Altera o endereço do elemento anterior ao que será excluído (ver linha 254)
				
 		beq t2, s6, update_last_pointer # Verifica se o elemento que se deseja remover é o último
		j update_remove_stats
	
	value_not_found:
		
		la a0, valuenotfound
		li a7, 4
		ecall
		
		j input_code
	
	list_values:
		beqz s3, empty_list            # Desvia caso a lista for vazia
		
		la a0, length
		li a7, 4
		ecall
		
		addi a0, s3, 0
		li a7, 1
		ecall                          # Imprime o tamanho da lista
		
		la a0, breakline
		li a7, 4
		ecall
		
		la a0, tab
		li a7, 4
		ecall

		j continue_listing
		
	continue_listing:
		lw a0, 0(t1)
		lw t1, -4(t1)                  # Acessa o endereço do próximo elemento

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
	
	empty_list:
		addi s2, sp, 0                 # Reseta o endereço do 1° e último elemento
		addi s1, sp, 0
		
		la a0, emptylistmessage
		li a7, 4
		ecall                          # Mostra mensagem de que a lista está vazia
		
		j input_code
	
	terminate:
		la a0, amountinserted
		li a7, 4
		ecall
		
		addi a0, s4, 0
		li a7, 1
		ecall		               # Mostra a quantidade de elementos inseridos
		
		la a0, breakline
		li a7, 4
		ecall

		la a0, amountremoved
		li a7, 4
		ecall
		
		addi a0, s5, 0
		li a7, 1
		ecall		               # Mostra a quantidade de elementos removidos
		
		la a0, breakline
		li a7, 4
		ecall
		
		la a0, exitmessage
		li a7, 4
		ecall
