
main:
	addi $t0, $0, 0  # i = 0
	addi $t1, $0, 10 # upper limit = 10
	addi $s1, $0, 0  # sum = 0
	j loop

loop: 
	slt $t2, $t0, $t1
	beq $t2, 0, done
	addi $t0, $t0, 1
	addi $s1, $s1, 1
	j loop

done:  
	lui $t3, 0x1001
	sw $s1 0($t3)

	