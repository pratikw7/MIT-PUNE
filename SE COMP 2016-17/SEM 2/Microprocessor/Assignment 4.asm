section .data

%macro io 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx, %4
	syscall
%endmacro

msg db "Enter Multiplicand: "
msglen equ $-msg
msg1 db "Enter Multiplier: "
msg1len equ $-msg1
msg2 db "1. By repeated addition",10
msg2len equ $-msg2
msg3 db "2. By shift add method",10
msg3len equ $-msg3
msg4 db "3. EXIT",10
msg4len equ $-msg4



section .bss

inp resb 2 ;	 	For inputing options
multiplier resb 1 ; 	For inputing Multiplier
multiplicand resb 1; 	For inputing Multiplicand
result resb 4; 
temp resb 3

section .text

global _start

_start:
	io 1,1,msg,msglen
	io 0,0,temp,3
	mov esi,multiplicand
	call pack
	io 1,1,msg1,msg1len
	io 0,0,temp,3
	mov esi,multiplier
	call pack


print:
	io 1,1,msg2,msg2len
	io 1,1,msg3,msg3len
	io 1,1,msg4,msg4len
	io 0,0,inp,2
	
	cmp byte[inp],31h
	je BY_ADD
	
	cmp byte[inp],32h
	je BY_SHIFT

	cmp byte[inp],33h
	je EXIT
BY_ADD:
call ByAdd
jmp print
BY_SHIFT:
call ByShift
jmp print
ByAdd:
	mov ax,0
	mov bl,0
	mov al,byte[multiplicand]
	mov bl,byte[multiplier]
loop:	add byte[reslut],al
	dec bl
	jnz loop
	
	call display
ret

ByShift:
ret

pack:
	mov edi,temp
	mov ax,0
	mov bx,0; result
up:	mov al,byte[edi]
	cmp al,0Ah
	je cmpl
	cmp al,39h
	jbe convert
	sub al,07h
convert:
	sub al,30h
	and al,000Fh
	rol bx,4
	add bx,ax
	inc edi
	jmp up
	
cmpl:
mov word[esi],bx
ret

display:
	mov dx,0
	mov cx,word[result]
up1:	rol cx,4
	mov [result],cx
	and cx, 0fh
	cmp cx,09h
	jbe down
	add cx,30h
down:	add cx,37h
	mov [temp],al
	io 1,1,temp,1
	inc dx
	mov cx,[result]
	jmp up1
ret

EXIT:
io 60,0,0,0







