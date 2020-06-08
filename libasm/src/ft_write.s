section .text
extern ___error
global  _ft_write

_ft_write:
    mov rax, 0x2000004
    syscall
	jc error
    ret

error:
	mov rdx, rax
	push rdx
	call ___error
	pop rdx
	mov qword[rax], rdx
	mov rax, -1
	ret
