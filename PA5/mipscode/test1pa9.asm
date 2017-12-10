.data
.text

main:
    #create integer a
    li $t0, 0;

    #load the value from STDIN
    li $v0, 5
    syscall

    #store value from STDIN in to a
    move $t0, $v0

    #load a into $a0 to print out
    li $v0, 1

    move $a0, $t0
    syscall

    li $v0, 10
    syscall