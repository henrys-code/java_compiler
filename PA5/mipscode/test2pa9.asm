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

    #load the value from STDIN
    li $v0, 5
    syscall

    #store value from STDIN in to b
    move $t1, $v0;

    #check which is bigger a or b
    slt $t2, $t1, $t0

    #print the smaller one
    beq $t2, $zero, L1

    #load a into $a0 to print out
    li $v0, 1

    move $a0, $t0
    syscall

    li $v0, 10
    syscall

L1:
    #load a into $a0 to print out
    li $v0, 1

    move $a0, $t1
    syscall

    li $v0, 10
    syscall