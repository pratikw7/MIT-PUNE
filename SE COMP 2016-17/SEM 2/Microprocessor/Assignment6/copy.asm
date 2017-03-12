section .data

	msg db "usage COPY [source] [destination]",10
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
destination resb 20
sourceHandle resq 1
destinationHandle resq 1
buff resb 512
buffLen resq 1

section .text
	global _start

_start:

	pop r8
	cmp r8,3
	jne down
	
	pop r8	
	pop r8
	mov esi,source


	

up: mov al,[r8]
	cmp al,00h
	je next
	mov [esi],al
	inc r8
	inc esi
	jmp up
	
next:	pop r8
	mov esi,destination
up3: mov al,[r8]
	cmp al,00h
	je next1

	mov [esi],al
	inc r8
	inc esi
	jmp up3

next1:	io 2,source,00000q,0777q
	mov [sourceHandle],rax
	io 85,destination,0666q,0
	io 2,destination,2,0666q
	mov [destinationHandle],rax

up2:	io 0,[sourceHandle],buff,512
	mov [buffLen], rax
	
	
	io 1,[destinationHandle],buff,[buffLen]
	mov r8,[buffLen]
	cmp r8,512
	je up2

close:
	io 3,[sourceHandle],0,0
	io 3,[destinationHandle],0,0

EXIT:
	io 60,0,0,0
down:
	io 1,1,msg,msglen
	jmp EXIT
	
