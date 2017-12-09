.data
.text

main:
    #create integer a
    li $t0, 0;

    #create integer b
    li $t1, 0;

    #load the value from STDIN
    li $v0, 5
    syscall

    #store value from STDIN in to a
    move $t0, $v0;

    #create integer i
    li $t2, 0;

    #check if a less than i
    slt $t3, $t0, $t2

    #enter loop
    beq $t3, $zero, L1

    #else print b
    li $v0, 1

    move $a0, $t1
    syscall

    li $v0, 10
    syscall

L1:
    #add i to b
    add $t1, $t1, $t2

    #increment i
    addi $t2, $t2, 1
    
    #check if a less than i
    slt $t3, $t0, $t2

    #keep looping
    beq $t3, $zero, L1

    j L2

L2:
    #print b
    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 10
    syscall