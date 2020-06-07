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
        mov dl, byte[rsi + rcx]
        mov byte[rdi + rcx], dl
        cmp dl, 0
        je end_loop
        inc rcx
        jmp start_loop
    end_loop:
        mov rax, rdi
        ret

; 아직 정확하게 모르겠는 부분 있음. dl이나 rsi, rdi 같은 것들?
; 어떻게 매개변수가 레지스터에 들어가는지?