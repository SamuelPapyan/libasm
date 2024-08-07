global		ft_strdup
extern 		__errno_location
extern		malloc
extern		ft_strlen
extern		ft_strcpy
; char	*strdup(const char *s1);
; s1 == rdi
section		.text

ft_strdup:
	push	rdi

_calculate_len:
	call	ft_strlen
	mov		rcx, rax
	inc		rcx

_malloc_dest:
	mov		rdi, rcx
	call	malloc
	cmp		rax, 0
	je		_error

_copy_string:
	mov		rdi, rax
	pop		rsi
	call	ft_strcpy
	ret

_error:
	pop		rdi
	call	__errno_location
	mov		rdx, 12
	mov		[rax], rdx
	mov		rax, 0
	ret