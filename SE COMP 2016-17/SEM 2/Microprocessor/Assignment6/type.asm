section .data

	msg db "Usage TYPE [flename]",10
	msglen equ $-msg

%macro io 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .bss

filename resb 10
fileHandle resq 1
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
	
	mov esi,filename
up: mov al,[r8]
	cmp al,00h
	je next
	mov [esi],al
	inc r8
	inc esi
	jmp up
next:
	io 2,filename,00000q,0777q
	mov [fileHandle],rax
	
up2:	io 0,[fileHandle],buff,512
	mov [buffLen], rax
	io 1,1,buff,[buffLen]
	mov r8,[buffLen]
	cmp r8,512
	je up2

close:
	io 3,[fileHandle],0,0

EXIT:
	io 60,0,0,0
down:
	io 1,1,msg,msglen
	jmp EXIT
	
