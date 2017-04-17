;Ashwin Vaidya
;202030
section .data
	msg db 'Factorial is:'
	msglen equ $-msg
	msgUsage db 'Usage [number]',0ah
	msgUlen equ $-msgUsage

	%macro io 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	%endmacro

section .bss
	temp resq 1
	temp1 resb 1
section .text

global _start
_start:
	
	pop r8
	cmp r8,2
	jne down
	pop r8
	pop r8
	io 1,1,msg,msglen
	mov bl,byte[r8]
	sub bl,30h
	mov eax,1
	call fact

	mov [temp],rax
	mov esi,temp
	mov rbx,0
	mov bp,4
	mov bx,ax
	
l2 :
	rol bx,4
	mov r9,rbx
	and rbx,000fh
	cmp bl,09
	jbe l1
	add bl,07h
	
	
l1 :    
	add bl,30h
	mov byte[temp1],bl
	io 1,1,temp1,1
	mov rbx,r9
	dec bp
	jnz l2
EXIT:
	io 60,0,0,0
fact:
	mul bx
	dec bx
	cmp bx,1
	jne driver
	ret
driver:
	call fact
	ret



down:
	io 1,1,msgUsage,msgUlen
	jmp EXIT
;;OUTPUT
;Factorial is:0078

