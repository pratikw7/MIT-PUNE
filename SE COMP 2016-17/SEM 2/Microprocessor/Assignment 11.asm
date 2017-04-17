section .data
a dd 1.0
b dd 4.0
c dd 1.0
four dd 4.0
two dd 2.0
zero dd 0.0
new db 10
tenthousand dd 10000.0
dot db 2EH
dotlen : equ $-dot
msg db "The roots of the equation are ",10
msglen : equ $-msg
msg1 db "The first root is ",10
msg1len : equ $-msg1
msg2 db "The second root is ",10
msg2len : equ $-msg2
msg3 db "The roots are imaginary ",10
msg3len :equ $-msg3
msg4 db "The roots are real ",10
msg4len :equ $-msg4
msg5 db "The roots are equal ",10
msg5len :equ $-msg5


%macro operate 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro
 


section .bss
temp resd 1
delta resd 1
root1 resd 1
root11 rest 1
root2 resd 1
root22 rest 1
;temp resb 1
count resb 1
count1 resb 1
digit resb 1





section .text
 global _start
 _start:
 
 fldz
 fld dword[four]
 fmul dword[a]
 fmul dword[c]
 fst dword[temp]
 
 fld dword[b]
 fmul dword[b]
 fsub dword[temp]
 ;fsqrt 
 ftst
 fstsw ax
 sahf
 ja reall
 jz equall
 operate 1,1,msg3,msg3len
 jmp exit

 reall:
 operate 1,1,msg4,msg4len
 jmp roots

 equall:
 operate 1,1,msg5,msg5len
 
 roots:
 fsqrt
fstp dword[delta]
 
 ;root1:
 fld dword[delta]
 fsub dword[b]
 fdiv dword[a]
 fdiv dword[two]
 fst dword[root1]
 fmul dword[tenthousand]
 fbstp tword[root11]

 operate 1,1,msg1,msg1len
 mov ebp,root11
 call display

 fldz
 fld dword[four]
 fmul dword[a]
 fmul dword[c]
 fst dword[temp]
 
 fld dword[b]
 fmul dword[b]
 fsub dword[temp]
 fsqrt 
 fstp dword[delta]


 ;root2:
 fld dword[delta]
 fchs 
 fsub dword[b]
 fdiv dword[a]
 fdiv dword[two]
 fst dword[root2]
 fmul dword[tenthousand]
 fbstp tword[root22]

 operate 1,1,msg2,msg2len
 mov ebp,root22
 call display
exit:
operate 60,0,0,0
 
 
 display:
 ;mov ebp,mean1
 mov byte[count],10
 add ebp,9
disp: cmp byte[ebp],00H
 je onlydecrement
  cmp byte[count],02H
  jne print
 operate 1,1,dot,dotlen
  
 print:mov byte[count1],2
      mov al,byte[ebp]
   inner: rol al,4
       mov byte[temp],al
       and al,0FH
       cmp al,09H
       jbe addy
       add al,07H
  addy:
       add al,30H
       mov byte[digit],al
       operate 1,1,digit,1
       mov al,byte[temp]
       dec byte[count1]
       jnz inner
  
onlydecrement:
 dec ebp
 dec byte[count]
 jnz disp
 operate 1,1,new,1
ret

 
 
 ;OUTPUT
 ;student@B4L0106:~$ nasm -f elf64 rooty.asm
 ;student@B4L0106:~$ ld -o rooty rooty.o
 ;student@B4L0106:~$ ./rooty
 ;The roots are real 
 ;The first root is 
 ;80.2679
 ;The second root is 
 ;8003.7321

 

