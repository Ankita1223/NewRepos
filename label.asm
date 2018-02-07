section .text
msg db 'my name is aditi' 
len equ $-

section .data
global_start
_start:

call print_txt
int 0x80
mov eax,1
int 0x80
 print_txt
mov eax,4
mov edx,len
mov ecx,msg
mov ebx,1
ret



