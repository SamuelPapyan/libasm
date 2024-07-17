section .text
	global	_ft_list_size

_ft_list_size:
init:
	xor	rax, rax

loop:
	cmp	rdi, 0
	je	return
	mov	rdi, [rdi+8]
	inc	rax
	jmp	loop

return:
	ret
