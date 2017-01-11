section .data
	%macro print 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	%macro scan 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	hello db 'Enter Name',10
	helloLen: equ $-hello
	length db 'Length is '
	lengthLen: equ $-length
	Name db 'Your Name: '
	NameLen: equ $-Name
	new db 10
section .bss
name resb 20
len resq 1
section .text
	global _start
_start:
print hello,helloLen

scan name,20


mov rbx,rax

dec al
add al,30h
mov byte[len],al
print length,lengthLen
print len,1
print new,1
print Name,NameLen
print name,rbx

mov rax,60
mov rdi,0
syscall
