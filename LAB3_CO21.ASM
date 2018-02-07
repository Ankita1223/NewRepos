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
bgt $t1,$t0,label1   #$t1>$t0
li $v0,4
la $a0,msg4
syscall
label1:
li $v0,4
la $a0,msg3

.data
msg1: .asciiz "Enter a"
msg2: .asciiz "Enter b"
msg3: .asciiz "2nd > 1st"
msg4: .asciiz "1st > 2nd"
