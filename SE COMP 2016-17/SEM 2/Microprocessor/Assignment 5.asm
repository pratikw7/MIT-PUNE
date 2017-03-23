;Ashwin Vaidya
;202030

section .data

	mg db "Value of GDTR. Base Address ",10
	mgl equ $-mg
	mg1 db "Limit ",10
	mg1l equ $-mg1
	ml db "Value of LDTR. Base Address ",10
	mll equ $-ml	
	mi db "Value of IDTR. Base Address ",10
	mil equ $-mi
	mt db "Value of TR. Base Address ",10
	mtl equ $-mt
	mms db "Value of MSW. Base Address ",10
	mmsl equ $-mms

	newl db 10

	%macro rw 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	%endmacro
section .bss

	gdtr resq 1
	gdtrlim resw 1

	idtr resq 1
	idtrlim resw 1

	ldtrlim resw 1
	trlim resw 1
	mswlim resw 1

	result64 resq 1
	result16 resw 1
	temp resb 1
section .text

global _start
_start:

	rw 1,1,newl,1
;GDTR
	rw 1,1,mg,mgl
	mov esi, gdtr
	sgdt [esi]
	mov rbx,[esi]
	call display64
	rw 1,1,newl,1
	
	rw 1,1,mg1,mg1l
	mov esi,gdtrlim
	mov bx,[esi]
	call display16
	rw 1,1,newl,1


	rw 1,1,newl,1
;IDTR
	rw 1,1,mi,mil
	mov esi, idtr
	sidt [esi]
	mov rbx,[esi]
	call display64
	rw 1,1,newl,1
	
	rw 1,1,mg1,mg1l
	mov esi,idtrlim
	mov bx,[esi]
	call display16
	rw 1,1,newl,1


	rw 1,1,newl,1
;LDTR
	rw 1,1,ml,mll
	mov esi, ldtrlim
	sldt [esi]
	mov bx,[esi]
	call display16
	rw 1,1,newl,1


	rw 1,1,newl,1
;TR
	rw 1,1,mt,mtl
	mov esi, trlim
	str [esi]
	mov bx,[esi]
	call display16
	rw 1,1,newl,1


	rw 1,1,newl,1
;MSW
	rw 1,1,mms,mmsl
	mov esi, mswlim
	smsw [esi]
	mov bx,[esi]
	call display16

	rw 1,1,newl,1
	rw 1,1,newl,1


exit:
	mov rax,60
	mov rsi,0
	syscall



display64:
	
	mov ebp,16
jump64:
	rol rbx,4
	mov qword[result64],rbx
	and rbx,0FH
	cmp rbx,09H
	jbe down64
	add rbx,07H
down64:
	add rbx,30H
	mov [temp],rbx
	rw 1,1,temp,1
	mov rbx,qword[result64]
	dec bp
	jnz jump64
	ret
display16:
	
	mov ebp,4
jump16:
	rol bx,4
	mov [result16],bx
	and bx,0FH
	cmp bx,09H
	jbe down16
	add bx,07H
down16:
	add bx,30H
	mov [temp],bx
	rw 1,1,temp,1
	mov bx,[result16]
	dec bp
	jnz jump16
	ret

;   OUTPUT

;Value of GDTR. Base Address 
;88007D604000007F
;Limit 
;FFFF

;Value of IDTR. Base Address 
;FFFF81DD70000FFF
;Limit 
;FFFF

;Value of LDTR. Base Address 
;0000

;Value of TR. Base Address 
;0040

;Value of MSW. Base Address 
;003B

