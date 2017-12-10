.data
.text

main:
    li $v0, 5               #load the value from STDIN
    syscall
    move $t0, $v0;          #store value from STDIN in to a
    li $t1, 0;              #create integer b
    li $t2, 0;              #create integer i
L0:
    slt $t3, $t0, $t2       #check if a less than i
    beq $t3, $zero, L1      #enter loop
    j L2
L1:
    add $t1, $t1, $t2       #add i to b
    addi $t2, $t2, 1        
    slt $t3, $t0, $t2       #check if a less than i
    beq $t3, $zero, L1      #keep looping
    j L2                    #else exit
L2:
    li $v0, 1               #print b
    move $a0, $t1
    syscall
    li $v0, 10              #exit
    syscall



##############################################################################

main:
    t1 call readIntFromSTDIN 
    a =: t1
    b =: 0
    i := 0
L0:
    t2 := i <= a
    if t2 goto L1
    goto L2
L1:
    b := i
    i := i + 1
    goto L0
L2:
    Print b
    EndFunc