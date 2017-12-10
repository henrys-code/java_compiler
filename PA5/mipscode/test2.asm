main:
    li $v0, 5
    syscall
    move $t0, $v0
    li $v0, 5
    syscall
    move $t1, $v0
    slt $t2, $t1, $t0
    beq $t2, $zero, L0
    j L1
L0:
    li $v0, 1
    move $a0, $t1
    syscall
    j L1
L1:
    slt $t3, $t0, $t1
    beq $t3, $zero, L2
    j L3
L2:
    li $v0, 1
    move $a0, $t0
    syscall
    j L3
L3:
    li $v0, 10
    syscall
