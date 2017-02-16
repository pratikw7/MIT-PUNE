section .data

msg1 db "Enter the BCD number: ",10
msg1len equ $-msg1

%macro io 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss

num resb 8

section .text

global _start
_start:

	mov bp,8
	io 1,1,msg1,msg1len
	io 0,0,num,8
	mov esi,num
	mov eax,0
	mov ecx,0Ah
convert:	
	mul ecx
	mov bl,byte[esi]
	sub bl,30h
	add ax,bx	
	inc esi
	cmp byte[esi],0Ah
	je display
	jmp convert


display:
	rol eax,4
	mov ebx,eax
	and eax,000fh
	cmp al,09
	jbe down
	add al,07h

down:
	add al,30h
	mov byte[num],al
	io 1,1,num,1
	mov eax,ebx
	dec bp
	jnz display
	
exit:
io 60,0,0,0
