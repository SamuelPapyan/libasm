global	_ft_strcmp
; int   ft_strcmp(const char *s1, const char *s2);
; s1 == rdi, s2 == rsi

section .text

_ft_strcmp:
	mov		rax, 0
	mov		rdx, 0
	mov		rcx, -1

_check:
	inc		rcx
	mov		al, byte[rdi + rcx]
	mov		dl, byte[rsi + rcx]
	cmp		al, 0
	je		_return
	cmp		dl, 0
	je		_return
	cmp		al, dl
	je		_check

_return:
	sub		rax, rdx
	ret