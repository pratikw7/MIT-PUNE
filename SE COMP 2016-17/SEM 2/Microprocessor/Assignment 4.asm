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
;msg2len equ $-msg2
msg3 db "2. By shift add method",10
;msg3len equ $-msg3
msg4 db "3. EXIT",10
msg4len equ $-msg2



section .bss

inp resb 2 ;	 	For inputting options
multiplier resb 1 ; 	For inputting Multiplier
multiplicand resb 1; 	For inputting Multiplicand
result resb 4;
temp resb 3

section .text

global _start

_start:



	
	call pack
mov esi,multiplicand
mov byte[esi],bl

	;io 1,1,msg1,msg1len
	;io 0,0,temp,3
	call pack
mov esi,multiplier
mov byte[esi],bl

	;io 1,1,msg2,msg4len
	;io 1,1,msg3,msg3len
	;io 1,1,msg4,msg4len
	;io 0,0,inp,2
		print:
	io 1,1,msg2,msg4len
	io 0,0,inp,2

	mov al,byte[inp]
	cmp al,31h
	je BY_ADD

	cmp al,32h
	je BY_SHIFT

	cmp al,33h
	je EXIT
BY_ADD:
call ByAdd
call display
jmp print
BY_SHIFT:
call ByShift
call display
jmp print
EXIT:
io 60,0,0,0

ByAdd:
	mov ax,0
	mov bl,0
  	mov cx,0
	mov al,byte[multiplicand]
	mov bl,byte[multiplier]
loop:	
	add cx,ax
	dec bl
	jnz loop

  	mov word[result],cx
ret

ByShift:
mov al,byte[multiplicand]
	mov bl,byte[multiplier]
	mov cx,0
	mov dx,8H
	
	up2:
		shl cx,1
		shl al,1        
		jnc ddo
		add cx,bx
		ddo:
			dec dx
			jnz up2
	mov word[result],cx
ret

pack:
	io 1,1,msg,msglen
	io 0,0,temp,3
	mov edi,temp
	
	mov bx,0; result
up:
	mov ax,0
    mov al,byte[edi]
	cmp al,0AH
	je cmpl
	cmp al,39H
	jbe convert
	sub al,07H
convert:
	sub al,30H
	and al,000fH
	rol bx,4
	add bx,ax
	inc edi
	jmp up

cmpl:

ret

display:
	mov bp,4
	mov ax,word[result]
up1:	
	rol ax,4
	mov word[result],ax
	and al, 0FH
	cmp al,09H
	jbe down
	add al,07H
down:	
	add al,30H
	mov byte[temp],al
	io 1,1,temp,1
  	mov ax,word[result]
	dec bp
  jnz up1


ret
-----------OUTPUT-------------
Enter Multiplicand: FF
Enter Multiplicand: FF
1. By repeated addition
2. By shift add method
3. EXIT
1
FE011. By repeated addition
2. By shift add method
3. EXIT
2
FE011. By repeated addition
2. By shift add method
3. EXIT
3

