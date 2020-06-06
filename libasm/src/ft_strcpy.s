; char *ft_strcpy(char *dest, const char *src)
; {
;     int i;

;     i = 0;
;     while (src[i])
;     {
;         dest[i] = src[i];
;         i++;
;     }
;     return (dest);
; }

section .text
global  ft_strcpy

ft_strcpy:
    xor rcx, rcx
    start_loop:
        cmp byte[rdi + rax], 0
        je end_loop
