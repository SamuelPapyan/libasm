global	ft_strcmp
; int   ft_strcmp(const char *s1, const char *s2);
; s1 == rdi, s2 == rsi

section .text

ft_strcmp:
	mov		rax, 0					; initialise rax to 0
	mov		rdx, 0					; initialise rdx to 0
	mov		rcx, -1					; initialise rcx to -1

_check:
	inc		rcx						; rcx becomes 0
	mov		al, BYTE[rdi + rcx]		; save current s1 char to al
	mov		dl, BYTE[rsi + rcx]		; save current s2 char to dl
	cmp		al, 0					; check if s1 char is \0
	je		_return					; if \0, go to return process
	cmp		dl, 0					; check if s2 char is \0
	je		_return					; if \0, go to return process
	cmp		al, dl					; compare s1 and s2 char
	je		_check					; if equal, start the loop again

_return:
	sub		rax, rdx				; subtract s1 char with s2 char
	ret								; return value saved in rax