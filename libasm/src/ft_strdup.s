; char *ft_strdup(char *str)
; {
;     int len;
;     char *ret;
;     int i;

;     len = ft_strlen(str);
;     ret = (char *)malloc(len + 1);
;     ret[len] = 0;
;     i = 0;
;     while (i < len)
;     {
;         ret[i] = str[i];
;         i++;
;     }
;     return (ret);
; }

section .text
extern malloc
extern ft_strlen
extern ft_strcpy
global  ft_strdup

ft_strdup:
    push rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc
    pop rsi
    mov rdi, rax
    call ft_strcpy
    ret