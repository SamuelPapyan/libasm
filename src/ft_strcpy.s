section .text
	global	_ft_strcpy
	extern	_ft_strlen

_ft_strcpy:
	push	rdi
	mov		rdi, rsi
	call	_ft_strlen
	mov		rcx, rax
	pop		rdi
	mov		rax, rdi
	cld
	rep		movsb
	mov		BYTE[rdi], 0
	ret
