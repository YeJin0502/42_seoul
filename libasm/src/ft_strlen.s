section .text
global  _ft_strlen

_ft_strlen:
    xor rax, rax
    start_loop:
        cmp byte[rdi + rax], 0
        je end_loop
        inc rax
        jmp start_loop
    end_loop:
        ret