section .text
global  ft_strcpy

ft_strcpy:
    xor rcx, rcx
    start_loop:
        mov dl, byte[rsi + rcx]
        mov byte[rdi + rcx], dl
        cmp dl, 0
        je end_loop
        inc rcx
        jmp start_loop
    end_loop:
        mov rax, rdi
        ret