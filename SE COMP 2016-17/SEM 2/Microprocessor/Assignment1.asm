section .data
	msg1 db "The array is: "
	msg1Len equ $-msg1
	msg2 db "No. of positive numbers are: "
	msg2Len equ $-msg2
	msg3 db "No. of negative numbers are: "
	msg3Len equ $-msg3
	nl db 10				; Print
	arr dq 23h,56h,	-98h,11h,-0AFh,0FFh,-90h
	%macro print 2				;Macro for print
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro 
section .bss
	pos resb 1
	negative resb 1
section .text
	global _start
_start:
	mov ebx,arr
	mov rcx,7
up:
	BT qword[ebx],63			;Check if pos or neg
	jnc posi
	inc byte[negative]
	jmp down
posi:
	inc byte[pos]
down:
	add ebx,8
	dec rcx
	jnz up

add byte[pos],30h
add byte[negative],30h
				;Print statements to console
print msg1,msg1Len
print nl,1
print msg2,msg2Len
print pos,1
print nl,1
print msg3,msg3Len
print negative,1
print nl,1
				;Exit call
mov rax,60
mov rdi,0
syscall
