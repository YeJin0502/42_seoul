section .text
global  ft_write

ft_write:
    mov rax, 1 ; for linux
    ; https://filippo.io/linux-syscall-table/
    syscall
    ret

; 에러 아직 구현 안함