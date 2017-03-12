global count,spaces,lines,specChar
extern fname,buff,fhandle,buff_len

section .data

%macro io 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss

spaces resb 1
lines resb 1
specChar resb 1

section .text


count:

	;io 1,1,buff,[buff_len]
	mov esi,buff
	mov rcx,qword[buff_len]
up:
	cmp byte[esi],20h
	je spa
	cmp byte[esi],2eh
	je dot
	cmp byte[esi],"@" ; @ is special character
	je spec
	jmp compl
spa:
	inc byte[spaces]
	jmp compl
dot:
	inc byte[lines]
	jmp compl
spec:
	inc byte[specChar]
	jmp compl
compl:
	inc esi
	dec rcx
	jnz up
	
	add byte[spaces],30h
	add byte[lines],30h
	add byte[specChar],30h
	
ret
