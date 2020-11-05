.globl main

.data

.text

	main:
		addi  a0, zero, 6
		addi a1, zero, 6
		addi a2, zero, 0
		addi a3, zero, 0
		addi a4, zero, 1
		j mult
		
	mult: 
		beq a0 a2, end
		add a3, a3, a1
		add a2, a2, a4
		j mult
		
	end:
		add s0, s0, a3
		ret
		
