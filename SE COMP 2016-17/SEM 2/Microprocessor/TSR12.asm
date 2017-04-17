 ;Macro to push all register's value onto the stack 
pushall macro
push ax
push bx
push cx
push dx
push si
push di
push ds
push es
push bp
push sp
endm

;Macro to retain all register's value from stack
popall macro
pop sp
pop bp
pop es
pop ds
pop di
pop si
pop dx
pop cx
pop bx
pop ax
endm

.model tiny
.code
;Originate to 100h as psp ends at 100h

org 100h

BEGIN:

jmp INIT
oldint8 dd ?
cnt db 0	;Initialise counter to 0
flag db 0


timer:
pushall
cmp cs:flag,1
je next1

mov ah,05       ;Activate a page
mov al,01       ; page no.    
int 10h

mov ah,02        ; set cursor
mov bh,01        ; page no.          
mov dh,12        ;row no.   
mov dl,40        ;column no. 
int 10h

in al,60h        ; keyboard port address
mov ah,09        ; display a character
mov bh,00        ; 
mov bl,7
mov cx,1
int 10h

inc cs:cnt	;Increment counter
cmp cs:cnt,91   ;compare with 91 ticks=5 secs
je next
jmp next1
next:
mov cs:flag,1

mov ah,05
mov al,00
int 10h

next1:

popall
jmp cs:oldint8



INIT:
CLI
mov ah,35h
mov al,8
int 21h

mov word ptr oldint8,bx
mov word ptr oldint8+2,es

mov ah,25h
mov al,8
mov dx,offset timer
int 21h



mov ah,31h
mov dx,offset INIT
int 21h

STI
END BEGIN
