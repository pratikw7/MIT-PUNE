
section .data


	msg1 db 10,"Original contents are : "
	msg1len equ $-msg1

	msg2 db 10,"Sorted contents are : "
	msg2len equ $-msg2


	newline db 10

filename db "array.txt",00h

	%macro operate 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	%endmacro

section .bss

	buffer resb 512
	filehd resq 1
	size resq 1
	arr resb 5
	disp resb 15
	temp resb 1
	flag resb 1

section .text
global _start
_start:
							
	operate 2,filename,0,777q					
	mov [filehd],rax						
	operate 0,[filehd],buffer,512					
	mov [size],rax							
	operate 1,1,msg1,msg1len
	operate 1,1,newline,1
	operate 1,1,buffer,[size]
	operate 3,[filehd],0,0						
	mov bh,0
	mov cl,5							
	mov esi,buffer
	mov edi,arr
up2:	
	mov ax,0
	
	up:	
		mov bl,[esi]
		cmp bl,0Ah
		je over
		cmp bl,39h
		jbe skip
		sub bl,7h

	skip:	
		sub bl,30h
		rol ax,4
		add ax,bx
		inc esi
		jmp up

over:	
	mov byte[edi],al
	inc edi
	inc esi							
	dec cl							
	jnz up2							

	operate 1,1,msg2,msg2len
	operate 1,1,newline,1
	mov dl,4						
	mov ch,0

OLoop:
	mov esi,arr
	mov cl,4						
	
	ILoop:	
		mov al,byte[esi]
		cmp al,byte[esi+1]
		jbe skip2
		xchg al,byte[esi+1]
		mov byte[esi],al
	
	skip2:
		inc esi
		dec cl
		jnz ILoop
		dec dl
		jnz OLoop					

	mov esi,arr
	mov edi,disp
	mov cl,5
	mov byte[flag],0

displl:
	;mov byte[flag],2
	mov al,byte[esi]

flg:	
	rol al,4
	mov byte[temp],al
	and al,0Fh
	cmp al,9
	jbe down
	add al,7h

	down:	
		add al,30h
		mov byte[edi],al
		mov al,byte[temp]
		inc edi
		mov bl,byte[flag]
		xor bl,1					
		mov byte[flag],bl				
		cmp bl,1
		je flg
		inc esi
		mov byte[edi],0Ah				
		inc edi
		dec cl
		jnz displl					
		operate 1,1,disp,15
		operate 1,1,newline,1
		operate 60,0,0,0
;OUTPUT
;Original contents are : 
;10
;15
;12
;3
;6
;
;Sorted contents are : 
;03
;06
;10
;12
;15

