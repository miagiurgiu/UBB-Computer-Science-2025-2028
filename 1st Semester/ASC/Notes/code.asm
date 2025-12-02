bits 32
global start
extern exit, fopen, fread, fclose, printf

import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll

segment data use32 class=data
    ; defining the file name
    file_name_input db "input.txt",0
    ; defining the mode - read
    mode db "r",0
    ; defining the descriptor
    descriptor dd 0
    ; defining the buffer for reading
    buffer db 100 dup(0) ; buffer times 100 db 0
    ; the buffer size (100)
    buffer_size equ 100
    
    ;defining the output
    file_name_output db "output.txt",0
    ; defining the format
    format_string db "%s",0
   
    s db 10,3,-2,7,-5,4,-8,20,0
    l equ $ - s
    d times l db 0

segment code use32 class=code
start:
    ; 1 task
    ; open
    ; values in the stack are put from right to left
    push dword mode ; this is why we start with the mode
    push dword file_name_input ; the file wewant to read
    call [fopen] ; call the fopen function
    add esp, 4*2 ; clear the stack - 2 parameters => 4*2

    ; handnling when unsuccessful opening
    cmp eax, 0 ; check if eax is 0
    je open_failed ; if yes, we could not open the file
    mov [descriptor], eax ; if not, we add the value in the descriptor so that we can close the file gracefully at the end

    ; reading the file
    push dword [descriptor]  ; using the descriptor
    push dword buffer_size
    push dword 1
    
    push dword buffer
    call [fread] ; call the read function
    add esp, 4*4 ; clear the stack - 4 parameters

    ; handling unsuccessful reading
    cmp eax, 0
    je read_failed

    ; printing the content of the file
    push dword buffer
    push dword format_string
    call [printf]
    add esp, 4*2

    ; closing
    push dword [descriptor]
    call [fclose]
    add esp, 4*1

    ; exiting
    push dword 0
    call [exit]

    open_failed:
    push dword 0
    call [exit]

    read_failed:
    push dword 0
    call [exit]
    
    ; idea for 2 task
    ; using fscanf read the content in the file
    ; using a loop take the whole string s and compute the sum using other loop
    
    ; idea for 3 task
    ; read a new file in the terminal
    ; read those pairs
    ; cmp each pair with -1,-1
    ; if encountered, jump to where the sum is calculated
