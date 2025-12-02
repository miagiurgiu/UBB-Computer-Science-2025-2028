bits 32
global start

extern exit, fopen, fscanf, fclose, printf, scanf, fprintf
import exit msvcrt.dll ; terminate program
import fopen msvcrt.dll ; open a file
import fscanf msvcrt.dll ; read formatted data from file
import fclose msvcrt.dll ; close file
import printf msvcrt.dll ; print to console
import scanf msvcrt.dll ; read formatted data from keyboard
import fprintf msvcrt.dll ; print in file

segment data use32 class=data
    input_name db "input.txt",0 ; inside it we have 10 3 -2 7 -5 4 -8 20 0 but 0 is not part of the array
    mode_r db "r",0

    fin dd 0 ; stores the file handle returned by fopen
    fout dd 0

    x times 100 dd 0 ; here will be stored the numbers from input.txt 10 3 -2 7 -5 4 -8 20
    y times 100 dd 0 ; here will be stored each partial sum 10, 13, 11, 18, 13, 17, 9, 29

    fmt_int db "%d",0 ; read one integer
    fmt_pair db "%d %d",0 ; read two integers
    fmt_out db "%d",10,0 ; print integer + newline

    ; variables for user-entered pairs:
    a dd 0
    b dd 0
    
    ; temporary pointer used to store computed addresses for fscanf
    pointer dd 0 
    
    output_name times 100 db 0
    mode_w db "w", 0
    fmt_string db "%s", 0

segment code use32 class=code
    start:

    ; open input file
        push mode_r
        push input_name
        call [fopen]
        add esp,4*2
        mov [fin],eax ; store returned file pointer from eax into variable fin

    ; read numbers from file into x[] until 0
        mov esi,0  ; esi is the index that goes through x
        
    read_nums:
        ; compute address of x[esi]
        mov ebx, x ; x is the base address
        mov eax, esi
        imul eax, 4 ; each element is 4 bytes
        add ebx, eax
        mov [pointer], ebx
        
        ; read one integer from file into x[esi]
        push dword [pointer]; address of x[esi]
        push fmt_int
        push dword [fin]
        call [fscanf]
        add esp,4*3
        
        ; check if the number is 0 -> stop, end of list
        mov eax,[x+esi*4] ; the address of x[esi]
        cmp eax,0
        je make_prefix
        inc esi
        jmp read_nums

    ; build prefix sums in y[]
    make_prefix:
        mov ecx,0
        mov eax,[x]
        mov [y],eax ; y[0]=x[0]
    
    prefix_loop:
        inc ecx
        cmp ecx,esi
        jge done_prefix ; stop when we encounter the last index
        
        ; compute y[ecx] = y[ecx-1] + x[ecx]
        mov eax,[y+(ecx-1)*4]
        add eax,[x+ecx*4]
        mov [y+ecx*4],eax
        jmp prefix_loop
        ; now we have y = 10 13 11 18 13 17 9 29

    done_prefix:

    ; read output filename
        push output_name
        push fmt_string
        call [scanf]
        add esp, 8
    
    ;open output file
        push mode_w
        push output_name
        call [fopen]
        add esp, 8
        mov [fout], eax
    
    ; read pairs from keyboard
    read_pairs:
        push b
        push a
        push fmt_pair
        call [scanf]
        add esp,4*3
            
        ; check if we need to exit 
        mov eax,[a]
        mov edx,[b]

        cmp eax,-1
        jne check_int
        cmp edx,-1
        je end_all

    check_int:
        ; validate interval 
        cmp eax,0
        jl read_pairs ; a<0 => invalid => next pair
        cmp edx,eax
        jl read_pairs ; b<a => invalid => next pair
        cmp edx,esi
        jge read_pairs ; b>=the nr of elements => invalid => next pair
    
        ; compute sum using prefix sums
        ; if a=0
        cmp eax,0 
        jne normal_sum
        mov ecx,[y+edx*4]
        jmp print_sum 
        ; sum = y[b]
    
    ; if a>0
    normal_sum:
        mov ecx,[y+edx*4]
        sub ecx,[y+(eax-1)*4]
        ; sum = y[b] - y[a-1]
    
    ; print the sum in the output file
    print_sum:
        push ecx
        push fmt_out
        push dword [fout]
        call [fprintf]
        add esp,4*3
        jmp read_pairs ; continue to read other pairs

    ; close file and exit
    end_all:
        push dword [fin]
        call [fclose]
        add esp,4*1
    
        push dword [fout]
        call [fclose]
        add esp, 4*1
        
        push 0
        call [exit]
