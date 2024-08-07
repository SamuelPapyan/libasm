section .text
	global	ft_list_create_elem
	extern	malloc
; t_list	*ft_list_create_elem(void *data)
; data == rdi

ft_list_create_elem:
	push	rdi
	mov		rdi, 16
	call	malloc
	pop		rdi
	mov		[rax], rdi
	mov		QWORD [rax+8], 0x0
	ret
