section .data

	msg db "usage DELETE [source]",10
	msglen equ $-msg

%macro io 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .bss

source resb 10
sourceHandle resq 1
buff resb 512
buffLen resq 1

section .text
	global _start

_start:

	pop r8
	cmp r8,2
	jne down
		
	pop r8
	pop r8
	mov esi,source


	

up: mov al,[r8]
	cmp al,00h
	je next1
	mov [esi],al
	inc r8
	inc esi
	jmp up
	
next1:	io 87,source,0,0

	
EXIT:
	io 60,0,0,0
down:
	io 1,1,msg,msglen
	jmp EXIT
	
