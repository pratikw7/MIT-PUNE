extern count,spaces,lines,specChar
global fname,buff,fhandle,buff_len

section .data

fname db "a.txt",00h

msg1 db "Number of spaces are: "
msg1len equ $-msg1
msg2 db "Number of lines are: "
msg2len equ $-msg2
msg3 db "Occurence of @ character is: "
msg3len equ $-msg3
nl db 0ah


%macro io 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss

	buff resb 512
	fhandle resq 1
	buff_len resq 1



section .text

global _start

_start:
	io 1,1,msg1,msg1len
	io 2,fname,000000q,0777q ;open
	mov [fhandle],rax

	io 0,[fhandle],buff,512 ;read
	mov qword[buff_len],rax
	
	call count
	io 1,1,msg1,msg1len
	io 1,1,spaces,1
	io 1,1,nl,1
	io 1,1,msg2,msg2len
	io 1,1,lines,1
	io 1,1,nl,1
	io 1,1,msg3,msg3len
	io 1,1,specChar,1
	io 1,1,nl,1
	io 3,fname,0,0 ;close
	io 60,0,0,0


