section .text
extern ___error
global  _ft_read

_ft_read:
    mov rax, 0x2000003
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
