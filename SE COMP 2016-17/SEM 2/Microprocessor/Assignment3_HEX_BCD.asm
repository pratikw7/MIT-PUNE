section .data

	msg db "Enter a HEX number",10
	msglen equ $-msg

%macro io 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss

num resb 5

section .text

global _start

_start:
	io 1,1,msg,msglen
	io 0,0,num,5
	mov eax,0h
	mov ebx,0h
	mov esi,num

loopCmp:
	mov al,byte[esi]
	cmp al,39h
	jbe convert
	sub al,07h
convert:
	sub al,30h
	and al,000Fh
	rol ebx,4
	add ebx,eax

	inc esi	
	cmp byte[esi],0ah
	jne loopCmp

mov eax,ebx
mov ebx,0Ah
mov ecx,0h
mov esi,num
loop:
	mov edx,0
	div bx
	push dx
	inc cx
	cmp ax,0h
	jne loop
store:
	mov edx,0
	pop dx
	add dx,30h
	mov byte[esi],dl
	inc esi
	dec cx
	jnz store
io 1,1,num,8


io 60,0,0,0
