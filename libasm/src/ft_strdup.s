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
global  ft_strdup

ft_strdup:
    mov rax, 0
    