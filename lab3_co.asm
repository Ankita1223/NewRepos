.text
.globl main
main:
li $v0,4
la $a0,msg1
syscall
li $v0,5
syscall
move $t0,$v0
li $v0,4
la $a0,msg2
syscall
li $v0,5
syscall
move $t1,$v0
blez $t1, exit

mul $t2,$t1,$t0
move $t3,$t0
loop:
move $a0,$t3
li $v0,1
syscall

beq $t2,$t3,endloop
add $t3,$t3,$t0
la $a0,space
li $v0,4
syscall
b loop
endloop:
la $a0, newline
li $v0, 4
syscall
 exit:
 li $v0, 10
 syscall
 
 .data
 msg1: .asciiz "Enter a"
 msg2: .asciiz "Entre b"
 space: .asciiz " "
 newline: .asciiz "\n"
 
