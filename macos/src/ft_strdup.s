global		_ft_strdup
extern 		___error
extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy
; char	*strdup(const char *s1);
; s1 == rdi
section		.text

_ft_strdup:
	push	rdi

_calculate_len:
	call	_ft_strlen
	mov		rcx, rax
	inc		rcx

_malloc_dest:
	mov		rdi, rcx
	call	_malloc
	cmp		rax, 0
	je		_error

_copy_string:
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret

_error:
	pop		rdi
	call	___error
	mov		rdx, 12
	mov		[rax], rdx
	mov		rax, 0
	ret