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
exitmsg db "5. Exit",10
exitmsgLen: equ $-exitmsg
msg1 db "1. Non-overlapping without string",10
msg1Len: equ $-msg1
msg2 db "2. Non-overlapping with string",10
msg2Len: equ $-msg2
msg3 db "3. Overlapping without string",10
msg3Len: equ $-msg3
msg4 db "4. Overlapping with string",10
msg4Len: equ $-msg4
msgOffset db "Enter offset: ",10
msgOffsetLen: equ $-msgOffset
newln db 10
;arr1 db 41h,42h,43h,44h,45h,0,0,0,0,0
arr1 db "ABCDE00000"

section .bss
input resb 2

section .text
	global _start
_start:
display:
print msg1,msg1Len
print msg2,msg2Len
print msg3,msg3Len
print msg4,msg4Len
print exitmsg,exitmsgLen
scan input,2

mov cl, 5 
mov rsi, arr1
mov rdi, arr1
add rdi,5

cmp byte[input],35h
je exit

cmp byte[input],31h
je choice1

cmp byte[input],32h
je choice2

cmp byte[input],33h
je choice3

cmp byte[input],34h
je choice4

choice4:
print msgOffset,msgOffsetLen
scan input,2
mov edx,0
mov dl,byte[input]
sub edx,30h

mov ax,ds
mov es,dx
mov edi,arr1
mov esi,arr1
add esi,4
add edi,4
mov ecx,5



add edi,edx
STD
rep movsb
print arr1,10
print newln,1
jmp display

choice3:
print msgOffset,msgOffsetLen
scan input,2
mov edx,0
mov dl,byte[input]
sub edx,30h

mov ax,ds
mov es,dx
mov edi,arr1
mov esi,arr1
add esi,4
add edi,4
mov ecx,5



add edi,edx

loop1:
mov al,[esi]
mov [edi],al
dec esi
dec edi
dec ecx
jnz loop1
print arr1,10
print newln,1
jmp display

choice1:
mov al, [rsi]
mov [rdi], al
inc rsi
inc rdi
dec cl
jnz choice1
print arr1,10
print newln,1
jmp display

choice2:
mov esi, arr1
mov edi, arr1
add edi, 5 
mov ecx,5
CLD
rep movsb
print arr1,10
jmp display


exit:
mov rax,60
mov rdi,0
syscall
