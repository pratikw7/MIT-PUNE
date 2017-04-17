
section .data

	%macro operate 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	%endmacro

	msg db 10,"Mean: "
	msglen equ $-msg

	msgvar db 10,"Variance: "
	msgvarlen equ $-msgvar
	
	msgstd db 10,"Standard Deviation: "
	msgstdlen equ $-msgstd

	newline db 10

	arrvar dd 0.0, 0.0, 0.0, 0.0, 0.0
	arr dd 3.0,4.0,12.5,10.8,4.5
	result dt 0.0						
	divisor dd 5.0
	mean dd 0.0
	variance dd 0.0
	stdev dd 0.0
	tenK dd 10000.0						
	dot db '.'
	count db 0
	count1 db 0
	temp db 0
	tempdisp db 0
	varcnt db 5


section .text
global _start
_start:

	operate 1,1,msg,msglen
	mov esi,arr						
	mov cl,5
	fldz							
	
up:	
	fadd dword[esi]
	add esi,4					
	dec cl
	jnz up						
	fdiv dword[divisor]				
	fst dword[mean]					
	fmul dword[tenK]				
	fbstp tword[result]				
							
							
							
	call displ					
	operate 1,1,newline,1


	operate 1,1,msgvar,msgvarlen
	
	mov esi,arr
	mov edi,arrvar

var1:	
	fld dword[esi]					
	fsub dword[mean]				
	fmul st0					
	fstp dword[edi]					
	add edi,4
	add esi,4
	dec byte[varcnt]
	jnz var1					
	mov cl,5
	mov esi,arrvar
	fldz						

VarUp:
	fadd dword[esi]
	add esi,4
	dec cl
	jnz VarUp					
	fdiv dword[divisor]
	fst dword[variance]
	fmul dword[tenK]
	fbstp tword[result]	
	call displ
	operate 1,1,newline,1


	operate 1,1,msgstd,msgstdlen			
	fld dword[variance]
	fsqrt						
	fst dword[stdev]				
	fmul dword[tenK]
	fbstp tword[result]
	call displ
	operate 1,1,newline,1

	operate 60,0,0,0				

displ:	
	mov byte[count],10
	mov ebp,result
	add ebp,9					

again:
	mov bl,byte[ebp]
	cmp byte[ebp],0
	je skip
	cmp byte[count],2
	jne down1
	operate 1,1,dot,1

down1:
	mov byte[count1],2

next:
	rol bl,4
	mov byte[temp],bl
	and bl,0Fh
	cmp bl,9
	jbe skip2
	add bl,7h

skip2:
	add bl,30h
	mov byte[tempdisp],bl
	operate 1,1,tempdisp,1
	mov bl,byte[temp]
	dec byte[count1]
	jnz next

skip:	
	dec ebp
	dec byte[count]
	jnz again
ret


;OUTPUT
;
;Mean: 06.96
;
;Variance: 15.1864
;
;Standard Deviation: 03.8970

