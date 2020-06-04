			section	.text
			global	ft_strlen

; delete RAX

ft_strlen:
			xor		rax, rax			; i = 0
			jmp		compare
increment:
			inc		rax					; i++
compare:
			cmp		BYTE [rdi + rax], 0	; str[i] == 0
			jne		increment
done:
			ret							; return i
