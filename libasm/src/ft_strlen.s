; int ft_strlen(char *str)
; {
; 	int i;

; 	i = 0;
; 	while (str[i])
; 		i++;
; 	return (i);
; }

section	.text
global	ft_strlen

ft_strlen:
	xor rax, rax
	start_loop:
		cmp	byte[rdi + rax], 0
		je	end_loop
		inc	rax
		jmp	start_loop
	end_loop:
		ret