section .text
	global	_ft_list_push_front
	extern	_ft_list_create_elem

_ft_list_push_front:
	push	rdi
	mov		rdi, rsi
	call	_ft_list_create_elem
	pop		rdi
	mov		rsi, [rdi]
	mov		QWORD [rax+8], rsi
	mov		QWORD [rdi], rax
	ret
